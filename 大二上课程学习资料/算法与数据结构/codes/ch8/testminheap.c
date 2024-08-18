/* 测试极小化堆 */ 

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "minheap.h"

int main()
{
   Heap H=MinHeapInit(6);
   HeapInsert(10,H);
   HeapInsert(20,H);
   HeapInsert(5,H);
   printf("堆中元素\n");
   HeapOut(H);
   HeapInsert(15,H);
   HeapInsert(30,H);
   printf("堆中元素\n");
   HeapOut(H);
   printf("最小元素%d\n",HeapMin(H));
   int x=DeleteMin(H);
   printf("删除最小元素%d\n",x);
   x=DeleteMin(H);
   printf("删除最小元素%d\n",x);
   printf("堆中元素\n");
   HeapOut(H);
   return 0;
}
