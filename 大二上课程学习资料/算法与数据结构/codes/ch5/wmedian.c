/* 带权中位数 */
#include <stdio.h>
#include <stdlib.h>

#include "item1.h"
#include "ranquicksort.h"

int select(Item a[],int l,int r,int k)
{
    int i,j;
    while(r>l){
        i=randompartition(a,l,r);
        j=i-l+1;
        if(j==k)return i;
        if(j>k)r=i-1;
        else{l=i+1;k-=j;}
    }
    return((r<i)?l:r);
}

Item wmedian1(Item a[],int n)
{/* 带权中位数 */
    int i=0;double c=0;
    sort(a,0,n-1);
    while(i<n && c+a[i].weight<0.5)c+=a[i++].weight;
    return a[i];
}

Item wmedian(Item a[],int l,int r,double s1,double s2)
{/* 带权中位数 */
    int i,m;
    double c1=0,c2;
    if(l==r)return a[l];
    m=select(a,l,r,(r-l+1)/2);
    for (i=l; i < m; i++)c1+=a[i].weight;
    c2=s1+s2-c1-a[m].weight;
    if (c1>s1)return wmedian(a,l,m-1,s1,s2-c2-a[m].weight);
    if (c2>s2)return wmedian(a,m+1,r,s1-c1-a[m].weight,s2);
    return a[m];
}

int  main()
{
    Item a[100];int N=0;
    N=33;
    for(int i=0;i<N;i++)a[i].element=1000*(1.0*rand()/RAND_MAX);
    for(int i=0;i<N;i++)a[i].weight=1000*(1.0*rand()/RAND_MAX);
    double s=0;
    for(int i=0;i<N;i++)s+=a[i].weight;
    for(int i=0;i<N;i++)a[i].weight/=s;
    for(int i=0;i<N;i++)printf("%f ",a[i].element);
    printf("\n");
    for(int i=0;i<N;i++)printf("%f ",a[i].weight);
    printf("\n");

    printf("带权中位数 ");
//    ItemShow(wmedian1(a,N));
    ItemShow(wmedian(a,0,N-1,0.5,0.5));
    for(int i=0;i<N;i++)printf("%f ",a[i].element);
    printf("\n");
    for(int i=0;i<N;i++) printf("%f ",a[i].weight);
    printf("\n");
    return 0;
}

