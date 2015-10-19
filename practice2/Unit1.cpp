//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CorepoEng2009"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
/**
 * フォームロード
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// メソッド内変数宣言
}
//---------------------------------------------------------------------------
/**
 * 終了ボタン押下
 */
void __fastcall TForm1::btn_EndClick(TObject *Sender)
{
	// メソッド内変数宣言

	//**************************************************
	//【終了】
	//**************************************************
	this->Close();
}
//---------------------------------------------------------------------------
/**
 * プレビューボタン押下
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// メソッド内変数宣言
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
		//**************************************************
		//【チェック】
		//**************************************************
		/*
		//
		// 名前
		//
		if (chk_Blank(txt_Name->Text))
		{
			// 未入力
			ShowMessage("名前が未入力です。");
			return;
		}
		//
		// 住所
		//
		if (chk_Blank(txt_Address->Text))
		{
			// 未入力
			ShowMessage("住所が未入力です。");
			return;
		}
		//
		// メモ
		//
		if (chk_Blank(txt_Memo->Text))
		{
			// 未入力
			ShowMessage("メモが未入力です。");
			return;
		}
		*/

		//**************************************************
		//【プレビュー】
		//**************************************************
		//
		// レポート設定
		//
		crp_Practice2->ReportPath = "practice2.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;
		//
		// 印刷ジョブ開始
		//
		if (crp_Practice2->OpenPrintJob(
				"",     //印刷ジョブ名
				prtOpt,	//オプション設定
				true,	//印刷プレビューの表示
				"",     //印刷プレビュー画面のタイトル
				NULL    //プレビューを表示するウインドウ
			)  == false)
		{
			// 印刷ジョブ開始失敗
			crp_Practice2->ReportPath = "";
			ShowMessage("印刷ジョブの開始中に異常が発生しました。");
			//return;
		}
		//
		// 印刷データ設定
		//
		crp_Practice2->Item("","lbl_Name")->Text = txt_Name->Text;
		crp_Practice2->Item("","lbl_Address")->Text = txt_Address->Text;
		crp_Practice2->Item("","lbl_Memo")->Text = txt_Memo->Text;
		//
		// 印刷
		//
		crp_Practice2->PrintReport();
		//
		// 印刷ジョブ終了
		//
		crp_Practice2->ClosePrintJob(true);

		//**************************************************
		//【レポートクローズ】
		//**************************************************
		crp_Practice2->ReportPath = "";
	}
	catch (int e)
	{
		ShowMessage("例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
/**
 * 【チェック処理】空白
 */
/*
bool __fastcall chk_Blank(UnicodeString *value)
{
	// メソッド内変数宣言
	bool ret = true;

	try
	{
		//**************************************************
		//【チェック処理】
		//  空白
		//**************************************************
		if (strlen(value) == 0)
		{
			// 空白
			ret = false;
		}
		if (value == '\0')
		{
			// NULL
			ret = false;
		}
	}
	catch (int e)
	{
		ret = false;
	}
	return ret;
}
*/

