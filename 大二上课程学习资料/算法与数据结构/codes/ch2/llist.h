// 用数组实现表
/* 
使用时前置语句 
#include "listitem.h"
#include "llist.h"
*/

typedef struct alist *List;/* 单链表指针类型 */
typedef struct alist{
      int n, /* 表长 */
          curr;/* 当前位置 */
      int maxsize;/* 数组上界 */
      ListItem *table;/* 存储表元素的数组 */ 
}Alist;

List ListInit(int size);                  /* 表结构初始化 */
int ListEmpty(List L);                    /* 测试表L是否为空 */
int ListLength(List L);                   /* 表L的长度 */
ListItem ListRetrieve(int k,List L);      /* 返回表L的位置k处的元素 */
int ListLocate(ListItem x,List L);        /* 元素x在表L中的位置 */
void ListInsert(int k,ListItem x,List L); /* 在表L的位置k之后插入元素x */
ListItem ListDelete(int k,List L);        /* 从表L中删除位置k处的元素 */
void PrintList(List L);                   /* 按位置次序输出表L中元素 */

List ListInit(int size)
{
   List L=(List)malloc(sizeof *L);
   L->table=(ListItem *)malloc(size*sizeof(ListItem));
   L->maxsize=size;
   L->n=0;
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
   return L->table[k-1];
}

int ListLocate(ListItem x,List L)
{
   for(int i=0;i<L->n;i++)
     if(L->table[i]==x)return ++i;
   return 0;
}

void ListInsert(int k,ListItem x,List L)
{
   if(k<0 || k>L->n)return;/* 越界 */
   for(int i=L->n-1;i>=k;i--)L->table[i+1]=L->table[i];
   L->table[k]=x;
   L->n++;
}

ListItem ListDelete(int k,List L)
{
   if(k<1 || k>L->n)return 0;/* 越界 */
   ListItem x=L->table[k-1];
   for(int i=k;i<L->n;i++)L->table[i-1]=L->table[i];
   L->n--;
   return x;
}

void PrintList(List L)
{
   for(int i=0;i<L->n;i++)ItemShow(L->table[i]);
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
   return &L->table[L->curr];
}

void InsertCurr(ListItem x,List L)
{
   ListInsert(L->curr,x,L);
}

ListItem DeleteCurr(List L)
{
   ListItem x=ListDelete(L->curr+1,L);
   L->curr=L->curr%L->n;
   return x;
}


