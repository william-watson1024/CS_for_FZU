/* DAG所有顶点对最短路 */
/* 
使用时前置语句 
#include "witem.h"
#include "lwdgraph.h"
#include "alldag.h"
*/

#include <limits.h>
#include "make2db.h"

#define maxW INT_MAX

void SPdfs(Graph G,int s,WItem **d,int **p)
{
    d[s][s]=0;
    for(glink u=G->adj[s];u!=NULL;u=u->next){
        int t=u->v;
        WItem w=u->w;
        if(d[s][t]>w){d[s][t]=w;p[s][t]=t;}
        if(d[t][t]==maxW) SPdfs(G,t,d,p);
        for(int i=1;i<=G->n;i++)
          if(d[t][i]<maxW)
            if(d[s][i]>w+d[t][i]){
                d[s][i]=w+d[t][i];
                p[s][i]=t;
            }
    }
}  

void AllShortes(Graph G, WItem **dist, int **path)
{
    for(int v=1;v<=G->n;v++)
      if(dist[v][v]==maxW)SPdfs(G,v,dist,path);
}
