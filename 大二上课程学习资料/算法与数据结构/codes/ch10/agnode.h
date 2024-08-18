/* 邻接矩阵无向图结构 */

#ifndef agnode_
#define agnode_

typedef struct graph *Graph;/* 无向图指针类型 */
struct graph{/* 邻接矩阵无向图结构 */
      int n;/* 顶点数 */
      int e;/* 边数 */
      int **a;/* 邻接矩阵 */
}Agraph;

Graph Graphinit(int n);
int GraphEdges(Graph G);
int GraphVertices(Graph G);
int GraphExist(int i,int j,Graph G);
void GraphAdd(int i,int j,Graph G);
void GraphDelete(int i,int j,Graph G);
int Degree(int i,Graph G);
void GraphOut(Graph G);

#endif
