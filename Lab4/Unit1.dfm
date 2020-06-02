object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 231
  ClientWidth = 505
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 17
    Top = 67
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label2: TLabel
    Left = 16
    Top = 96
    Width = 6
    Height = 13
    Caption = 'B'
  end
  object Label3: TLabel
    Left = 16
    Top = 120
    Width = 7
    Height = 13
    Caption = 'C'
  end
  object Label4: TLabel
    Left = 16
    Top = 144
    Width = 7
    Height = 13
    Caption = 'D'
  end
  object Label5: TLabel
    Left = 17
    Top = 170
    Width = 6
    Height = 13
    Caption = 'E'
  end
  object Expression: TEdit
    Left = 255
    Top = 29
    Width = 225
    Height = 21
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    TextHint = 'Expression'
  end
  object Res: TEdit
    Left = 255
    Top = 162
    Width = 225
    Height = 21
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
    TextHint = 'Result'
  end
  object Button1: TButton
    Left = 320
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Convert'
    TabOrder = 6
    OnClick = Button1Click
  end
  object A: TEdit
    Left = 41
    Top = 64
    Width = 81
    Height = 21
    TabOrder = 1
  end
  object B: TEdit
    Left = 41
    Top = 91
    Width = 82
    Height = 21
    TabOrder = 2
  end
  object C: TEdit
    Left = 41
    Top = 118
    Width = 81
    Height = 21
    TabOrder = 3
  end
  object D: TEdit
    Left = 41
    Top = 145
    Width = 81
    Height = 21
    TabOrder = 4
  end
  object E: TEdit
    Left = 41
    Top = 172
    Width = 81
    Height = 21
    TabOrder = 5
  end
  object PolNot: TEdit
    Left = 255
    Top = 104
    Width = 225
    Height = 21
    ParentShowHint = False
    ShowHint = True
    TabOrder = 8
    TextHint = 'Polish notation'
  end
  object Data: TButton
    Left = 16
    Top = 16
    Width = 130
    Height = 25
    Caption = #1044#1072#1085#1085#1099#1077
    TabOrder = 9
    OnClick = DataClick
  end
  object Button2: TButton
    Left = 320
    Top = 131
    Width = 75
    Height = 25
    Caption = '='
    TabOrder = 10
    OnClick = Button2Click
  end
end
