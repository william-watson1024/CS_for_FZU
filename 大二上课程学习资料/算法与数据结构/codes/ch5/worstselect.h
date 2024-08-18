// 最坏情况下线性时间选择
/* 
使用时前置语句 
#include "item.h"
#include "worstselect.h"
*/

#include "quicksort.h"

int partitionv(Item a[],int l,int r,Item v)//对a[l,r]按v为基准划分 
{  
    int i=l-1,j=r+1,q=r;
    for (;;){
        while(less(a[++i],v));
        while(less(v,a[--j]))if(j==l)break;
        if(i>=j)break;
        swap(a[i],a[j]);
        if(!less(v,a[j]))q=j;
    }
    if(less(v,a[i]))swap(a[i],a[q]);
    return i;
}

Item select(Item a[],int l,int r,int k)
{
    if(r-l<7){
        /* 用某个简单排序算法对数组a[l:r]排序 */
        sort(a,l,r);
        int s=l+k-1;
        if(s>r)s=r;
        if(s<l)s=l;
        return a[s];
    }
    /* 将a[l+5*i]至a[l+5*i+4]的第3小元素与a[l+i]交换位置 */
    /* 找中位数的中位数，r-l-4即上面所说的n-5 */
    for(int i=0;i<=(r-l-4)/5;i++){
        int s=l+5*i;
        int t=s+4;
        sort(a,s,t);
        swap(a[l+i], a[s+2]);
    }
    Item x=select(a,l,l+(r-l-4)/5,(r-l+6)/10);
    int i=partitionv(a,l,r,x);
    int j=i-l+1;
    if(j==k)return a[i];
    if(j>k)return select(a,l,i-1,k);
    else return select(a,i+1,r,k-j);
}


