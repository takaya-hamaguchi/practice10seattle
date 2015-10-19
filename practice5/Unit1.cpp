//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CorepoEng2009"
#pragma link "cxGraphics"
#pragma link "dxBarBuiltInMenu"
#pragma link "dxCore"
#pragma link "dxCoreClasses"
#pragma link "dxGDIPlusAPI"
#pragma link "dxGDIPlusClasses"
#pragma link "dxRichEdit.Control"
#pragma link "dxRichEdit.Options"
#pragma link "dxRichEdit.Platform.Win.Control"
#pragma link "dxRichEdit.Types"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
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
		crp_Practice2->ReportPath = "practice5.crp";
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

