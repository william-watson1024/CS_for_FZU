/* 离线最小值 */

#include <stdio.h>
#include <stdlib.h>
#include "ufset3.h"

#define swap(A,B) {int t=A;A=B;B=t;}

int randomi(int l,int r)
{
    return l+(r-l)*(1.0*rand()/RAND_MAX);
}

void offmin(int in[],int e[],int out[],int n,int k)
{
   UFset U=UFinit(n+1);
   int *si=(int *)malloc((n+2)*sizeof(int));
   int *is=(int *)malloc((n+2)*sizeof(int));
   int *prev=(int *)malloc((k+2)*sizeof(int));
   int *next=(int *)malloc((k+2)*sizeof(int));
   for(int i=1;i<=k;i++){
      int curr=(e[i]>e[i-1])?in[e[i-1]+1]:0;
      if(e[i]<i || e[i]<e[i-1])exit(1);
      for(int j=e[i-1]+2;j<=e[i];j++) 
         curr=UFunion(curr,in[j],U);
      si[curr]=i;
      is[i]=curr;
   }
   is[k+1]=0;
   for(int i=0;i<=k;i++){
        prev[i+1]=i;
        next[i]=i+1;
   }
   for(int i=1;i<=n;i++){
      int name=UFfind(i,U);
      int j=si[name];
      if(j<=k){
         int newset=name;
         if(is[next[j]])
            newset=UFunion(name,is[next[j]],U);
         si[newset]=next[j];
         is[next[j]]=newset;
         next[prev[j]]=next[j];
         prev[next[j]]=prev[j];
         out[j]=i;
      }
   }
}

int main()
{
   int a[12],e[11],out[11];
   int n=10,k=6;
   for(int i=1;i<=n;i++)a[i]=n-i+1;
   for (int m=0;m<5;m++)
      for (int i=1;i<n;i++){
          int j=randomi(i+1,n);
          swap(a[i],a[j]);
      }
   for(int i=1;i<=n;i++)printf(" %d",a[i]);
   printf("\n");
   e[0]=0;e[1]=2;e[2]=2;e[3]=5;e[4]=5;e[5]=5;e[6]=10;a[11]=0;
   offmin(a,e,out,n,k);
   for(int i=1;i<=k;i++) printf(" %d",out[i]);
   printf("\n");
   return 0;
}
