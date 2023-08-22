//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW05_Linked_List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

struct node
{
	int data;
	struct node * next;
};

struct Dnode
{ struct Dnode * prev;
  int data;
  struct Dnode * next;
};

struct node * first, * last;
struct node * top; //for stack
struct node * front, * rear;   //for Queue

struct Dnode * head, * tail;   //Double linked list


struct node * NewNode(int element)
{
	struct node * p; //告訴別人即將有個指標 = new struct node;
	p = (struct node *) malloc (sizeof(struct node)) ;     //實體空間
	p->data = element;
	p->next = NULL;
	return p;
}

struct Dnode * NewDnode(int element)
{
	struct Dnode * p; //= new struct Dnode;
	p = (struct Dnode *) malloc (sizeof(struct Dnode));
	p->prev = NULL;
	p->data = element;
	p->next = NULL;
	return p;
}

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
//這裡的設置為 當Form行程時 自動生成
	first = NewNode(0); //開頭空白節點   header node
	first->next = first; //環狀串列生成  circular list
	last = first; //目前只有開頭空白節點

	top = NewNode(0); //為stack做準備
	top->next = top;

	front = NewNode(0); //Queue
	front->next = front;
	rear = front;

	head = NewDnode(0);      //Dnode
	head->next = head;
    tail = head;


}
//---------------------------------------------------------------------------

void InsertFirst(int element)
//把一個串列丟到first後
{   struct node * p = NewNode(element);
	p->next = first->next;
	first->next = p;
	if (last == first) last = p;
}


void InsertLast(int element)
{   struct node * p = NewNode(element);
	p->next = last->next;
	last->next = p;
	last = p;
}

void PrintList(struct node * first)
//針對Button要把所有結果print出來
{   struct node * p;
	String list = "";
	for(p=first->next; p!=first;p=p->next)
		list += IntToStr(p->data)+"-->";
	Form1->Memo1->Lines->Add(list+"< END!");
}

void PrintStack(struct node * top)
{   struct node * p;
	String list = "";
	for(p=top->next; p!=top;p=p->next)
		list += IntToStr(p->data)+"-->";
	Form1->Memo2->Lines->Add(list+"< END!");
}

void PrintQueue(struct node * first)
{   struct node * p;
	String list ="";
	for(p=first->next; p!=first; p=p->next)
		list += IntToStr(p->data)+"-->";
	Form1->Memo3->Lines->Add(list+"< END!");
}

struct node * SearchTarget(int target)
{   struct node * p;
	for(p=first->next; (p!=first && p->data!=target); p=p->next);
		if (p == first) return NULL ;   //相當於繞了一圈且都沒找到
		return p;  //回原本的值
}


struct node * SearchTargetBefore(int target)
{   struct node * p, * q;
	for(q=first, p=first->next; (p!=first && p->data!=target); q=p, p=p->next); //讓q永遠在p前面
		if (p == first) return NULL ;   //相當於繞了一圈且都沒找到
		return q;  //回原本的值
}

void InsertAfter(int element, struct node * x)
{   struct node * p = NewNode(element);
	p->next = x->next;
	x->next = p;
}

void DeleteAfter(struct node * x)
{   struct node *p = x->next;  //設一個p為要remove掉的
	x->next = p->next;
	if (p == last)  last = x;
	free (p);
}

void ClearList(struct node * first)
{   struct node *p;
	for (p = first->next; p!=first; p = first->next)
	{   first->next = p->next;
		free(p);
	}
	last = first; //重新給他一個last (已清空 last必定等於first)
}


void Reverse()
{   struct node *r, *s, *t;
	r = first;
	s = NULL;
	while (r!=NULL)
	{   t = s;
		s = r;
		r = r->next;
        s->next = t;
    }
	first = s;
}


void push(int target)
{   struct node * p = NewNode(target);
	p->next = top->next;
	top->next = p;
}

int pop ()
{   struct node * p = top->next;     //POP處理後的第一個element
	if (p == top) return -1;
	int result = p->data;
	top->next = p->next; //為p free掉做準備
	free(p);
	return result;
}

void InsertQueue(int target)
{   struct node * p = NewNode(target);
	p->next = rear->next;
	rear->next = p;
	rear = p;
}

int DeleteQueue()
{	struct node * p = front->next;
		if (p == front) return -1;
		front->next = p->next;
		int target = p->data;
		if(p == rear) rear = front;
		free(p);
	return target;
}



//Double-----------------------------------------------------------------------
void PrintDList(struct Dnode * first)
{   struct Dnode * p;
	String list = "";
	for(p=first->next; p!=first; p=p->next)
		list += IntToStr(p->data)+"-->";
	Form1->Memo4->Lines->Add(list+"< END!");
}


void InsertDListFirst(int element)
{   struct Dnode * p = NewDnode(element);
	p->prev = head;
	p->next = head->next;
	head->next->prev = p;
	head->next = p;
	if (tail == head) tail = p;
}

