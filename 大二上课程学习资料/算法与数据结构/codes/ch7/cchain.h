// 单循环链表
/* 
使用时前置语句 
#include "listitem.h"
#include "cchain.h"
*/

#include "ccnode.h"

List ListInit()
{
   List L=(List)malloc(sizeof *L);
   link y=NewNode();
   y->next=y;
   L->last=y;
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
   int i=1;
   if(k<1 || k>L->n)return 0;/* 越界 */
   link p=L->last->next->next;
   while(i<k){
      p=p->next;
      i++;
   }
   return p->element;
}

int ListLocate(ListItem x,List L)
{
   int i=1;
   link p=L->last->next->next;
   L->last->next->element=x;
   while(p->element!=x){
      p=p->next;
      i++;
   }
   return((p==L->last->next)?0:i);
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0 || k>L->n)return;/* 越界 */
   link p=L->last->next;
   for(int i=1;i<=k;i++)p=p->next;
   link y=NewNode();
   y->element=x;
   y->next=p->next;
   p->next=y;
   if(k==L->n)L->last=y;
   L->n++;
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* 越界 */
   link q=L->last->next;
   for(int i=0;i<k-1;i++)q=q->next;
   link p=q->next;
   q->next=p->next;
   if(k==L->n)L->last=q;
   ListItem x=p->element;
   free(p);
   L->n--;
   return x;
}


void PrintList(List L)
{
   for (link p=L->last->next->next;p!=L->last->next;p=p->next)
	   ItemShow(p->element);
}

void IterInit(List L)
{
   L->curr=L->last->next;
}

void IterNext(List L)
{
   L->curr=L->curr->next;
   if (L->curr==L->last) L->curr=L->curr->next;
}

ListItem *CurrItem(List L)
{
   if(L->n==0)return 0;
   else return &L->curr->next->element;
}

void InsertCurr(ListItem x,List L)
{
   link y=NewNode();
   y->element=x;
   y->next=L->curr->next;
   L->curr->next=y;
   if (L->curr==L->last) L->last=y;
   L->n++;
}

ListItem DeleteCurr(List L)
{
   link q=L->curr;
   link p=q->next;
   q->next=p->next;
   if(p==L->last){L->last=q;L->curr=L->curr->next;}
   ListItem x=p->element;
   free(p);
   L->n--;
   return x;
}
