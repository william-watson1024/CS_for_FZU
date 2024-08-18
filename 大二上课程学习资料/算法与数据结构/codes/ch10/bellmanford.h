/* Bellman-Ford算法 */
/* 
使用时前置语句 
#include "witem.h"
#include "lwdgraph.h"
#include "BellmanFord.h"
*/

#include <limits.h>
#include "qitem.h"
#include "lqueue.h"

int BellmanFord(int s,WItem dist[],int prev[],Graph G)
{
    Queue qu;
    glink p;
    int n=G->n;
    if(s<1 || s>n)return 0;
    int *count=(int *)malloc((n+1)*sizeof(int));
    int *ub=(int *)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
        count[i]=0;
        prev[i]=0;
        ub[i]=0;
    }
    qu=QueueInit();
    dist[s]=0;
    EnterQueue(s,qu);
    while(!QueueEmpty(qu)){
        int k=DeleteQueue(qu);
        ub[k]=0;
        count[k]++;
        if (count[k]>n){
            printf("有负圈");
            return 0;
        }
        p=G->adj[k];
        while(p){
            int j=p->v;
            if(dist[j]>dist[k]+p->w){
                dist[j]=dist[k]+p->w;
                prev[j]=k;
                if(!ub[j]){
                    EnterQueue(j,qu);
                    ub[j]=1;
                }
            }
            p=p->next;
        }
    }
    return 1;
}
