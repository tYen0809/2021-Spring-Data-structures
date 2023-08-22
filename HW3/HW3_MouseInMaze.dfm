object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'HW03_MouseInMaze by Y.L Yen 20220328_ver 1.0'
  ClientHeight = 594
  ClientWidth = 704
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
    Left = 16
    Top = 48
    Width = 55
    Height = 13
    Caption = 'Grid_Size ='
  end
  object Edit1: TEdit
    Left = 77
    Top = 45
    Width = 57
    Height = 21
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = '40'
    TextHint = '40'
  end
  object PageControl1: TPageControl
    Left = 176
    Top = 24
    Width = 520
    Height = 562
    ActivePage = TabSheet4
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Maze_Memo'
      object Memo1: TMemo
        Left = 0
        Top = -3
        Width = 509
        Height = 534
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Show Numbers'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = -13
        Top = 0
        Width = 526
        Height = 537
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'StringGrid_fixed'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 513
        Height = 537
        TabOrder = 0
        OnClick = StringGrid2Click
        OnDrawCell = StringGrid2DrawCell
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Color with 0/1'
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = -4
        Top = -1
        Width = 517
        Height = 532
        TabOrder = 0
        OnDrawCell = StringGrid3DrawCell
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Color'
      ImageIndex = 4
      object StringGrid4: TStringGrid
        Left = -4
        Top = -3
        Width = 517
        Height = 540
        TabOrder = 0
        OnDrawCell = StringGrid4DrawCell
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Color Without Lines'
      ImageIndex = 5
      object StringGrid5: TStringGrid
        Left = -4
        Top = -3
        Width = 517
        Height = 540
        TabOrder = 0
        OnDrawCell = StringGrid5DrawCell
      end
    end
  end
  object Button1: TButton
    Left = 16
    Top = 88
    Width = 129
    Height = 41
    Caption = #36617#20837#36855#23470' (.txt)'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 184
    Width = 129
    Height = 41
    Caption = #25214#20986#21475'!'
    TabOrder = 3
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 272
    Width = 153
    Height = 97
    Caption = 'Click StringGrid_fixed to see'
    TabOrder = 4
    object Label2: TLabel
      Left = 3
      Top = 24
      Width = 29
      Height = 13
      Caption = 'Cells: '
    end
    object Label3: TLabel
      Left = 3
      Top = 43
      Width = 26
      Height = 13
      Caption = 'Size: '
    end
    object Label4: TLabel
      Left = 3
      Top = 62
      Width = 46
      Height = 13
      Caption = 'Content: '
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 136
    Top = 304
  end
end
