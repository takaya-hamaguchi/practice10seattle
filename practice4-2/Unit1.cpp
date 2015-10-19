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
//【イベント処理】
//**************************************************
//---------------------------------------------------------------------------
/**
 * フォームロード
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// メソッド内変数宣言
	TGridRect selection;

	try
	{
		//**************************************************
		//【初期化】
		//  変数
		//**************************************************
		selection.Left = -1;
		selection.Top = -1;
		selection.Right = -1;
		selection.Bottom = -1;

		//**************************************************
		//【初期化】
		//  コントロール
		//**************************************************
		// 住所リスト
		this->grd_Address->RowCount = 1;
		this->grd_Address->RowHeights[0] = 24;
		this->grd_Address->FixedRows = 0;

		// 住所リスト（ヘッダ）
		this->grd_Address->Cells[0][0] = "ID";
		this->grd_Address->ColWidths[0] = 50;

		this->grd_Address->Cells[1][0] = "名前";
		this->grd_Address->ColWidths[1] = 100;

		this->grd_Address->Cells[2][0] = "住所";
		this->grd_Address->ColWidths[2] = 174;

		this->grd_Address->Cells[3][0] = "メモ";
		this->grd_Address->ColWidths[3] = 150;

		this->grd_Address->Cells[4][0] = "有効";
		this->grd_Address->ColWidths[4] = 45;

		// 住所リスト（選択状態）
		this->grd_Address->Selection = selection;

		//**************************************************
		//【住所リスト表示】
		//**************************************************
		ShowAddress();
	}
	catch (int e)
	{
		ShowMessage("初期表示中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
/**
 * 閉じるボタン押下
 * @param TObject *Sender 呼び出し元オブジェクト
 * @return void
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
 * CSV出力ボタン押下
 * @param TObject *Sender 呼び出し元オブジェクト
 * @return void
 */
