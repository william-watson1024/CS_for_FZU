/* 随机选择算法 */
/* 
使用时前置语句 
#include "item.h"
#include "select.h"
*/

#include "ranquicksort.h"

Item randomsel(Item a[],int l,int r,int k)
{/* 随机选择算法 */
    if(r<=l)return a[r];
    int i=randompartition(a,l,r);
    int j=i-l+1;
    if(j==k)return a[i];
    if(j>k)return randomsel(a,l,i-1,k);
    else return randomsel(a,i+1,r,k-j);
}

Item randomselect(Item a[],int l,int r,int k)
{/* 消除尾递归选择算法 */
    int i,j;
    while(r>l){
        i=randompartition(a,l,r);
        j=i-l+1;
        if(j==k)return a[i];
        if(j>k)r=i-1;
        else{l=i+1;k-=j;}
    }
    return((r<i)?a[l]:a[r]);
}

Item select(Item a[],int l,int r,int k)
{
    //randomsel(a,l,r,k);
    randomselect(a,l,r,k);
}
