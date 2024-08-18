/* 链图深度优先搜索 */

#include <stdio.h>
#include <stdlib.h>
#include "lgraph.h"

#define maxN 10000

static int cnt, pre[maxN];

void dfs(Graph G,int i)
{ 
    glink p;
    pre[i]=cnt++;
    for(p=G->adj[i];p;p=p->next)
      if(pre[p->v]==0)dfs(G,p->v);
}

void GraphSearch(Graph G)
{
    cnt=1;
    for(int i=1;i<=G->n;i++)pre[i]=0;
    for(int i=1;i<=G->n;i++)
      if(pre[i]==0)dfs(G,i);
}

int main()
{
   Graph G=Graphinit(8);

   GraphAdd(1,3,G);
   GraphAdd(1,6,G);
   GraphAdd(1,8,G);
   GraphAdd(2,8,G);
   GraphAdd(3,7,G);

   GraphAdd(4,5,G);
   GraphAdd(4,6,G);
   GraphAdd(5,6,G);
   GraphAdd(5,7,G);
   GraphAdd(5,8,G);

   printf("搜索图 \n");

   GraphOut(G);

   printf("从顶点 1 开始搜索\n");

   GraphSearch(G);

   for(int i=1;i<=8;i++)printf(" %d  ",pre[i]);
   printf("\n");
   return 0;
}