void __fastcall TForm1::btn_CsvOutputClick(TObject *Sender)
{
	// メソッド内変数宣言

	try
	{
		//**************************************************
		//【チェック】
		//**************************************************
        //
		// データ
		//
		if (this->grd_Address->Row == 0)
		{
			// なし
			ShowMessage("CSV出力するデータがありません。");
			return;
		}

		//**************************************************
		//【CSV出力処理】
		//**************************************************
        CsvOutput();
	}
	catch (int e)
	{
		ShowMessage("CSV出力中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
 /**
 * プレビューボタン押下
 * @param TObject *Sender 呼び出し元オブジェクト
 * @return void
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// メソッド内変数宣言

	try
	{
        //**************************************************
		//【チェック】
		//**************************************************
        //
		// データ
		//
		if (this->grd_Address->Row == 0)
		{
			// なし
			ShowMessage("プレビューするデータがありません。");
			return;
		}

		//**************************************************
		//【プレビュー処理】
		//**************************************************
        Preview();
	}
	catch (int e)
	{
		ShowMessage("プレビュー中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
 /**
 * 住所リスト描画
 * @param TObject *Sender 呼び出し元オブジェクト
 * @param int ACol 描画する列位置
 * @param int ARow 描画する行位置
 * @param TRect &Rect 描画するセル座標
 * @param TGridDrawState State
 * @return void
 */
void __fastcall TForm1::grd_AddressDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
//	// メソッド内変数宣言
//    AnsiString value;
//	unsigned int pos;
//	RECT r = RECT(Rect);
//
//	//**************************************************
//	//【ヘッダ】
//	//**************************************************
//	if (ARow == 0)
//	{
//		pos = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
//	}
//	//**************************************************
//	//【通常行】
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
//			// 名前
//			case 1:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// 住所
//			case 2:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// メモ
//			case 3:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// 有効
//			case 4:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
//				break;
//		}
//	}
//
//	// セル値取得
//	value = grd_Address->Cells[ACol][ARow];
//
//	// クリア
//	grd_Address->Canvas->FillRect(Rect);
//
//	// フォーカス枠の描画
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
////	// テキスト表示領域の設定
////	InflateRect(
////		&r,
////		-2,
////		-2
////	);
//
//	// セル再描画
//	DrawText(
//		grd_Address->Canvas->Handle,
//		value.c_str(),
//		value.Length(),
//		&Rect,
//		pos
//	);
	AnsiString value = grd_Address->Cells[ACol][ARow];
	unsigned int position = DT_VCENTER|DT_CENTER|DT_SINGLELINE;

	// セルの背景色を変更する
	if (ARow == 0)
	{
		grd_Address->Canvas->Brush->Color = clBtnFace;
	}
	else
	{
		grd_Address->Canvas->Brush->Color = clWhite;
	}

	// 背景色で塗りつぶす
	grd_Address->Canvas->FillRect(Rect);

	// セルの中の文字列を再度、Canvasに描画する。
	// フォントカラーを書き直す
	// 背景色を書き直す
	grd_Address->Canvas->Font->Color=grd_Address->Font->Color;

	// 位置
	if (ARow == 0)
	{
		// ヘッダ
		position = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
	}
	else if (ARow > 0)
	{
		// 通常行
		switch (ACol)
		{
			// ID
			case 0:
				position = DT_SINGLELINE | DT_VCENTER | DT_RIGHT;
				break;

			// 名前
			case 1:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// 住所
			case 2:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// メモ
			case 3:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// 有効
			case 4:
				position = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
				break;
		}
	}

	// 再描画
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
//【ユーザー定義関数】
//**************************************************
/**
 * 住所リスト表示
 * @param
 * @return void
 */
void __fastcall TForm1::ShowAddress()
{
	// メソッド内変数宣言
	String path;
	String sql;
	String fatalMsg;

	try
	{
		//**************************************************
		//【初期化】
		//**************************************************
		path = GetCurrentDir() + "\\practice4.sqlite3";
		//path = StringReplace(path, "\\", "/", TReplaceFlags() << rfReplaceAll);
		sql = "";
		fatalMsg = "";

		// ＤＢ接続オブジェクト
		dbCon->Params->Clear();
		dbCon->Params->Add("DriverName=Sqlite");
		dbCon->Params->Add("Database=" + path);
		ShowMessage(dbCon->Params->GetText());

		//**************************************************
		//【ＤＢ接続】
		//**************************************************
		fatalMsg = "ＤＢ接続中に異常が発生しました。";

		// ＤＢ接続
		dbCon->Connected = true;

//		// クエリ設定
//		dbSql->SQLConnection = dbCon;

		//**************************************************
		//【ＳＱＬ生成】
		//**************************************************
		fatalMsg = "ＤＢ接続中に異常が発生しました。";

		// ＳＱＬ生成
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
		//【ＳＱＬ実行】
		//**************************************************
		fatalMsg = "ＳＱＬ実行中に異常が発生しました。";

		if (!dbSql->IsEmpty())
		{
			TStringList* columnNames = new TStringList;

			// 先頭レコードへ
			dbSql->First();

			__try
			{
				// 列名リスト取得
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

					// 次のレコードへ
					dbSql->Next();
				}
			}
			__finally
			{
				columnNames->Free();
			}
		}

		// オブジェクト解放
		dbSql->Close();
		dbSql->Active=false;

		//**************************************************
		//【ＤＢ切断】
		//**************************************************
		dbCon->Connected = false;
	}
	/*
	catch (EDatabaseError& E)
	{
		ShowMessage(fatalMsg + "\r\nエラーメッセージ：" + E.Message);
	}
	catch (EExternalException& E)
	{
		ShowMessage(fatalMsg + "\r\nエラーメッセージ：" + E.Message);
	}
	*/
	catch (Exception& E)
	{
		ShowMessage(fatalMsg + "\r\nエラーメッセージ：" + E.Message);
	}
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * CSV出力処理
 * @param
 * @return void
 */
void __fastcall TForm1::CsvOutput()
{
	// メソッド内変数宣言
	TStringList *output = new TStringList;

	try
	{
        //**************************************************
		//【CSV出力データ生成】
		//**************************************************
		for (int i = 0; i < this->grd_Address->RowCount; i++)
		{
			//==================================================
			//【出力データ抽出】
			//==================================================
			AnsiString id = this->grd_Address->Cells[0][i];
			AnsiString name = this->grd_Address->Cells[1][i];
			AnsiString address = this->grd_Address->Cells[2][i];
			AnsiString memo = this->grd_Address->Cells[3][i];
			AnsiString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//【チェック】
			//==================================================
			if (i != 0 && valid != "○")
			{
				continue;
			}

			//==================================================
			//【出力レコード生成】
			//==================================================
			TStringList *record = new TStringList;
			record->Add(id);
			record->Add(name);
			record->Add(address);
			record->Add(memo);

			//==================================================
			//【出力データ設定】
			//==================================================
			output->Add(record->CommaText);
		}

		//**************************************************
		//【CSV出力】
		//**************************************************
		// ダイアログ設定
		dlg_CsvOutput->DefaultExt = ".csv";
		dlg_CsvOutput->Filter = "CSVファイル (*.csv)|*.csv";
		dlg_CsvOutput->Title = "出力先を指定してください。";
		dlg_CsvOutput->Options << ofOverwritePrompt << ofCreatePrompt;

		// ダイアログ表示
		if (dlg_CsvOutput->Execute())
		{
			// 出力
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
 * プレビュー処理
 * @param
 * @return void
 */
void __fastcall TForm1::Preview()
{
	// メソッド内変数宣言
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
        //**************************************************
		//【レポート設定】
		//**************************************************
		crp_practice4->ReportPath = "practice4.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;

        //**************************************************
		//【印刷ジョブ開始】
		//**************************************************
		if (crp_practice4->OpenPrintJob(
				"",     //印刷ジョブ名
				prtOpt,	//オプション設定
				true,	//印刷プレビューの表示
				"",     //印刷プレビュー画面のタイトル
				NULL    //プレビューを表示するウインドウ
			)  == false)
		{
			// 印刷ジョブ開始失敗
			crp_practice4->ReportPath = "";
			ShowMessage("印刷ジョブの開始中に異常が発生しました。");
			return;
		}

        //**************************************************
		//【印刷データ設定】
		//  住所リスト
		//**************************************************
		int record = 0;
		int page = 1;
		int pageAll = (this->grd_Address->RowCount / 15) + 1;

		for (int i = 1; i < this->grd_Address->RowCount; i++)
		{
			//==================================================
			//【印刷データ抽出】
			//==================================================
			AnsiString id = this->grd_Address->Cells[0][i];
			AnsiString name = this->grd_Address->Cells[1][i];
			AnsiString address = this->grd_Address->Cells[2][i];
			AnsiString memo = this->grd_Address->Cells[3][i];
			AnsiString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//【チェック】
			//==================================================
			if (valid != "○")
			{
				continue;
			}

			//==================================================
			//【改ページ処理】
			//==================================================
			if (record >= 15)
			{
				crp_practice4->ClearAllText();
				record = 0;
				page++;
			}

			record++;

            //==================================================
			//【印刷データ設定】
			//==================================================
			// ID
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Id")->Text = id;

			// 名前
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Name")->Text = name;

			// 住所
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Address")->Text = name;

			// メモ
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Memo")->Text = name;

			//==================================================
			//【印刷（プレビュー）】
			//==================================================
			if (record >= 15)
			{
				// タイトル
				crp_practice4->Item("", "lbl_Title")->Text = "課題４";

				//【ヘッダ】ID
				crp_practice4->Item("", "lbl_Header_Id")->Text = "ID";

				//【ヘッダ】名前
				crp_practice4->Item("", "lbl_Header_Name")->Text = "名前";

				//【ヘッダ】住所
				crp_practice4->Item("", "lbl_Header_Address")->Text = "住所";

				//【ヘッダ】メモ
				crp_practice4->Item("", "lbl_Header_Memo")->Text = "メモ";

				// ページ数
				crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + "／" + IntToStr(pageAll);

				// 印刷（プレビュー）
				crp_practice4->PrintReport();
			}
		}

		//**************************************************
		//【印刷データ設定】
		//  空行
		//**************************************************
		while (record < 15)
		{
			record++;

			//==================================================
			//【空行非表示】
			//==================================================
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Id")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Name")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Address")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Memo")->Visible = false;
		}

		// タイトル
		crp_practice4->Item("", "lbl_Title")->Text = "課題４";

		//【ヘッダ】ID
		crp_practice4->Item("", "lbl_Header_Id")->Text = "ID";

		//【ヘッダ】名前
		crp_practice4->Item("", "lbl_Header_Name")->Text = "名前";

		//【ヘッダ】住所
		crp_practice4->Item("", "lbl_Header_Address")->Text = "住所";

		//【ヘッダ】メモ
		crp_practice4->Item("", "lbl_Header_Memo")->Text = "メモ";

		// ページ数
		crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + "／" + IntToStr(pageAll);

        //**************************************************
		//【印刷（プレビュー）】
		//  空行
		//**************************************************
		crp_practice4->PrintReport();

        //**************************************************
		//【印刷ジョブ終了】
		//**************************************************
		crp_practice4->ClosePrintJob(true);

		//**************************************************
		//【レポートクローズ】
		//**************************************************
		crp_practice4->ReportPath = "";
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------

