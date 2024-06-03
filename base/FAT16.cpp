//---------------------------------------------------------------------------

#pragma hdrstop

#include "FAT16.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "FAT16.h"
#include "Iterator.h"
#include <iostream>
#include "windows.h"
#include "stdio.h"
#include "FAT16Iterator.h"
using namespace std;

bool FAT16::ReadClusterSize()
{
    BYTE sector[512];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);

    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = 0;

    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        throw std::invalid_argument("Set FilePointer error");
        CloseHandle(fileHandler);
        return false;
    }
    if (!ReadFile(fileHandler, sector, bytesToRead, &bytesRead, NULL))
    {
        throw std::invalid_argument("ReadFile error");
        CloseHandle(fileHandler);
        return false;
    }

	BootRecord* pBootRecord = reinterpret_cast<BootRecord*>(sector);
    reservedSectors = static_cast<int>(pBootRecord->reservedSectors);
    unsigned int countSectors = 0;
	if (pBootRecord->countSectors16 != 0) {
		countSectors = static_cast<int>(pBootRecord->countSectors16);
	}
	else if (pBootRecord->countSectors32 != 0) {
        countSectors = static_cast<int>(pBootRecord->countSectors32);
    }
    else {
        throw std::invalid_argument("Can't get count sectors per disk");
    }
	sectorSize = pBootRecord->sectorSize;
    unsigned int sectorsPerCluster = static_cast<int>(pBootRecord->clasterSize);
    clusterSize = sectorSize * sectorsPerCluster;
    clusterCount = countSectors / sectorsPerCluster;
    return true;
}

bool FAT16::ReadCluster(Cluster* item, unsigned int clusterNum)
{
    DWORD bytesRead;
    DWORD bytesToRead = clusterSize;
    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = (static_cast<LONGLONG>(clusterNum) * clusterSize) + reservedSectors * sectorSize; // Смещение для размера сектора
    BYTE* arr = new BYTE[clusterSize];
	// Устанавливаем смещение
    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        throw std::invalid_argument("Set FilePointer error");
        CloseHandle(fileHandler);
        return false;
    }
    if (!ReadFile(fileHandler, arr, clusterSize, &bytesRead, NULL))
    {
        throw std::invalid_argument("ReadFile error");
        CloseHandle(fileHandler);
        return false;
    }
    item->SetClusterNum(clusterNum);
    item->SetContent(arr, clusterSize);
    delete[] arr;
    return true;
}