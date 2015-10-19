//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "CorepoEng2009.hpp"
#include <DB.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *lbl_Title;
	TShape *shp_Title;
	TButton *btn_Preview;
	TShape *Shape2;
	TButton *btn_End;
	TButton *btn_CsvOutput;
	TCrpReport *crp_practice4;
	TStringGrid *grd_Address;
	TSaveDialog *dlg_CsvOutput;
	void __fastcall btn_EndClick(TObject *Sender);
	void __fastcall btn_CsvOutputClick(TObject *Sender);
	void __fastcall btn_PreviewClick(TObject *Sender);
	void __fastcall grd_AddressDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:	// ユーザー宣言
	void __fastcall ShowAddress();
	void __fastcall CsvOutput();
	void __fastcall Preview();
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
