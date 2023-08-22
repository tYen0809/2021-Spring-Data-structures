//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW3_MouseInMaze.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

#define MaxStack 200

struct offset      //把dx, dy兩個int視為一體
{
 int dx,dy;
};
//enum directions {N,NE,E,SE,S,SW,W,NW} {0,1,2,3,4,5,6,7}
struct position
{
 int x, y;
 int dir; //directions
};

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

int Maze[20][20];
int MARK[20][20];
int m, n, top;
struct position stack[MaxStack];

void StackFull()
{
 Form1->Memo1->Lines->Add("Stack is Full!!");
}

void StackEmpty()
{
 Form1->Memo1->Lines->Add("Stack is Empty!!");
}

void push (struct position data)   //push
{
 if (top == (m*n-1)) StackFull();
 else stack[++top] = data;  //此區data為"struct position"
}

struct position pop()
{
 if (top == -1) StackEmpty();
 else return stack[top--];
}

void Path(int m, int n)
{
 struct position Step;  //struct position (x, y, dir)
 int i, j, u, v, d;   //d = direction
 bool found = false;
 struct offset move[8]; // struct offset (x, y) 定義8個方位的移動(0~7)
	move[0].dx = -1; move[0].dy = 0; //N
	move[1].dx = -1; move[1].dy = 1; //NE
	move[2].dx = 0; move[2].dy = 1; //E
	move[3].dx = 1; move[3].dy = 1; //SE
	move[4].dx = 1; move[4].dy = 0; //S
	move[5].dx = 1; move[5].dy = -1; //SW
	move[6].dx = 0; move[6].dy = -1; //W
	move[7].dx = -1; move[7].dy = -1; //NW

	Step.x = 1; Step.y = 0; Step.dir = 2;
	Maze[1][0] = 3; // 起點
	top = -1;
 push(Step);
	while (top != -1 && !found)  // stack not empty
	{
		Step = pop();
		i=Step.x; j=Step.y; d=Step.dir;
		while (d<=7 && !found)    //d<=NW  還可以繼續走下去
		{
		 u = i+move[d].dx; v = j+move[d].dy;
		 if((!Maze[u][v]) && (!MARK[u][v]))
		 {
			Maze[u][v] = 3;
			Step.x = i; Step.y = j; Step.dir = d;
			push(Step);
			if ((u==m-2) && (v==n-1))
			{
			 Maze[u][v] = 4;
			 found = true;
			 Form1->Memo1->Lines->Add("路徑為: ");
			 for(i=0; i<=top; i++)
				Form1->Memo1->Lines->Add("("+IntToStr(stack[i].x) + "," + IntToStr(stack[i].y) + "," + IntToStr(stack[i].dir)+")-->" );
			 Form1->Memo1->Lines->Add("("+IntToStr(m-2)+","+IntToStr(n-1)+")");
			 while (top!=-1)
			 {
				position s = pop();
				Maze[s.x][s.y] = 4;
			 }
				return;
			}
			  i = u; j = v; d = 0;
		 }
			else ++d;
		}
	}
}




