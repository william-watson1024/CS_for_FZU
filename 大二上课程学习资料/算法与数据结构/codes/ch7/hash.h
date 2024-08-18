/* 闭散列表 */
/* 
使用时前置语句 
#include "setitem.h"
#include "hash.h"
*/

#ifndef HashTable_
#define HashTable_

typedef struct hashtable *HashTable;
typedef struct hashtable{
      int size;/* 桶数组大小 */
      int (*hf)(SetItem x);/* 散列函数 */
      SetItem *ht;/* 桶数组 */
      int *state;/* 占用状态数组 */
}Hashtable;

HashTable HTInit(int div, int(*hashf)(SetItem x))
{/* 创建一个空散列表 */
   HashTable H=(HashTable)malloc(sizeof *H);
   H->size=div;
   H->hf=hashf;
   H->ht=(SetItem *)malloc(H->size*sizeof(SetItem));
   H->state=(int *)malloc(H->size*sizeof(int));
   for (int i=0;i<H->size;i++)H->state[i]=1;
   return H;
}

int HashProb(int i)
{/* 线性探测 */
   return i;
}

int FindMatch(SetItem x,HashTable H)
{/* 在桶数组中查找存储元素x的位置或遇空桶 */
    int j=(*H->hf)(x);/* 初始桶 */
    for(int i=0;i<H->size;i++){
        int k=(j+HashProb(i))%H->size;
        if(H->state[k]==1)break;
        if(!H->state[k] && eq(H->ht[k],x))return k;
    }
    return H->size;
}

int Unoccupied(SetItem x,HashTable H)
{/* 桶数组中可存储元素x的未占用桶单元位置 */
   int j=(*H->hf)(x);/* 初始桶 */
   for(int i=0;i<H->size;i++){
        int k=(j+HashProb(i))%H->size;
        if(H->state[k])return k;
    }
    return H->size;
}

int HTMember(SetItem x,HashTable H)
{/* 成员查询 */
    int i=FindMatch(x,H);
    if(i<H->size && eq(H->ht[i],x))return 1;
    return 0;
}

void HTInsert(SetItem x,HashTable H)
{/* 插入元素 */
   if(HTMember(x,H))return;
   int i=Unoccupied(x,H);/* 桶数组中的可插入位置 */
   if(i<H->size){/* 可插入 */
       H->state[i]=0;
       H->ht[i]=x;
   }
   else return;
}

void HTDelete(SetItem x,HashTable H)
{/* 删除元素 */
   int i=FindMatch(x,H);
   if(i<H->size && H->ht[i]==x)H->state[i]=2;
}

void HTDelete1(SetItem x,HashTable H)
{/* 填充被删除元素释放的桶空间 */
    int j,i=FindMatch(x,H);
    if(i<H->size && H->ht[i]==x)
        for(;;){
            H->state[i]=1;
            for(j=(i+1)%H->size;!H->state[j];j=(j+1)%H->size){
                int k=(*H->hf)(H->ht[j]);
                if((k<=i && i<j)||(i<j && j<k)||(j<k && k<=i))break;
            }
            if(H->state[j])break;
            H->ht[i]=H->ht[j];
            H->state[i]=H->state[j];
            i=j;
        }
}
 
void HTOutput(HashTable H)
{
   for(int i=0;i<H->size;i++){
      if(H->state[i]==1)printf("空桶 ");
      else if(H->state[i]==2)printf("已删除 ");
      else SetItemShow(H->ht[i]);
    }
}

#endif
