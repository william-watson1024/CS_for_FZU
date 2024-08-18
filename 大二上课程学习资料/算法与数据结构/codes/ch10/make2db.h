
#ifndef Make2DArray_
#define Make2DArray_

WItem **Make2DArray(int rows,int cols,WItem value)
{/* 创建动态2维数组 */
    WItem **t=(WItem **)malloc(rows*sizeof(WItem *));
    for(int i=0;i<rows;i++)
      t[i]=(WItem *)malloc(cols*sizeof(WItem));
    for(int i=0;i<rows;i++)
       for(int j=0;j<cols;j++)t[i][j]=value;
    return t;
}

void Erase2D(WItem**t, int rows)
{/* 删除动态2维数组 */
   for(int i=0;i<rows;i++)free(t[i]);
   free(t);
}

#endif
