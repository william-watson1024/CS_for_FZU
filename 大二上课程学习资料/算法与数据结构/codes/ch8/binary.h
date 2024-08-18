/* 二叉树 */ 

/* 
使用时前置语句 
#include "treeitem.h"
#include "binary.h"
*/

int count;

#include "btnode.h"
#include "stackitem.h"
#include "lstack.h"
#include "qitem.h"
#include "lqueue.h"

BinaryTree BinaryInit()
{
   BinaryTree T=(BinaryTree)malloc(sizeof *T);
   T->root=0;
   return T;
}

int BinaryEmpty(BinaryTree T)
{
    return T->root == 0;
}

TreeItem Root(BinaryTree T)
{/* 前提：树非空 */
    return T->root->element;
}

void MakeTree(TreeItem x,BinaryTree T,BinaryTree L,BinaryTree R)
{/* 构建新二叉树 */
   T->root=NewBNode();
   T->root->element=x;
   T->root->left=L->root;
   T->root->right=R->root;
   L->root=R->root=0;
}

TreeItem BreakTree(BinaryTree T,BinaryTree L,BinaryTree R)
{/* 二叉树拆分 前提：树非空  */
   TreeItem x=T->root->element;
   L->root=T->root->left;
   R->root=T->root->right;
   T->root=0;
   return x;
}

void PreOrder(void(*visit)(btlink u),btlink t)
{/* 前序遍历 */
   if(t){
        (*visit)(t);
        PreOrder(visit,t->left);
        PreOrder(visit,t->right);
    }
}

void InOrder(void(*visit)(btlink u),btlink t)
{/* 中序遍历 */
   if(t){
        InOrder(visit,t->left);
        (*visit)(t);
        InOrder(visit,t->right);
    }
}

void PostOrder(void(*visit)(btlink u),btlink t)
{/* 后序遍历 */
   if(t){
        PostOrder(visit,t->left);
        PostOrder(visit,t->right);
        (*visit)(t);
    }
}

void PreOrder1(void(*visit)(btlink u),btlink t)
{/* 非递归前序遍历 */
    Stack s=StackInit();
    Push(t,s);
    while(!StackEmpty(s)){
       (*visit)(t=Pop(s));
       if(t->right)Push(t->right,s);
       if(t->left)Push(t->left,s);
    }
}

void LevelOrder(void(*visit)(btlink u),btlink t)
{/* 层序遍历 */
   Queue q=QueueInit();
   EnterQueue(t,q);
   while(!QueueEmpty(q)){
        (*visit)(t=DeleteQueue(q));
        if(t->left)EnterQueue(t->left,q);
        if(t->right)EnterQueue(t->right,q);
    }
}

int Size(btlink t)
{
   if(!t)return 0;
   return Size(t->left)+Size(t->right)+1;
}

void Add1(btlink t) {count++;}

int Size1(btlink t)
{
   count=0;
   PreOrder(Add1, t);
   return count;
}

int Height(btlink t)
{/* 二叉树的高度 */
   int hl,hr;
   if(!t)return -1;/* 空树 */
   hl=Height(t->left);/* 左子树的高度 */
   hr=Height(t->right);/* 右子树的高度 */
   if(hl>hr)return ++hl;
   else return ++hr;
}

void outnode(btlink t)
{
   TreeItemShow(t->element);
}

void PreOut(BinaryTree T)
{
   PreOrder(outnode,T->root);
}

void InOut(BinaryTree T)
{
   InOrder(outnode,T->root);
}

void PostOut(BinaryTree T)
{
   PostOrder(outnode,T->root);
}

void LevelOut(BinaryTree T)
{
   LevelOrder(outnode,T->root);
}
