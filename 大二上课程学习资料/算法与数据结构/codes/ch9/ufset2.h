/* 树实现并查集 */

typedef struct ufset *UFset;/* 并查集指针类型 */
typedef struct ufset{/* 并查集结构 */
      int *parent;/* 父结点数组 */
}UFS;

UFset UFinit(int size)
{/* 初始化成单元素集合 */
   UFset U=(UFset)malloc(sizeof *U);
   U->parent=(int *)malloc((size+1)*sizeof(int));
   for(int e=1;e<=size;e++)
      U->parent[e]=0;
   return U;
}

int UFunion(int i,int j,UFset U)
{/* 合并集合 */
   U->parent[j]=i;
   return i;
}

int UFfind(int e,UFset U)
{/* 找出包含元素e的集合 */
   while(U->parent[e])e=U->parent[e];/* 上移 */ 
   return e;
}

