/* 带权中位数 */
#include <stdio.h>
#include <stdlib.h>

#include "item2.h"

int randomi(int l,int r)
{
    return l+(r-l)*(1.0*rand()/RAND_MAX);
}

int partition(Item a[],double w[],int l,int r)
{ 
    int i=l-1,j=r;Item v=a[r];
    for(;;){
        while(less(a[++i],v));
        while(less(v,a[--j]))if(j==l)break;
        if(i>=j)break;
        swap(a[i],a[j]);
        swap(w[i],w[j]);
    }
    swap(a[i],a[r]);
    swap(w[i],w[r]);
    return i;
}

int randompartition(Item a[],double w[],int l,int r)
{
    int i=randomi(l,r);
    swap(a[i],a[l]);
    swap(w[i],w[l]);
    return partition(a,w,l,r);
}

int select(Item a[],double w[],int l,int r,int k)
{
    int i,j;
    while(r>l){ 
        i=randompartition(a,w,l,r);
        j=i-l+1;
        if(j==k)return i;
        if(j>k)r=i-1;
        else{l=i+1;k-=j;}
    }
    return((r<i)?l:r);
}

void sort(Item a[],double w[],int l,int r)
{
    for(int i=l+1;i<=r;i++)
      for(int j=i;j>l;j--)
        if(less(a[j],a[j-1])){
          swap(a[j-1],a[j]);
          swap(w[j-1],w[j]);
        }
}

Item wmedian1(Item a[],double w[],int n)
{
    int i=0;double c=0;
    sort(a,w,0,n-1);
    while(i<n && c+w[i]<=0.5)c+=w[i++];
    return a[i];
}

Item wmedian(Item a[],double w[],int l,int r,double s1,double s2)
{
    int i,m;
    double c1=0,c2;
    if(l==r)return a[l];
    m=select(a,w,l,r,(r-l+1)/2);
    for(i=l;i<m;i++)c1+=w[i];
    c2=s1+s2-c1-w[m];
    if(c1>s1)return wmedian(a,w,l,m-1,s1,s2-c2-w[m]);
    if(c2>s2)return wmedian(a,w,m+1,r,s1-c1-w[m],s2);
    return a[m];
}

int main()
{
    Item a[100];int N=0;
    double w[100];
    N=33;
    for(int i=0;i<N;i++)a[i]=1000*(1.0*rand()/RAND_MAX);
    for(int i=0;i<N;i++)w[i]=1000*(1.0*rand()/RAND_MAX);
    double s=0;
    for(int i=0;i<N;i++)s+=w[i];
    for(int i=0;i<N;i++)w[i]/=s;
    printf("带权中位数 %f\n",wmedian1(a,w,N));

    for(int i=0;i<N;i++)printf("%f ",a[i]);
    printf("\n");
    for(int i=0;i<N;i++)printf("%f ",w[i]);
    printf("\n");

    printf("带权中位数 %f\n",wmedian(a,w,0,N-1,0.5,0.5));
    for(int i=0;i<N;i++)printf("%f ",a[i]);
    printf("\n");
    for(int i=0;i<N;i++)printf("%f ",w[i]);
    printf("\n");
}

