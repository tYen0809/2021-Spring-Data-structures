object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Magic Square by Y.L Yen 03/14/2022 Ver 0.3'
  ClientHeight = 428
  ClientWidth = 769
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
    Left = 8
    Top = 8
    Width = 93
    Height = 13
    Caption = #39764#34899#26041#38499#37002#38263'(n): '
  end
  object Label2: TLabel
    Left = 82
    Top = 39
    Width = 122
    Height = 13
    Caption = '('#31684#22285#38480#21046':  3<=n<=25)'
  end
  object Edit1: TEdit
    Left = 8
    Top = 36
    Width = 57
    Height = 21
    TabOrder = 0
    Text = '3'
  end
  object Button1: TButton
    Left = 256
    Top = 18
    Width = 89
    Height = 33
    Caption = #22855#25976
    TabOrder = 1
    OnClick = Button1Click
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 134
    Width = 753
    Height = 274
    ActivePage = TabSheet2
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = #30452#25509#32080#26524
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 520
        Height = 457
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = #22266#23450#27396#23532
      ImageIndex = 1
      object Memo2: TMemo
        Left = 3
        Top = 3
        Width = 517
        Height = 457
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'StringGrid'
      ImageIndex = 3
      object StringGrid1: TStringGrid
        Left = -4
        Top = 0
        Width = 725
        Height = 457
        TabOrder = 0
      end
    end
  end
  object Button3: TButton
    Left = 256
    Top = 72
    Width = 89
    Height = 33
    Caption = '4'#30340#20493#25976
    TabOrder = 3
    OnClick = Button3Click
  end
  object GroupBox2: TGroupBox
    Left = 426
    Top = 8
    Width = 208
    Height = 97
    Caption = '1'#30340#20301#32622'('#22855#25976')'
    TabOrder = 4
    object RadioButton5: TRadioButton
      Left = 82
      Top = 18
      Width = 113
      Height = 17
      Caption = #19978
      TabOrder = 0
    end
    object RadioButton6: TRadioButton
      Left = 3
      Top = 41
      Width = 113
      Height = 17
      Caption = #24038
      TabOrder = 1
    end
    object RadioButton7: TRadioButton
      Left = 163
      Top = 41
      Width = 113
      Height = 17
      Caption = #21491
      TabOrder = 2
    end
    object RadioButton8: TRadioButton
      Left = 79
      Top = 72
      Width = 113
      Height = 17
      Caption = #19979
      TabOrder = 3
    end
    object Button4: TButton
      Left = 65
      Top = 41
      Width = 75
      Height = 25
      Caption = #22519#34892'!'
      TabOrder = 4
      OnClick = Button4Click
    end
  end
end
