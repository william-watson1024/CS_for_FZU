/* 开散列表 */
/* 
使用时前置语句 
#include "setitem.h"
#include "linkedhash.h"
*/

#ifndef HASH_TABLE_CLASS
#define HASH_TABLE_CLASS

#include "listitem.h"
#include "cchain.h"

typedef struct open *OpenHashTable;/* 开散列表 */
typedef struct open{
      int size;/* 桶数组的大小 */
      int(*hf)(SetItem x);/* 散列函数 */
      List *ht;/* 桶数组 */
}Open;

OpenHashTable HTInit(int nbuckets,int(*hashf)(SetItem x))
{/* 创建空开散列表 */
   OpenHashTable H=(OpenHashTable)malloc(sizeof *H);
   H->size=nbuckets;
   H->hf=hashf;
   H->ht=(List *)malloc(H->size*sizeof(List));
   for(int i=0;i<H->size;i++)
      H->ht[i]=ListInit();
   return H;
}

int HTMember(SetItem x,OpenHashTable H)
{/* 成员查询 */
   int i=(*H->hf)(x)%H->size;
   return(ListLocate(x,H->ht[i])>0);
}

void HTInsert(SetItem x,OpenHashTable H)
{/* 插入元素 */
   if(HTMember(x,H))return;
   int i=(*H->hf)(x)%H->size;
   ListInsert(0,x,H->ht[i]);
}

void HTDelete(SetItem x,OpenHashTable H)
{/* 删除元素 */
   int i,k;
   i=(*H->hf)(x)%H->size;
   if(k=ListLocate(x,H->ht[i]))ListDelete(k,H->ht[i]);
}

void HTOutput(OpenHashTable H)
{
    for(int i=0;i<H->size;i++){
        printf("i= %d\n",i);
        PrintList(H->ht[i]);
        printf("\n");
    }
}

#endif 
