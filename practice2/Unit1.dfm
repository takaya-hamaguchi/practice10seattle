object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #35506#38988#65298
  ClientHeight = 302
  ClientWidth = 404
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lbl_Title: TLabel
    Left = 0
    Top = 0
    Width = 405
    Height = 30
    Alignment = taCenter
    AutoSize = False
    Caption = #35506#38988#65298
    Color = 16744448
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object lbl_Name: TLabel
    Left = 30
    Top = 50
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #21517#21069#65306
  end
  object lbl_Address: TLabel
    Left = 30
    Top = 90
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #20303#25152#65306
  end
  object lbl_Memo: TLabel
    Left = 30
    Top = 130
    Width = 50
    Height = 20
    AutoSize = False
    Caption = #12513#12514#65306
  end
  object txt_Name: TEdit
    Left = 75
    Top = 47
    Width = 150
    Height = 21
    TabOrder = 0
  end
  object txt_Address: TEdit
    Left = 75
    Top = 87
    Width = 150
    Height = 21
    TabOrder = 1
  end
  object btn_End: TButton
    Left = 275
    Top = 250
    Width = 100
    Height = 30
    Caption = #32066#20102
    TabOrder = 4
    OnClick = btn_EndClick
  end
  object btn_Preview: TButton
    Left = 150
    Top = 250
    Width = 100
    Height = 30
    Caption = #12503#12524#12499#12517#12540
    TabOrder = 3
    OnClick = btn_PreviewClick
  end
  object txt_Memo: TMemo
    Left = 75
    Top = 127
    Width = 300
    Height = 100
    TabOrder = 2
  end
  object crp_Practice2: TCrpReport
    Copies = 1
    Top = 272
  end
end