void __fastcall TForm1::Button1Click(TObject *Sender)
//Load .txt
{
  FILE *fp;
	String out;
	int i, j;
	AnsiString infile;
	if (OpenDialog1->Execute())
	{
		infile = OpenDialog1->FileName;
		fp = fopen(infile.c_str(),"r+");
		fscanf(fp, "%d %d", &m, &n);
		Memo1->Lines->Add("(m, n) = "+IntToStr(m)+","+IntToStr(n));
		for(i=0; i<m; i++)
			for (j=0; j<n; j++)
			 fscanf(fp, "%d", &Maze[i][j]);
		fclose(fp);
		for(i=0; i<n; i++)        //將Maze print到memo1
		{
			out = "";    //String
			for (j=0; j<n; j++)  out += "  "+IntToStr(Maze[i][j]);
			Memo1->Lines->Add(out);
		}
		//StringGrid  (Show_number) 將載入之txt檔放在此stringGrid
        StringGrid1->RowCount = m;
		StringGrid1->ColCount = n;
		 for (i=0; i<m; i++)
		   for (j=0; j<n; j++)
			 StringGrid1->Cells[j][i] = Maze[i][j];
	}
	else  Memo1->Lines->Add("ERROR :(");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
//path / Grid_size / 各StringGrid 的導入
{
	int i, j;
	String out;
	int Gridsize = Edit1->Text.ToInt();
	Path(m, n);
	//StringGrid(Show Number)
	StringGrid1->RowCount = m;
	StringGrid1->ColCount = n;
	  for (i=0; i<m; i++)
		 for (j=0; j<n; j++)
			StringGrid1->Cells[j][i] = Maze[i][j];
	// StringGrid_fixed with 0/1
    StringGrid2->RowCount = m;
	StringGrid2->ColCount = n;
	StringGrid2->FixedCols = 0; StringGrid2->FixedRows = 0;
	StringGrid2->DefaultDrawing = false;  //避免垂直分隔線過粗
	for (i=0;i<m;i++)
		StringGrid2->RowHeights[i] = Gridsize;
	for (i=0;i<n;i++)
		StringGrid2->ColWidths[i] = Gridsize;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			StringGrid2->Cells[j][i] = StringGrid1->Cells[j][i];
	//StringGrid3 (Color With Numbers)
	StringGrid3->RowCount = m;
	StringGrid3->ColCount = n;
	StringGrid3->FixedCols = 0; StringGrid3->FixedRows = 0;
	StringGrid3->DefaultDrawing = false;
	for(i=0; i<m; i++)
		StringGrid3->RowHeights[i] = Gridsize;
	for(i=0; i<n; i++)
		StringGrid3->ColWidths[i] = Gridsize;
	//StringGrid4 (Color Without Numbers)
	StringGrid4->RowCount = m;
	StringGrid4->ColCount = n;
	StringGrid4->FixedCols = 0; StringGrid4->FixedRows = 0;
	StringGrid4->DefaultDrawing = false;
	for(i=0; i<m; i++)
		StringGrid4->RowHeights[i] = Gridsize;
	for(i=0; i<n; i++)
		StringGrid4->ColWidths[i] = Gridsize;
	//StringGrid5   (Color Without Numbers and Lines)
	StringGrid5->RowCount = m;
	StringGrid5->ColCount = n;
	StringGrid5->FixedCols = 0; StringGrid5->FixedRows = 0;
	StringGrid5->DefaultDrawing = false;
	StringGrid5->GridLineWidth = 0;  //格線寬度設置為0
	for(i=0; i<m; i++)
		StringGrid5->RowHeights[i] = Gridsize;
	for(i=0; i<n; i++)
		StringGrid5->ColWidths[i] = Gridsize;

	StringGrid2->Refresh();
	StringGrid3->Refresh();
	StringGrid4->Refresh();
	StringGrid5->Refresh();
    for (i=0; i<m; i++)
	{   out = "";
		for (j=0; j<n; j++)
			out += " "+IntToStr(Maze[i][j]);
		Memo1->Lines->Add(out);
	}



}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
//StringGrid_2 (Fixed)
{
	StringGrid2->Canvas->Brush->Color = clWhite;
	StringGrid2->Canvas->Font->Color = clBlue;
	StringGrid2->Canvas->FillRect(Rect);
	AnsiString text = StringGrid2->Cells[ACol][ARow];
	StringGrid2->Canvas->TextRect(Rect, Rect.Left+8, Rect.Top+8, text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2Click(TObject *Sender)
//StringGrid_2 (位置)
{
  TRect Recto = StringGrid1->CellRect(StringGrid1->Col, StringGrid1->Row);
  int width = Recto.Width();
  int height = Recto.Height();
  Label2->Caption = "Size: "+IntToStr(width)+"X"+IntToStr(height);
  Label3->Caption = "Cell: ["+IntToStr(StringGrid2->Col)+","+IntToStr(StringGrid2->Row)+"] = "+StringGrid2->Cells[StringGrid2->Col][StringGrid2->Row];
  Label4->Caption = "Content: "+StringGrid1->Cells[StringGrid2->Col][StringGrid2->Row];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	AnsiString text = StringGrid2->Cells[ACol][ARow];
	if (text == "0")
		 StringGrid3->Canvas->Brush->Color = TColor RGB(255, 107, 107);  //Red
	else if (text == "1")
		 StringGrid3->Canvas->Brush->Color = TColor RGB(107, 203, 119);  //Green
	else if (text == "2")
		 StringGrid3->Canvas->Brush->Color = TColor RGB(77, 150, 255);  //Blue
	else if (text == "3")
		 StringGrid3->Canvas->Brush->Color = TColor RGB(255, 217, 61); //Yellow
	else    //4
		StringGrid3->Canvas->Brush->Color = TColor (RGB(80, 80, 80));    //Gray
		StringGrid3->Canvas->FillRect(Rect);
		StringGrid3->Canvas->TextRect(Rect, Rect.Left+6, Rect.Top+8, text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid4DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	AnsiString text = StringGrid2->Cells[ACol][ARow];
	if (text == "0")
		 StringGrid4->Canvas->Brush->Color = TColor RGB(255, 107, 107);  //Red
	else if (text == "1")
		 StringGrid4->Canvas->Brush->Color = TColor RGB(107, 203, 119);  //Green
	else if (text == "2")
		 StringGrid4->Canvas->Brush->Color = TColor RGB(77, 150, 255);  //Blue
	else if (text == "3")
		 StringGrid4->Canvas->Brush->Color = TColor RGB(255, 217, 61); //Yellow
	else
	StringGrid4->Canvas->Brush->Color = TColor RGB(80, 80, 80);   //Gray
	StringGrid4->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid5DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	AnsiString text = StringGrid2->Cells[ACol][ARow];
	if (text == "0")
		 StringGrid5->Canvas->Brush->Color = TColor RGB(255, 107, 107);  //Red
	else if (text == "1")
		 StringGrid5->Canvas->Brush->Color = TColor RGB(107, 203, 119);  //Green
	else if (text == "2")
		 StringGrid5->Canvas->Brush->Color = TColor RGB(77, 150, 255);  //Blue
	else if (text == "3")
		 StringGrid5->Canvas->Brush->Color = TColor RGB(255, 217, 61); //Yellow
	else
	StringGrid5->Canvas->Brush->Color = TColor RGB(80, 80, 80);   //Gray
	StringGrid5->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------

