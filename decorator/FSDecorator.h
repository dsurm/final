//---------------------------------------------------------------------------

#ifndef FSDecoratorH
#define FSDecoratorH
//---------------------------------------------------------------------------
#endif
#pragma once
#include "Decorator.h"
#include "Cluster.h"
#include <iostream>
class FSDecorator :public Decorator<Cluster>
{
private:
	FileTypeEnum TargetFile;
public:
	FSDecorator(Iterator<Cluster>* it, FileTypeEnum targetFile) : Decorator(it) {
		TargetFile = targetFile;
	}
	void First();
	void Next();
};

