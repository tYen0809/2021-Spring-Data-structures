object Form1: TForm1
  Left = 366
  Top = 0
  Caption = 'Selection vs. Bubble vs. Quick sorts by Y.L Yen ver 1.0 20220302'
  ClientHeight = 463
  ClientWidth = 923
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 49
    Top = 32
    Width = 17
    Height = 13
    Caption = 'n ='
  end
  object Label2: TLabel
    Left = 24
    Top = 67
    Width = 42
    Height = 13
    Caption = 'Range ='
  end
  object Label3: TLabel
    Left = 711
    Top = 67
    Width = 83
    Height = 13
    Caption = 'Target Number ='
  end
  object Button1: TButton
    Left = 24
    Top = 104
    Width = 145
    Height = 33
    Caption = 'Generate Random number'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 72
    Top = 29
    Width = 73
    Height = 21
    TabOrder = 1
    Text = '10'
  end
  object Memo1: TMemo
    Left = 24
    Top = 143
    Width = 145
    Height = 297
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 72
    Top = 64
    Width = 73
    Height = 21
    TabOrder = 3
    Text = '1000'
  end
  object Button2: TButton
    Left = 193
    Top = 104
    Width = 144
    Height = 33
    Caption = 'Selection Sort'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Memo2: TMemo
    Left = 193
    Top = 143
    Width = 144
    Height = 297
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 216
    Top = 31
    Width = 97
    Height = 17
    Caption = 'Echo Print'
    TabOrder = 6
  end
  object CheckBox2: TCheckBox
    Left = 216
    Top = 66
    Width = 97
    Height = 17
    Caption = 'Self-Check'
    TabOrder = 7
  end
  object Button3: TButton
    Left = 343
    Top = 104
    Width = 144
    Height = 33
    Caption = 'Bubble Sort '
    TabOrder = 8
    OnClick = Button3Click
  end
  object Memo3: TMemo
    Left = 343
    Top = 143
    Width = 144
    Height = 297
    Lines.Strings = (
      'Memo3')
    TabOrder = 9
  end
  object Button4: TButton
    Left = 493
    Top = 104
    Width = 144
    Height = 33
    Caption = 'Quick Sort'
    TabOrder = 10
    OnClick = Button4Click
  end
  object Memo4: TMemo
    Left = 493
    Top = 143
    Width = 144
    Height = 297
    Lines.Strings = (
      'Memo4')
    TabOrder = 11
  end
  object Button5: TButton
    Left = 712
    Top = 104
    Width = 145
    Height = 33
    Caption = 'Binary Search'
    TabOrder = 12
    OnClick = Button5Click
  end
  object Memo5: TMemo
    Left = 712
    Top = 143
    Width = 145
    Height = 297
    Lines.Strings = (
      'Memo5')
    TabOrder = 13
  end
  object Edit3: TEdit
    Left = 800
    Top = 64
    Width = 73
    Height = 21
    TabOrder = 14
    Text = '300'
  end
end
