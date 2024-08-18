/* 测试数组实现符号表 */

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "atable.h"

int main()
{
   Table s,t;
   s=TableInit(100);
   t=TableInit(100);

   TableInsert(4,t);
   TableInsert(7,t);
   TableInsert(12,t);
   TableInsert(5,s);
   TableInsert(4,s);
   TableInsert(7,s);

   printf("s=");
   TableOut(s);
   printf("\n");
   printf("t=");
   TableOut(t);
   printf("\n");

   printf("TableMember(7,s)=%d \n",TableMember(7,s));
   printf("TableMember(6,s)= %d \n",TableMember(6,s));
   TableInsert(6,s);

   printf("s=");
   TableOut(s);
   printf("\n");


   TableAssign(s,t);

   printf("s=");
   TableOut(s);
   printf("\n");

   TableDelete(4,s);
   printf("s=");
   TableOut(s);
   printf("\n");

   TableDelete(7,s);
   printf("s=");
   TableOut(s);
   printf("\n");

   TableDelete(12,s);
   printf("s=");
   TableOut(s);
   printf("\n");
   return 0;
}

