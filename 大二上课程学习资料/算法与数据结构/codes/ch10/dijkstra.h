/* Dijkstra算法 */
/* 
使用时前置语句 
#include "witem.h"
#include "awdgraph.h"
#include "dijkstra.h"
*/

#include "listitem.h"
#include "chain.h"

ListItem ListDelMin(List L,WItem dist[])
{
   link p,q,t,r;
   if(ListEmpty(L))return 0;
   p=L->first;t=p;r=t;q=p->next;
   while(q){
       if(dist[q->element]<dist[r->element]){t=p;r=q;}
       p=q;
       q=q->next;
   }
   if(t==r)L->first=r->next;
   else t->next=r->next;
   ListItem x=r->element;
   free(r);
   return x;
}

void Dijkstra(int s,WItem dist[],int prev[],Graph G)
{/* Dijkstra算法 */
   List L=ListInit(); 
   if(s<1 || s>G->n)return;
   /* 初始化dist, prev和 L */
   for(int i=1;i<=G->n;i++){
      dist[i]=G->a[s][i];
      if(dist[i]==G->NoEdge)prev[i]=0;
      else{
          prev[i]=s;
          ListInsert(0,i,L);
      }
   }
   dist[s]=0;
    /* 修改 dist和prev */
   while(!ListEmpty(L)){
      /* 找L中具有最小dist值的顶点v */
      /* 将顶点v从表L中删除，并修改dist的值 */
      int i=ListDelMin(L,dist);
      for(int j=1;j<=G->n;j++){
         if(G->a[i][j]!=G->NoEdge && (!prev[j] || dist[j]>dist[i]+G->a[i][j])){
            /* dist[j] 减少 */
            dist[j]=dist[i]+G->a[i][j];
            /* 顶点j插入表 L */
            if(!prev[j])ListInsert(0,j,L);
            prev[j]=i;
         }
       }
   }
}

