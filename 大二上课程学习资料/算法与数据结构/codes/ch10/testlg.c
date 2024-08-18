/* 测试邻接表实现无向图 */

#include <stdio.h>
#include <stdlib.h>
#include "lgraph.h"

int main()
{
   Graph G=Graphinit(4);
   printf("边数 %d \n",GraphEdges(G));

   GraphAdd(2,4,G);
   GraphAdd(1,3,G);
   GraphAdd(2,1,G);
   GraphAdd(1,4,G);
   GraphAdd(3,2,G);

   printf("无向图 \n");

   GraphOut(G);
   GraphDelete(3,1,G);

   printf("删除 <3,1> \n");

   GraphOut(G);

   printf("Exist(3,1)=%d \n",GraphExist(3,1,G));
   printf("Degree(2)=%d \n",Degree(2,G));
   printf("边数 %d \n",GraphEdges(G));
   return 0;
}

