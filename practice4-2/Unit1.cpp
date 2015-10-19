//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CorepoEng2009"
#pragma resource "*.dfm"
TForm1 *Form1;

//**************************************************
//�y�C�x���g�����z
//**************************************************
//---------------------------------------------------------------------------
/**
 * �t�H�[�����[�h
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// ���\�b�h���ϐ��錾
	TGridRect selection;

	try
	{
		//**************************************************
		//�y�������z
		//  �ϐ�
		//**************************************************
		selection.Left = -1;
		selection.Top = -1;
		selection.Right = -1;
		selection.Bottom = -1;

		//**************************************************
		//�y�������z
		//  �R���g���[��
		//**************************************************
		// �Z�����X�g
		this->grd_Address->RowCount = 1;
		this->grd_Address->RowHeights[0] = 24;
		this->grd_Address->FixedRows = 0;

		// �Z�����X�g�i�w�b�_�j
		this->grd_Address->Cells[0][0] = "ID";
		this->grd_Address->ColWidths[0] = 50;

		this->grd_Address->Cells[1][0] = "���O";
		this->grd_Address->ColWidths[1] = 100;

		this->grd_Address->Cells[2][0] = "�Z��";
		this->grd_Address->ColWidths[2] = 174;

		this->grd_Address->Cells[3][0] = "����";
		this->grd_Address->ColWidths[3] = 150;

		this->grd_Address->Cells[4][0] = "�L��";
		this->grd_Address->ColWidths[4] = 45;

		// �Z�����X�g�i�I����ԁj
		this->grd_Address->Selection = selection;

		//**************************************************
		//�y�Z�����X�g�\���z
		//**************************************************
		ShowAddress();
	}
	catch (int e)
	{
		ShowMessage("�����\�����ɗ�O���������܂����B");
	}
}
//---------------------------------------------------------------------------
/**
 * ����{�^������
 * @param TObject *Sender �Ăяo�����I�u�W�F�N�g
 * @return void
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
 * CSV�o�̓{�^������
 * @param TObject *Sender �Ăяo�����I�u�W�F�N�g
 * @return void
 */
void __fastcall TForm1::btn_CsvOutputClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	try
	{
		//**************************************************
		//�y�`�F�b�N�z
		//**************************************************
        //
		// �f�[�^
		//
		if (this->grd_Address->Row == 0)
		{
			// �Ȃ�
			ShowMessage("CSV�o�͂���f�[�^������܂���B");
			return;
		}

		//**************************************************
		//�yCSV�o�͏����z
		//**************************************************
        CsvOutput();
	}
	catch (int e)
	{
		ShowMessage("CSV�o�͒��ɗ�O���������܂����B");
	}
}
//---------------------------------------------------------------------------
 /**
 * �v���r���[�{�^������
 * @param TObject *Sender �Ăяo�����I�u�W�F�N�g
 * @return void
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// ���\�b�h���ϐ��錾

	try
	{
        //**************************************************
		//�y�`�F�b�N�z
		//**************************************************
        //
		// �f�[�^
		//
		if (this->grd_Address->Row == 0)
		{
			// �Ȃ�
			ShowMessage("�v���r���[����f�[�^������܂���B");
			return;
		}

		//**************************************************
		//�y�v���r���[�����z
		//**************************************************
        Preview();
	}
	catch (int e)
	{
		ShowMessage("�v���r���[���ɗ�O���������܂����B");
	}
}
//---------------------------------------------------------------------------
 /**
 * �Z�����X�g�`��
 * @param TObject *Sender �Ăяo�����I�u�W�F�N�g
 * @param int ACol �`�悷���ʒu
 * @param int ARow �`�悷��s�ʒu
 * @param TRect &Rect �`�悷��Z�����W
 * @param TGridDrawState State
 * @return void
 */
