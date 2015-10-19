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
#include <Data.FMTBcd.hpp>
#include <Data.DbxSqlite.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TLabel *lbl_Title;
	TShape *shp_Title;
	TButton *btn_Preview;
	TShape *Shape2;
	TButton *btn_End;
	TButton *btn_CsvOutput;
	TCrpReport *crp_practice4;
	TStringGrid *grd_Address;
	TSaveDialog *dlg_CsvOutput;
	TFDConnection *dbCon;
	TFDPhysSQLiteDriverLink *dbDrv;
	TFDQuery *dbQuery;
	void __fastcall btn_EndClick(TObject *Sender);
	void __fastcall btn_CsvOutputClick(TObject *Sender);
	void __fastcall btn_PreviewClick(TObject *Sender);
	void __fastcall grd_AddressDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:	// ���[�U�[�錾
	void __fastcall ShowAddress();
	void __fastcall CsvOutput();
	void __fastcall Preview();
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
