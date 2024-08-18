// ≤‚ ‘≈≈–ÚÀ„∑®

#include <stdio.h>
#include <stdlib.h>

#include "item.h"
//#include "bubble.h"
//#include "insort.h"
//#include "selsort.h"
#include "quicksort.h"
//#include "ranquicksort.h"
//#include "nonquicksort.h"
//#include "m3quicksort.h"
//#include "3wquicksort.h"
#include "msort.h"
//#include "countsort.h"
//#include "radixsort.h"

#define maxN 433333 

void test()
{
    int a[maxN],N=0;
    //while(scanf("%d",&a[N])==1)N++;
    N=333;
    for(int i=0;i<N;i++)a[i]=maxN*(1.0*rand()/RAND_MAX);
    //for(int i=0;i<N;i++)printf("%3d ",a[i]);printf("\n");
    sort(a,0,N-1);
    //sort(a,N);
    for(int i=0;i<N;i++)printf("%3d ",a[i]);
    printf("\n");
}

int  main()
{
    test();
    return 0;
}

