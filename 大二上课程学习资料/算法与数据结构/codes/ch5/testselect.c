// 测试选择算法

#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "select.h"
//#include "worstselect.h"

int  main()
{
    int a[100],k=9,N=0;
    //while(scanf("%d",&a[N])==1)N++;
    N=33;
    for(int i=0;i<N;i++)a[i]=1000*(1.0*rand()/RAND_MAX);
    int m=select(a,0,N-1,k);
    sort(a,0,N-1);
    for(int i=0;i<N;i++)printf("%3d ",a[i]);
    printf("\n");
    printf("第k小元素  %3d\n", m);
    printf("\n");
    return 0;
}

