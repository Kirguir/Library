object Login: TLogin
  Left = 545
  Top = 284
  Width = 224
  Height = 219
  Caption = #1042#1093#1086#1076
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 98
    Width = 32
    Height = 19
    Caption = #1048#1084#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 16
    Top = 122
    Width = 53
    Height = 19
    Caption = #1055#1072#1088#1086#1083#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object RG: TRadioGroup
    Left = 16
    Top = 8
    Width = 185
    Height = 81
    ItemIndex = 0
    Items.Strings = (
      #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
      #1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088)
    TabOrder = 0
    OnClick = RGClick
  end
  object Pass: TMaskEdit
    Left = 80
    Top = 120
    Width = 121
    Height = 21
    PasswordChar = '*'
    TabOrder = 2
    Visible = False
  end
  object BitBtn1: TBitBtn
    Left = 72
    Top = 147
    Width = 75
    Height = 25
    TabOrder = 3
    OnClick = BitBtn1Click
    Kind = bkOK
  end
  object Name: TEdit
    Left = 80
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 1
    Visible = False
  end
end
