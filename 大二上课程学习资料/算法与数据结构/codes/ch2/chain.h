// 用指针实现表
/* 
使用时前置语句 
#include "listitem.h"
#include "chain.h"
*/

#include "cnode.h"

List ListInit()
{
   List L=(List)malloc(sizeof *L);
   L->first=0;
   return L;
}

int ListEmpty(List L)
{
   return L->first==0;
}

int ListLength(List L)
{
   int len=0;
   link p=L->first;
   while(p){
     len++;
     p=p->next;
   }
   return len;
}

ListItem ListRetrieve(int k,List L)
{
   if(k<1)return 0;
   link p=L->first;
   int i=1;
   while(i<k && p){
      p=p->next;
      i++;
    }
   return p->element;
}

int ListLocate(ListItem x,List L)
{
   int i=1;
   link p=L->first;
   while(p && p->element!=x){
      p=p->next;
      i++;
   }
   return p?i:0;
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0)return;
   link p=L->first;
   for(int i=1;i<k && p;i++)p=p->next;
   link y=NewNode();
   y->element=x;
   if(k){y->next=p->next;p->next=y;}
   else{y->next=L->first;L->first=y;}
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || !L->first)return 0;
   link p=L->first;
   if(k==1)L->first=p->next;
   else{
      link q=L->first;
      for(int i=1;i<k-1 && q;i++)q=q->next;
      p=q->next;
      q->next=p->next;
   }
   ListItem x=p->element;
   free(p);
   return x;
}

void PrintList(List L)
{
   for(link p=L->first;p;p=p->next)ItemShow(p->element);
}

void IterInit(List L)
{
   L->curr=L->first;
   if(L->curr==0)return;
   while(L->curr->next)L->curr=L->curr->next;
   L->last=L->curr;
}

void IterNext(List L)
{
   if(L->curr->next)L->curr=L->curr->next;
   else L->curr=L->first;
}

ListItem *CurrItem(List L)
{
   if(L->first==0)return 0;
   if(L->curr==L->last)return &L->first->element;
   else return &L->curr->next->element;
}

ListItem DeleteCurr(List L)
{
   link p,q=L->curr;
   if(q==L->last){
     p=L->first;
     L->first=p->next;
   }
   else{
     p=q->next;
     q->next=p->next;
     if(p==L->last)L->last=q;
   }
   ListItem x=p->element;
   free(p);
   return x;
}

void ListFree(List L)
{	// 释放表空间 
   link p,q=L->first;
   while(q){
        p=q->next;
		free(q);
		q=p;
    }
    free(L);
}






