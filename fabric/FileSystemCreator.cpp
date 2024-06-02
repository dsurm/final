//---------------------------------------------------------------------------

#pragma hdrstop

#include "FileSystemCreator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "FileSystemCreator.h"
#include "FS.h"
#include "NTFS.h"
#include "FAT16.h"

FS* MyFileSystemCreator::CreateFileSystem(
	FileSystemTypeEnum fsType,
	const WCHAR* fileName
)
{
	switch (fsType) {
	case FileSystemTypeEnum::NTFS: {
		NTFS* fs = new NTFS();
		fs->Init(fileName);
		return fs;
	};
	case FileSystemTypeEnum::FAT16: {
		FAT16* fs = new FAT16();
		fs->Init(fileName);
		return fs;
	};
	default: {
		throw std::invalid_argument("Invalid file sytem type");
	}
	}
}

UnicodeString GetFsName(FileSystemTypeEnum fsType) {
	switch (fsType) {
		case FileSystemTypeEnum::NTFS: {
			return System::UnicodeString(L"NTFS");
		};
		case FileSystemTypeEnum::FAT16: {
			return System::UnicodeString(L"FAT16");
		};
		default: {
			return System::UnicodeString(L"Undefined");
		}
	}
}
