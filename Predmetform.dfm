object PredForm: TPredForm
  Left = 395
  Top = 176
  Width = 446
  Height = 675
  Caption = #1055#1088#1077#1076#1084#1077#1090
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object DBGridEh1: TDBGridEh
    Left = 0
    Top = 0
    Width = 438
    Height = 592
    Align = alClient
    DataSource = DM.dsoPred
    FooterColor = clWindow
    FooterFont.Charset = DEFAULT_CHARSET
    FooterFont.Color = clWindowText
    FooterFont.Height = -11
    FooterFont.Name = 'MS Sans Serif'
    FooterFont.Style = []
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    VertScrollBar.Tracking = True
    OnDblClick = DBGridEh1DblClick
    OnKeyDown = DBGridEh1KeyDown
    Columns = <
      item
        EditButtons = <>
        FieldName = 'N_PREDMET'
        Footers = <>
        Title.Caption = #1055#1056#1045#1044#1052#1045#1058
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 592
    Width = 438
    Height = 49
    Align = alBottom
    TabOrder = 1
    object Button1: TButton
      Left = 24
      Top = 8
      Width = 105
      Height = 33
      Caption = #1042#1099#1073#1088#1072#1090#1100
      Default = True
      TabOrder = 0
      Visible = False
      OnClick = DBGridEh1DblClick
    end
    object BitBtn1: TBitBtn
      Left = 312
      Top = 8
      Width = 105
      Height = 33
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 1
      Kind = bkClose
    end
  end
end
