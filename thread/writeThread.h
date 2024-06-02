//---------------------------------------------------------------------------

#ifndef writeThreadH
#define writeThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Cluster.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
class WriteThread : public TThread
{
private:
	void __fastcall OnUpdate();
	sqlite3_stmt* res;
	sqlite3* Database;
	TBytes buff;
	char content[16];
protected:
	void __fastcall Execute();
public:
	__fastcall WriteThread(bool CreateSuspended);
	TEvent *DataReadyEvent;
	TEvent *DataCopiedEvent;
	Cluster* currentCluster;
};
//---------------------------------------------------------------------------
#endif
