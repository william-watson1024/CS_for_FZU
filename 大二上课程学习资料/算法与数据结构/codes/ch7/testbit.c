/* 测试位向量集合 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"
 
void bitset()
{
   Set a,s,t;
   s=SetInit(100);
   t=SetInit(100);
   SetInsert(4,t);
   SetInsert(7,t);
   SetInsert(12,t);
   SetInsert(5,s);
   SetInsert(4,s);

   printf("s=");
   SetOut(s);
   printf("t=");
   SetOut(t);

   a=SetUnion(s,t);
   printf("s+t =");
   SetOut(a);

   a=SetIntersection(s,t);
   printf("s*t=");
   SetOut(a);

   a=SetDifference(s,t);
   printf("s-t=");
   SetOut(a);

   a=SetDifference(t,s);
   printf("t-s=");
   SetOut(a);

   SetDelete(7,t);
   printf("t-7=");
   SetOut(t);
}

int main()
{
    bitset();
    return 0;
}
