/* ≤‚ ‘Õÿ∆À≈≈–Ú */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
//#include "lwdgraph.h"
#include "ldgraph.h"
#include "topsort.h"

#define maxN 10000


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
      //GraphAdd(u,v,w,G);
      GraphAdd(u,v,G);
   }
   TopSort(G,V);
   for(int i=1;i<=n;i++)printf("%d ",V[i]);
   printf("\n");
   free(V); 
   return 0;
}

