/* 邻接矩阵赋权图结构 */

#ifndef awgnode_
#define awgnode_

typedef struct graph *Graph;/* 赋权图指针类型 */
struct graph{/* 邻接矩阵赋权图结构 */
      WItem NoEdge;/* 无边标记 */
      int n;/* 顶点数 */
      int e;/* 边数 */
      WItem **a;/* 邻接矩阵 */
}AWDgraph;

Graph Graphinit(int n,WItem noEdge);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,WItem w,Graph G);
void GraphDelete(int i,int j,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
