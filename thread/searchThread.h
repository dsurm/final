//---------------------------------------------------------------------------
#ifndef searchThreadH
#define searchThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "FileSystemCreator.h"
#include <sqlite3.h>
#include "writeThread.h"
//---------------------------------------------------------------------------
class SearchThread : public TThread
{
private:
	void __fastcall OnStart();
	void __fastcall OnUpdate();
    void __fastcall OnEnd();
    WriteThread *writeThread;
	__int64 clusterNum = 0;
	LPCWSTR diskName;
    FileTypeEnum fileType;
	FileSystemCreator* fsCreator;
	FileSystemTypeEnum fsType;
	FileSystemTypeEnum __fastcall DetectFileSystem(const WCHAR* fileName);
	FS* fs;
	__int64 curClaster = 0;
protected:
	void __fastcall Execute();
public:
	__fastcall SearchThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
