/* 数组实现符号表 */ 
/* 
使用时前置语句 
#include "setitem.h"
#include "atable.h"
*/

#ifndef ATable_CLASS
#define ATable_CLASS

typedef struct atab *Table;
typedef struct atab{
    int arraysize;
    int last;
    SetItem *data;
}Atab;

Table TableInit(int size)
{
   Table T=(Table)malloc(sizeof *T);
   T->arraysize=size;
   T->last=0;
   T->data=(SetItem *)malloc(size*sizeof(SetItem));
   return T;
}

void TableAssign(Table A,Table B)
{
    A->last=B->last;
    for(int i=0;i<A->last;i++)A->data[i]=B->data[i];
}

int TableMember(SetItem x,Table T)
{
    for(int i=0;i<T->last;i++)
        if(T->data[i]==x)return 1 ;
    return 0;
}

void TableInsert(SetItem x,Table T)
{
   if(!TableMember(x,T) && T->last<T->arraysize)T->data[T->last++]=x;
}

void TableDelete(SetItem x,Table T)
{
    int i=0;
    if(T->last>0){
        while(T->data[i]!=x && i<T->last)i++;
        if(i<T->last && T->data[i]==x)T->data[i]=T->data[--T->last];
    }
}

void TableOut(Table T)
{
    for(int i=0;i<T->last;i++)SetItemShow(T->data[i]);
    printf("\n");
}

#endif
