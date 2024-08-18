// 快速排序算法
/* 
使用时前置语句 
#include "item.h"
#include "quicksort.h"
*/

int partition(Item a[],int l,int r)
{/* 元素划分算法 */
   int i=l-1,j=r;Item v=a[r];
   /* 将大于等于v的元素交换到右边区域 */
   /* 将小于等于v的元素交换到左边区域 */
   for(;;){
      while(less(a[++i],v));
      while(less(v,a[--j]))if(j==l)break;
      if(i>=j)break;
      swap(a[i],a[j]);
   }
   swap(a[i],a[r]);
   return i;
}

void sort(Item a[],int l,int r)
{/* 快速排序算法 */ 
    if(r<=l)return;
    int i=partition(a,l,r);
    sort(a,l,i-1);/* 对左半段排序 */
    sort(a,i+1,r);/* 对右半段排序 */
} 
  
/*void sort(Item a[], int l, int r)
{ /* 快速排序算法 /
    if(r<=l)return;
    int i=partition(a,l,r);
    if(i-l>r-i){sort(a,i+1,r);sort(a,l,i-1);}
    else{sort(a,l,i-1);sort(a,i+1,r);}
}*/ 

