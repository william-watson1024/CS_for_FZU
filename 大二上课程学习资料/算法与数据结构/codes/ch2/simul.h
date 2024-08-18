// 模拟空间结构类型
#include "snode.h"

typedef struct space *Space;/* 模拟空间指针类型 */
typedef struct space{/* 模拟空间结构 */
   int num,/* 可用数组空间大小 */
       first;/* 可用数组单元下标 */
   link node;/* 可用空间数组 */
} Simul;

Space SpaceInit(int max);
int SpaceAllocate(Space s);
void SpaceDeallocate(int i,Space s);

Space SpaceInit(int max)
{
   Space s=(Space)malloc(sizeof *s);
   s->num=max;
   s->node=(link)malloc(max*(sizeof *s->node));
   for(int i=0;i<max-1;i++)s->node[i].next=i+1;
   s->node[max-1].next=-1;
   s->first=0 ;
   return s;
}

int SpaceAllocate(Space s)
{
   int i=s->first;
   s->first=s->node[i].next;
   return i;
}

void SpaceDeallocate(int i,Space s)
{
   s->node[i].next=s->first;
   s->first=i;
}

