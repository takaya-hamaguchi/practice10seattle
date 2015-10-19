//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CorepoEng2009.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *lbl_Title;
	TLabel *lbl_Name;
	TEdit *txt_Name;
	TLabel *lbl_Address;
	TEdit *txt_Address;
	TLabel *lbl_Memo;
	TButton *btn_End;
	TButton *btn_Preview;
	TMemo *txt_Memo;
	TCrpReport *crp_Practice2;
	void __fastcall btn_EndClick(TObject *Sender);
	void __fastcall btn_PreviewClick(TObject *Sender);
private:	// ユーザー宣言
	//bool __fastcall chk_Blank(TStrings *value);
	//bool __fastcall chk_Blank(UnicodeString *value);
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
