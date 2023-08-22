//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW1_Sorting.h"
//內有抓取CPU_time的function
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

# define SWAP(x, y, t) (t=x, x=y, y=t)

int data [90000];
int original_data[90000];
int n;


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void SelectionSort(int data[], int n)
// Selection Sort
{   int i,j, min, temp;
		for (i = 0; i < n; i++)
		{   min = i;
			for (j = i+1; j < n; j++)
			{    if (data[j] < data[min])
				   {
					   min = j;
				   }

			}
			//temp = data[i];
			//data[i] = data[min];
			//data[min] = temp	;
			SWAP(data[i], data[min], temp);
		}
}


void BubbleSort(int data[], int n)
//Bubble Sort
{ int i, j, temp;
	for (i = n-1; i>=0; i--)
	{ for (j = 1; j<=i; j++)
		{
		if (data[j-1]>data[j])
			SWAP(data[j], data[j-1], temp);
		}
	}
}


void QuickSort(int data[], int left, int right)
//Quick Sort
{   int i, j, target, temp;
	if (left<right)
	{   i = left + 1;
		j = right;
		target = data[left];
		do
		{
		 while (data[i]<target && i<=j) i++;
		 while (data[j]>=target && i<=j) j--;
		 if (i<j) SWAP(data[i], data[j], temp);
		}
	  while (i<j);
	  if (left<j) SWAP(data[left], data[j], temp);
	  QuickSort(data, left, j-1);
	  QuickSort(data, j+1, right);
	}
}


int BinarySearch(int data[], int n, int target)
//Binary Search
{  int left=0, right= n, middle;
		while(left <= right)
		{   middle = (left+right)/2;
			if (target == data[middle])
				return middle;
			else if (target > data[middle])
				left = middle+1;
			else
				right = middle-1;
		}
	return -1;
}



void PrintData(int data[], int n, int flag)
{   int i;
		if (flag == 1)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else if (flag == 2)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo2->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else if (flag == 3)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo3->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else if (flag == 4)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo4->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else  //(flag == 5)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo5->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
}


void CheckData(int data[], int n, int flag)
{   int i;
	for (i=0; i<n-1; i++)
	{
		if (data[i] > data[i+1]) break;
	}
	if (i == n-1)
	{   if (flag == 2)
			Form1->Memo2->Lines->Add("Correctly Sorted.");
		else if (flag == 3)
			Form1->Memo3->Lines->Add("Correctly Sorted.");
		else if (flag == 4)
			Form1->Memo4->Lines->Add("Correctly Sorted.");
	}
	else
	{
		if (flag == 2)
			Form1->Memo2->Lines->Add("NOT Sorted.");
		else if (flag == 3)
			Form1->Memo3->Lines->Add("NOT Sorted.");
		else if (flag == 4)
			Form1->Memo4->Lines->Add("NOT Sorted.");
	}
}


void RandData(int original_data[], int n, int range)
{   int i;
		for (i=0; i<n; i++)
		original_data[i] = rand() % range + 1;
}


void GetData(int data[], int original_data[], int n)
{   int i;
		for (i=0; i<n; i++)
		data[i] = original_data[i];
}



void __fastcall TForm1::Button1Click(TObject *Sender)
//製造隨機數量
//rand最大:32767
{   n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int i;
		srand( time(NULL) );
	clock_t t_begin, t_end;
		t_begin = clock();
		RandData(original_data, n, range);
		t_end = clock();
		if (CheckBox1->Checked) PrintData(original_data, n, 1);
		Form1->Memo1->Lines->Add("CPU time(Sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{ //Selection_Sort的button
	 clock_t t_begin, t_end;
		t_begin = clock();
		GetData(data, original_data, n);
		SelectionSort(data, n);
		t_end = clock();
		if (CheckBox1->Checked) PrintData(data, n, 2);
		if (CheckBox2->Checked) CheckData(data, n, 2);
		Form1->Memo2->Lines->Add("CPU time(Sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		//if (CheckBox1->Checked)	 printData(data, n);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{  //Bubble_Sort的button
	 clock_t t_begin, t_end;
		t_begin = clock();
		GetData(data, original_data, n);
		BubbleSort(data,n);
		t_end = clock();
		if (CheckBox1->Checked) PrintData(data, n, 3);
		if (CheckBox2->Checked) CheckData(data, n, 3);
		Form1->Memo3->Lines->Add("CPU time(Sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{  //Quick_Sort的button
    clock_t t_begin, t_end;
		t_begin = clock();
		GetData(data, original_data, n);
		QuickSort(data, 0, n);
		t_end = clock();
		if (CheckBox1->Checked) PrintData(data, n, 4);
		if (CheckBox2->Checked) CheckData(data, n, 4);
		Form1->Memo4->Lines->Add("CPU time(Sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{   //Binary_Search的button
	int target = StrToInt(Edit3->Text);
		int Success = -1;
		Success = BinarySearch(data, n, target);
		if(Success >=0 && Success<=n)
			Memo5->Lines->Add(IntToStr(target)+" has been found in data[" + IntToStr(Success)+ "]!");
		else
			Memo5->Lines->Add(IntToStr(target)+" HASN'T been found !");
}
//---------------------------------------------------------------------------
