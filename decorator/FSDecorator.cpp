//---------------------------------------------------------------------------

#pragma hdrstop

#include "FSDecorator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void FSDecorator::First()
{
	It->First();
	while (!It->IsDone() && It->GetCurrent().GetFileType() != TargetFile) {
		It->Next();
	}
}
void FSDecorator::Next()
{
	do {
		It->Next();
	} while (!It->IsDone() && It->GetCurrent().GetFileType() != TargetFile);
}
