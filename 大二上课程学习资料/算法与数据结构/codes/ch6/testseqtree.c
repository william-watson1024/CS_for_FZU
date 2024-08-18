/* ≤‚ ‘–Ú¡– ˜ */

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<algorithm>
using namespace std;

#include "seqtree.h"

void tst()
{
	int a,b,c,n;
    scanf("%d",&n);
    treeinit(n);
    //outtree();
    //outtree(1);
    printf("n=%d\n",n);
    while(scanf("%d %d %d",&a,&b,&c)==3){
        if(c==0){
            //outtree(1);
            printf("smu=%d\n",querysum(a,b));
            printf("min=%d\n",querymin(a,b));
            printf("max=%d\n",querymax(a,b));
        }
        else if(c<0)insert(a,-b);
        else insert(a,b);
    }
}


int main()
{
	tst();
	//h=6;m=1;
	//printf("%d\n",1<<(h-m));
    return 0;
}

/* tst.in
10
1 2 3 4 5 6 7 8 9 10
1 3 0
3 6 1
2 7 0
10 2 -1
6 3 1
3 10 0

tst.out
n=10
smu=6
min=1
max=3
smu=33
min=2
max=9
smu=59
min=4
max=9
*/
