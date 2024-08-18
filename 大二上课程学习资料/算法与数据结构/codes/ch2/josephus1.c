// Josephus排列问题

#include <stdio.h>
#include <stdlib.h>

void Josephus(int n,int m)
{
   int * next=(int *)malloc(n*sizeof(int));
   for(int i=0;i<n-1;i++)next[i]=i+1; /* 第i个元素的下一元素为i+1 */
   int k=n-1;next[k]=0; /*  k为搜索游标 */
   for(int i=1;i<n;i++){
     for(int j=1;j<m;j++)k=next[k]; /* 循环计数 */
     printf("删除竞赛者 %d \n",next[k]+1);/* 输出第m个元素 */
     next[k]=next[next[k]];/* 删除第m个元素 */
   }
   printf("竞赛者 %d  胜出 \n", next[k]+1);
}

int main()
{
   int n,m;
   n=8;m=5;
   Josephus(n,m);
   return 0;
}
