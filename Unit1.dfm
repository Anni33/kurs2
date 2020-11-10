object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 514
  ClientWidth = 742
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 18
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 18
    Top = 35
    Width = 55
    Height = 25
    Caption = 'add'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 35
    Width = 51
    Height = 25
    Caption = 'delete'
    TabOrder = 2
  end
  object Button3: TButton
    Left = 192
    Top = 6
    Width = 75
    Height = 25
    Caption = 'MaxLevel'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 192
    Top = 37
    Width = 75
    Height = 21
    TabOrder = 4
  end
  object Button4: TButton
    Left = 288
    Top = 6
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 5
  end
end
