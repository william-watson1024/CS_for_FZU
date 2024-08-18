/* 用邻接表实现赋权图 */
/* 
使用时前置语句 
#include "witem.h"
#include "lwgraph.h"
*/

#ifndef LinkedWGraph_
#define LinkedWGraph_

#include "lwgnode.h"

Graph Graphinit(int v)
{/* 创建n个孤立顶点的图 */
   Graph G=(Graph)malloc(sizeof *G);
   G->n=v;
   G->e=0;
   G->adj=(glink *)malloc((v+1)*sizeof(glink));
   for(int i=0;i<=v;i++)G->adj[i]=0;
   return G;
}

int GraphEdges(Graph G)
{/* 边数 */
    return G->e;
}

int GraphVertices(Graph G)
{/* 顶点数 */
    return G->n;
}

int GraphExist(int i, int j, Graph G)
{/* 边(i,j)是否存在 */
   if(i<1 || j<1 || i>G->n || j>G->n)return 0;
   glink p=G->adj[i];
   while(p && p->v!=j)p=p->next;
   if(p)return 1;
   else return 0;
}

void GraphAdd(int i, int j, WItem w, Graph G)
{/* 加入边(i,j) */
   if(i<1 || j<1 || i>G->n || j>G->n || i==j || GraphExist(i,j,G))return;
   G->adj[i] = NewLWNode(j,w,G->adj[i]);
   G->adj[j] = NewLWNode(i,w,G->adj[j]);
   G->e++;
}

void GraphDelete(int i,int j,Graph G)
{/* 删除边(i,j) */
   glink p,q;
   if(i<1 || j<1 || i>G->n || j>G->n || !GraphExist(i,j,G))return;
   p=G->adj[i];
   if(p->v == j){
      G->adj[i]=p->next;
      free(p);
   }
   else{
      while(p && p->next->v!=j)p=p->next;
      if(p){
          q=p->next;
          p->next=q->next;
          free(q);
      }
   }
   p=G->adj[j];
   if(p->v==i){
       G->adj[j]=p->next;
       free(p);
   }
   else{
      while(p && p->next->v!=i)p=p->next;
      if(p){ 
          q=p->next;
          p->next=q->next;
          free(q);
      }
   }
   G->e--;
}

int Degree(int i, Graph G)
{/* 顶点i的度 */
   int j=0;
   if(i<1 || i>G->n)return -1;
   /* 统计边 */
   glink p=G->adj[i];
   while(p){
        j++;
        p=p->next;
   }
   return j;
}

void GraphOut(Graph G)
{/* 输出邻接表 */
   for(int i=1;i<=G->n;i++){
     glink p=G->adj[i];
     while(p){
       ShowNode(p);
       p=p->next;
     }
     printf("\n");}
}

#endif
