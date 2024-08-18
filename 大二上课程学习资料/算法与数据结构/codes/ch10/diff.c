/* 差分约束系统 */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "lwdgraph.h"
#include "BellmanFord.h"

int n,e,*path,*dist;
Graph G;

void build()
{/* 构造差分约束有向赋权图 */
   int u,v,w;
   scanf("%d",&n);
   n++;
   G=Graphinit(n);
   dist=(int *)malloc((n+1)*sizeof(int));
   path=(int *)malloc((n+1)*sizeof(int));
   scanf("%d", &e);
   for(int i=1;i<=e;i++){
      scanf("%d %d %d", &v,&u,&w);
      GraphAdd(u,v,w,G);
   }
   for(int i=1;i<n;i++)GraphAdd(n,i,0,G);
}

int diff()
{/* 差分约束系统的解 */
   if(!BellmanFord(n, dist, path, G)){
	   printf("No solution!\n");
	   return 0;
   }
   for(int u=1;u<n;u++){
	   glink p=G->adj[u];
	   while(p){
		   int v=p->v;
		   int w=p->w;
		   if(dist[v]-dist[u]>w) {
			   printf("No solution!\n");
			   return 0;
		   }
		   //printf("%d - %d <= %d\n",dist[v],dist[u],w);
		   p=p->next;
	   }
   }
   return 1;
}

int out()
{/* 输出解 */
   int u=0,v=INT_MAX;
   for(int i=1;i<=n;i++){
	   if(dist[i]>u)u=dist[i];
	   if(dist[i]<v)v=dist[i];
   }
   return u-v;
}

int main()
{
   build();
   if(diff())printf("%d\n",out());
   return 0;
}
