/* ≤‚ ‘FloydÀ„∑® */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "awdgraph.h"
#include "floyd.h"

int main()
{
   int **path;
   WItem **c;
   Graph G=Graphinit(5,100);

   GraphAdd(1,2,4,G);
   GraphAdd(1,3,2,G);
   GraphAdd(1,5,8,G);
   GraphAdd(2,4,4,G);
   GraphAdd(2,5,5,G);

   GraphAdd(3,4,1,G);
   GraphAdd(4,5,3,G);

   printf(" ‰»ÎÕº \n");

   GraphOut(G);
   c=Make2DArray(6,6,0);
   path=Make2DArray(6,6,0);

   Floyd(c,path,G);

   printf("∑—”√æÿ’Û \n");
   for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++)printf("%d  ",c[i][j]);
      printf("\n");
   }

   printf("¬∑æ∂æÿ’Û \n");
   for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++)printf("%d  ",path[i][j]);
      printf("\n");
   }
   return 0;
}

