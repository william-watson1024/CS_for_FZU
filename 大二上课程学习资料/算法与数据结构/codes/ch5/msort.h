/* 合并排序算法 */

//使用时前置语句 
#include "item.h"
//#include "msort.h"


#define mini(A,B) (A<B)?A:B
#define maxN 10000

Item b[maxN];//作临时存放数据的数组 

void insertion(Item a[],int l,int r)//插入排序 
{
    for(int i=l+1;i<=r;i++)compswap(a[l],a[i]);
    for(int i=l+2;i<=r;i++){ 
        int j=i;Item v=a[i];
        while(less(v,a[j-1])){a[j]=a[j-1];j--;}
        a[j]=v;
    }
}

void copy(Item b[],Item a[],int l,int r)
{
    for(int i=l;i<=r;i++)a[i]=b[i];
}

void mergeab(Item a[],Item b[],int l,int m,int r)
{/* 合并a[l:m]}和a[m+1:r] 到b[l:r] */
   int i=l,j=m+1,k=l;
    /* 取两段中较小元素到数组b中 */
   while((i<=m) && (j<=r))
      if(less(a[i],a[j]))b[k++]=a[i++];
      else b[k++]=a[j++];
   /* 处理剩余元素 */
   if(i>m)for(i=j;i<=r;i++)b[k++]=a[i];
   else for(;i<=m;i++)b[k++]=a[i];
}

void msort(Item a[],int l,int r)
{/* 合并排序算法 */
    int m=(r+l)/2;/* 取中点 */
    if(r<=l)return;
    msort(a,l,m);/* 对左半段排序 */
    msort(a,m+1,r);/* 对右半段排序 */
    mergeab(a,b,l,m,r);/* 合并到数组b */
    copy(b,a,l,r);/* 复制回数组a */
}

void mergeAB(Item c[],Item a[],int N,Item b[],int M )
{//把数组a和b合并到c内 
    for(int i=0,j=0,k=0;k<N+M;k++){
        if(i==N){c[k]=b[j++];continue;}
        if(j==M){c[k]=a[i++];continue; }
        c[k]=(less(a[i],b[j]))?a[i++]:b[j++];
    }
}

void merge(Item a[],int l,int m,int r)
{
    int i,j,k;
    for(i=m+1;i>l;i--)b[i-1]=a[i-1];
    for(j=m;j<r;j++)b[r+m-j]=a[j+1]; 
    for(k=l;k<=r;k++)//一样用临时数组来合并 
       if(less(b[i],b[j]))a[k]=b[i++];
       else a[k]=b[j--];
}

void mergesort(Item a[],int l,int r)
{
    int m=(r+l)/2;
    if(r<=l)return;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
}
  
void mergesortAB(Item a[],Item b[],int l,int r)
{
    int m=(l+r)/2;
    if(r-l<=10){insertion(a,l,r);return;}
    mergesortAB(b,a,l,m);
    mergesortAB(b,a,m+1,r);
    mergeab(b,a,l,m,r);//合并b的两个区间内容到a 
}

void mergesort1(Item a[],int l,int r)
{
    for(int i=l;i<=r;i++)b[i]=a[i];
    mergesortAB(a,b,l,r);//b是临时数组 
}

void mergesortBU(Item a[],int l,int r)
{//自底向上合并排序 
    for(int m=1;m<=r-l;m=m+m)
      for(int i=l;i<=r-m;i+=m+m)
        merge(a,i,i+m-1,mini(i+m+m-1,r));
}

void sort(Item a[],int l,int r)
{
    //msort(a,l,r);    
    //mergesort(a,l,r);    
    mergesortBU(a,l,r);    
}

