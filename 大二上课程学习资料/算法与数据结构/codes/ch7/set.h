/* 位向量集合 */
/* 
使用时前置语句 
#include "set.h"
*/

#ifndef SET_CLASS
#define SET_CLASS

typedef struct bitset *Set;/* 位向量集合指针类型 */
typedef struct bitset{/* 位向量集合 */
    int setsize;/* 集合大小 */
    int arraysize;/* 位数组大小 */
    unsigned short *v;/* 位数组 */
}Bitset;

int ArrayIndex(int x)
{/* 右移4位获得x在数组中的位置 */
    return x>>4;
}

unsigned short BitMask(int x)
{/* 确定x在相应数组单元中的准确位置 */
    return 1<<(x&15);
}

Set SetInit(int size)
{/* 创建一个用位向量实现的空集 */
   Set S=(Set)malloc(sizeof *S);
   S->setsize=size;
   /* 存储大小为setsize的集合所需的无符号短整数位数 */
   S->arraysize=(size+15)>>4;
   S->v=(unsigned short *)malloc(size*sizeof(unsigned short));
   /* 初始化为空集 */
   for(int i=0;i<size;i++)S->v[i]=0;
   return S;
}

void SetAssign(Set A,Set B)
{/* 集合赋值运算 */
    if(A->setsize!=B->setsize)return;
    for(int i=0;i<A->arraysize;i++)A->v[i]=B->v[i];
}

int SetMember(int x,Set S)
{/* 成员属性判断 */
    if(x<0 || x>=S->setsize)return 0;
    return S->v[ArrayIndex(x)]&BitMask(x);
}

int SetEqual(Set A,Set B)
{/* 判定集合A和B是否相等 */
    if(A->setsize!=B->setsize)return 0;
    int retval=1;
    for(int i=0;i<A->arraysize;i++)
        if(A->v[i] != B->v[i]){
            retval=0;
            break;
        }
    return retval;
}

Set SetUnion (Set A,Set B)
{/* 并集运算 */
    Set tmp=SetInit(A->setsize);
    for(int i=0;i<A->arraysize;i++)
        tmp->v[i]=A->v[i] | B->v[i];
    return tmp;
}

Set SetIntersection(Set A,Set B)
{/* 交集运算 */
    Set tmp=SetInit(A->setsize);
    for(int i=0;i<A->arraysize;i++)
        tmp->v[i]=A->v[i] & B->v[i];
    return tmp;
}

Set SetDifference(Set A,Set B)
{/* 差集运算 */
    Set tmp=SetInit(A->setsize);
    for(int i=0;i<A->arraysize;i++)
        tmp->v[i]= A->v[i]^(B->v[i] & A->v[i]);
    return tmp;
}

void SetInsert(int x,Set S)
{/* 插入运算 */
    if(x<0 || x>=S->setsize)return;
    S->v[ArrayIndex(x)] |= BitMask(x);
}

void SetDelete(int x, Set S)
{/* 删除运算 */
    if(x<0 || x>=S->setsize)return;
    S->v[ArrayIndex(x)]&=~BitMask(x);
}

void SetOut(Set S)
{/* 输出集合元素 */
    for(int i=0;i<S->setsize;i++)
      if(S->v[ArrayIndex(i)] & BitMask(i))printf(" %d ",i);
    printf("\n");
}

#endif
