//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW07.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


int n;
int **W;


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
//Generate G
{
	int i, j;
	int range, max_range, large_int, souce_no;
	  n = StrToInt(Edit1->Text);
	  range = StrToInt(Edit2->Text);
	  max_range = StrToInt(Edit3->Text);
	  large_int = StrToInt(Edit4->Text);
	  souce_no = StrToInt(Edit5->Text);

	if (W != NULL)                //W不為空的狀況下 清空
	{  for (i=0;i<n;i++) delete W[i];
	   delete W;
	}

	W = new int * [n];           //動態宣告W陣列
		for (i=0;i<n;i++)
		W[i]= new int [n];

	for (i=0;i<n;i++)            //根據Edit輸入的數值決定起始陣列
	{   for (j=i+1;j<n;j++)
		{   W[i][j] = rand()%range + 1;
			if (W[i][j] > max_range) W[i][j] = large_int;
			W[j][i] = W[i][j];
		}
		W[i][i] = 0;
	}

	Form1->StringGrid1->RowCount = n+1;
	Form1->StringGrid1->ColCount = n+1;
	int k, l;                            //行列留一格--> +1
			for (k=0; k<n; k++)
			{	for (l=0; l<n; l++)
					{StringGrid1->Cells[l+1][k+1] = IntToStr(W[k][l]);
					}
			}

	int index[n];              //標示地點0~9
	int i_index, j_index;

	for(i_index=0;i_index<n;i_index++)
		 { index[i_index]=i_index;
		 }

	for(j_index=0;j_index<n;j_index++)
		 { StringGrid1->Cells[0][j_index+1]=index[j_index];
		   StringGrid1->Cells[j_index+1][0]=index[j_index];
		 }

	 //先將標示地點0~9 填入後面之StringGrid內
	 int j_index2;

		StringGrid2->RowCount = n+1;
		StringGrid2->ColCount = n+2;      //多留一格放從哪來

	 for (j_index2 = 0;j_index2<n;j_index2++)
		{  StringGrid2->Cells[0][j_index2+1]=index[j_index2];
		   StringGrid2->Cells[j_index2+1][0]=index[j_index2];
		}

	 Form1->StringGrid2->Cells[n+1][0]="from";    //多留的一格放從哪來

	 Form1->StringGrid3->RowCount = n+1;
	 Form1->StringGrid3->ColCount = n+1;

	 Form1->StringGrid4->RowCount = n+1;
	 Form1->StringGrid4->ColCount = n+1;

	 for (j_index2 = 0;j_index2<n;j_index2++)
		{  StringGrid3->Cells[0][j_index2+1]=index[j_index2];
		   StringGrid3->Cells[j_index2+1][0]=index[j_index2];
		   StringGrid4->Cells[0][j_index2+1]=index[j_index2];
		   StringGrid4->Cells[j_index2+1][0]=index[j_index2];
		}



//---------------------------------------------------------------------------
}
void __fastcall TForm1::Button2Click(TObject *Sender)
//SSAD
{   int large_int = StrToInt(Edit4->Text);
	int souce_no = StrToInt(Edit5->Text);
	int c[n],D[n];
	int found[n];

	for(int q;q<n;q++)
		{found[q]=0;
		}


	int u = souce_no, v; //u到V
	for (v=0;v<n;v++) {
		D[v]=W[u][v];
		StringGrid2->Cells[1][v+1]=D[v];
		c[v]=u;
	}

	D[u]=0;

	found[u]=1;

	int i;
	int col=1;
		while(1)
		{
			int found_num=0;
			col++;
			for(i=0;i<n;i++)
			{	if(found[i]==1) found_num++;
			}
			if(found_num==n) break;
			int k, j;
			int min = large_int;
				for(j=0;j<n;j++){
					if(found[j]!=1 && min>D[j] && j!=u)   //直達和轉乘相比 給出較短的
					{	 min=D[j];
						 k=j;
					}
				}
				found[k]=1;
				int v_2;
				for(int v_2=0;v_2<n;v_2++)
				{	if(found[v_2]!=1 && D[k]+W[k][v_2]<D[v_2] && v_2!=u)
					{	D[v_2]=D[k] + W[k][v_2];
						c[v_2]=k;
					}
					StringGrid2->Cells[col][v_2+1]=D[v_2];     //給出結果
				}
			}

	for (int u_2=0;u_2<n;u_2++)
	{	StringGrid2->Cells[n+1][u_2+1]=c[u_2];
	}

Form1->Memo1->Lines->Add("=============================================================")  ;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
//All pairs
{  	int distance[n][n];
	int i, j, k;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	distance[i][j] = W[i][j];
		}
	}

	for(k=0;k<n;k++)
	{	for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{	if(distance[i][k] + distance[k][j] < distance[i][j])
				{distance[i][j] = distance[i][k]+distance[k][j];
				}
			}
		}
	}

	for (int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{	if(i==j) StringGrid3->Cells[j+1][i+1]=0;      //自己和自己距離為0
			else StringGrid3->Cells[j+1][i+1]= distance[i][j];
		}
	}

	//Print Results
	for (int i=0;i<n;i++)
	{	for(int j=0; j<n;j++)
		{	if(i!=j)Form1->Memo1->Lines->Add("Shortest distance from "+IntToStr(i)+" to "+IntToStr(j)+" is "+ distance[i][j]);
		}
		Form1->Memo1->Lines->Add("");
	}
	Form1->Memo1->Lines->Add("=============================================================") ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
//Transitive Closure
{   int A[n][n];
	int large_int = StrToInt(Edit4->Text);

	for(int i=0;i<n;i++)
	{	for (int j=0; j<n; j++)
		{	A[i][j]=W[i][j];
		}
	}

	for (int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{	if(A[i][j]==large_int) A[i][j]=0;      //沒有更快的路
			else A[i][j]=1;
		}
	}

	for (int i=0;i<n;i++)
	{	for (int j=0;j<n;j++)
		{	for (int k=0;k<n;k++)
			{A[i][j]=A[i][j] || (A[i][k] && A[k][j]);
			}
		}
	}

	for (int i=0;i<n;i++)
	{	for (int j=0;j<n;j++)
		{StringGrid4->Cells[j+1][i+1]=A[i][j];
		}
	}

}
//---------------------------------------------------------------------------

