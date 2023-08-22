//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW06.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------

 struct BSTnode
 { struct BSTnode *leftchild;
   int data;
   struct BSTnode *rightchild;
 };
 struct BSTnode *root;

 struct Qnode
 { struct BSTnode *treenode;
   struct Qnode *next;
 };
 struct Qnode *front, *rear;

struct StackNode
{   struct BSTnode *treenode;

	struct StackNode *next;
};
struct StackNode *top;

//---------------------------------------------------------------------------

int count_node;
String tree;


//Using Queue for LevelOrder-------------------------------------------------

void QEmpty()
 {   Form1->Memo1->Lines->Add("Queue is Empty!!");}

 void AddQ(struct BSTnode *Tnode)
 {  struct Qnode *node;   //�i�D�O�H�Y�N���ӫ��� = new struct Qnode;
	node = (struct Qnode *) malloc(sizeof(struct Qnode)); //����Ŷ�
	node->treenode = Tnode;
	node->next = NULL;
	if (front == NULL) front = node; //�S���F�誺�ɭ� �[��front
	else rear->next = node; //���F�誺���p�h�[��᭱
	rear = node;
 }

struct BSTnode *DeleteQ()
{   struct BSTnode *Tnode;
	struct Qnode *old_front;
	if (rear == NULL)
		QEmpty();
	else
	{   Tnode = front->treenode;
		old_front = front;
		front = front->next;
		free(old_front);
		return Tnode;
	}
}

//Level order
void LevelOrder(struct BSTnode *node)
{ AddQ(node);
  while (front != NULL)
  { node = DeleteQ();
	tree += IntToStr(node->data)+"__";
	if (node->leftchild != NULL)
		AddQ(node->leftchild);
	if (node->rightchild != NULL)
		AddQ(node->rightchild);
  }
}
//Using Queue for LevelOrder-------------------------------------------------

//InsertBST
int InsertBST(int x)
{	struct BSTnode *p, *q;
	p = root; q = NULL;
	while (p != NULL) //�bp������NULL�ɶi�J ���쬰NULL
	{ q = p;
		if (x == p->data) return 0; //�Ҽ{���ƪ����p
		if (x < p->data)            //�p->����
			p = p->leftchild;
		else                        //�j->�k��
			p = p->rightchild;
	}
	p = new struct BSTnode;          //����@BSTnode���j�p
	p->data = x;                 //data��x
	p->leftchild = p->rightchild = NULL;  //���k���ONULL
	if (root == NULL)
	{ root = p;
	  count_node++;
	}
	else if (x < q->data)
	{ q->leftchild = p;
	  count_node++;
	}
	else
	{ q->rightchild = p;
	  count_node++;
	}
	return 1;
}

//DeleteBST
int DeleteBST(int x)
{   struct BSTnode *p, *father, *k, *f;
	p = root; father = NULL;
	while (p != NULL)
	{   if (x == p->data) //���X�ҦbNODE
		{   if ((p->leftchild == NULL) && (p->rightchild == NULL))
			k = NULL;
			else if (p->leftchild != NULL) //X���D�l���I
			{	f = p;           //���P���l�𪺳̥k��
				k = p->leftchild;
					while (k->rightchild != NULL)
					{   f = k;
						k = k->rightchild;
					}   //K����P�B
				if (p == f)
					f->leftchild = k->leftchild;
				else
					f->rightchild = k->leftchild;
			}
			else        //P�L�l�𪺪��A
			{   f = p;  //��XP�k�l�𪺳̥���
				k = p->rightchild;
				while (k->leftchild != NULL)
				{   f = k;
					k = k->leftchild;
				}
				if (p == f)
					f->rightchild = k->rightchild;
				else
					f->leftchild = k->rightchild;
			}
			if (k != NULL)   //k���ʦ�P�B�~��P�����k����
			{   k->leftchild = p->leftchild;
				k->rightchild = p->rightchild;
			}
			if (father == NULL) root = k; //Father�S�F�� K�N�O�̤W����
			else if (x < father->data)  //x<father �h����
				father->leftchild = k;
			else                        //x>father �h�k��
				father->rightchild = k;
			free(p);
			return 1;   //�R��X �󦹶Ǧ^1��^�I�s�B
		}
		else //�S���X ���U�@�h��
		{   father = p;
			if (x < p->data)
				p = p->leftchild;
			else
				p = p->rightchild;
		}
	}
	return 0; //�����X �Ǧ^0
}

//Inorder+print  (Recursive)
 void inorder_Print(struct BSTnode *node)
 { if (node != NULL)
	{ inorder_Print(node->leftchild);
	  tree+= IntToStr(node->data)+"--";
	  inorder_Print(node->rightchild);
	}
 }

//Preorder+Print  (Recursive)
void preorder_Print(struct BSTnode *node)
{  if (node != NULL)
	{ tree += IntToStr(node->data)+"--";
	  preorder_Print(node->leftchild);
	  preorder_Print(node->rightchild);
	}
}

//Postorder+Print  (Recursive)
void postorder_Print(struct BSTnode *node)
{  if (node != NULL)
	{ postorder_Print(node->leftchild);
	  postorder_Print(node->rightchild);
	  tree += IntToStr(node->data)+"--";
	}
}

