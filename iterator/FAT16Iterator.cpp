//---------------------------------------------------------------------------

#pragma hdrstop

#include "FAT16Iterator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cluster FAT16Iterator::GetCurrent()
{
	Cluster* item = new Cluster();
	fat16->ReadCluster(item, Cursor);

	return *item;
}
