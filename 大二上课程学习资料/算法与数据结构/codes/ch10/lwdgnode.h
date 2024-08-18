/* 邻接表赋权有向图结构 */

#ifndef lwgnode_
#define lwgnode_

typedef struct lwnode *glink;/* 赋权邻接表指针类型 */
struct lwnode{/* 赋权邻接表结点类型 */ 
    int v;/* 边的另一个顶点 */ 
    WItem w;/* 边权 */ 
    glink next;/* 邻接表指针 */ 
}Lwnode;

glink NewLWNode(int v,WItem w,glink next)
{/* 创建一个新邻接表结点 */
    glink x=(glink)malloc(sizeof *x);
    x->v=v;x->w=w;x->next=next;
    return x;
}

typedef struct graph *Graph;/* 赋权图指针类型 */
struct graph{/* 邻接表赋权图结构 */
    int n;/* 顶点数 */
    int e;/* 边数 */
    glink *adj;/* 邻接表数组 */
}Lwgraph;

void ShowNode(glink p)
{
   printf("%d %d ",p->v,p->w);
}

Graph Graphinit(int v);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,WItem w,Graph G);
void GraphDelete(int i,int j,Graph G);
int Degree(int i,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
