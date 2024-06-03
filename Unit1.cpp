//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees.AncestorVCL"
#pragma link "VirtualTrees.BaseAncestorVCL"
#pragma link "VirtualTrees.BaseTree"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    resultStringTree->NodeDataSize = sizeof(NodeStruct);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::startButtonClick(TObject *Sender)
{
	if (! isStarted) {
        start();
	}
	else {
        stop();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::start() {
	Form1->Timer1->Enabled = true;
	thread = new SearchThread(false);
	volumeEdit->Enabled  = false;
	searchFileType->Enabled  = false;
	isStarted = true;
	progressBar->Position = 0;
	Form1->execTime->Caption = 0;
	resultStringTree->Clear();
	startButton->Caption = L"Остановить поиск";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::stop() {
	thread->Terminate();
	Form1->Timer1->Enabled = false;
	volumeEdit->Enabled  = true;
	searchFileType->Enabled  = true;
	isStarted = false;
	totalTime = 0;
	startButton->Caption = L"Начать поиск";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::resultStringTreeGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)
{
	if (!Node) {
		return;
	}

	NodeStruct *nodeData = (NodeStruct*)Sender->GetNodeData(Node);
	switch (Column) {
		case 0: CellText = nodeData->clusterNum;break;
		case 1: CellText = nodeData->content;break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    totalTime++;
	execTime->Caption=totalTime*0.001*Timer1->Interval;
}
//---------------------------------------------------------------------------

