object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 
    'HW08_Performance Evaluation for Sorting Algorithms by Y.L Yen 20' +
    '22/06/18 Final'
  ClientHeight = 478
  ClientWidth = 812
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
    Width = 154
    Height = 13
    Caption = 'Input--------------------------------'
  end
  object Label2: TLabel
    Left = 29
    Top = 30
    Width = 17
    Height = 13
    Caption = 'n ='
  end
  object Label4: TLabel
    Left = 27
    Top = 69
    Width = 42
    Height = 13
    Caption = 'Range ='
  end
  object Label5: TLabel
    Left = 8
    Top = 136
    Width = 154
    Height = 13
    Caption = 'Sorting------------------------------'
  end
  object Label3: TLabel
    Left = 27
    Top = 112
    Width = 38
    Height = 13
    Caption = 'Times ='
  end
  object Edit1: TEdit
    Left = 75
    Top = 27
    Width = 70
    Height = 21
    TabOrder = 0
    Text = '10'
  end
  object Edit2: TEdit
    Left = 75
    Top = 66
    Width = 70
    Height = 21
    TabOrder = 1
    Text = '100'
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 155
    Width = 97
    Height = 17
    Caption = '1 Selection Sort'
    TabOrder = 2
  end
  object CheckBox2: TCheckBox
    Left = 8
    Top = 178
    Width = 97
    Height = 17
    Caption = '2 Insertion Sort'
    TabOrder = 3
  end
  object CheckBox3: TCheckBox
    Left = 8
    Top = 201
    Width = 97
    Height = 17
    Caption = '3 Bubble Sort'
    TabOrder = 4
  end
  object CheckBox4: TCheckBox
    Left = 8
    Top = 224
    Width = 137
    Height = 17
    Caption = '4 Quick Sort (Recursive)'
    TabOrder = 5
  end
  object CheckBox5: TCheckBox
    Left = 8
    Top = 247
    Width = 153
    Height = 17
    Caption = '5 Quick Sort (Non-recursive)'
    TabOrder = 6
  end
  object CheckBox6: TCheckBox
    Left = 8
    Top = 270
    Width = 153
    Height = 17
    Caption = '6 Merge Sort (Recursive)'
    TabOrder = 7
  end
  object CheckBox7: TCheckBox
    Left = 8
    Top = 293
    Width = 169
    Height = 17
    Caption = '7 Merge Sort (Non-recursive)'
    TabOrder = 8
  end
  object CheckBox8: TCheckBox
    Left = 8
    Top = 316
    Width = 97
    Height = 17
    Caption = '8 Heap Sort'
    TabOrder = 9
  end
  object Button1: TButton
    Left = 8
    Top = 355
    Width = 154
    Height = 38
    Caption = 'Sort!'
    TabOrder = 10
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 75
    Top = 109
    Width = 70
    Height = 21
    TabOrder = 11
    Text = '5'
  end
  object PageControl1: TPageControl
    Left = 183
    Top = 8
    Width = 613
    Height = 462
    ActivePage = TabSheet1
    TabOrder = 12
    object TabSheet1: TTabSheet
      Caption = 'Results'
      object Memo1: TMemo
        Left = -4
        Top = -5
        Width = 621
        Height = 438
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
  end
  object CheckBox9: TCheckBox
    Left = 8
    Top = 416
    Width = 97
    Height = 17
    Caption = 'See Data'
    TabOrder = 13
  end
end
