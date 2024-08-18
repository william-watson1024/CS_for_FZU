#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <deque>
#include "qitem.h"
#include "queue.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)
#define maxn 1500

namespace win{ 
int n,k;
int a[maxn];
int wmax[maxn];
int wmin[maxn];

void out()
{
    for(int i=k-1;i<n-1;i++)printf("%d ", wmin[i]);
    printf("%d\n", wmin[n-1]);
    for(int i=k-1;i<n-1;i++)printf("%d ", wmax[i]);
    printf("%d\n", wmax[n-1]);   
}

void comp()
{
    Queue maxq,minq;
    maxq=QueueInit(n);minq=QueueInit(n);
    for(int i=0;i<n;i++){
        while(!QueueEmpty(maxq) && a[i]>a[QueueLast(maxq)])
           DeleteRear(maxq);
        if(!QueueEmpty(maxq) && i-QueueFirst(maxq)>=k)
           DeleteQueue(maxq);
        EnterQueue(i,maxq);
        while(!QueueEmpty(minq) && a[i]<a[QueueLast(minq)])
           DeleteRear(minq);
        if(!QueueEmpty(minq) && i-QueueFirst(minq)>=k)
           DeleteQueue(minq);
        EnterQueue(i,minq);
        wmax[i]=a[QueueFirst(maxq)];
        wmin[i]=a[QueueFirst(minq)];
    }
    out();
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++){
        int d;
        scanf("%d", &d);
        a[i]=d;
    }
    comp();
    return 0;
}
}

int main()
{
	win::main();
	//rinput::create();
	return 0;
}
