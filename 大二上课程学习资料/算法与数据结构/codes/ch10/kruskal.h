/* Kruskal算法 */
/* 
使用时前置语句 
#include "witem.h"
#include "awgraph.h"
#include "kruskal.h"
*/

#include "item.h"
#include "quicksort.h"
#include "ufset.h"

Edge EDGE(int u,int v,WItem w)
{
    Edge e;
    e.u=u;e.v=v;e.w=w;
    return e;
}

int Edges(Edge a[],Graph G)
{ 
    int k=0;
    for(int i=1;i<=G->n;i++)
      for(int j=i+1;j<=G->n;j++)
        if(G->a[i][j]!=G->NoEdge)
            a[k++]=EDGE(i,j,G->a[i][j]);
    return k;
}

void Kruskal(Edge mst[],Graph G)
{
    Edge a[maxE];
    UFset U;
    int e=Edges(a,G);
    sort(a,0,e-1);
    U=UFinit(G->n);
    for(int i=0,k=0;i<e && k<G->n-1;i++){
       int s=UFfind(a[i].u,U);
       int t=UFfind(a[i].v,U);
       if(s!=t){
            mst[k++]=a[i];
            UFunion(s,t,U);
       }
    }
}
