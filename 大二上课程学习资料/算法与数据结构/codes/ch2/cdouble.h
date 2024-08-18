// 循环双链表实现 
/* 
使用时前置语句 
#include "listitem.h"
#include "cdouble.h"
*/

#include "dnode.h"

List ListInit()
{
   List L=(List)malloc(sizeof *L);
   link y=NewNode();
   y->left=y;
   y->right=y;
   L->header=y;
   L->n=0;
   return L;
}

int ListEmpty(List L)
{
   return L->n==0;
}

int ListLength(List L)
{
   return L->n;
}

ListItem ListRetrieve(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* 越界 */
   if(k==L->n)return L->header->left->element; 
   link p=L->header->right;
   for(int i=1;i<k;i++)p=p->right;
   return p->element;
}


int ListLocate(ListItem x,List L)
{
   int i=1;
   link p=L->header->right;
   L->header->element=x;
   while(p->element!=x){
      p=p->right;
      i++;
   }
   return((p==L->header)?0:i);
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0 || k>L->n)return;/* 越界 */
   link p=L->header;   
   if(k==L->n)p=L->header->left;
   else for(int i=1;i<=k;i++) p=p->right;
   link y=NewNode();
   y->element=x;
   y->left=p;
   y->right=p->right;
   p->right->left=y;
   p->right=y;
   L->n++;
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* 越界 */
   link p=L->header;
   if(k==L->n)p=L->header->left; 
   else for(int i=1;i<=k;i++)p=p->right;
   p->left->right=p->right;
   p->right->left=p->left;
   ListItem x=p->element;
   free(p);
   L->n--;
   return x;
}

void PrintList(List L)
{
   for(link p=L->header->right;p!=L->header;p=p->right)
	   ItemShow(p->element);
}

void IterInit(List L)
{
   L->curr=L->header;
}

void IterNext(List L)
{
   L->curr=L->curr->right;
   if(L->curr->right==L->header) L->curr=L->curr->right;
}

ListItem CurrItem(List L)
{
   if(L->n==0)return 0;
   else return L->curr->right->element;
}

ListItem DeleteCurr(List L)
{
   link p=L->curr->right;
   p->left->right=p->right;
   p->right->left=p->left;
   ListItem x=p->element;
   free(p);
   if(L->curr->right==L->header)L->curr=L->curr->right;
   L->n--;
   return x;
}

void ListFree(List L)
{	// 释放表空间 
   link p,q=L->header->right;
   while(q!=L->header){
        p=q->right;
		free(q);
		q=p;
    }
    free(L);
}
