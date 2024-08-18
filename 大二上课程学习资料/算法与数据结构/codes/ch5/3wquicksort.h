/* 三划分快速排序算法 */
/* 
使用时前置语句 
#include "item.h"
#include "3wquicksort.h"
*/

void sort(Item a[],int l,int r)
{/* 三划分快速排序算法 */
    int i=l-1,j=r,p=l-1,q=r;
    Item v=a[r];//把最后一个数当作基准值 
    if(r<=l)return;
    for(;;){
       while(less(a[++i],v));//找到前面大于v的 
       while(less(v,a[--j]))if(j==l)break;//找到后面小于v的
       if(i>=j)break;
       swap(a[i],a[j]);//交换这两个找到的 
       if(eq(a[i],v)){p++;swap(a[p],a[i]);}//把前面与v相等的聚集到前面 
       if(eq(v,a[j])){q--;swap(a[q],a[j]);}//把后面与v相等的聚集到最后 
    }
    swap(a[i],a[r]);j=i-1;i=i+1;//把基准值v(a[r])放到中间 
    for(int k=l;k<p;k++,j--)swap(a[k],a[j]);//把聚集到前面的与v相等的放到中间 
    for(int k=r-1;k>q;k--,i++)swap(a[k],a[i]);//把聚集到后面的与v相等的放到中间
    sort(a,l,j);//小于基准值v的部分继续递归 
    sort(a,i,r);//大于基准值v的部分继续递归
}

