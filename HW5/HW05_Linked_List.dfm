object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Singly Linked List by Y.L Yen 2022/04/20 ver final'
  ClientHeight = 492
  ClientWidth = 736
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
    Left = 1
    Top = -4
    Width = 730
    Height = 249
    ActivePage = TabSheet4
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Singly Linked List'
      object Label1: TLabel
        Left = 16
        Top = 32
        Width = 42
        Height = 13
        Caption = 'Element:'
      end
      object Label2: TLabel
        Left = 16
        Top = 63
        Width = 39
        Height = 13
        Caption = 'Target: '
      end
      object Label3: TLabel
        Left = 16
        Top = 104
        Width = 13
        Height = 13
        Caption = 'n: '
      end
      object Label4: TLabel
        Left = 96
        Top = 104
        Width = 38
        Height = 13
        Caption = 'Range: '
      end
      object Edit1: TEdit
        Left = 72
        Top = 29
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Edit2: TEdit
        Left = 72
        Top = 60
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '20'
      end
      object Edit3: TEdit
        Left = 35
        Top = 101
        Width = 41
        Height = 21
        TabOrder = 2
        Text = '10'
      end
      object Edit4: TEdit
        Left = 140
        Top = 101
        Width = 77
        Height = 21
        TabOrder = 3
        Text = '1000'
      end
      object Button1: TButton
        Left = 240
        Top = 27
        Width = 89
        Height = 25
        Caption = 'Insert First'
        TabOrder = 4
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 335
        Top = 27
        Width = 90
        Height = 25
        Caption = 'Insert Last'
        TabOrder = 5
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 240
        Top = 58
        Width = 89
        Height = 25
        Caption = 'Search: Target'
        TabOrder = 6
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 335
        Top = 58
        Width = 114
        Height = 25
        Caption = 'Search: InsertAfter'
        TabOrder = 7
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 455
        Top = 58
        Width = 114
        Height = 25
        Caption = 'Search: InsertBefore'
        TabOrder = 8
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 575
        Top = 58
        Width = 90
        Height = 25
        Caption = 'Search: Delete'
        TabOrder = 9
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 240
        Top = 99
        Width = 137
        Height = 25
        Caption = 'Insert n random numbers'
        TabOrder = 10
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 576
        Top = 147
        Width = 89
        Height = 54
        Caption = 'Clear List'
        TabOrder = 11
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 16
        Top = 161
        Width = 137
        Height = 25
        Caption = '<--Reverse-->'
        TabOrder = 12
        OnClick = Button9Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Linked Stack'
      ImageIndex = 1
      object Label5: TLabel
        Left = 168
        Top = 64
        Width = 43
        Height = 13
        Caption = 'Target ='
      end
      object Label7: TLabel
        Left = 400
        Top = 149
        Width = 3
        Height = 13
        Color = clMaroon
        ParentColor = False
      end
      object Edit5: TEdit
        Left = 233
        Top = 61
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '123'
      end
      object Button10: TButton
        Left = 233
        Top = 97
        Width = 121
        Height = 25
        Caption = 'Push '
        TabOrder = 1
        OnClick = Button10Click
      end
      object Button11: TButton
        Left = 233
        Top = 144
        Width = 121
        Height = 25
        Caption = 'Pop'
        TabOrder = 2
        OnClick = Button11Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Linked Queue'
      ImageIndex = 2
      object Label6: TLabel
        Left = 168
        Top = 64
        Width = 43
        Height = 13
        Caption = 'Target ='
      end
      object Label8: TLabel
        Left = 384
        Top = 149
        Width = 3
        Height = 13
      end
      object Edit6: TEdit
        Left = 232
        Top = 61
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '456'
      end
      object Button12: TButton
        Left = 232
        Top = 99
        Width = 121
        Height = 25
        Caption = 'Insert'
        TabOrder = 1
        OnClick = Button12Click
      end
      object Button13: TButton
        Left = 232
        Top = 144
        Width = 121
        Height = 25
        Caption = 'Delete'
        TabOrder = 2
        OnClick = Button13Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = '(Bonus) Doubly Linked List'
      ImageIndex = 3
      object Label9: TLabel
        Left = 16
        Top = 35
        Width = 42
        Height = 13
        Caption = 'Element:'
      end
      object Label10: TLabel
        Left = 16
        Top = 62
        Width = 39
        Height = 13
        Caption = 'Target: '
      end
      object Edit7: TEdit
        Left = 72
        Top = 32
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Edit8: TEdit
        Left = 72
        Top = 59
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '20'
      end
      object Button14: TButton
        Left = 240
        Top = 30
        Width = 105
        Height = 25
        Caption = 'Insert first'
        TabOrder = 2
        OnClick = Button14Click
      end
      object Button15: TButton
        Left = 377
        Top = 30
        Width = 105
        Height = 25
        Caption = 'Insert Last'
        TabOrder = 3
        OnClick = Button15Click
      end
      object Button16: TButton
        Left = 240
        Top = 61
        Width = 105
        Height = 25
        Caption = 'Search: Target'
        TabOrder = 4
        OnClick = Button16Click
      end
      object Button17: TButton
        Left = 377
        Top = 61
        Width = 105
        Height = 25
        Caption = 'Search: InsertAfter'
        TabOrder = 5
        OnClick = Button17Click
      end
      object Button18: TButton
        Left = 504
        Top = 61
        Width = 110
        Height = 25
        Caption = 'Search: InsertBefore'
        TabOrder = 6
        OnClick = Button18Click
      end
      object Button19: TButton
        Left = 631
        Top = 61
        Width = 82
        Height = 25
        Caption = 'Search: Delete'
        TabOrder = 7
        OnClick = Button19Click
      end
    end
  end
  object PageControl2: TPageControl
    Left = 1
    Top = 251
    Width = 734
    Height = 239
    ActivePage = TabSheet8
    TabOrder = 1
    object TabSheet5: TTabSheet
      Caption = 'Singly Lnked list output'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 714
        Height = 217
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Linked Stack output'
      ImageIndex = 1
      object Memo2: TMemo
        Left = -4
        Top = 0
        Width = 717
        Height = 209
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Linked Queue Output'
      ImageIndex = 2
      object Memo3: TMemo
        Left = -4
        Top = 0
        Width = 717
        Height = 209
        Lines.Strings = (
          'Memo3')
        TabOrder = 0
      end
    end
    object TabSheet8: TTabSheet
      Caption = 'Doubly linked list output'
      ImageIndex = 3
      object Memo4: TMemo
        Left = 0
        Top = 0
        Width = 729
        Height = 209
        Lines.Strings = (
          'Memo4')
        TabOrder = 0
      end
    end
  end
end
