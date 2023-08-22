object Form1: TForm1
  Left = 0
  Top = 0
  Caption = '220524 DS_HW07_ShortestPath by Y.L Yen ver final'
  ClientHeight = 551
  ClientWidth = 957
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
    Width = 37
    Height = 13
    Caption = 'G (V, E)'
  end
  object Label2: TLabel
    Left = 8
    Top = 27
    Width = 104
    Height = 13
    Caption = 'Randomly Generated '
  end
  object Label3: TLabel
    Left = 25
    Top = 46
    Width = 20
    Height = 13
    Caption = 'n = '
  end
  object Label4: TLabel
    Left = 23
    Top = 65
    Width = 69
    Height = 13
    Caption = 'range(w(e)) ='
  end
  object Label5: TLabel
    Left = 23
    Top = 84
    Width = 45
    Height = 13
    Caption = 'if w(e) > '
  end
  object Label6: TLabel
    Left = 23
    Top = 103
    Width = 33
    Height = 13
    Caption = 'w(e) ='
  end
  object Label7: TLabel
    Left = 23
    Top = 122
    Width = 58
    Height = 13
    Caption = 'souce no. ='
  end
  object Label8: TLabel
    Left = 8
    Top = 240
    Width = 99
    Height = 13
    Caption = 'Shortest path Solver'
  end
  object Edit1: TEdit
    Left = 112
    Top = 43
    Width = 73
    Height = 21
    TabOrder = 0
    Text = '10'
  end
  object Edit2: TEdit
    Left = 112
    Top = 62
    Width = 73
    Height = 21
    TabOrder = 1
    Text = '1000'
  end
  object Edit3: TEdit
    Left = 112
    Top = 81
    Width = 73
    Height = 21
    TabOrder = 2
    Text = '700'
  end
  object Edit4: TEdit
    Left = 112
    Top = 100
    Width = 73
    Height = 21
    TabOrder = 3
    Text = '9999'
  end
  object Edit5: TEdit
    Left = 112
    Top = 119
    Width = 73
    Height = 21
    TabOrder = 4
    Text = '3'
  end
  object Button1: TButton
    Left = 8
    Top = 160
    Width = 177
    Height = 49
    Caption = 'Generate G'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 280
    Width = 177
    Height = 49
    Caption = 'Single Source All Destination '
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 352
    Width = 177
    Height = 49
    Caption = 'All Pairs'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 424
    Width = 177
    Height = 49
    Caption = 'Transitive Closure'
    TabOrder = 8
    OnClick = Button4Click
  end
  object PageControl1: TPageControl
    Left = 191
    Top = 8
    Width = 762
    Height = 577
    ActivePage = TabSheet4
    TabOrder = 9
    object TabSheet1: TTabSheet
      Caption = 'G'#39's adajacent Matrix'
      ImageIndex = 4
      object Memo1: TMemo
        Left = -4
        Top = -8
        Width = 765
        Height = 561
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Graph in adjacent matrix'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = -4
        Top = 0
        Width = 757
        Height = 553
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'SSAD table'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = -4
        Top = -5
        Width = 757
        Height = 502
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'All pairs'
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = -4
        Top = 0
        Width = 757
        Height = 489
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Transitive Closure'
      ImageIndex = 4
      object StringGrid4: TStringGrid
        Left = -4
        Top = 0
        Width = 757
        Height = 497
        TabOrder = 0
      end
    end
  end
end
