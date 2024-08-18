// 用间接寻址实现表
/* 
使用时前置语句 
#include "listitem.h"
#include "indlist.h"
*/

#include "indnode.h"

List ListInit(int size)
{
   List L=(List)malloc(sizeof *L);
   L->n=0;
   L->maxsize=size;
   L->table=(addr *)malloc(size*sizeof(addr));
   return L;
}

void ListFree(List L)
{
    free(L->table);
    free(L);
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
   return *L->table[k-1];
}

int ListLocate(ListItem x,List L)
{
   for(int i=0;i<L->n;i++)
     if(*L->table[i]==x)return ++i;
   return 0;
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0 || k>L->n)return;/* 越界 */
   for(int i=L->n-1;i>=k;i--)L->table[i+1]=L->table[i];
   L->table[k]=NewNode();
   *L->table[k]=x;
   L->n++;
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* 越界 */
   addr p=L->table[k-1];
   ListItem x=*p;
   for(int i=k;i<L->n;i++) L->table[i-1]=L->table[i];
   L->n--;
   free(p);
   return x;
}

void PrintList(List L)
{
   for (int i=0;i<L->n;i++)ItemShow(*L->table[i]);
}

void IterInit(List L)
{
   L->curr=0;
}

void IterNext(List L)
{
   L->curr=(L->curr+1)%L->n;
}

ListItem *CurrItem(List L)
{
   return L->table[L->curr];
}

ListItem DeleteCurr(List L)
{
   addr p=L->table[L->curr];
   ListItem x=*p;
   for(int i=L->curr;i<L->n-1;i++)L->table[i]=L->table[i+1];
   L->n--;
   L->curr=L->curr%L->n;
   free(p);
   return x;
}
