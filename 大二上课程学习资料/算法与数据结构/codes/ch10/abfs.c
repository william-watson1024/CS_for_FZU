/* 广度优先搜索 */

#include <stdio.h>
#include <stdlib.h>
#include "agraph.h"
#include "qitem.h"
#include "lqueue.h"

#define maxN 10000

static int cnt, pre[maxN];

void bfs1(Graph G,int i)
{
    Queue q=QueueInit();
    EnterQueue(i,q);
    while(!QueueEmpty(q))
      if(pre[i=DeleteQueue(q)]==0){
        pre[i]=cnt++;
        for(int j=1;j<=G->n;j++)
          if(G->a[i][j])
            if(pre[j]==0)EnterQueue(j,q);
      }
}

void bfs(Graph G,int i)
{ 
    Queue q=QueueInit();
    EnterQueue(i,q);
    pre[i]=cnt++;
    while(!QueueEmpty(q)){
       i=DeleteQueue(q);
       for(int j=1;j<=G->n;j++)
         if((G->a[i][j]) && (pre[j]==0)){ 
             EnterQueue(j,q);
             pre[j]=cnt++;
         }
    }
}

void GraphSearch(Graph G)
{
    cnt=1;
    for(int i=1;i<=G->n;i++)pre[i]=0;
    for(int i=1;i<=G->n;i++)
      if(pre[i]==0)bfs(G,i);
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

   for(int i=1;i<=8;i++)
      printf(" %d  ",pre[i]);
   printf("\n");
   return 0;
}

