#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "item.h"
#include "quicksort.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)
#define maxn 1500

int n,m;
int a[maxn][maxn];

int maxs()
{
    for(int i=0;i<n;i++)sort(a[i],0,m-1);
    int i,j,sum=a[n-1][m-1],pre=a[n-1][m-1];
    for(i=n-2;i>=0;i--){
       for(j=m-1;j>=0;j--)
         if(a[i][j]<pre){
            pre=a[i][j];
            sum+=pre;
            break;
         }
       /* j=-1 则找不到递增序列 */
       if(j==-1)return 0;
    }
    return sum;
}
 
void comp()
{
    while(scanf("%d",&n)==1){
        scanf("%d",&m);
        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
              scanf("%d",&a[i][j]);
        cout << maxs();
    }
}

int main()
{
	comp();
	return 0;
} 
