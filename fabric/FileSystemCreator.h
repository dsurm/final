//---------------------------------------------------------------------------

#ifndef FileSystemCreatorH
#define FileSystemCreatorH
//---------------------------------------------------------------------------
#endif
#pragma once
#include "Windows.h"
#include "FS.h"
#include <vcl.h>

enum class FileSystemTypeEnum {NTFS, FAT16};

class FileSystemCreator {
public:
	virtual FS* CreateFileSystem(
		FileSystemTypeEnum fsType,
		const WCHAR* filename
	) = 0;
};

class MyFileSystemCreator : public FileSystemCreator {
public:
	virtual FS* CreateFileSystem(
		FileSystemTypeEnum fsType,
		const WCHAR* filename
	);
};

UnicodeString GetFsName(FileSystemTypeEnum fsType);
