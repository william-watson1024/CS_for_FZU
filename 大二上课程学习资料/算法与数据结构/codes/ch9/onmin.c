/* 在线最小值 */

#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "minheap.h"

int randomi(int l,int r)
{
    return l+(r-l)*(1.0*rand()/RAND_MAX);
}

void onmin(int in[],int e[],int out[],int n,int m)
{
   int curr=1;
   Heap H=MinHeapInit(n);
   for(int i=1;i<=m;i++){
        while(curr<=e[i])HeapInsert(in[curr++],H);
        out[i]=DeleteMin(H);
   }
}

int main()
{
   int a[12],e[11],out[11];
   int n=10,k=6;
   for(int i=1;i<=n;i++)a[i]=n-i+1;

   for(int m=0;m<5;m++)
      for(int i=1;i<n;i++){
            int j=randomi(i+1,n);
            swap(a[i],a[j]);
       }

   for(int i=1;i<=n;i++)printf(" %d",a[i]);
   printf("\n");

   e[0]=0;e[1]=2;e[2]=2;e[3]=5;e[4]=5;e[5]=5;e[6]=10;a[11]=0;
   onmin(a,e,out,n,k);
   for(int i=1;i<=k;i++) printf(" %d",out[i]);
   printf("\n");
   return 0;
}
