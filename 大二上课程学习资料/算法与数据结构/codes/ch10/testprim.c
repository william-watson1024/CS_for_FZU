/* 测试Prim算法 */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "awgraph.h"
#include "prim.h"

int main()
{
   WItem *lowcost;
   int *closest;

   Graph G=Graphinit(7, 100);

   GraphAdd(1,2,28,G);
   GraphAdd(1,6,10,G);
   GraphAdd(2,7,14,G);
   GraphAdd(2,3,16,G);
   GraphAdd(6,5,25,G);

   GraphAdd(7,5,24,G);
   GraphAdd(7,4,18,G);
   GraphAdd(3,4,12,G);
   GraphAdd(5,4,22,G);

   printf("输入图 \n");

   GraphOut(G);

   lowcost=(WItem *)malloc(7*sizeof(WItem));
   closest=(int *)malloc(7*sizeof(int));

   Prim(lowcost,closest,G);

   printf("closest= \n");
   for(int i=1;i<=7;i++)printf("%d  ",closest[i]);
   printf("\n");
   printf("lowcost= \n");
   for(int i=1;i<=7;i++)printf("%d  ",lowcost[i]);
   printf("\n");
   printf("最小支撑树 \n");
   for(int i=2;i<=7;i++)
      printf("%d %d %d \n",i,closest[i],lowcost[i]);
   return 0;
}

