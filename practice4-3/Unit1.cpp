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
		this->grd_Address->Cells[0][0] = L"ID";
		this->grd_Address->ColWidths[0] = 50;

		this->grd_Address->Cells[1][0] = L"���O";
		this->grd_Address->ColWidths[1] = 100;

		this->grd_Address->Cells[2][0] = L"�Z��";
		this->grd_Address->ColWidths[2] = 174;

		this->grd_Address->Cells[3][0] = L"����";
		this->grd_Address->ColWidths[3] = 150;

		this->grd_Address->Cells[4][0] = L"�L��";
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
	// ���\�b�h���ϐ��錾
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
//	DrawTextA(
//		grd_Address->Canvas->Handle,
//		value.c_str(),
//		value.Length(),
//		&Rect,
//		position
//	);

//	DrawText(
//		grd_Address->Canvas->Handle,
//		(wchar_t *)&value,
//		value.Length(),
//		&Rect,
//		position
//	);

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
		sql = "";
		fatalMsg = "";

		//**************************************************
		//�y�c�a�ڑ��z
		//**************************************************
		fatalMsg = L"�c�a�ڑ����Ɉُ킪�������܂����B";

		// �c�a�ڑ�
		dbCon->Connected = true;

		//**************************************************
		//�y�r�p�k�����z
		//**************************************************
		fatalMsg = L"�c�a�ڑ����Ɉُ킪�������܂����B";

		// �r�p�k����
		sql =
			"SELECT "
				"* "
			"FROM "
				"p4_address "
			"ORDER BY "
				"id"
		;
		dbQuery->SQL->Text = sql;

		//**************************************************
		//�y�r�p�k���s�z
		//**************************************************
		fatalMsg = L"�r�p�k���s���Ɉُ킪�������܂����B";

		// �r�p�k���s
		dbQuery->Active = True;

		//**************************************************
		//�y�r�p�k���s���ʎ擾�z
		//**************************************************
		if (!dbQuery->IsEmpty())
		{
			TStringList* columnNames = new TStringList;

			// �擪�s��
			dbQuery->First();

			__try
			{
				// �񖼃��X�g�擾
				dbQuery->GetFieldNames(columnNames);

				while (!dbQuery->Eof)
				{
					UnicodeString id = "";
					UnicodeString name = "";
					UnicodeString address = "";
					UnicodeString memo = "";
					UnicodeString valid = "";

                    //==================================================
					//�y�f�[�^���o�z
					//==================================================
					for (int i = 0; i < columnNames->Count; ++i)
					{
						TField* currentField = dbQuery->FieldByName(columnNames->Strings[i]);

						switch (i)
						{
							case 0:
								id = currentField->AsString;
								break;

							case 1:
								name = currentField->AsString;
								break;

							case 2:
								address = currentField->AsString;
								break;

							case 3:
								memo = currentField->AsString;
								break;

							case 4:
								valid = currentField->AsString;
								break;
						}
					}

					//==================================================
					//�y�s�ǉ��z
					//==================================================
					this->grd_Address->RowCount++;

					//==================================================
					//�y�s�C���f�b�N�X�擾�z
					//==================================================
					int rowIndex = this->grd_Address->RowCount - 1;

					//==================================================
					//�y�X�^�C���ݒ�z
					//==================================================
					this->grd_Address->FixedRows = 1;
					this->grd_Address->RowHeights[rowIndex] = 24;

					//==================================================
					//�y�f�[�^�ݒ�z
					//==================================================
					// ID
					this->grd_Address->Cells[0][rowIndex] = id;

					// ���O
					this->grd_Address->Cells[1][rowIndex] = name;

					// �Z��
					this->grd_Address->Cells[2][rowIndex] = address;

					// ����
					this->grd_Address->Cells[3][rowIndex] = memo;

					// �L��
					if (valid == "1")
					{
						// ���F�L��
						Form1->grd_Address->Cells[4][rowIndex] = L"��";
					}
					else
					{
						// �~�F����
						Form1->grd_Address->Cells[4][rowIndex] = L"�~";
					}

					//==================================================
					//�y���̃��R�[�h�ցz
					//==================================================
					dbQuery->Next();
				}
			}
			__finally
			{
				// �I�u�W�F�N�g���
				columnNames->Free();
			}
		}

		// �I�u�W�F�N�g���
		dbQuery->Close();
		dbQuery->Active = false;

		//**************************************************
		//�y�c�a�ؒf�z
		//**************************************************
		dbCon->Connected = false;
	}
	catch (Exception& E)
	{
		ShowMessage(fatalMsg + L"\r\n�G���[���b�Z�[�W�F" + E.Message);
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
			if (i != 0 && valid != L"��")
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
		dlg_CsvOutput->DefaultExt = L".csv";
		dlg_CsvOutput->Filter = L"CSV�t�@�C�� (*.csv)|*.csv";
		dlg_CsvOutput->Title = L"�o�͐���w�肵�Ă��������B";
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
			UnicodeString id = this->grd_Address->Cells[0][i];
			UnicodeString name = this->grd_Address->Cells[1][i];
			UnicodeString address = this->grd_Address->Cells[2][i];
			UnicodeString memo = this->grd_Address->Cells[3][i];
			UnicodeString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//�y�`�F�b�N�z
			//==================================================
			if (valid != L"��")
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
				crp_practice4->Item("", "lbl_Title")->Text = L"�ۑ�S";

				//�y�w�b�_�zID
				crp_practice4->Item("", "lbl_Header_Id")->Text = L"ID";

				//�y�w�b�_�z���O
				crp_practice4->Item("", "lbl_Header_Name")->Text = L"���O";

				//�y�w�b�_�z�Z��
				crp_practice4->Item("", "lbl_Header_Address")->Text = L"�Z��";

				//�y�w�b�_�z����
				crp_practice4->Item("", "lbl_Header_Memo")->Text = L"����";

				// �y�[�W��
				crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + L"�^" + IntToStr(pageAll);

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
		crp_practice4->Item("", "lbl_Title")->Text = L"�ۑ�S";

		//�y�w�b�_�zID
		crp_practice4->Item("", "lbl_Header_Id")->Text = L"ID";

		//�y�w�b�_�z���O
		crp_practice4->Item("", "lbl_Header_Name")->Text = L"���O";

		//�y�w�b�_�z�Z��
		crp_practice4->Item("", "lbl_Header_Address")->Text = L"�Z��";

		//�y�w�b�_�z����
		crp_practice4->Item("", "lbl_Header_Memo")->Text = L"����";

		// �y�[�W��
		crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + L"�^" + IntToStr(pageAll);

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
