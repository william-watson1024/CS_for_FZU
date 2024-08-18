/* ≤‚ ‘≤¢≤ÈºØ */

#include <stdio.h>
#include <stdlib.h>
//#include "ufset.h"
//#include "ufset2.h"
#include "ufset3.h"

int main()
{
   UFset U=UFinit(10);
   UFunion(1,2,U);
   UFunion(3,4,U);
   UFunion(1,3,U);
   printf("Find(1)=%d  Find(2)=%d\n",UFfind(1,U),UFfind(2,U));
   printf("Find(3)=%d  Find(4)=%d\n",UFfind(3,U),UFfind(4,U));
   printf("Find(5)=%d  Find(6)=%d\n",UFfind(5,U),UFfind(6,U));
   return 0;
}
