object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #35506#38988#65300
  ClientHeight = 412
  ClientWidth = 584
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object shp_Title: TShape
    Left = 0
    Top = 0
    Width = 584
    Height = 30
    Pen.Color = clGray
  end
  object lbl_Title: TLabel
    Left = 0
    Top = 0
    Width = 584
    Height = 29
    Alignment = taCenter
    AutoSize = False
    Caption = #35506#38988#65300
    Color = clFuchsia
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -16
    Font.Name = #65325#65331' '#26126#26397
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
    Layout = tlCenter
  end
  object Shape2: TShape
    Left = -1
    Top = 368
    Width = 586
    Height = 46
    Pen.Color = clGray
  end
  object btn_Preview: TButton
    Left = 445
    Top = 375
    Width = 120
    Height = 30
    Caption = #12503#12524#12499#12517#12540
    TabOrder = 0
    OnClick = btn_PreviewClick
  end
  object btn_End: TButton
    Left = 20
    Top = 375
    Width = 120
    Height = 30
    Caption = #32066#20102
    TabOrder = 1
    OnClick = btn_EndClick
  end
  object btn_CsvOutput: TButton
    Left = 300
    Top = 375
    Width = 120
    Height = 30
    Caption = 'CSV'#20986#21147
    TabOrder = 2
    OnClick = btn_CsvOutputClick
  end
  object grd_Address: TStringGrid
    Left = 21
    Top = 50
    Width = 544
    Height = 300
    Color = clBtnFace
    DefaultColWidth = 100
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    TabOrder = 3
    OnDrawCell = grd_AddressDrawCell
  end
  object crp_practice4: TCrpReport
    Copies = 2
  end
  object dlg_CsvOutput: TSaveDialog
    Left = 32
  end
end
