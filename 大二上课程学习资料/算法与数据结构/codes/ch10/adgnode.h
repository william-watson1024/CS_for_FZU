/* 邻接矩阵有向图结构 */

#ifndef adgnode_
#define adgnode_

typedef struct graph *Graph;/* 有向图指针类型 */
struct graph{/* 邻接矩阵有向图结构 */
      int n;/* 顶点数 */
      int e;/* 边数 */
      int **a;/* 邻接矩阵 */
}AWDgraph;

Graph Graphinit(int n);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,Graph G);
void GraphDelete(int i,int j,Graph G);
int OutDegree(int i,Graph G);
int InDegree(int i,Graph G);
void GraphOut(Graph G);

#endif
