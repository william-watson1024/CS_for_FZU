// 测试表 
#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
//#include "llist.h"
//#include "chain.h"
//#include "indlist.h"
//#include "schain.h"
//#include "cchain.h"
#include "cdouble.h"

int main()
{
   //List l=ListInit(10);
   List l=ListInit();
   printf("表长=%d \n", ListLength(l));
   printf("空表=%d \n", ListEmpty(l));
   ListInsert(0,2,l);
   ListInsert(1,6,l);
   ListInsert(1,8,l);
   ListInsert(0,9,l);
   PrintList(l);
   printf("空表=%d \n", ListEmpty(l));
   printf("元素6位于%d \n", ListLocate(6,l));
   printf("首元素为%d \n", ListRetrieve(1,l));
   printf("第二个元素是%d \n", ListRetrieve(2,l));
   printf("第三个元素是%d \n", ListRetrieve(3,l));
   printf("表长=%d \n", ListLength(l));
   printf("被删除元素%d \n", ListDelete(2,l));
   int len=ListLength(l);
   printf("表长=%d \n", len);
   PrintList(l);
   printf("删除表尾元素%d \n", ListDelete(len,l));
   PrintList(l);
   printf("表首元素为%d \n", ListRetrieve(1,l));
   printf("表尾元素为%d \n", ListRetrieve(ListLength(l),l));
   printf("表首插入元素 10\n");
   ListInsert(0,10,l);
   PrintList(l);
   printf("表尾插入元素 15\n");
   ListInsert(ListLength(l),15,l);
   PrintList(l);
   ListFree(l);
   return 0;
}
