object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'DS_Bonus03_Infix2Postfix/Prefix by Y.L.Yen 20220428 ver final'
  ClientHeight = 400
  ClientWidth = 686
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 8
    Width = 678
    Height = 185
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Infix'
      object Label1: TLabel
        Left = 80
        Top = 88
        Width = 82
        Height = 13
        Caption = 'PLZ Enter a infix:'
      end
      object Label2: TLabel
        Left = 24
        Top = 29
        Width = 163
        Height = 13
        Caption = 'Operator:'#65371'+, -, *, /, ^, |, (, )'#65373
      end
      object Label3: TLabel
        Left = 24
        Top = 48
        Width = 294
        Height = 13
        Caption = 'Operand: Each of them reperesents by one English character'
      end
      object Edit1: TEdit
        Left = 176
        Top = 85
        Width = 121
        Height = 21
        TabOrder = 0
        Text = 'A-B*C'
      end
      object Button1: TButton
        Left = 376
        Top = 84
        Width = 75
        Height = 25
        Caption = '2Postfix'
        TabOrder = 1
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 376
        Top = 115
        Width = 75
        Height = 25
        Caption = '2Prefix'
        TabOrder = 2
        OnClick = Button2Click
      end
      object Edit2: TEdit
        Left = 472
        Top = 85
        Width = 121
        Height = 21
        TabOrder = 3
      end
      object Edit3: TEdit
        Left = 472
        Top = 115
        Width = 121
        Height = 21
        TabOrder = 4
      end
      object CheckBox1: TCheckBox
        Left = 80
        Top = 128
        Width = 97
        Height = 17
        Caption = 'Tracing '
        TabOrder = 5
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Prefix'
      ImageIndex = 1
      object Label6: TLabel
        Left = 24
        Top = 29
        Width = 166
        Height = 13
        Caption = 'Operator:'#65371'+, -, *, /, ^,  |, (, )'#65373
      end
      object Label7: TLabel
        Left = 24
        Top = 48
        Width = 294
        Height = 13
        Caption = 'Operand: Each of them reperesents by one English character'
      end
      object Label8: TLabel
        Left = 88
        Top = 96
        Width = 90
        Height = 13
        Caption = 'PLZ Enter a Prefix:'
      end
      object Button3: TButton
        Left = 384
        Top = 91
        Width = 75
        Height = 25
        Caption = '2Postfix'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 384
        Top = 132
        Width = 75
        Height = 25
        Caption = '2Infix'
        TabOrder = 1
        OnClick = Button4Click
      end
      object Edit4: TEdit
        Left = 197
        Top = 93
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '-A*BC'
      end
      object Edit5: TEdit
        Left = 480
        Top = 93
        Width = 121
        Height = 21
        TabOrder = 3
      end
      object Edit6: TEdit
        Left = 480
        Top = 133
        Width = 121
        Height = 21
        TabOrder = 4
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Postfix'
      ImageIndex = 2
      object Label4: TLabel
        Left = 24
        Top = 21
        Width = 163
        Height = 13
        Caption = 'Operator:'#65371'+, -, *, /, ^, |, (, )'#65373
      end
      object Label5: TLabel
        Left = 24
        Top = 40
        Width = 294
        Height = 13
        Caption = 'Operand: Each of them reperesents by one English character'
      end
      object Label9: TLabel
        Left = 92
        Top = 96
        Width = 95
        Height = 13
        Caption = 'PLZ Enter a Postfix:'
      end
      object Button5: TButton
        Left = 360
        Top = 92
        Width = 75
        Height = 25
        Caption = '2Prefix'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 360
        Top = 129
        Width = 75
        Height = 25
        Caption = '2Infix'
        TabOrder = 1
        OnClick = Button6Click
      end
      object Edit7: TEdit
        Left = 197
        Top = 93
        Width = 121
        Height = 21
        TabOrder = 2
        Text = 'ABC*-'
      end
      object Edit8: TEdit
        Left = 464
        Top = 93
        Width = 121
        Height = 21
        TabOrder = 3
      end
      object Edit9: TEdit
        Left = 464
        Top = 133
        Width = 121
        Height = 21
        TabOrder = 4
      end
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 195
    Width = 678
    Height = 197
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
end
