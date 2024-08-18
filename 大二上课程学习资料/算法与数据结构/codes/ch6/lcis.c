/* 最长连续递增子序列问题 */

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<algorithm>
using namespace std;
#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)

#include "seqtree1.h"

int comp()
{
	int x,y,n,m;
	char str[10];
	while(scanf("%d",&n)==1){
        scanf("%d",&m);
        for(int i=0;i<n;i++)scanf("%d",&xx[i]);
		treeinit(n);
		while(m--){
            scanf("%s%d%d",str,&x,&y);
            switch(str[0]){
                case 'Q':
                    printf("%d\n",query(x,y));
                    break;
                case 'A':
                    add(x,y);
                    break;
                case 'S':
                    add(x,-y);
                    break;
                case 'I':
                    insert(x,y);
                    break;
            }        			
		}
		//for(int i=0;i<n;i++)cout<<xx[i]<<" ";cout<<endl;
	}
	return 0;		
}

int main()
{
	comp();
	return 0;
}


