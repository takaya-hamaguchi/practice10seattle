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
 * �t�H�[�����[�h
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// ���\�b�h���ϐ��錾
}
//---------------------------------------------------------------------------
/**
 * �I���{�^������
 */
void __fastcall TForm1::btn_EndClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	//**************************************************
	//�y�I���z
	//**************************************************
	this->Close();
}
//---------------------------------------------------------------------------
/**
 * �v���r���[�{�^������
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
		//**************************************************
		//�y�`�F�b�N�z
		//**************************************************
		/*
		//
		// ���O
		//
		if (chk_Blank(txt_Name->Text))
		{
			// ������
			ShowMessage("���O�������͂ł��B");
			return;
		}
		//
		// �Z��
		//
		if (chk_Blank(txt_Address->Text))
		{
			// ������
			ShowMessage("�Z���������͂ł��B");
			return;
		}
		//
		// ����
		//
		if (chk_Blank(txt_Memo->Text))
		{
			// ������
			ShowMessage("�����������͂ł��B");
			return;
		}
		*/

		//**************************************************
		//�y�v���r���[�z
		//**************************************************
		//
		// ���|�[�g�ݒ�
		//
		crp_Practice2->ReportPath = "practice5.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;
		//
		// ����W���u�J�n
		//
		if (crp_Practice2->OpenPrintJob(
				"",     //����W���u��
				prtOpt,	//�I�v�V�����ݒ�
				true,	//����v���r���[�̕\��
				"",     //����v���r���[��ʂ̃^�C�g��
				NULL    //�v���r���[��\������E�C���h�E
			)  == false)
		{
			// ����W���u�J�n���s
			crp_Practice2->ReportPath = "";
			ShowMessage("����W���u�̊J�n���Ɉُ킪�������܂����B");
			//return;
		}
		//
		// ����f�[�^�ݒ�
		//
		crp_Practice2->Item("","lbl_Name")->Text = txt_Name->Text;
		crp_Practice2->Item("","lbl_Address")->Text = txt_Address->Text;
		crp_Practice2->Item("","lbl_Memo")->Text = txt_Memo->Text;
		//
		// ���
		//
		crp_Practice2->PrintReport();
		//
		// ����W���u�I��
		//
		crp_Practice2->ClosePrintJob(true);

		//**************************************************
		//�y���|�[�g�N���[�Y�z
		//**************************************************
		crp_Practice2->ReportPath = "";
	}
	catch (int e)
	{
		ShowMessage("��O���������܂����B");
	}
}
//---------------------------------------------------------------------------
/**
 * �y�`�F�b�N�����z��
 */
/*
bool __fastcall chk_Blank(UnicodeString *value)
{
	// ���\�b�h���ϐ��錾
	bool ret = true;

	try
	{
		//**************************************************
		//�y�`�F�b�N�����z
		//  ��
		//**************************************************
		if (strlen(value) == 0)
		{
			// ��
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

