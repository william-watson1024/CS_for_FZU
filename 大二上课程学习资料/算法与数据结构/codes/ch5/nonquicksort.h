// 非递归快速排序算法
/* 
使用时前置语句 
#include "item.h"
#include "nonquicksort.h"
*/

#include "lstack.h"

#define push2(A,B,s)  Push(B,s); Push(A,s);

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
{/* 非递归快速排序算法 */
    Stack s=StackInit();
    push2(l,r,s);
    while(!StackEmpty(s)){
       l=Pop(s);r=Pop(s);
       if(r<=l)continue;
       int i=partition(a,l,r);
       if(i-l>r-i){push2(l,i-1,s);push2(i+1,r,s);}
       else{push2(i+1,r,s);push2(l,i-1,s);}
    }
}

