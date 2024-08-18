/* 测试二叉搜索树 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeitem.h"
#include "bstree.h"
//#include "avltree.h"
//#include "rbtree.h"

const unsigned long maxshort =65536L;
const unsigned long multiplier=1194211693L;
const unsigned long adder=12345L;

unsigned long randSeed;

void Randomseed(unsigned long s)
{/* 随机种子 */ 
    if (s==0)randSeed=time(0); /* 系统时间 */ 
    else randSeed=s; /* 用户提供 */ 
}

unsigned short Random(unsigned long n)
{/* 随机整数 0<=value<=n-1<65536 */
    randSeed=multiplier*randSeed+adder;
    return (unsigned short)((randSeed>>16)%n);
}

double fRandom ()
{/* 随机实数数 0<=f<1 */
    return Random(maxshort)/(maxshort);
}

void dic_test(int N,int *A,BinaryTree D)
{
    for(int i=0;i<N;i++)BSInsert(A[i],D);
    //RBPrintTree(D->root,0);
    for(int i=0;i<N;i++)BSDelete(A[i],D);
    if(!(D->root==0))printf(" NOT EMPTY ");
    else printf("Empty\n");
    //RBPrintTree(D->root,0);
    printf("\n");
}

void found(int x)
{
   printf("y=%d\n",3*x);
}

int main()
{
   int i,N;
   int *Int;
   BinaryTree D,x,y;
   N=1000000;
   D=BinaryInit();
   y=BinaryInit();
   Int=(int *)malloc(N*sizeof(int));
   Randomseed(0);
   for(i=0;i<N;i++)Int[i]=Random(100000);
   dic_test(N,Int,D);
   BSInsert(1,y);
   BSInsert(6,y);
   BSInsert(4,y);
   BSInsert(8,y);
   BSInsert(50,y);
   BSInsert(80,y);
   BSInsert(68,y);
   printf("集合元素递增排列\n");
   BSAscend(y);
   //RBPrintTree(y->root,0);
   x=BSTCopy(y);
   printf("集合x中元素\n");
   BSAscend(x);
   printf("BSMember(4,y)=%d\n",BSMember(4,y));
   BSDelete(4,y);
   printf("删除 4 \n");
   printf("集合元素递增排列\n");
   BSAscend(y);
   //RBPrintTree(y->root,0);
   BSDelete(8,y);
   printf("删除 8\n");
   printf("集合元素递增排列\n");
   BSAscend(y);
   //RBPrintTree(y->root,0);
   BSDelete(6,y);
   printf("删除 6\n");
   printf("集合元素递增排列\n");
   BSAscend(y);
   //RBPrintTree(y->root,0);
   BSDelete(6,y);
   printf("删除 6\n");
   printf("集合元素递增排列\n");
   BSAscend(y);
   //RBPrintTree(y->root,0);
   printf("集合x中元素\n");
   BSAscend(x);
   BSInsertVisit(4,found,x);
   printf("集合x中元素\n");
   BSAscend(x);
   return 0;
}

