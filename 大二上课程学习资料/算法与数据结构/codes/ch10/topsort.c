/* ≤‚ ‘Õÿ∆À≈≈–Ú */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "adigraph.h"

#define maxN 10000

static int cnt,pre[maxN];

void TSdfs(Graph D,int v,int ts[])
{ 
    pre[v]=0; 
    for(int w=0;w<D->n;w++)
      if(D->a[w][v] && pre[w])TSdfs(D,w,ts); 
    ts[cnt++]=v;
}

void TopSort(Graph D,int ts[])
{ 
    cnt=1;
    for(int v=0;v<=D->n;v++)pre[v]=1; 
    for(int v=1;v<=D->n;v++)
       if(pre[v])TSdfs(D,v,ts);
}

int main()
{
   int n,e,u,v,w,*V;
   Graph G;
   scanf("%d",&n);
   G=Graphinit(n);
   V=(int *)malloc((n+1)*sizeof(int));
   scanf("%d",&e);
   for(int i=1;i<=e;i++){
      scanf("%d %d %d",&u,&v,&w);
      GraphAdd(u,v,G);
   }
   TopSort(G,V);
   for(int i=1;i<=n;i++)printf("%d ",V[i]);
   printf("\n");
   return 0;
}

