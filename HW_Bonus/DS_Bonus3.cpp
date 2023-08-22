//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DS_Bonus3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define SIZE 100

String Stack1[SIZE];
String Stack2[SIZE];

int TOP1 = -1;
int TOP2 = -1;

void Tracing()
//��V�ɱN�U�B�Jprint�X��
{   int i;
	String data1 = "", data2 = "";
	for(i=0; i<=TOP1; i++)
		data1 += Stack1[i]+"  ";
	for(i=0; i<TOP2; i++)
		data2 += Stack2[i]+"  ";
	Form1->Memo1->Lines->Add("Stack1 -> "+data1);
	Form1->Memo1->Lines->Add("Stack2 -> "+data2);
}

void push(int flag, String data)
//Push with flag to determine different situations
{ 	switch(flag)
	{   case(1):
			if (TOP1 == SIZE-1)
				Form1->Memo1->Lines->Add("Stack if FULL!");
			else
				Stack1[++TOP1]=data;
			break;
		case(2):
			if (TOP2 == SIZE-1)
				Form1->Memo1->Lines->Add("Stack is FULL!");
			else
				Stack2[++TOP2]=data;
			break;
	}
	if (Form1->CheckBox1->Checked)
		Tracing();
}

String pop(int flag)
//Pop with flag to determine different situations
{   switch(flag)
	{   case(1):
			if (TOP1 == -1)
				Form1->Memo1->Lines->Add("Stack is EMPTY!");
			else return Stack1[TOP1--];
			break;
		case(2):
			if (TOP2 == -1)
				Form1->Memo1->Lines->Add("Stack is EMPTY!");
			else return Stack2[TOP2--];
			break;
	}
}

int p(String OP)
//Stack�~���v��
{ if ((OP == '+')||(OP == '-')) return 3;
  if ((OP == '*')||(OP == '/')) return 4;
  if ((OP == '^')||(OP == '|')) return 5;
  if ((OP == '(')) return 8;
  if ((OP == '#')) return 0;
}

int q (String OP)
//Stack�����v��
{ if ((OP == '+')||(OP == '-')) return 3;
  if ((OP == '*')||(OP == '/')) return 4;
  if ((OP == '^')||(OP == '|')) return 5;
  if ((OP == '(')) return 1;
  if ((OP == '#')) return 0;
}

 void get_fix(String x, int flag)
 //�Q��flag �M�w����Prefix Postfix�ഫ
 {	String a = pop(2);
	a = (flag == 1) ? x+pop(2)+a : pop(2)+a+x;
	push (2, a);
 }

boolean IsOperand(String S)
//�P�_�O�_��Operand
 {	if ((S!="+") && (S!="-") && (S!="*") && (S!="/") && (S!="^")
		 && (S!="|") && (S!="(") && (S!=")")) return true;
	return false;
 }

String Transform(String infix, int flag)  //infix
{  int n = infix.Length();
   int i, j;
   String S, x;
   push(1, '#');     //���N#��i�h���|
   for (i=1;i<=n;i++)
   {    S = infix[i];
		if (IsOperand(S))
			push(2, S);
		else if (S == ')')   //�k�A�����ت����M�䥪�A��
			while ((x=pop(1))!="(") get_fix(x, flag);  //�Nstack���Ĥ@��(���e���B��l��POP�X�æL�X
		else
		{   while (p(S) <= q(Stack1[TOP1]))  // p() ���|�~ q()���|��
			{   x = pop(1);              //���j�����} pop�X�h
				get_fix(x, flag);
			}
			push (1, S);                   //�]���̭������񥦤p�F �ҥHpush�i�h
		}

   }
   while (Stack1[TOP1]!="#")
	{   x = pop(1);
		get_fix(x, flag);
	}
	pop(1);           //�̫�n��#pop�X�h �]���O�ƥ��[��
	return pop(2);
}

 String Prefix2Postfix_Reverse(String prefix)
 {  int n = prefix.Length();
	int i, count = 0;
	String S, post;
	for(i=n; i>=1; i--)
	{   S = prefix[i];
		if(IsOperand(S))
			push(2, S);
		else
		{   post = pop(2);
			post += pop(2)+S;
			push (2, post);
		}
	}
	return pop(2);
 }

 String Postfix2Prefix(String postfix)
 // Postfix2Prefix
 {	int n = postfix.Length();
	int i;
	String S, x;
	for(i=1; i<=n; i++)
	{   S = postfix[i];
		if(IsOperand(S))
			push(2, S);
		else get_fix(S, 1);
	}
    return pop(2);
 }

String Postfix2Infix(String postfix)
// Postfix2Infix
 {  int n = postfix.Length();
	int i;
	String S, S1, S2, x, y, prev = "#";
	for(i=1; i<=n; i++)
	{   S = postfix[i];
		if (IsOperand(S))    //�p�Goperand����� �hpush�i�h
		{   push(2, S);
            push(1, "#");
        }
		else                 //�Y�S��� �h��operand pop�X�h
		{   S1 = pop(1);
			S2 = pop(1);
			x = pop(2);
			y = pop(2);
			if (p(S) > p(S1) && x.Length()>1)
				x = "("+x+")";
			if (p(S) > p(S1) && y.Length()>1)
				y = "("+y+")";
			if (Form1->CheckBox1->Checked)
				Form1->Memo1->Lines->Add("p"+S+")="+IntToStr(p(S))+"("+S1+")="+
				IntToStr(p(S1))+"p("+S2+")="+IntToStr(p(S2))+" s1="+S1+" s2="+
				S2+" x="+x+" y="+y);
				push(2, y+S+x);
				push(1, S);
		}
    }
	while (TOP1 != -1)        // �̫����ӥu�Ѥ@�����bstack�� �B�Ӥ����ŦXinfix���Ƨ�
		x = pop(1);
    return pop(2);
 }



TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
//Infix2Postfix
{   String Infix = Edit1->Text;
    String infix =  Edit1->Text;
	String postfix = Transform(infix, 2);
	Edit2->Text = postfix;
	Memo1->Lines->Add("Infix:  "+infix);
	Memo1->Lines->Add("Prefix:  "+postfix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{   String infix =  Edit1->Text;
	String prefix = Transform(infix, 1);
	Edit3->Text = prefix;
	Memo1->Lines->Add("Infix:  "+infix);
	Memo1->Lines->Add("Prefix:  "+prefix);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{   String postfix;
	String prefix = Edit4->Text;
	Memo1->Lines->Add("Prefix:  "+prefix);
	postfix = Prefix2Postfix_Reverse(prefix);
	Edit5->Text = postfix;
	Memo1->Lines->Add("Postfix:  "+postfix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{   String infix;
	String prefix = Edit4->Text;
	String postfix = Edit5->Text;
	Memo1->Lines->Add("Prefix:  "+prefix);
	infix = Postfix2Infix(postfix);
	Edit6->Text = infix;
	Memo1->Lines->Add("Infix:  "+infix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{   String prefix;
	String postfix = Edit7->Text;
	Memo1->Lines->Add("Postfix:  "+postfix);
	prefix = Postfix2Prefix(postfix);
	Edit8->Text = prefix;
	Memo1->Lines->Add("Prefix:  "+prefix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{   String infix;
	String postfix = Edit7->Text;
	Memo1->Lines->Add("Postfix:  "+postfix);
	infix = Postfix2Infix(postfix);
	Edit9->Text = infix;
	Memo1->Lines->Add("Infix:  "+infix);
}
//---------------------------------------------------------------------------

