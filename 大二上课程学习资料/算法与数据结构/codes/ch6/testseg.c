/* ²âÊÔÏß¶ÎÊ÷ */

#include <stdio.h>
#include <stdlib.h>
#include "segtree.h"

#define rep(i,n) for(int i=0;i<=n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repD(i,n) for(int i=n;i;i--)
#define swap(a,b) (a)^=(b)^=(a)^=(b)

int n,m;
float x[maxn];
intv s[maxn];

int readin0()
{
    int j=0;
    while(scanf("%f",&xx[j++])==1);j--;
    printf("%d\n",j);
    rep(i,j-1)printf("%.2f  ",xx[i]);printf("\n");
    return j;
}

void readin()
{
    int l,h;
    scanf("%d",&n);
    rep(i,n-1)scanf("%f",&x[i]);
    scanf("%d",&m);
    rep(i,m-1){
        scanf("%d %d",&l,&h);
        s[i].low=l,s[i].high=h;
    }
    printf("%d %d\n",n,m);
    rep(i,n-1)printf("%.2f  ",x[i]);printf("\n");
    rep(i,m-1)printf("%d %d\n",s[i].low,s[i].high);printf("\n");
}

int main()
{
    float xxx=1.50;
    readin();
    buildst(n,m,x,s);
    //buildst(14,m,x,s);
    outtree(n);
    printf("x=%.2f stab=%d\n",xxx,stab(xxx,1));
    printf("del s[0]\n"); 
    erase(s[0],1);
    outtree(n);
    return 0;
}

/* test.in 
7
1.5
3.6
11.7
23.9
156.3
211.7
356.8
4
0 3
1 6
1 5
4 6
*/ 
 
