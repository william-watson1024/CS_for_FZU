// 测试链表结构排序算法

#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "linkmsort.h"
//#include "binsort.h"

void test()
{ 
    int N=33;
    link p=NewNode();
    link c=p;
    p->element=1000*(1.0*rand()/RAND_MAX);
    p->next=0;
    for(int i=1;i<N;i++){
        link q=NewNode();
        q->element=1000*(1.0*rand()/RAND_MAX);
        q->next=0;
        p->next=q;
        p=q;
    }
    c=mergesort1(c);
    //c=binsort(c);
    for(p=c;p;p=p->next)printf("%3d ",p->element);
    printf("\n");
}

int  main()
{
    test();
    return 0;
}

