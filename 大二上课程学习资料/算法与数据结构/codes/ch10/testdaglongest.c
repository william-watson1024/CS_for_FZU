/* 测试DAG的多源最长路径 */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "lwdgraph.h"
#include "daglongest.h"

int main()
{
   int i,n,e,u,v,w,*path;
   glink t;
   WItem *c;
   Graph G;
   scanf("%d",&n);
   G=Graphinit(n);
   path=(int *)malloc((n+1)*sizeof(int));
   c=(WItem *)malloc((n+1)*sizeof(WItem));
   scanf("%d",&e);
   for(i =1;i<=e;i++) {
      scanf("%d %d %d",&u,&v,&w);
      GraphAdd(u,v,w,G);
   }
   //GraphOut(G);
   for(v=1;v<=G->n;v++) 
	   for(t=G->adj[v];t;t=t->next)
		   in[t->v]++;
   for(i=1;i<=n;i++) {if(in[i]) c[i]=minW;else c[i]=0;}
   for(i=0;i<=n;i++)path[i]=0;
   longest(G,path,c);
   for(i=1;i<=n;i++)printf("%d  ",c[i]);
   printf("\n");
   return 0;
}