//Search BST (Non-recursive)
struct BSTnode *searchBST (struct BSTnode *node, int x)
{
   *node = *root;
   while (node != NULL && x != node->data)
   {    if (x< node->data)
			node = node->leftchild;
		else
			node = node->rightchild;
   }
   return node;
}

void StackEmpty()
 {   Form1->Memo1->Lines->Add("Stack is Empty!!");}

//------------------non-recursive order----------------------------------------
//Stacknode_push
void push_node(struct BSTnode *node )
{ struct StackNode *old_top;
  old_top = top;
  top = (struct StackNode *) malloc (sizeof(struct StackNode));
  top->treenode = node;
  top->next = old_top;
}

//Stacknode_pop
struct BSTnode *pop_node()
{ struct BSTnode *Tnode;
  struct StackNode *old_top;
  if (top == NULL) StackEmpty();
  else
  {  Tnode = top->treenode;
	 old_top = top;
	 top = top->next;
	 free(old_top);
	 return Tnode;
  }
}

//Inorder_non_recursive
void inorder_stack(struct BSTnode *node)
{   do
	{   while (node != NULL)
		{   push_node(node);
			node = node->leftchild;
		}   //Leftchild�q�q��i�h
		if (top != NULL)
		{   node = pop_node();
			tree += IntToStr(node->data)+"--";
			node = node->rightchild;
		}   //�N��print�X�� �ýT�wrightchild
	}  while ((top != NULL) || (node != NULL));  //�קKstack�w�� �άO�S���k�l��
}

//Preorder-non_recursive
void Preorder_Stack(struct BSTnode * node)
{  do
   { while (node != NULL)
	 {   tree += IntToStr(node->data)+"--";
		 push_node(node);
		 node = node->leftchild;
	 }   // push all left children
	 if (top != NULL)
	 {   node = pop_node();
		 node = node->rightchild;
	 }
   } while ((top!=NULL)||(node!=NULL));
}

//Postorder_non_recursive
void Postorder_Stack(struct BSTnode * node)
{  do
   {  while (node != NULL)
	  {   tree = IntToStr(node->data)+"--"+tree;
		  push_node(node);
		  node = node->rightchild;
	  }   // push all left children
	  if (top != NULL)
	  {   node = pop_node();
		  node = node->leftchild;
	  }
  } while ((top!=NULL)||(node!=NULL));
}

//Clean
void Clear_BST(struct BSTnode *BSTnode)
{   if(BSTnode != NULL)
	{   Clear_BST(BSTnode->leftchild);
		Clear_BST(BSTnode->rightchild);
		delete(BSTnode);
	}
}


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
//Insert and Present Inorder outcome
{
   int data = StrToInt(Edit1->Text);
   int success = InsertBST(data);
   if(!success)
		Memo1->Lines->Add("FAIL to insert: "+IntToStr(data));
   else
   {  tree = "";
	  inorder_Print(root);
	  Memo1->Lines->Add("Inorder(Recursively): "+tree);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
//Change BST to Preorder
{  tree = "";
   preorder_Print(root);
   Memo1->Lines->Add("Preorder(Recursively): " +tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
//Change BST to Postorder
{  tree = "";
   postorder_Print(root);
   Memo1->Lines->Add("Postorder(Recursively): " +tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
//Change BST to Level order
{  tree = "";
   LevelOrder(root);
   Memo1->Lines->Add("Level order(Recursively): " +tree);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
//Delete specific target in BST
{  int target = StrToInt(Edit2->Text);
   int success = DeleteBST(target);
   if(success)
		Memo1->Lines->Add(IntToStr(target)+" has been deleted!");
   else
		Memo1->Lines->Add(IntToStr(target)+" has NOT been found in BST!");
	tree = "";
	inorder_Print(root);
	Memo1->Lines->Add("Inorder(Recursively): "+tree);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
//Search target in BST
{  int target = StrToInt(Edit3->Text);
   struct BSTnode *success = searchBST(root, target);
   if(success != NULL)
		Memo1->Lines->Add("The target you searched ("+IntToStr(target)+ ") is in BST");
   else
		Memo1->Lines->Add("The target you searched (" +IntToStr(target)+ ") is NOT in BST");
   tree = "";
   inorder_Print(root);
   Memo1->Lines->Add("Inorder(Recursively): "+tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
//Insert random numbers
{   int n = StrToInt(Edit4->Text);
	int *data = new int[n];
	String string = "";
	int range_min = Edit5->Text.ToInt();
	int range_max = Edit6->Text.ToInt();
	for(int i = 0; i<n; i++)
	{   data[i] = rand()%(range_max-range_min+1)+range_min;
		int success = InsertBST(data[i]);
		string += IntToStr(data[i])+"-";
	}
	Memo1->Lines->Add(string);
	tree = "";
	inorder_Print(root);
	Memo1->Lines->Add("Inorder(Recursively): "+tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
//Clean BST
{	Memo1->Text = "";
	Clear_BST(root);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
//Inorder_non recursive
{   tree = "";
	inorder_stack(root);
	Memo1->Lines->Add("Inorder (nonrecursively): "+tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{   tree = "";
	Preorder_Stack(root);
	Memo1->Lines->Add("Preorder (nonrecursively):"+tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{   tree = "";
	Postorder_Stack(root);
	Memo1->Lines->Add("Postorder(nonrecursively):"+tree);
}
//---------------------------------------------------------------------------

