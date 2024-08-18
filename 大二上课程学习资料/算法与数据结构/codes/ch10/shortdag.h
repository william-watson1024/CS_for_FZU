/* DAG的最短路径 */
/* 
使用时前置语句 
#include "witem.h"
#include "lwdgraph.h"
#include "shortdag.h"
*/

#include <limits.h>
#include "topsort.h"

#define maxW INT_MAX
#define minW INT_MIN

static int ts[maxN];

void shortest(Graph G,int p[],WItem c[])
{
    int i,v,w;glink t;
    TopSort(G,ts);
    for(v=ts[i=1];i<=G->n;v=ts[i++])
       for(t=G->adj[v];t;t=t->next)
          if(c[w=t->v]>c[v]+t->w){
                p[w]=v;
                c[w]=c[v]+t->w;
          }
}

