// 双空间模拟结构类型
#include "snode.h"

typedef struct dspace *Space;/* 双模拟空间指针类型 */
typedef struct dspace{/* 双模拟空间结构类型 */
   int num,/* 可用数组空间大小 */
   first1, /* 第一可用数组单元下标 */
   first2;/* 第二可用数组单元下标 */
   link node;/* 可用空间数组 */
}Dspace;

Space SpaceInit(int max);
int SpaceAllocate(Space s);
void SpaceDeallocate(int i,Space s);

Space SpaceInit(int max)
{
   Space s=(Space)malloc(sizeof *s);
   s->num=max;
   s->node=(link)malloc(max*(sizeof *s->node));
   s->first1=0;
   s->first2=-1;
   return s;
}

int SpaceAllocate(Space s)
{
   if(s->first2==-1)return s->first1++;
   int i=s->first2;
   s->first2=s->node[i].next;
   return i;
}

void SpaceDeallocate(int i,Space s)
{
   s->node[i].next=s->first2;
   s->first2=i;
}

