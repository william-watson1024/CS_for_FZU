/* Prim算法 */
/* 
使用时前置语句 
#include "witem.h"
#include "awgraph.h"
#include "prim.h"
*/

void Prim(WItem *lowcost,int *closest,Graph G)
{
    WItem min;
    int *s;
    s=(int *)malloc((G->n+1)*sizeof(int));
    for(int i=1;i<=G->n;i++){
        lowcost[i]=G->a[i][1];
        closest[i]=1;
        s[i]=0;
    }
    s[1]=1;
    for(int i=1;i<G->n;i++){
        WItem min=G->NoEdge;
        int j=1;
        for(int k=2;k<=G->n;k++)
           if((lowcost[k]<min)&&(!s[k])){
                min=lowcost[k];
                j=k;
           }
        s[j]=1;
        for(int k=2;k<=G->n;k++)
           if((G->a[k][j]<lowcost[k])&&(!s[k])){
                lowcost[k]=G->a[k][j];
                closest[k]=j;
           }
    }
}


