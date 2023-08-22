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
	struct node * p; //�i�D�O�H�Y�N���ӫ��� = new struct node;
	p = (struct node *) malloc (sizeof(struct node)) ;     //����Ŷ�
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
//�o�̪��]�m�� ��Form��{�� �۰ʥͦ�
	first = NewNode(0); //�}�Y�ťո`�I   header node
	first->next = first; //������C�ͦ�  circular list
	last = first; //�ثe�u���}�Y�ťո`�I

	top = NewNode(0); //��stack���ǳ�
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
//��@�Ӧ�C���first��
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
//�w��Button�n��Ҧ����Gprint�X��
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
		if (p == first) return NULL ;   //�۷��¶�F�@��B���S���
		return p;  //�^�쥻����
}


struct node * SearchTargetBefore(int target)
{   struct node * p, * q;
	for(q=first, p=first->next; (p!=first && p->data!=target); q=p, p=p->next); //��q�û��bp�e��
		if (p == first) return NULL ;   //�۷��¶�F�@��B���S���
		return q;  //�^�쥻����
}

void InsertAfter(int element, struct node * x)
{   struct node * p = NewNode(element);
	p->next = x->next;
	x->next = p;
}

void DeleteAfter(struct node * x)
{   struct node *p = x->next;  //�]�@��p���nremove����
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
	last = first; //���s���L�@��last (�w�M�� last���w����first)
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
{   struct node * p = top->next;     //POP�B�z�᪺�Ĥ@��element
	if (p == top) return -1;
	int result = p->data;
	top->next = p->next; //��p free�����ǳ�
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
	x = SearchTargetBefore(target);   //�n���D�e���O����~��R��
	if (x) DeleteAfter(x);
	else   Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	PrintList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
//Insert N Ramdom numbers
{  int n = StrToInt(Edit3->Text);
   int range = StrToInt(Edit4->Text);
   int * data = new int [n]; //���ͤ��üƥ���b��
   String line = "";
   for(int i=0; i<n; i++)
   { data[i] = rand() % range + 1;  //random�����G��1 ~ range
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

