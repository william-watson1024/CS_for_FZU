// ²âÊÔÕ» 

#include <stdio.h>
#include <stdlib.h>
#include "stackitem.h"
#include "stack.h"
//#include "lstack.h"

int main()
{
   Stack ss,tt;
   ss=StackInit(10);
   tt=StackInit(10);
   //ss=StackInit();
   //tt=StackInit();

   Push(1,ss);
   Push(2,ss);
   Push(3,ss);

   Push(4,tt);
   Push(5,tt);
   Push(6,tt);

   if(!StackEmpty(ss))printf("ssµÄÕ»¶¥ÔªËØ  %d \n", StackTop(ss));
   if(!StackEmpty(tt))printf("ttµÄÕ»¶¥ÔªËØ  %d \n", StackTop(tt));

   if(!StackEmpty(ss))printf("É¾³ý  %d \n", Pop(ss));
   if(!StackEmpty(ss))printf("É¾³ý  %d \n", Pop(ss));
   if(!StackEmpty(ss))printf("É¾³ý  %d \n", Pop(ss));

   if(!StackEmpty(tt))printf("É¾³ý  %d \n", Pop(tt));
   if(!StackEmpty(tt))printf("É¾³ý  %d \n", Pop(tt));
   if(!StackEmpty(tt))printf("É¾³ý  %d \n", Pop(tt));
   if(!StackEmpty(tt))printf("É¾³ý  %d \n", Pop(ss));
   StackFree(ss);StackFree(tt); 
   return 0;
}
