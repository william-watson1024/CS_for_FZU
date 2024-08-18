#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
#include "cdouble.h"
//#include "cchain.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)
#define maxn 150000

int n,m;
long long s[maxn];
List L;

long long maxsum()
{
    long long msum=s[1];
    L=ListInit();
    for(int i=1;i<=n;i++){
        s[i]+=s[i-1];/* 前缀和 */
        while(!ListEmpty(L) && s[ListRetrieve(1,L)]>s[i])
            ListDelete(1,L);
        ListInsert(0,i,L);
        int len=ListLength(L);/* 表长 */
        while(!ListEmpty(L) && i-m>ListRetrieve(len,L))
            ListDelete(len--,L);
        msum=max(msum,s[i]-s[ListRetrieve(len,L)]);
    }
    return msum;
}

int comp()
{
    while(scanf("%d",&n)==1){
          scanf("%d",&m);
          for(int i=1;i<=n;i++)scanf("%I64d",&s[i]);
          printf("%I64d\n",maxsum());
	 }
     return 0;
}

int main()
{
	comp();
	return 0;
}

