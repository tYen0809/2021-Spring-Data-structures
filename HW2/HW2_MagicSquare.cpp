//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW2_MagicSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Maxsize 25
//�̤j�����
int square[Maxsize][Maxsize];


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void MagicSquare(int n)
//�_��
{
  int i, j, k, l, data;
  String Line;
  //if ((n > Maxsize)||(n<1))
  //�i���W�X�d��
	//{
	  //printf
	  //Form1->Memo1->Lines->Add("��J����L�j�A�����B�z�C");
	  //return;
	//}
	//else if ((n%2)==0)
	//{
	  //Form1->Memo1->Lines->Add("��J�����������ơA�����B�z�C");
	  //return;
	//}
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] =0;


	//1����m
	i = 0; j = (n-1)/2;
	square[i][j] = 1;
	data = 2;
	while (data <= n*n)  //�w�q�p���U�@�B
	{
	  k = (i-1<0) ? n-1 : i-1;
	  l = (j-1<0) ? n-1 : j-1;
	  if (square[k][l] > 0) i = i+1%n;     //�Y�Q�e��-->���U�@��
	  else { i = k; j = l;}
	  square[i][j] = data++;
	}
	//Form1->Memo1->Lines->Add(IntToStr(n)+"X"+IntToStr(n)+"��MAGIC_SQUARE");
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
//4������
{
   int i,j;
   String Line;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] =0;
   //�s�y�x�}�P���I

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
	Form1->StringGrid1->RowCount = n+1;   //�Y�S��n+1�h�|��print�@Column�PRow
	Form1->StringGrid1->ColCount = n+1;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			Form1->StringGrid1->Cells[j][i] = square[i][j];
	}
}

void PrintSquare (int n)
//�T�w���PString Grid
{
	String row1;
	int len = IntToStr(n*n).Length();
	int block_len = len+3;
	   // ��e���׳]���� n*n �Ʀr����Ʀh 3
	int blank_len, i, j, k;
	for (i=0; i<n; i++)
	{
		row1="";
		for (j=0; j<n; j++)
		{
		  blank_len=block_len-IntToStr(square[i][j]).Length();
		  // �Ʀr�e���Ů�� = ��e - �Ʀr���r����
		  for (k=0; k<blank_len; k++) row1 += " ";
		  // �b�r��e���w�� blank_len�h���Ů�
		  row1 += IntToStr(square[i][j]);
		  // �N�N��Ʀr���r��, ���b row1�r�ꤧ��
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
//1���_�l��m����
{
   int i, j, k, l, data;
   String Line;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] =0;

   if(Form1->RadioButton5->Checked)        //�W
   {
	  i = 0; j = (n-1)/2;
   }

   else if(Form1->RadioButton6->Checked)  //��
   {
	  i = (n-1)/2; j = 0;
   }

   else if(Form1->RadioButton7->Checked)  //�k
   {
	  i = (n-1)/2; j = n-1;
   }

   else if(Form1->RadioButton8->Checked) //�U
   {
	  i = n-1; j = (n-1)/2;
   }

	square[i][j] = 1;
	data = 2;

	while (data <= n*n)  //�w�q�p���U�@�B
	{
	  k = (i-1<0) ? n-1 : i-1;
	  l = (j-1<0) ? n-1 : j-1;
	  if (square[k][l] > 0) i = i+1%n;     //�Y�Q�e��-->���U�@��
	  else { i = k; j = l;}
	  square[i][j] = data++;
	}
	Form1->Memo1->Lines->Add(IntToStr(n)+"X"+IntToStr(n)+"��MAGIC_SQUARE");
	for (i=0; i<n; i++)
	{ Line = "";
	  for (j=0; j<n; j++)
		Line += IntToStr(square[i][j]) + "  ";
		  Form1->Memo1->Lines->Add(Line);
	}
}



//---------------------------------------------------------------------------
//�H�U�}�lbutton
void __fastcall TForm1::Button1Click(TObject *Sender)
//�_��
{
	int i, j;
		int n = StrToInt(Edit1->Text);
		if ((n>Maxsize) || n<=1)
		 //�i���W�X�d��
		{
		Form1->Memo1->Lines->Add("��J����L�j�A�����B�z:)");
		Form1->Memo2->Lines->Add("��J����L�j�A�����B�z:)");

		}

		else if ((n%2)==0)
		//�i����J�_��
		{
		Form1->Memo1->Lines->Add("��J�����������ơA�п�J����3~25�����_��");
		Form1->Memo2->Lines->Add("��J�����������ơA�п�J����3~25�����_��");

		}

		else
		{
		Form1->Memo1->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"��MAGIC_SQUARE");
		Form1->Memo2->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"��MAGIC_SQUARE");

		MagicSquare(n);
		PrintSquare(n);

		}
	Form1->Memo1->Lines->Add("-------------------------------------------------");
	Form1->Memo2->Lines->Add("-------------------------------------------------");

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
//1����m
{
	int i, j;
		int n = StrToInt(Edit1->Text);
		if ((n>Maxsize) || n<=1)
		 //�i���W�X�d��
		{
		Form1->Memo1->Lines->Add("��J����L�j�A�����B�z:)");
		Form1->Memo2->Lines->Add("��J����L�j�A�����B�z:)");

		}

		else if ((n%2)==0)
		//�i����J�_��
		{
		Form1->Memo1->Lines->Add("��J�����������ơA�п�J����3~25�����_��");
		Form1->Memo2->Lines->Add("��J�����������ơA�п�J����3~25�����_��");

		}

		else
		{
		Form1->Memo1->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"��MAGIC_SQUARE");
		Form1->Memo2->Lines->Add(IntToStr(n)+" X "+IntToStr(n)+"��MAGIC_SQUARE");

		LocationOf1(n);
		}
	Form1->Memo1->Lines->Add("-------------------------------------------------");
	Form1->Memo2->Lines->Add("-------------------------------------------------");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
//4������
{
	int i, j;
	int n = StrToInt(Edit1->Text);
	if ((n>Maxsize) || (n%4)!=0)
		Form1->Memo1->Lines->Add("Wrong size!");
	else
	{   Form1->Memo1->Lines->Add(IntToStr(n)+" �� "+IntToStr(n)+" Magic Square!");
		Multiple4(n);
	}
	Form1->Memo1->Lines->Add("-------------------------------------------------");
}
//---------------------------------------------------------------------------

