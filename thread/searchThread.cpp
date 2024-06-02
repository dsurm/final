//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "searchThread.h"
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "Unit1.h"
#include "FileSystemCreator.h"
#include "Iterator.h"
#include "Decorator.h"
#include "FSDecorator.h"
#include "Cluster.h"
#include "FAT16Iterator.h"
#include "writeThread.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall SearchThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall SearchThread::SearchThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;

	writeThread = new WriteThread(false);
	diskName = (Form1->volumeEdit->Text).c_str();
	fsType = DetectFileSystem(diskName);

	fsCreator = new MyFileSystemCreator;
	fs = fsCreator->CreateFileSystem(fsType, (Form1->volumeEdit->Text).c_str()); // fabr
	if (!fs->Init(diskName)) {
		throw  "Cannot open disk";
	};
	clusterNum = fs->ClusterCount();
	fileType = getFileTypeEnum(Form1->searchFileType->Text);

	Synchronize(&OnStart);
}
//---------------------------------------------------------------------------
void __fastcall SearchThread::Execute()
{
	Iterator<Cluster>* it = new FSDecorator(
		new FAT16Iterator(fs),
		fileType
	);

	Cluster currentCluster;
	for (it->First();!it->IsDone() && !Terminated;it->Next()) {
		currentCluster = it->GetCurrent();
        curClaster = currentCluster.getClusterNum();
		Synchronize(&OnUpdate);

		writeThread->currentCluster = &currentCluster; // ѕередаЄм кластер в соседний поток
		writeThread->DataReadyEvent->SetEvent();

		while(writeThread->DataCopiedEvent->WaitFor(1000) != wrSignaled) { } // ∆дЄм секунду пока поток не прожуЄт данные

		writeThread->DataCopiedEvent->ResetEvent();
	}

    Synchronize(&OnEnd);
    writeThread->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall SearchThread::OnStart() {
	Form1->progressBar->Max = clusterNum;
	Form1->fsType->Caption = GetFsName(fsType);
	Form1->fsClusterNum->Caption = clusterNum;
	Form1->fsClusterSize->Caption = fs->ClusterSize();
}
//---------------------------------------------------------------------------
void __fastcall SearchThread::OnUpdate() {
	Form1->progressBar->Position = curClaster;
}
//---------------------------------------------------------------------------
void __fastcall SearchThread::OnEnd() {
    Form1->stop();
	Form1->progressBar->Position = clusterNum;
}
//---------------------------------------------------------------------------
FileSystemTypeEnum __fastcall SearchThread::DetectFileSystem(LPCWSTR fileName) {
    HANDLE fileHandler = CreateFileW(
        fileName,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
		NULL);                  // Handle to template

	if (fileHandler == INVALID_HANDLE_VALUE)
    {
        throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
    }

    DWORD bytesRead;
    BYTE buffer[2048];
    if (!ReadFile(fileHandler, buffer, sizeof(buffer), &bytesRead, nullptr)) {
        throw "Error reading volume\n";
    }

    if (buffer[3] == 'N' && buffer[4] == 'T' && buffer[5] == 'F' && buffer[6] == 'S') {
        return FileSystemTypeEnum::NTFS;
	}
	else if (buffer[54] == 0x46 && buffer[55] == 0x41 && buffer[56] == 0x54 && buffer[57] == 0x31) {
		return FileSystemTypeEnum::FAT16;
    }
    throw "Cannot detect fs!";
}
//---------------------------------------------------------------------------
