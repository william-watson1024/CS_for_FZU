/* ∑¥Õÿ∆À≈≈–Ú */

#include <stdio.h>
#include <stdlib.h>
#include "ldgraph.h"

#define maxN 10000

static int cnt,pre[maxN];

void TSdfs(Graph D,int v,int ts[])
{ 
    pre[v]=0; 
    for(glink t=D->adj[v];t;t=t->next)
      if(pre[t->v])TSdfs(D,t->v,ts); 
    ts[cnt++]=v;
}

void RevTopSort(Graph D,int ts[])
{ 
    cnt=1;
    for(int v=0;v<=D->n;v++)pre[v]=1; 
    for(int v=1;v<=D->n;v++)
      if(pre[v])TSdfs(D,v,ts);
}

int main()
{
   int i,n,e,u,v,w,*V;
   Graph G;
   scanf("%d",&n);
   G=Graphinit(n);
   V=(int *)malloc((n+1)*sizeof(int));
   scanf("%d",&e);
   for(i=1;i<=e;i++){
      scanf("%d %d %d",&u,&v,&w);
      GraphAdd(u,v,G);
   }
   RevTopSort(G,V);
   for(i=1;i<=n;i++)printf("%d ",V[i]);
   printf("\n");
   return 0;
}

