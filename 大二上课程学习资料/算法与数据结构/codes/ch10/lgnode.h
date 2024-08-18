/* 邻接表图结构 */

#ifndef lgnode_
#define lgnode_

typedef struct lnode *glink;/* 邻接表指针类型 */
struct lnode{/* 邻接表结点类型 */ 
    int v;/* 边的另一个顶点 */ 
    glink next;/* 邻接表指针 */ 
}Lnode;

glink NewLNode(int v,glink next)
{/* 建新邻接表结点 */ 
    glink x=(glink)malloc(sizeof *x);
    x->v=v;x->next=next;
    return x;
}

typedef struct graph *Graph;
struct graph{
      int n;/* 顶点数 */
      int e;/* 边数 */
      glink *adj;/* 邻接表数组 */
}Lgraph;

Graph Graphinit(int n);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,Graph G);
void GraphDelete(int i,int j,Graph G);
int Degree(int i,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
