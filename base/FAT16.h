//---------------------------------------------------------------------------

#ifndef FAT16H
#define FAT16H
#endif
//---------------------------------------------------------------------------
#pragma once
#include "FS.h"
#include <iostream>

class FAT16 :
	public FS
{
private:
#pragma pack(push, 1)
	typedef struct {
		BYTE padding1[11];
		uint16_t sectorSize;
		uint8_t clasterSize;
		BYTE padding2[5];
		uint16_t countSectors16;
		BYTE padding3[11];
		uint32_t countSectors32;
	} BootRecord;
#pragma pack(pop)
protected:
	// В разных ФС различается только процесс получения размера кластера
	bool ReadClusterSize();
};


