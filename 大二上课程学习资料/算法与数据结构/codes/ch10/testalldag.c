/* 测试DAG所有顶点对最短路 */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "lwdgraph.h"
#include "alldag.h"

int main()
{
   int n,e,u,v,w,**path;
   glink t;
   WItem **c;
   Graph G;
   scanf("%d",&n);
   G=Graphinit(n);
   c=Make2DArray(n+1,n+1,maxW);
   path=Make2DArray(n+1,n+1,0);
   scanf("%d",&e);
   for(int i=1;i<=e;i++){
      scanf("%d %d %d",&u,&v,&w);
      GraphAdd(u,v,w,G);
   }
   GraphOut(G);
   AllShortes(G,c,path);
   for(int i=1;i<=n;i++){
	   for(int j=1;j<=n;j++)
		   printf("%d  ",c[i][j]);
	   printf("\n");
   }
   return 0;
}

