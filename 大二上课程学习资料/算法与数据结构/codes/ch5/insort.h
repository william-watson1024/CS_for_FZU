// 插入排序算法
/* 
使用时前置语句 
#include "item.h"
#include "insort.h"
*/
void insert(Item a[],int l,int i)
{/* 元素a[i]插入数组a[l:i] */
    Item v=a[i];
    while(i>l && less(v,a[i-1])){a[i]=a[i-1];i--;}
    a[i]=v;
}

void sort(Item a[],int l,int r)
{/* 插入排序算法 */
    for(int i=l+1;i<=r;i++)insert(a,l,i);
}

