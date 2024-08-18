/* 计数排序算法 */
/* 
使用时前置语句 
#include "item.h"
#include "countsort.h"
*/

#define m 10000

void ctsort(int a[],int b[],int n)
{/* 计数排序算法 */
    int cnt[m]={0};
    for(int i=0;i<n;i++)cnt[a[i]]++;
    /* cnt[i]中存放的是a中键值等于i的元素个数 */
    for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
    /* cnt[i]中存放的是a中键值小于或等于i的元素个数 */
    for(int i=n-1;i>=0;i--)b[--cnt[a[i]]]=a[i];
}

void countsort(int a[],int l,int r)
{/* 计数排序算法 */
    int *b=(int *)malloc(sizeof(int)*(r+1));
    int cnt[m]={0};
    for(int i=l;i<=r;i++)cnt[a[i]]++;
    /* cnt[i]中存放的是aa[l,r]中键值等于i的元素个数 */
    for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
    /* cnt[i]中存放的是a[l,r]中键值小于或等于i的元素个数 */
    for(int i=r;i>=l;i--)b[--cnt[a[i]]]=a[i];
    /* 回写a[l,r] */
    for(int i=l;i<=r;i++)a[i]=b[i-l];
    free(b);    
}

void sort(int a[],int l,int r)
{
    countsort(a,l,r);
}

