/* 小树合并到大树 */
#include<iostream>
using namespace std;

typedef struct ufset *UFset;/* 并查集指针类型 */
typedef struct ufset{/* 并查集结构 */
      int *parent;/* 父结点数组 */
      int *root;/* 根结点数组 */
}UFS;

UFset UFinit(int size)
{/* 初始化成单元素集合 */
   UFset U=(UFset)malloc(sizeof *U);
   U->parent=(int *)malloc((size+1)*sizeof(int));
   U->root=(int *)malloc((size+1)*sizeof(int));
   for(int e=0;e<=size;e++){
      U->parent[e]=1;
      U->root[e]=1;
   }
   return U;
}

void UFfree(UFset U)
{/* 释放空间 */
   free(U->parent);
   free(U->root);
   free(U);
}

int UFunion(int i,int j,UFset U)
{/* 合并集合 */
   if(i==j)return i;
   if(U->parent[i]<U->parent[j]){
      /* i 成为 j 的子树 */
      U->parent[j]+=U->parent[i];
      U->root[i]=0;
      U->parent[i]=j;
      return j;
   }
   else{/* j 成为 i 的子树 */
      U->parent[i]+=U->parent[j];
      U->root[j]=0;
      U->parent[j]=i;
      return i;
   }
}

int UFfind(int e, UFset U)
{/* 找出包含元素e的集合 */
   while(!U->root[e])e=U->parent[e];/* 上移 */ 
   return e;
}

int UFsize(int e, UFset U)
{/* 找出包含元素e的集合 */
   while(!U->root[e])e=U->parent[e];/* 上移 */ 
   return U->parent[e];
}

int UFfind1(int e,UFset U)
{/* 找出包含元素e的集合 */
   int i,j=e;
   while(!U->root[j])j=U->parent[j];/* 上移 */ 
   while(j!=e){/* 路径压缩 */
     i=U->parent[e];
     U->parent[e]=j;
     e=i;
   }
   return j;
}

