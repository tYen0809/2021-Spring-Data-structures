//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW2_MagicSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Maxsize 25
//最大的邊長
int square[Maxsize][Maxsize];


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void MagicSquare(int n)
//奇數
{
  int i, j, k, l, data;
  String Line;
  //if ((n > Maxsize)||(n<1))
  //告知超出範圍
	//{
	  //printf
	  //Form1->Memo1->Lines->Add("輸入方塊過大，不予處理。");
	  //return;
	//}
	//else if ((n%2)==0)
	//{
	  //Form1->Memo1->Lines->Add("輸入方塊邊長為偶數，不予處理。");
	  //return;
	//}
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] =0;


	//1的位置
	i = 0; j = (n-1)/2;
	square[i][j] = 1;
	data = 2;
	while (data <= n*n)  //定義如何找下一步
	{
	  k = (i-1<0) ? n-1 : i-1;
	  l = (j-1<0) ? n-1 : j-1;
	  if (square[k][l] > 0) i = i+1%n;     //若被占用-->往下一格
	  else { i = k; j = l;}
	  square[i][j] = data++;
	}
	//Form1->Memo1->Lines->Add(IntToStr(n)+"X"+IntToStr(n)+"的MAGIC_SQUARE");
	for (i=0; i<n; i++)
	{  Line = "";
		for (j=0; j<n; j++)
		 {
		   Line += IntToStr(square[i][j])+"  ";
		 }
	   Form1->Memo1->Lines->Add(Line);
	}
}

void Multiple4 (int n)
//4的倍數
{
   int i,j;
   String Line;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] =0;
   //製造矩陣與原點

   for (i=1; i<=n; i++)
	for (j=1; j<=n; j++)
	{
		if (j % 4 == i % 4 || (j % 4 + 1) == 1)
			square[i][j] = (n + 1 - i)* n - j + 1;
		else
			square[i][j] = (i - 1)* n + j;
	}
   for (i=1; i<=n; i++)
	{    Line = "";
		 for (j=1; j<=n; j++)
		  Line += IntToStr(square[i][j])+"  ";
		  Form1->Memo1->Lines->Add(Line);
	}
	Form1->StringGrid1->RowCount = n+1;   //若沒有n+1則會少print一Column與Row
	Form1->StringGrid1->ColCount = n+1;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			Form1->StringGrid1->Cells[j][i] = square[i][j];
	}
}

void PrintSquare (int n)
//固定方格與String Grid
{
	String row1;
	int len = IntToStr(n*n).Length();
	int block_len = len+3;
	   // 欄寬長度設為比 n*n 數字的位數多 3
	int blank_len, i, j, k;
	for (i=0; i<n; i++)
	{
		row1="";
		for (j=0; j<n; j++)
		{
		  blank_len=block_len-IntToStr(square[i][j]).Length();
		  // 數字前的空格數 = 欄寬 - 數字的字元數
		  for (k=0; k<blank_len; k++) row1 += " ";
		  // 在字串前先預放 blank_len多的空格
		  row1 += IntToStr(square[i][j]);
		  // 將代表數字的字串, 接在 row1字串之後
		}
		Form1->Memo2->Lines->Add(row1);
	}
	//StringGrid
	Form1->StringGrid1->RowCount = n+1;   //??
	Form1->StringGrid1->ColCount = n+1;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			Form1->StringGrid1->Cells[j][i] = square[i][j];
	}
}

void LocationOf1 (int n)
//1的起始位置改變
{
   int i, j, k, l, data;
   String Line;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] =0;

   if(Form1->RadioButton5->Checked)        //上
   {
	  i = 0; j = (n-1)/2;
   }

   else if(Form1->RadioButton6->Checked)  //左
   {
	  i = (n-1)/2; j = 0;
   }

   else if(Form1->RadioButton7->Checked)  //右
   {
	  i = (n-1)/2; j = n-1;
   }

   else if(Form1->RadioButton8->Checked) //下
   {
	  i = n-1; j = (n-1)/2;
   }

	square[i][j] = 1;
	data = 2;

	while (data <= n*n)  //定義如何找下一步
	{
	  k = (i-1<0) ? n-1 : i-1;
	  l = (j-1<0) ? n-1 : j-1;
	  if (square[k][l] > 0) i = i+1%n;     //若被占用-->往下一格
	  else { i = k; j = l;}
	  square[i][j] = data++;
	}
	Form1->Memo1->Lines->Add(IntToStr(n)+"X"+IntToStr(n)+"的MAGIC_SQUARE");
	for (i=0; i<n; i++)
	{ Line = "";
	  for (j=0; j<n; j++)
		Line += IntToStr(square[i][j]) + "  ";
		  Form1->Memo1->Lines->Add(Line);
	}
}



//---------------------------------------------------------------------------
//以下開始button
void __fastcall TForm1::Button1Click(TObject *Sender)
//奇數
{
	int i, j;
		int n = StrToInt(Edit1->Text);
		if ((n>Maxsize) || n<=1)
		 //告知超出範圍
		{
		Form1->Memo1->Lines->Add("輸入邊長過大，不予處理:)");
		Form1->Memo2->Lines->Add("輸入邊長過大，不予處理:)");

		}

		else if ((n%2)==0)
		//告知輸入奇數
		{
		Form1->Memo1->Lines->Add("輸入方塊邊長為偶數，請輸入介於3~25間之奇數");
		Form1->Memo2->Lines->Add("輸入方塊邊長為偶數，請輸入介於3~25間之奇數");

		}

		else
		{
		Form1->Memo1->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"的MAGIC_SQUARE");
		Form1->Memo2->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"的MAGIC_SQUARE");

		MagicSquare(n);
		PrintSquare(n);

		}
	Form1->Memo1->Lines->Add("-------------------------------------------------");
	Form1->Memo2->Lines->Add("-------------------------------------------------");

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
//1的位置
{
	int i, j;
		int n = StrToInt(Edit1->Text);
		if ((n>Maxsize) || n<=1)
		 //告知超出範圍
		{
		Form1->Memo1->Lines->Add("輸入邊長過大，不予處理:)");
		Form1->Memo2->Lines->Add("輸入邊長過大，不予處理:)");

		}

		else if ((n%2)==0)
		//告知輸入奇數
		{
		Form1->Memo1->Lines->Add("輸入方塊邊長為偶數，請輸入介於3~25間之奇數");
		Form1->Memo2->Lines->Add("輸入方塊邊長為偶數，請輸入介於3~25間之奇數");

		}

		else
		{
		Form1->Memo1->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"的MAGIC_SQUARE");
		Form1->Memo2->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"的MAGIC_SQUARE");

		LocationOf1(n);
		}
	Form1->Memo1->Lines->Add("-------------------------------------------------");
	Form1->Memo2->Lines->Add("-------------------------------------------------");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
//4的倍數
{
	int i, j;
	int n = StrToInt(Edit1->Text);
	if ((n>Maxsize) || (n%4)!=0)
		Form1->Memo1->Lines->Add("Wrong size!");
	else
	{   Form1->Memo1->Lines->Add(IntToStr(n)+" × "+IntToStr(n)+" Magic Square!");
		Multiple4(n);
	}
	Form1->Memo1->Lines->Add("-------------------------------------------------");
}
//---------------------------------------------------------------------------

