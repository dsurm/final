//---------------------------------------------------------------------------

#ifndef NTFSH
#define NTFSH
//---------------------------------------------------------------------------
#endif
#pragma once
#include "FS.h"
#include <iostream>
#include <cstdint>
#include <cstring>
class NTFS :
	public FS
{
private:
#pragma pack(push, 1)
	typedef struct {
		uint8_t jumpInstruction[3];
		char oemID[8];
		uint16_t bytesPerSector;
		uint8_t sectorsPerCluster;
		uint8_t jumpInstruction3[26];
		uint64_t countSectors;
	} BootRecord;
#pragma pack(pop)
protected:
	// � ������ �� ����������� ������ ������� ��������� ������� ��������
	bool ReadClusterSize();
};

