object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'BSTree by Y.L Yen 20220511 ver 0.1'
  ClientHeight = 597
  ClientWidth = 663
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
    Top = 40
    Width = 45
    Height = 13
    Caption = 'Element: '
  end
  object Label2: TLabel
    Left = 8
    Top = 178
    Width = 79
    Height = 13
    Caption = 'Delete element: '
  end
  object Label3: TLabel
    Left = 8
    Top = 233
    Width = 81
    Height = 13
    Caption = 'Search element: '
  end
  object Label4: TLabel
    Left = 8
    Top = 311
    Width = 70
    Height = 13
    Caption = '# of integers: '
  end
  object Label5: TLabel
    Left = 24
    Top = 335
    Width = 139
    Height = 13
    Caption = 'Range (Must >0, Min < Max)'
  end
  object Label7: TLabel
    Left = 8
    Top = 357
    Width = 23
    Height = 13
    Caption = 'Min: '
  end
  object Label8: TLabel
    Left = 87
    Top = 357
    Width = 27
    Height = 13
    Caption = 'Max: '
  end
  object Label6: TLabel
    Left = 59
    Top = 429
    Width = 70
    Height = 13
    Caption = 'Non-Recursive'
    Color = clBlack
    ParentColor = False
  end
  object Label10: TLabel
    Left = 67
    Top = 18
    Width = 47
    Height = 13
    Caption = 'Recursive'
  end
  object PageControl1: TPageControl
    Left = 188
    Top = 12
    Width = 473
    Height = 569
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'BST'
      object Memo1: TMemo
        Left = -4
        Top = 1
        Width = 473
        Height = 548
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
  end
  object Edit1: TEdit
    Left = 59
    Top = 37
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '10'
  end
  object Button1: TButton
    Left = 8
    Top = 72
    Width = 172
    Height = 25
    Caption = 'Insert BST (In-order)'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 103
    Width = 73
    Height = 25
    Caption = 'Pre-order'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 113
    Top = 103
    Width = 69
    Height = 25
    Caption = 'Post-order'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 134
    Width = 172
    Height = 25
    Caption = 'Level-order'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 10
    Top = 202
    Width = 172
    Height = 25
    Caption = 'Delete element from BST'
    TabOrder = 6
    OnClick = Button5Click
  end
  object Edit2: TEdit
    Left = 93
    Top = 175
    Width = 87
    Height = 21
    TabOrder = 7
    Text = '20'
  end
  object Edit3: TEdit
    Left = 95
    Top = 233
    Width = 87
    Height = 21
    TabOrder = 8
    Text = '30'
  end
  object Button6: TButton
    Left = 8
    Top = 260
    Width = 172
    Height = 25
    Caption = 'Search element from BST'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Edit4: TEdit
    Left = 84
    Top = 308
    Width = 87
    Height = 21
    TabOrder = 10
    Text = '3'
  end
  object Button7: TButton
    Left = 10
    Top = 381
    Width = 172
    Height = 25
    Caption = 'Add Random integers'
    TabOrder = 11
    OnClick = Button7Click
  end
  object Edit5: TEdit
    Left = 32
    Top = 354
    Width = 49
    Height = 21
    TabOrder = 12
    Text = '0'
  end
  object Edit6: TEdit
    Left = 120
    Top = 354
    Width = 49
    Height = 21
    TabOrder = 13
    Text = '99'
  end
  object Button9: TButton
    Left = 5
    Top = 552
    Width = 177
    Height = 25
    Caption = 'Clear BST!!'
    TabOrder = 14
    OnClick = Button9Click
  end
  object Button8: TButton
    Left = 8
    Top = 479
    Width = 174
    Height = 25
    Caption = 'Inorder'
    TabOrder = 15
    OnClick = Button8Click
  end
  object Button10: TButton
    Left = 8
    Top = 448
    Width = 174
    Height = 25
    Caption = 'Preorder'
    TabOrder = 16
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 8
    Top = 510
    Width = 174
    Height = 25
    Caption = 'Postorder'
    TabOrder = 17
    OnClick = Button11Click
  end
end
