/* Floyd算法 */
/* 
使用时前置语句 
#include "witem.h"
#include "awdgraph.h"
#include "floyd.h"
*/

#include "make2db.h"

void Floyd(WItem **c,int **path,Graph G)
{
  /* 初始化c[i][j] */
  for(int i=1;i<=G->n;i++)
    for(int j=1;j<=G->n;j++){
      c[i][j]=G->a[i][j];
      path[i][j]=0;
    }
  for(int i=1;i<=G->n;i++)c[i][i]=0;
  /* 循环计算c[i][j] 的值 */
  for(int k=1;k<=G->n;k++)
    for(int i=1;i<=G->n;i++)
      for(int j=1;j<=G->n;j++){
        WItem t1=c[i][k],t2=c[k][j],t3=c[i][j];
        if(t1!=G->NoEdge && t2!=G->NoEdge && (t3==G->NoEdge || t1+t2<t3)){
            c[i][j]=t1+t2;
            path[i][j]=k;
        }
    }
}

