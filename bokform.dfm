object BookForm: TBookForm
  Left = 306
  Top = 306
  BorderStyle = bsSingle
  Caption = #1050#1085#1080#1075#1080
  ClientHeight = 381
  ClientWidth = 596
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
    Width = 596
    Height = 225
    Align = alTop
    DataSource = DM.dsoBook
    FooterColor = clWindow
    FooterFont.Charset = DEFAULT_CHARSET
    FooterFont.Color = clWindowText
    FooterFont.Height = -11
    FooterFont.Name = 'MS Sans Serif'
    FooterFont.Style = []
    STFilter.Local = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = BitBtn2Click
    OnKeyDown = DBGridEh1KeyDown
    Columns = <
      item
        EditButtons = <>
        FieldName = 'F_AUTHOR'
        Footers = <>
        Title.Caption = #1060#1072#1084#1080#1083#1080#1103
      end
      item
        EditButtons = <>
        FieldName = 'N_AUTHOR'
        Footers = <>
        Title.Caption = #1048
        Width = 14
      end
      item
        EditButtons = <>
        FieldName = 'T_AUTHOR'
        Footers = <>
        Title.Caption = #1054
        Width = 12
      end
      item
        EditButtons = <>
        FieldName = 'BOOKNAME'
        Footers = <>
        Title.Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1082#1085#1080#1075#1080
        Width = 314
      end
      item
        AutoDropDown = True
        DblClickNextVal = True
        EditButtons = <>
        FieldName = 'TYPEBOOK'
        Footers = <>
        KeyList.Strings = (
          '1'
          '2'
          '3'
          '4')
        PickList.Strings = (
          #1052#1077#1090#1086#1076#1080#1095#1085#1110' '#1074#1082#1072#1079#1110#1074#1082#1080
          #1053#1072#1074#1095#1072#1083#1100#1085#1080#1081' '#1087#1086#1089#1110#1073#1085#1080#1082
          #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1110' '#1088#1086#1073#1086#1090#1110
          #1069#1082#1079#1072#1084#1077#1085#1072#1094#1110#1081#1085#1110' '#1074#1086#1087#1088#1086#1089#1080)
        STFilter.Visible = False
        Title.Caption = #1058#1080#1087' '#1082#1085#1080#1075#1080
        Width = 125
      end>
  end
  object BitBtn1: TBitBtn
    Left = 504
    Top = 352
    Width = 83
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    Kind = bkClose
  end
  object BitBtn2: TBitBtn
    Left = 312
    Top = 352
    Width = 83
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 2
    Visible = False
    OnClick = BitBtn2Click
    Kind = bkYes
  end
  object BitBtn3: TBitBtn
    Left = 400
    Top = 352
    Width = 97
    Height = 25
    Caption = #1047#1072#1084#1077#1085#1080#1090#1100' '#1092#1072#1081#1083
    TabOrder = 3
    OnClick = BitBtn3Click
  end
  object FilterBox: TComboBox
    Left = 424
    Top = 232
    Width = 169
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 4
    Text = #1042#1089#1077
    OnChange = FilterEditChange
    Items.Strings = (
      #1042#1089#1077
      #1052#1077#1090#1086#1076#1080#1095#1085#1110' '#1074#1082#1072#1079#1110#1074#1082#1080
      #1053#1072#1074#1095#1072#1083#1100#1085#1080#1081' '#1087#1086#1089#1110#1073#1085#1080#1082
      #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1110' '#1088#1086#1073#1086#1090#1110
      #1069#1082#1079#1072#1084#1077#1085#1072#1094#1110#1081#1085#1110' '#1074#1086#1087#1088#1086#1089#1080)
  end
  object FilterEdit: TEdit
    Left = 5
    Top = 232
    Width = 132
    Height = 21
    TabOrder = 5
    OnChange = FilterEditChange
  end
  object DBMemo1: TDBMemo
    Left = 5
    Top = 256
    Width = 588
    Height = 89
    DataField = 'ABOUT'
    DataSource = DM.dsoBook
    TabOrder = 6
  end
end
