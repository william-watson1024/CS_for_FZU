/* 测试二叉树 */

#include <stdio.h>
#include <stdlib.h>
#include "treeitem.h"
#include "binary.h"

int main()
{
   BinaryTree a,x,y,z;

   a=BinaryInit();
   x=BinaryInit();
   y=BinaryInit();
   z=BinaryInit();

   MakeTree(1,y,a,a);
   MakeTree(2,z,a,a);
   MakeTree(3,x,y,z);
   MakeTree(4,y,x,a);

   printf("前序列表 \n");
   PreOut(y);
   printf("中序列表 \n");
   InOut(y);
   printf("后序列表 \n");
   PostOut(y);
   printf("层序列表 \n");
   LevelOut(y);

   printf("结点数 %d\n",Size(y->root));
   printf("结点数 %d\n",Size1(y->root));
   printf("高度 %d\n",Height(y->root));

   count=0;
   PreOrder(Add1, y->root);
   printf("count= %d\n",count);
   return 0;
}
