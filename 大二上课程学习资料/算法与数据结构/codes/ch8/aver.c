/* 大数据统计 */

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include<vector>
#include <queue>
#include<algorithm>
#include "setitem.h"
#include "minheap.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)

namespace aver{
    
int high,low,n,x;
 
double comp(int low,int high,int n)
{
    int m=max(low,high);
    Heap minh=MinHeapInit(1+m);
    Heap maxh=MinHeapInit(1+m);
    long long sum=0;
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        sum+=x;
        HeapInsert(-x,maxh);
        if(HeapSize(maxh)>low)DeleteMin(maxh);
        HeapInsert(x,minh);
        if(HeapSize(minh)>high)DeleteMin(minh);
    }
    while(HeapSize(minh)>0)sum-=DeleteMin(minh);
    while(HeapSize(maxh)>0)sum+=DeleteMin(maxh);
    return 1.0*sum/(n-high-low);
}
  
int main()
{
    while (scanf("%d%d%d",&high,&low,&n), high && low && n)
       printf("%.2lf\n",comp(low,high,n));
    return 0;
}
}

int main()
{
	aver::main();
	return 0;
}
