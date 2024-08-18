// 电路布线

#include <stdio.h>
#include <stdlib.h>
#include "qitem2.h"
#include "lqueue.h"
#include "make2db.h"

int **g,n,m;

void Input(Pos a, Pos b)
{
    int k;
    scanf("%d",&n);
    scanf("%d",&m);
    g=malloc2d(n+2,m+2);
    scanf("%d",&a->row);
    scanf("%d",&a->col);
    scanf("%d",&b->row);
    scanf("%d",&b->col);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++){
            scanf("%d",&k);
            g[i][j]=k;
        }
}

void Output(int Len,Pos *path)
{
    for(int i=0;i<Len;i++)
      printf("%d %d\n",(path[i])->row,(path[i])->col);
}

int Search(Pos a,Pos b,Pos *path)
{ /* 计算从起始位置a到目标位置b的最短布线路径
     找到最短布线路径则返回最短路长,否则返回0  */
    Pos off[4];/* 相对位移 */
    Queue Q;/* 待考察方格队列 */
    Q=QueueInit();
    if((a->row==b->row) && (a->col==b->col))return 0;/* a=b */
    /* 设置方格阵列围墙 */
    for(int i=0;i<=m+1;i++)g[0][i]=g[n+1][i]=1;/* 顶部和底部 */
    for(int i=0;i<=n+1;i++)g[i][0]=g[i][m+1]=1;/* 左翼和右翼 */
    /* 初始化相对位移 */
    for(int i=0;i<4;i++)off[i]=NewPos();
    off[0]->row=0;off[0]->col=1;/* 右 */
    off[1]->row=1;off[1]->col=0;/* 下 */
    off[2]->row=0;off[2]->col=-1;/* 左 */
    off[3]->row=-1;off[3]->col=0;/* 上 */
    int k=4;/* 相邻方格数 */
    Pos nbr,cur=NewPos();
    cur->row=a->row;
    cur->col=a->col;
    g[a->row][a->col]=2;
    /* 标记可达方格位置 */
    while(1){/* 标记可达相邻方格 */
       for(int i=0;i<k;i++){
         nbr=NewPos();
         nbr->row=cur->row+off[i]->row;
         nbr->col=cur->col+off[i]->col;
         if(g[nbr->row][nbr->col]==0){
            /* 该方格未标记 */
            g[nbr->row][nbr->col]=g[cur->row][cur->col]+1;
            if((nbr->row==b->row)&&(nbr->col==b->col))break; /* 完成布线 */
            EnterQueue(nbr,Q);
         }
       }
       /* 是否到达目标位置b? */
       if((nbr->row==b->row)&&(nbr->col==b->col))break; /* 完成布线 */
       /* 待考察方格队列是否非空 */
       if(QueueEmpty(Q))return 0; /* 无解 */
       cur=DeleteQueue(Q); /* 取下一个考察方格 */
    }
    /* 构造最短布线路径 */
    int len=g[b->row][b->col] - 2;
    for(int i=0;i<len;i++)path[i]=NewPos();
    cur=b;/* 从目标位置b开始向起始位置回溯 */
    for(int j=len-1;j>=0;j--){
        path[j]=cur;
        /* 找前驱位置 */
        for(int i=0;i<k;i++){
            nbr=NewPos();
            nbr->row=cur->row+off[i]->row;
            nbr->col=cur->col+off[i]->col;
            if(g[nbr->row][nbr->col]==j+2)break;
        }
        cur=nbr;/* 向前移动 */
    }
    return len;
}

int main()
{
   Pos s,f,*p;
   s=(Pos)malloc(sizeof(*s));
   f=(Pos)malloc(sizeof(*f));
   Input(s,f);

   printf("n=%d\n",n);
   printf("m=%d\n",m);

   printf("%d  ",s->row);
   printf("%d  ",s->col);
   printf("%d  ",f->row);
   printf("%d\n",f->col);

   p=(Pos *)malloc(n*m*sizeof(Pos));

   Output(Search(s,f,p),p);
   return 0;
}

/* test.in
7 7
3 2
4 6
0 0 1 0 0 0 0
0 0 1 1 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 0 0
1 0 0 0 1 0 0
1 1 1 0 0 0 0
1 1 1 0 0 0 0
*/

/* test.out
n=7
m=7
3  2  4  6
4 2
5 2
5 3
5 4
6 4
6 5
6 6
5 6
4 6
*/ 
