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
 {  struct Qnode *node;   //告訴別人即將有個指標 = new struct Qnode;
	node = (struct Qnode *) malloc(sizeof(struct Qnode)); //實體空間
	node->treenode = Tnode;
	node->next = NULL;
	if (front == NULL) front = node; //沒有東西的時候 加到front
	else rear->next = node; //有東西的狀況則加到後面
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
	while (p != NULL) //在p不等於NULL時進入 直到為NULL
	{ q = p;
		if (x == p->data) return 0; //考慮重複的狀況
		if (x < p->data)            //小->左邊
			p = p->leftchild;
		else                        //大->右邊
			p = p->rightchild;
	}
	p = new struct BSTnode;          //給其一BSTnode的大小
	p->data = x;                 //data為x
	p->leftchild = p->rightchild = NULL;  //左右都是NULL
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
	{   if (x == p->data) //找到X所在NODE
		{   if ((p->leftchild == NULL) && (p->rightchild == NULL))
			k = NULL;
			else if (p->leftchild != NULL) //X位於非子結點
			{	f = p;           //找到P左子樹的最右樹葉
				k = p->leftchild;
					while (k->rightchild != NULL)
					{   f = k;
						k = k->rightchild;
					}   //K移至P處
				if (p == f)
					f->leftchild = k->leftchild;
				else
					f->rightchild = k->leftchild;
			}
			else        //P無子樹的狀態
			{   f = p;  //找出P右子樹的最左樹葉
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
			if (k != NULL)   //k移動至P處繼承P的左右指標
			{   k->leftchild = p->leftchild;
				k->rightchild = p->rightchild;
			}
			if (father == NULL) root = k; //Father沒東西 K就是最上面的
			else if (x < father->data)  //x<father 去左邊
				father->leftchild = k;
			else                        //x>father 去右邊
				father->rightchild = k;
			free(p);
			return 1;   //刪除X 於此傳回1返回呼叫處
		}
		else //沒找到X 往下一層找
		{   father = p;
			if (x < p->data)
				p = p->leftchild;
			else
				p = p->rightchild;
		}
	}
	return 0; //未找到X 傳回0
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
		}   //Leftchild通通丟進去
		if (top != NULL)
		{   node = pop_node();
			tree += IntToStr(node->data)+"--";
			node = node->rightchild;
		}   //將其print出來 並確定rightchild
	}  while ((top != NULL) || (node != NULL));  //避免stack已空 或是沒有右子樹
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

