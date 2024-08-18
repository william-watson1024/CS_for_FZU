/* 测试Kruskal算法 */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "awgraph.h"
#include "kruskal.h"

int main()
{
   Graph G=Graphinit(7,100);
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
   Edge *t=(Edge *)malloc(7*sizeof(Edge));
   Kruskal(t,G);
   printf("最小支撑树 \n");
   for(int i=0;i<6;i++)
         printf("%d %d %d \n",t[i].u,t[i].v,t[i].w);
    return 0;
}

