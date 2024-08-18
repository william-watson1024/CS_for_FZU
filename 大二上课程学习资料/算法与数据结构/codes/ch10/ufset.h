/* 数组实现并查集 */

typedef struct ufset *UFset;/* 并查集指针类型 */
typedef struct ufset{/* 并查集结构 */
      int *components;/* 元素所属子集关系数组 */
      int n;/* 集合中元素个数 */
}UFS;

UFset UFinit(int size)
{/* 初始化成单元素集合 */
   UFset U=(UFset)malloc(sizeof *U);
   U->components=(int *)malloc((size+1)*sizeof(int));
   for(int e=1;e<=size;e++)
      U->components[e]=e;
   U->n=size;
   return U;
}

int UFunion(int i,int j,UFset U)
{/* 合并集合 */
   for(int k=1;k<=U->n;k++)
      if(U->components[k]==j)U->components[k]=i;
   return i;
}

int UFfind(int e,UFset U)
{/* 找出包含元素e的集合 */
    return U->components[e];
}

