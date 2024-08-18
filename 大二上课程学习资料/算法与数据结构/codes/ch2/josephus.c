// Josephus排列问题

#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
#include "cdouble.h"

void Josephus(int n,int m)
{
   List l=ListInit();/* 创建一个空表 */
   for(int i=1;i<=n;i++) ListInsert(i-1,i,l);/* 表中第i个元素为i */
   IterInit(l);/* 初始化搜索游标 */
   for(int i=1;i<n;i++){
     for(int j=1;j<m;j++)IterNext(l);/* 搜索游标下移 */
     ListItem x=DeleteCurr(l);/* 删除第m个元素 */
     printf("删除竞赛者 %d \n", x);/* 输出被删除元素 */
   }
   printf("竞赛者 %d  胜出 \n", *CurrItem(l));
}

int main()
{
   int n,m;
   n=8;m=5;
   Josephus(n,m);
   return 0;
}
