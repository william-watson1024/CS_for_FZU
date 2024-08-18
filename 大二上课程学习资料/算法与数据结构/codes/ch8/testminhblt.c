/* 测试极小化左偏树 */ 

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "minhblt.h"

int main()
{
   int w,x,y,z;
   int a[6]={0,7,9,1,8,11};
   int b[5]={0,2,6,4,9};
   MinHBLT H,J;
   H=BuildHBLT(a,5);
   printf("左偏树\n");
   HBLTOut(H->root);
   printf("\n");

   J=BuildHBLT(b,4);
   printf("左偏树\n");
   HBLTOut(J->root);
   printf("\n");

   HBLTConc(H,J);
   printf("合并左偏树\n");
   HBLTOut(H->root);
   printf("\n");

   w=DeleteMin(H);
   x=DeleteMin(H);
   y=DeleteMin(H);
   z=DeleteMin(H);

   printf("4次删除最小元\n");
   HBLTOut(H->root);
   printf("\n");

   printf("删除的最小元素\n");
   printf("%d %d %d %d\n",w,x,y,z);

   HBLTInsert(10,H);
   HBLTInsert(20,H);
   HBLTInsert(5,H);

   printf("左偏树\n");
   HBLTOut(H->root);
   printf("\n");

   HBLTInsert(15,H);
   HBLTInsert(30,H);
   HBLTInsert(2,H);

   printf("左偏树\n");
   HBLTOut(H->root);
   printf("\n");

   printf("最小元素%d\n",HBLTMin(H));

   x=DeleteMin(H);
   printf("删除最小元 %d\n",x);

   printf("左偏树\n");
   HBLTOut(H->root);
   printf("\n");

   x=DeleteMin(H);
   printf("删除最小元 %d\n",x);

   printf("左偏树\n");
   HBLTOut(H->root);
   printf("\n");

   while(!HBLTEmpty(H))x=DeleteMin(H);
   return 0;
}
