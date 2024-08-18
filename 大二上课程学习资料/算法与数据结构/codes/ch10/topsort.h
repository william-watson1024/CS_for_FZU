/* 拓扑排序 */
/* 
使用时前置语句 
#include "witem.h"
#include "lwdgraph.h"
#include "topsort.h"
*/

#include "qitem.h"
#include "queue.h"

#define maxN 10000

static int cnt,in[maxN];
Queue q;

void TopSort(Graph D,int ts[])
{ 
    for(int v=1;v<=D->n;v++){in[v]=0;ts[v]=0;}
    for(int v=1;v<=D->n;v++) 
      for(glink t=D->adj[v];t;t=t->next)
         in[t->v]++;
    q=QueueInit(D->n);
    for(int v=1;v<=D->n;v++)
      if(in[v]==0)EnterQueue(v,q);
    for(int i=1;!QueueEmpty(q);i++){
        int v=DeleteQueue(q);
        ts[i]=v;
        for(glink t=D->adj[v];t;t=t->next)
           if(--in[t->v]==0)EnterQueue(t->v,q);
    }
}

