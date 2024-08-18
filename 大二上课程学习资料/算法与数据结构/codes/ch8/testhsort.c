/* ²âÊÔ¶ÑÅÅĞòËã·¨ */

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "minheap.h"

int main()
{
   int a[100],n=33;
   for(int i=1;i<=n;i++)a[i]=1000*(1.0*rand()/RAND_MAX);
   HeapSort(a,n);
   for(int i=1;i<=n;i++)printf(" %d ",a[i]);
   printf("\n");
   return 0;
}
