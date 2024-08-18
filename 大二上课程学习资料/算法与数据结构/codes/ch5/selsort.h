// 选择排序算法
/* 
使用时前置语句 
#include "item.h"
#include "selsort.h"
*/

int mini(Item a[], int i, int r)
{/* 确定a[i:r]中最小元素下标 */
   int min=i;
   for(int j=i+1;j<=r;j++)if(less(a[j],a[min]))min=j;
   return min;
}

void sort(Item a[], int l, int r)
{ /* 选择排序算法 */
    for(int i=l;i<r;i++){int j=mini(a,i,r);swap(a[i],a[j]);}
}



