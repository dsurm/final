//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "writeThread.h"
#include "sqlite3.h"
#include "Cluster.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall WriteThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall WriteThread::WriteThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;
	DataReadyEvent = new TEvent(NULL, true, false, "", false);
	DataCopiedEvent = new TEvent(NULL, true, false, "", false);

	// Подключение к SQLite
	sqlite3* Database;
	int openResult = sqlite3_open16(L"../../cluster.db", &Database);
	if (openResult != SQLITE_OK) {
		throw "Can't open db";
	}

	// Создание таблицы
    char* errmsg;
	char sql[] = "CREATE TABLE IF NOT EXISTS data(cluster INT NOT NULL,"
		"content TEXT NOT NULL);";
	int execResult = sqlite3_exec(Database, sql, NULL, NULL, &errmsg);
	if (execResult != SQLITE_OK) {
		throw "Can't create table";
	}

	// Подготовка запроса на вставку
	int rc = sqlite3_prepare_v2(Database, "INSERT INTO data(cluster, content) VALUES (?, ?)", -1, &res, 0);
	if (rc != SQLITE_OK)
	{
		throw "Cannot prepate query";
	}

    buff.set_length(16);
}
//---------------------------------------------------------------------------
void __fastcall WriteThread::Execute()
{
	while (! Terminated) {
		if (DataReadyEvent->WaitFor(INFINITE) == wrSignaled) {
			memcpy(content, currentCluster->GetContent(), 16);
			memcpy(&buff[0],  currentCluster->GetContent(), 16);

			DataReadyEvent->ResetEvent();

			// Записать в VirtualStringTree и обновить прочую информацию на форме
			Synchronize(&OnUpdate);

			// Записать в базу
			sqlite3_exec(Database, "BEGIN;", nullptr, nullptr, nullptr);
			sqlite3_bind_int(res, 1, currentCluster->getClusterNum());
			sqlite3_bind_text(res, 2, content, -1, SQLITE_STATIC);
			sqlite3_exec(Database, "COMMIT;", nullptr, nullptr, nullptr);
			int step = sqlite3_step(res);
			if (step == SQLITE_ERROR)
			{
				throw "SQLITE_ERROR";
			}
			sqlite3_reset(res);
			sqlite3_clear_bindings(res);

			DataCopiedEvent->SetEvent();
		}
	}

	sqlite3_close(Database);
	sqlite3_finalize(res);
	delete DataReadyEvent;
    delete DataCopiedEvent;
}
//---------------------------------------------------------------------------
void __fastcall WriteThread::OnUpdate() {
	// Добавляем очередную запись
	PVirtualNode entryNode = Form1->resultStringTree->AddChild(Form1->resultStringTree->RootNode);

	// Заполняем данные узла
	NodeStruct *nodeData = (NodeStruct*)Form1->resultStringTree->GetNodeData(entryNode);
	nodeData->clusterNum = currentCluster->GetNum();
	nodeData->content = System::Sysutils::StringOf(buff);
}