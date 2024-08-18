/* ≤‚ ‘¡¥±ÌºØ∫œ */

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "linkedset.h"

void lset()
{
   Set a,s,t;
   s=SetInit();
   t=SetInit();
   SetInsert(4,t);
   SetInsert(7,t);
   SetInsert(12,t);
   SetInsert(5,s);
   SetInsert(4,s);
   SetInsert(7,s);

   printf("s=");
   SetOut(s);
   printf("\n");
   printf("t=");
   SetOut(t);
   printf("\n");

   a=SetInter(s,t);
   printf("s*t=");
   SetOut(a);
   printf("\n");

   SetDelete(2,t);
   printf("t-7=");
   SetOut(t);
   printf("\n");
}

int main()
{
    lset();
    return 0;
}