void __fastcall TForm1::grd_AddressDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
//	// ���\�b�h���ϐ��錾
//    AnsiString value;
//	unsigned int pos;
//	RECT r = RECT(Rect);
//
//	//**************************************************
//	//�y�w�b�_�z
//	//**************************************************
//	if (ARow == 0)
//	{
//		pos = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
//	}
//	//**************************************************
//	//�y�ʏ�s�z
//	//**************************************************
//	else if (ARow > 0)
//	{
//		switch (ACol)
//		{
//			// ID
//			case 0:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_RIGHT;
//				break;
//
//			// ���O
//			case 1:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// �Z��
//			case 2:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// ����
//			case 3:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// �L��
//			case 4:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
//				break;
//		}
//	}
//
//	// �Z���l�擾
//	value = grd_Address->Cells[ACol][ARow];
//
//	// �N���A
//	grd_Address->Canvas->FillRect(Rect);
//
//	// �t�H�[�J�X�g�̕`��
//	if (State.Contains(gdSelected))
//	{
//		grd_Address->Canvas->Font->Color = clHighlightText;
//
//		if (State.Contains(gdFocused))
//		{
//			DrawFocusRect(
//				grd_Address->Canvas->Handle,
//				&r
//			);
//		}
//	}
//	else
//	{
//		//grd_Address->Canvas->Font->Color = grd_Address->Font->Color;
//		grd_Address->Canvas->Font->Color = clWindowText;
//	}
//
////	// �e�L�X�g�\���̈�̐ݒ�
////	InflateRect(
////		&r,
////		-2,
////		-2
////	);
//
//	// �Z���ĕ`��
//	DrawText(
//		grd_Address->Canvas->Handle,
//		value.c_str(),
//		value.Length(),
//		&Rect,
//		pos
//	);
	AnsiString value = grd_Address->Cells[ACol][ARow];
	unsigned int position = DT_VCENTER|DT_CENTER|DT_SINGLELINE;

	// �Z���̔w�i�F��ύX����
	if (ARow == 0)
	{
		grd_Address->Canvas->Brush->Color = clBtnFace;
	}
	else
	{
		grd_Address->Canvas->Brush->Color = clWhite;
	}

	// �w�i�F�œh��Ԃ�
	grd_Address->Canvas->FillRect(Rect);

	// �Z���̒��̕�������ēx�ACanvas�ɕ`�悷��B
	// �t�H���g�J���[����������
	// �w�i�F����������
	grd_Address->Canvas->Font->Color=grd_Address->Font->Color;

	// �ʒu
	if (ARow == 0)
	{
		// �w�b�_
		position = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
	}
	else if (ARow > 0)
	{
		// �ʏ�s
		switch (ACol)
		{
			// ID
			case 0:
				position = DT_SINGLELINE | DT_VCENTER | DT_RIGHT;
				break;

			// ���O
			case 1:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// �Z��
			case 2:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// ����
			case 3:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// �L��
			case 4:
				position = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
				break;
		}
	}

	// �ĕ`��
	DrawTextA(
		grd_Address->Canvas->Handle,
		value.c_str(),
		value.Length(),
		&Rect,
		position
	);
}
//---------------------------------------------------------------------------

//**************************************************
//�y���[�U�[��`�֐��z
//**************************************************
/**
 * �Z�����X�g�\��
 * @param
 * @return void
 */
