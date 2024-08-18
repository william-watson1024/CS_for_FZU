// 用游标实现表
/* 
使用时前置语句 
#include "listitem.h"
#include "schain.h"
*/

#include "dsimul.h"
//#include "simul.h"
#include "simunode.h"

List ListInit(int size)
{
   List L=(List)malloc(sizeof *L);
   L->s=SpaceInit(size);
   L->first=-1;
   return L;
}

int ListEmpty(List L)
{
   return L->first==-1;
}

int ListLength(List L)
{
   int i=L->first,len=0;
   while(i!=-1){
     len++;
     i=L->s->node[i].next;
   }
   return len;
}

ListItem ListRetrieve(int k,List L)
{
   int p,i=1;
   if(k<1)return 0;
   p=L->first;
   while(i<k && p!=-1){
      p=L->s->node[p].next;
      i++;
   }
   return L->s->node[p].element;
}

int ListLocate(ListItem x,List L)
{
   int p,i=1;
   p=L->first;
   while(p!=-1 && L->s->node[p].element!=x) {
      p=L->s->node[p].next;
      i++;
   }
   return ((p >= 0) ? i : 0);
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0)return;
   int p=L->first;
   for(int i=1;i<k && p!=-1;i++)p=L->s->node[p].next;
   int y=SpaceAllocate(L->s);
   L->s->node[y].element=x;
   if(k){
      L->s->node[y].next=L->s->node[p].next;
      L->s->node[p].next=y;
   }
   else{
      L->s->node[y].next=L->first;
      L->first=y;
   }
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || L->first==-1)return 0;/* 越界 */
   int p=L->first;
   if(k==1)L->first=L->s->node[p].next;
   else{
      int q=p;
      for(int i=1;i<k-1 && q!=-1;i++)q=L->s->node[q].next;
      p=L->s->node[q].next;
      L->s->node[q].next=L->s->node[p].next;
   }
   ListItem x=L->s->node[p].element;
   SpaceDeallocate(p,L->s);
   return x;
}

void PrintList(List L)
{
   for(int p=L->first;p!=-1;p=L->s->node[p].next)
      ItemShow(L->s->node[p].element);
}

void IterInit(List L)
{
   L->curr=L->first;
   if(L->curr==-1)return;
   while(L->s->node[L->curr].next!=-1)L->curr=L->s->node[L->curr].next;
   L->last=L->curr;
}

void IterNext(List L)
{
   if(L->s->node[L->curr].next!=-1)L->curr=L->s->node[L->curr].next;
   else L->curr=L->first;
}

ListItem *CurrItem(List L)
{
   if(L->first==-1)return 0;
   if(L->curr==L->last)return &L->s->node[L->first].element;
   else return &L->s->node[L->s->node[L->curr].next].element;
}

ListItem DeleteCurr(List L)
{
   int p,q=L->curr;
   if(q==L->last){
     p=L->first;
     L->first=L->s->node[p].next;
   }
   else{
     p=L->s->node[q].next;
     L->s->node[q].next=L->s->node[p].next;
     if(p==L->last)L->last=q;
     }
   ListItem x=L->s->node[p].element;
   SpaceDeallocate(p,L->s);
   return x;
}

void ListFree(List L)
{
    free(L);
}

