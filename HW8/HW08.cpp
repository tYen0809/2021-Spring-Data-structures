//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW08.h"
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

# define SWAP(x, y, t) (t=x, x=y, y=t)

#define MAXSIZE 90000

int data [90000];
int original_data[90000];
int n;

//int STACK[MAXSIZE];


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//int top;

/*
void push(int element1, int element2)
{  if (top == MAXSIZE-1)
		Form1->Memo1->Lines->Add("Stack is full");
   else
	  STACK[++top]= element1;
	  STACK[++top]= element2;
}

int pop()
{ if (top == -1)
  {  Form1->Memo1->Lines->Add("Stack is empty");
	 return -1;
  }
	return STACK[top--];
}
*/

void SWAP_A (int *a, int *b)    //Swap Address
{
  int t = *a;
  *a = *b;
  *b = t;
}


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
			SWAP(data[i], data[min], temp);
		}
}

void InsertionSort(int data[], int n)
//Insertion Sort
{ int i, j, target;
	for (i=0;i<n;i++)
	{  target = data[i];
	   j = i;
	   while ((data[j-1]>target && (j>0)))
	   { data[j] = data[j-1];
		 j--;
	   }
	   data[j] = target;
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
//Quick Sort recursive
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

int PartionForQuickSort(int data[], int left, int right) //把分左右的過程拉出來
{
  int A = data[right];
  int i = (left - 1);
  int j;
  for (j=left;j<=right-1;j++)
  { if (data[j]<= A)
	  { i++;
		SWAP_A (&data[i], &data[j]);
	  }
  }
  SWAP_A (&data[i+1], &data[right]);
  return (i+1);
}

void QuickSort_iterative (int data[],int left,int right)
//Quick Sort (Non-recursive)
{ int STACK[MAXSIZE];
  int top = -1;
  int j;
  //int i;
  //int target, tmp;
  //push (left, right);
  STACK[++top] = left;   //push left
  STACK[++top] = right;  //push right
  while(top != -1) //left right存在 , top != -1  >=0也可以
  {
	 right = STACK[top--]; //pop();
	 left = STACK[top--];  //pop();
	 j = PartionForQuickSort(data, left, right);

	//target = data[left];
	//i = left+1;
	//j = right;
	//do                       //partion
	//{  while (data[i]<target && i<=j) i++;
	//   while (data[j]>=target && i<=j) j--;
	//   if (i<j) SWAP(data[i], data[j], tmp);
	//}   while (i<j);
	//if (left<j) SWAP(data[left], data[j], tmp);

	  if (left<j-1)
	  { //push(left, j-1);
		//push(j-1);
		STACK[++top] = left;   //push left
		STACK[++top] = j-1;    //push right
	  }

	if (j+1<right)
	  { //push(j+1, right);
		STACK[++top] = j+1;    //push j+1
		STACK[++top] = right;  //push right
	  }

  }
}

void merge(int C[], int left, int middle, int right)
//merge_sort的function
{
 int i, j, k;
 int n1 = middle - left + 1;
 int n2 = right - middle;
 int L[n1];
 int R[n2] ;
 for (i = 0; i < n1; i++) L[i] = C[left + i];      // Copy to Left
 for (j = 0; j < n2; j++) R[j] = C[middle + 1 + j];  // Copy to Right
 i = 0; j = 0; k = left;
 while (i < n1 && j < n2)
 {
 if (L[i] <= R[j])
  { C[k] = L[i];  i++;
  }
 else
  { C[k] = R[j]; j++;
  }
  k++;
 }
 while (i < n1)
  { C[k] = L[i]; i++; k++;
  }
 while (j < n2)
  { C[k] = R[j]; j++; k++;
  }
}

void merge_sort (int A[], int left, int right)
//Merge Sort (Recursive)
{  int i, j, k, m;
   if(left < right)  //代表還可以分
	{ m = left + (right - left)/2;  //先分兩半
	  merge_sort(A, left, m);   //排左邊的
	  merge_sort(A, m+1, right); //排右邊的
	  merge(A, left, m, right); //最後合併
    }
}


int Min (int a, int b)
{
  return (a<b) ? a:b;
}


void MERGESORT (int A[], int n)
//Merge Sort (Non recursive)
{ int i;
  int left;
  int mid, right;
  for (i=1;i<=n-1;i=2*i)
	for (left=0;left<n;left+=2*i)
	{  mid = Min(left+i-1, n-1);
	   right = Min(left+2*i-1, n-1);
	   merge(A, left, mid, right);
	}
}


void restore (int data[], int k, int i)
//Function for Heap sort
{  int j=i;
   int l = 2*i + 1;
   int r = 2*i + 2;
   int temp;
   if (l<k && data[l]>data[j])
	j = l;
   if (r<k && data[r]>data[j])
	j=r;
   if (j != i)
   {
	 SWAP(data[i], data[j], temp);
	 restore (data, k, j);
   }
}

void HeapSort(int data[], int p)
//Heap sort
{   int temp;
	for (int i= p/2-1;i>=0;i--)
	   restore(data, p, i);
	for (int i= p-1;i>0;i--)
	{
	  SWAP (data[0], data[i], temp);
	   restore(data, i, 0);
	}

}


void RandData(int original_data[], int n, int range)
{   int i;
	int j;
		for (i=0; i<n; i++)
		original_data[i] = rand() % range + 1;

}

void GetData(int data[], int original_data[], int n)
{   int i;
		for (i=0; i<n; i++)
		data[i] = original_data[i];
}

void PrintData(int data[], int n, int flag)
{   int i;
		if (flag == 1)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Selection Sort["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else if (flag == 2)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Insertion Sort["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else if (flag == 3)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Bubble Sort["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else if (flag == 4)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Quick Sort (Recursive)["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else  if (flag == 5)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Quick Sort (Non Recursive)["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else  if (flag == 6)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Merge Sort(Recursive)["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else  if (flag == 7)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Merge Sort (Non recursive)["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
		else  if (flag == 8)
		{  for(i=0; i < n; i++)
		   {
			 Form1->Memo1->Lines->Add("Heap Sort["+IntToStr(i)+"] = "+IntToStr(data[i]));
		   }
		}
}





void __fastcall TForm1::Button1Click(TObject *Sender)
{
	n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int times = StrToInt(Edit3->Text);
	int y;
	clock_t t_begin, t_end;
	for (y=n;y<=times*n;y+=n)
  {
		RandData(original_data, n, range);

		if (CheckBox1->Checked)
		  {
		   srand  (time(NULL));
		   GetData(data, original_data, n);
		   t_begin = clock();
		   SelectionSort(data, n);
		   t_end = clock();
		   Form1->Memo1->Lines->Add("Selection Sort Complete");
		   if (CheckBox9->Checked) PrintData(data, n, 1);
		   Form1->Memo1->Lines->Add("CPU time(Selection_Sort) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
		if (CheckBox2->Checked)
		  {
		   srand  (time(NULL));
		   GetData(data, original_data, n);
		   t_begin = clock();
		   InsertionSort(data, n);
		   t_end = clock();
		   Form1->Memo1->Lines->Add("Insertion Sort Complete");
		   if (CheckBox9->Checked) PrintData(data, n, 2);
		   Form1->Memo1->Lines->Add("CPU time(Insertion_Sort) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
		if (CheckBox3->Checked)
		  {srand  (time(NULL));
		   GetData(data, original_data, n);
		   t_begin = clock();
		   BubbleSort(data, n);
		   t_end = clock();
		   Form1->Memo1->Lines->Add("Bubble sort Complete");
		   if (CheckBox9->Checked) PrintData(data, n, 3);
		   Form1->Memo1->Lines->Add("CPU time(Bubble_Sort) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
		if (CheckBox4->Checked)
		  { srand  (time(NULL));
			GetData(data, original_data, n);
			t_begin = clock();
			QuickSort(data, 0, n);
			t_end = clock();
			Form1->Memo1->Lines->Add("Quick Sort (recursive) Complete");
			if (CheckBox9->Checked) 	PrintData(data, n, 4);
			Form1->Memo1->Lines->Add("CPU time(Quick_Sort_Recursive) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
		if (CheckBox5->Checked)
		  {
           srand  (time(NULL));
		   GetData(data, original_data, n);
		   t_begin = clock();
		   QuickSort_iterative(data, 0, n-1);
		   t_end = clock();
		   Form1->Memo1->Lines->Add("Quick Sort (Non-recursive) Complete");
		   if (CheckBox9->Checked) PrintData(data, n, 5);
		   Form1->Memo1->Lines->Add("CPU time(Quick_Sort_Interative) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
		if (CheckBox6->Checked)
		  {
           srand  (time(NULL));
		   GetData(data, original_data, n);
		   t_begin = clock();
		   merge_sort(data, 0, n);
		   t_end = clock();
		   Form1->Memo1->Lines->Add("Merge Sort (Recursive) Complete");
		   if (CheckBox9->Checked) PrintData(data, n, 6);
		   Form1->Memo1->Lines->Add("CPU time(Merge_Sort_Recursive) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
		if (CheckBox7->Checked)
		  {
            srand  (time(NULL));
			GetData(data, original_data, n);
			t_begin = clock();
			MERGESORT(data, n);
			t_end = clock();
			Form1->Memo1->Lines->Add("Merge Sort (Non-recursive) Complete");
			if (CheckBox9->Checked) PrintData(data, n, 7);
			Form1->Memo1->Lines->Add("CPU time(Merge_Sort_Interative) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));

		  }
		if (CheckBox8->Checked)
		{   srand  (time(NULL));
			GetData(data, original_data, n);
			t_begin = clock();
			HeapSort(data, n);
			t_end = clock();
			Form1->Memo1->Lines->Add("Heap Sort Complete");
            if (CheckBox9->Checked) PrintData(data, n, 8);
			Form1->Memo1->Lines->Add("CPU time(Heap_Sort) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
		  }
  }
}
//---------------------------------------------------------------------------
