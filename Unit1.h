//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include <Vcl.ComCtrls.hpp>
#include "searchThread.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *startButton;
	TVirtualStringTree *resultStringTree;
	TProgressBar *progressBar;
	TLabel *Label2;
	TEdit *volumeEdit;
	TComboBox *searchFileType;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *fsClusterNum;
	TLabel *fsType;
	TLabel *Label5;
	TLabel *fsClusterSize;
	TLabel *Label6;
	TLabel *execTime;
	TTimer *Timer1;
	void __fastcall startButtonClick(TObject *Sender);
	void __fastcall resultStringTreeGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	SearchThread *thread;
	unsigned int totalTime = 0;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall start();
    void __fastcall stop();
	bool isStarted = false;
};
typedef struct {
	ULONGLONG clusterNum;
	UnicodeString content;
} NodeStruct;
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