void InsertDListLast(int element)
{   struct Dnode * p = NewDnode(element);
		p->prev = tail;
		p->next = tail->next;
		tail->next->prev = p;
		tail->next = p;
	tail = p;
}

struct Dnode *SearchDList(int target)
{   struct Dnode * p;
	for(p = head->next; ((p->data!=target) && (p!=head)); p=p->next);
	if(p == head)
		return NULL;
	return p;
}

struct Dnode * SearchDListBefore(int target)
{   struct Dnode * p, * q;
	for(q = head, p = head->next; ((p->data!=target) && (p!=head)); q=p, p=p->next);
	if(p == head)
		return NULL;
	return q;
}

void InsertDListAfter(int element, struct Dnode * p)
{  struct Dnode * x = NewDnode(element);
	x->prev = p;
	x->next = p->next;
	p->next->prev = x;
	p->next = x;
}

void DeleteDListAfter(struct Dnode * p)
{   struct Dnode * x = p->next;
	x->prev->next = x->next;
	x->next->prev = x->prev;
	if (p == tail)
		tail = p;
    free(p);
}

//Double-----------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
//InsertFirst
{   int element = StrToInt(Edit1->Text);
		InsertFirst(element);
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
//InsertLast
{   int element = StrToInt(Edit1->Text);
		InsertLast(element);
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
//SearchTarget
{   int target = StrToInt(Edit2->Text);
	struct node * x;
	x = SearchTarget(target);
	if (x) Form1->Memo1->Lines->Add(IntToStr(x->data)+" has been found.");
	else   Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
//Search:InsertAfter
{   int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	struct node * x;
	x = SearchTarget(target);
	if (x) InsertAfter(element,x);
	else   Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
//Search:InsertBefore
{   int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	struct node * x;
	x = SearchTargetBefore(target);
	if (x) InsertAfter(element,x);
	else   Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
//Search:Delete
{   int target = StrToInt(Edit2->Text);
	struct node * x;
	x = SearchTargetBefore(target);   //要知道前面是什麼才能刪除
	if (x) DeleteAfter(x);
	else   Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
//Insert N Ramdom numbers
{  int n = StrToInt(Edit3->Text);
   int range = StrToInt(Edit4->Text);
   int * data = new int [n]; //產生之亂數先放在此
   String line = "";
   for(int i=0; i<n; i++)
   { data[i] = rand() % range + 1;  //random的結果為1 ~ range
	 line += IntToStr(data[i]) + "_";
	 InsertLast(data[i]);
   }
   Form1->Memo1->Lines->Add(IntToStr(n)+" random numbers:"+line);
   PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
//Clear List
{   ClearList(first);
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
//push
{   int target = StrToInt(Edit5->Text);
	push(target);
	PrintStack(top);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
//pop
{  int result = pop();
   if (result != -1) PrintStack(top);
   else Form1->Memo2->Lines->Add("Stack is empty");
   Label7->Caption = "pop result = "+IntToStr(result);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
//Reverse
{  Reverse();
   PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
//InsertQueue
{	int target = StrToInt(Edit6->Text);
		InsertQueue(target);
		PrintQueue(front);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
//DeleteQueue
{   int result = DeleteQueue();
	if  (result != -1)  PrintQueue(front);
	else Form1->Memo3->Lines->Add("Queue is empty");
	Label8->Caption = "Delete result = "+IntToStr(result);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
//Double: Insert first
{  int element = StrToInt(Edit7->Text);
		InsertDListFirst(element);
	PrintDList(head);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
// Double: Insert Last
{  int element = StrToInt(Edit7->Text);
		InsertDListLast(element);
	PrintDList(head);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
//Double: Search
{
	int target = StrToInt(Edit8->Text);
	struct Dnode * p;
	p = SearchDList(target);
	if (p) Form1->Memo4->Lines->Add(IntToStr(p->data)+" has been found!");
	else Form1->Memo4->Lines->Add(IntToStr(target)+" has NOT been found!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
//Double: Search insert after
{   int target = StrToInt(Edit8->Text);
	int element = StrToInt(Edit7->Text);
	struct Dnode * p;
	p = SearchDList(target);
	if (p) InsertDListAfter(element, p);
	else Form1->Memo4->Lines->Add(IntToStr(target)+" has NOT been found!");
	PrintDList(head);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
////Double: Search insert before
{   int target = StrToInt(Edit8->Text);
	int element = StrToInt(Edit7->Text);
	struct Dnode * p;
	p = SearchDListBefore(target);
	if (p) InsertDListAfter(element, p);
	else Form1->Memo4->Lines->Add(IntToStr(target)+" has NOT been found!");
	PrintDList(head);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
////Double: Search Delete
{   int target = StrToInt(Edit8->Text);
	struct Dnode * p;
	p = SearchDListBefore(target);
	if (p) DeleteDListAfter(p);
	else Form1->Memo4->Lines->Add(IntToStr(target)+" has NOT been found!");
	PrintDList(head);
}
//---------------------------------------------------------------------------

