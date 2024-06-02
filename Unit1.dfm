object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1055#1086#1080#1089#1082' '#1082#1083#1072#1089#1090#1077#1088#1086#1074' '#1087#1086' '#1079#1072#1076#1072#1085#1085#1086#1084#1091' '#1082#1088#1080#1090#1077#1088#1080#1102
  ClientHeight = 637
  ClientWidth = 495
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDefault
  TextHeight = 15
  object Label1: TLabel
    Left = 15
    Top = 88
    Width = 265
    Height = 15
    AutoSize = False
    Caption = #1048#1085#1090#1077#1088#1077#1089#1091#1077#1084#1086#1077' '#1088#1072#1089#1096#1080#1088#1077#1085#1080#1077' '#1092#1072#1081#1083#1072':'
    EllipsisPosition = epPathEllipsis
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 15
    Top = 13
    Width = 265
    Height = 15
    AutoSize = False
    Caption = #1052#1077#1090#1082#1072' '#1080#1079#1091#1095#1072#1077#1084#1086#1075#1086' '#1090#1086#1084#1072':'
    EllipsisPosition = epPathEllipsis
  end
  object Label3: TLabel
    Left = 16
    Top = 581
    Width = 145
    Height = 17
    Caption = #1058#1080#1087' '#1092#1072#1081#1083#1086#1074#1086#1081' '#1089#1080#1089#1090#1077#1084#1099': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 520
    Width = 221
    Height = 17
    Caption = #1042#1089#1077#1075#1086' '#1089#1077#1082#1090#1086#1088#1086#1074' '#1074' '#1092#1072#1081#1083#1086#1074#1086#1081' '#1089#1080#1089#1090#1077#1084#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object fsClusterNum: TLabel
    Left = 243
    Top = 520
    Width = 62
    Height = 17
    Caption = 'Undefined'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object fsType: TLabel
    Left = 169
    Top = 582
    Width = 62
    Height = 17
    Caption = 'Undefined'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 17
    Top = 551
    Width = 159
    Height = 17
    Caption = #1056#1072#1079#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072' '#1074' '#1073#1072#1081#1090#1072#1093':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object fsClusterSize: TLabel
    Left = 188
    Top = 550
    Width = 62
    Height = 17
    Caption = 'Undefined'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 17
    Top = 612
    Width = 153
    Height = 17
    Caption = #1042#1088#1077#1084#1103' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' ('#1089#1077#1082'): '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object execTime: TLabel
    Left = 172
    Top = 612
    Width = 62
    Height = 17
    Caption = 'Undefined'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object startButton: TButton
    Left = 336
    Top = 13
    Width = 137
    Height = 119
    Caption = #1053#1072#1095#1072#1090#1100' '#1087#1086#1080#1089#1082
    TabOrder = 0
    OnClick = startButtonClick
  end
  object resultStringTree: TVirtualStringTree
    Left = 13
    Top = 186
    Width = 460
    Height = 312
    DefaultNodeHeight = 19
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 1
    TreeOptions.PaintOptions = [toShowButtons, toShowDropmark, toShowHorzGridLines, toShowRoot, toShowTreeLines, toShowVertGridLines, toThemeAware, toUseBlendedImages, toFullVertGridLines]
    OnGetText = resultStringTreeGetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 0
        Text = #1053#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072
        Width = 109
      end
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 1
        Text = #1055#1077#1088#1074#1099#1077' 16 '#1073#1072#1081#1090' '#1082#1083#1072#1089#1090#1077#1088#1072
        Width = 188
      end>
  end
  object progressBar: TProgressBar
    Left = 13
    Top = 155
    Width = 460
    Height = 17
    TabOrder = 2
  end
  object volumeEdit: TEdit
    Left = 16
    Top = 35
    Width = 305
    Height = 23
    TabOrder = 3
    Text = '\\.\C:'
  end
  object searchFileType: TComboBox
    Left = 15
    Top = 109
    Width = 305
    Height = 23
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 4
    Text = 'exe'
    Items.Strings = (
      'exe'
      'pdf'
      'jpeg')
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 448
    Top = 584
  end
end
