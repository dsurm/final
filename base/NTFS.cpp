//---------------------------------------------------------------------------

#pragma hdrstop

#include "NTFS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "NTFS.h"
#include <iostream>
#include "windows.h"
#include "stdio.h"
using namespace std;

bool NTFS::ReadClusterSize()
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
	unsigned int sectorsPerCluster = static_cast<unsigned int>(pBootRecord->sectorsPerCluster);
	unsigned int sectorSize = static_cast<unsigned int>(pBootRecord->bytesPerSector);
	clusterCount = static_cast<uint64_t>(pBootRecord->countSectors);
	clusterSize = sectorSize * sectorsPerCluster;
    return true;
}