void __fastcall TForm1::ShowAddress()
{
	// ���\�b�h���ϐ��錾
	String path;
	String sql;
	String fatalMsg;

	try
	{
		//**************************************************
		//�y�������z
		//**************************************************
		path = GetCurrentDir() + "\\practice4.sqlite3";
		//path = StringReplace(path, "\\", "/", TReplaceFlags() << rfReplaceAll);
		sql = "";
		fatalMsg = "";

		// �c�a�ڑ��I�u�W�F�N�g
		dbCon->Params->Clear();
		dbCon->Params->Add("DriverName=Sqlite");
		dbCon->Params->Add("Database=" + path);
		ShowMessage(dbCon->Params->GetText());

		//**************************************************
		//�y�c�a�ڑ��z
		//**************************************************
		fatalMsg = "�c�a�ڑ����Ɉُ킪�������܂����B";

		// �c�a�ڑ�
		dbCon->Connected = true;

//		// �N�G���ݒ�
//		dbSql->SQLConnection = dbCon;

		//**************************************************
		//�y�r�p�k�����z
		//**************************************************
		fatalMsg = "�c�a�ڑ����Ɉُ킪�������܂����B";

		// �r�p�k����
		sql =
			"SELECT "
				"* "
			"FROM "
				"p4_address "
			"ORDER BY "
				"id"
		;
		//dbSql->CommandText = sql;
		dbSql->SQL->Text = sql;
		dbSql->Active = true;

		//**************************************************
		//�y�r�p�k���s�z
		//**************************************************
		fatalMsg = "�r�p�k���s���Ɉُ킪�������܂����B";

		if (!dbSql->IsEmpty())
		{
			TStringList* columnNames = new TStringList;

			// �擪���R�[�h��
			dbSql->First();

			__try
			{
				// �񖼃��X�g�擾
				dbSql->GetFieldNames(columnNames);

				while (!dbSql->Eof)
				{
					String currentLine = "";

					for (int i = 0; i < columnNames->Count; ++i)
					{
						TField* currentField = dbSql->FieldByName(columnNames->Strings[i]);

						currentLine = currentLine + " " + currentField->AsString;
					}
					//outputMemo->Lines->Add(currentLine);

					// ���̃��R�[�h��
					dbSql->Next();
				}
			}
			__finally
			{
				columnNames->Free();
			}
		}

		// �I�u�W�F�N�g���
		dbSql->Close();
		dbSql->Active=false;

		//**************************************************
		//�y�c�a�ؒf�z
		//**************************************************
		dbCon->Connected = false;
	}
	/*
	catch (EDatabaseError& E)
	{
		ShowMessage(fatalMsg + "\r\n�G���[���b�Z�[�W�F" + E.Message);
	}
	catch (EExternalException& E)
	{
		ShowMessage(fatalMsg + "\r\n�G���[���b�Z�[�W�F" + E.Message);
	}
	*/
	catch (Exception& E)
	{
		ShowMessage(fatalMsg + "\r\n�G���[���b�Z�[�W�F" + E.Message);
	}
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * CSV�o�͏���
 * @param
 * @return void
 */
void __fastcall TForm1::CsvOutput()
{
	// ���\�b�h���ϐ��錾
	TStringList *output = new TStringList;

	try
	{
        //**************************************************
		//�yCSV�o�̓f�[�^�����z
		//**************************************************
		for (int i = 0; i < this->grd_Address->RowCount; i++)
		{
			//==================================================
			//�y�o�̓f�[�^���o�z
			//==================================================
			AnsiString id = this->grd_Address->Cells[0][i];
			AnsiString name = this->grd_Address->Cells[1][i];
			AnsiString address = this->grd_Address->Cells[2][i];
			AnsiString memo = this->grd_Address->Cells[3][i];
			AnsiString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//�y�`�F�b�N�z
			//==================================================
			if (i != 0 && valid != "��")
			{
				continue;
			}

			//==================================================
			//�y�o�̓��R�[�h�����z
			//==================================================
			TStringList *record = new TStringList;
			record->Add(id);
			record->Add(name);
			record->Add(address);
			record->Add(memo);

			//==================================================
			//�y�o�̓f�[�^�ݒ�z
			//==================================================
			output->Add(record->CommaText);
		}

		//**************************************************
		//�yCSV�o�́z
		//**************************************************
		// �_�C�A���O�ݒ�
		dlg_CsvOutput->DefaultExt = ".csv";
		dlg_CsvOutput->Filter = "CSV�t�@�C�� (*.csv)|*.csv";
		dlg_CsvOutput->Title = "�o�͐���w�肵�Ă��������B";
		dlg_CsvOutput->Options << ofOverwritePrompt << ofCreatePrompt;

		// �_�C�A���O�\��
		if (dlg_CsvOutput->Execute())
		{
			// �o��
			output->SaveToFile(dlg_CsvOutput->FileName);
		}
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * �v���r���[����
 * @param
 * @return void
 */
void __fastcall TForm1::Preview()
{
	// ���\�b�h���ϐ��錾
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
        //**************************************************
		//�y���|�[�g�ݒ�z
		//**************************************************
		crp_practice4->ReportPath = "practice4.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;

        //**************************************************
		//�y����W���u�J�n�z
		//**************************************************
		if (crp_practice4->OpenPrintJob(
				"",     //����W���u��
				prtOpt,	//�I�v�V�����ݒ�
				true,	//����v���r���[�̕\��
				"",     //����v���r���[��ʂ̃^�C�g��
				NULL    //�v���r���[��\������E�C���h�E
			)  == false)
		{
			// ����W���u�J�n���s
			crp_practice4->ReportPath = "";
			ShowMessage("����W���u�̊J�n���Ɉُ킪�������܂����B");
			return;
		}

        //**************************************************
		//�y����f�[�^�ݒ�z
		//  �Z�����X�g
		//**************************************************
		int record = 0;
		int page = 1;
		int pageAll = (this->grd_Address->RowCount / 15) + 1;

		for (int i = 1; i < this->grd_Address->RowCount; i++)
		{
			//==================================================
			//�y����f�[�^���o�z
			//==================================================
			AnsiString id = this->grd_Address->Cells[0][i];
			AnsiString name = this->grd_Address->Cells[1][i];
			AnsiString address = this->grd_Address->Cells[2][i];
			AnsiString memo = this->grd_Address->Cells[3][i];
			AnsiString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//�y�`�F�b�N�z
			//==================================================
			if (valid != "��")
			{
				continue;
			}

			//==================================================
			//�y���y�[�W�����z
			//==================================================
			if (record >= 15)
			{
				crp_practice4->ClearAllText();
				record = 0;
				page++;
			}

			record++;

            //==================================================
			//�y����f�[�^�ݒ�z
			//==================================================
			// ID
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Id")->Text = id;

			// ���O
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Name")->Text = name;

			// �Z��
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Address")->Text = name;

			// ����
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Memo")->Text = name;

			//==================================================
			//�y����i�v���r���[�j�z
			//==================================================
			if (record >= 15)
			{
				// �^�C�g��
				crp_practice4->Item("", "lbl_Title")->Text = "�ۑ�S";

				//�y�w�b�_�zID
				crp_practice4->Item("", "lbl_Header_Id")->Text = "ID";

				//�y�w�b�_�z���O
				crp_practice4->Item("", "lbl_Header_Name")->Text = "���O";

				//�y�w�b�_�z�Z��
				crp_practice4->Item("", "lbl_Header_Address")->Text = "�Z��";

				//�y�w�b�_�z����
				crp_practice4->Item("", "lbl_Header_Memo")->Text = "����";

				// �y�[�W��
				crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + "�^" + IntToStr(pageAll);

				// ����i�v���r���[�j
				crp_practice4->PrintReport();
			}
		}

		//**************************************************
		//�y����f�[�^�ݒ�z
		//  ��s
		//**************************************************
		while (record < 15)
		{
			record++;

			//==================================================
			//�y��s��\���z
			//==================================================
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Id")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Name")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Address")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Memo")->Visible = false;
		}

		// �^�C�g��
		crp_practice4->Item("", "lbl_Title")->Text = "�ۑ�S";

		//�y�w�b�_�zID
		crp_practice4->Item("", "lbl_Header_Id")->Text = "ID";

		//�y�w�b�_�z���O
		crp_practice4->Item("", "lbl_Header_Name")->Text = "���O";

		//�y�w�b�_�z�Z��
		crp_practice4->Item("", "lbl_Header_Address")->Text = "�Z��";

		//�y�w�b�_�z����
		crp_practice4->Item("", "lbl_Header_Memo")->Text = "����";

		// �y�[�W��
		crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + "�^" + IntToStr(pageAll);

        //**************************************************
		//�y����i�v���r���[�j�z
		//  ��s
		//**************************************************
		crp_practice4->PrintReport();

        //**************************************************
		//�y����W���u�I���z
		//**************************************************
		crp_practice4->ClosePrintJob(true);

		//**************************************************
		//�y���|�[�g�N���[�Y�z
		//**************************************************
		crp_practice4->ReportPath = "";
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------

