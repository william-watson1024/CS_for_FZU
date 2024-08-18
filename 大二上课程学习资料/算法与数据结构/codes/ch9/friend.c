/* ≈Û”—»¶Œ Ã‚ */ 

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ufset3.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)
#define maxn 30030

void uni(int x,int y,UFset uf)
{
    int a=UFfind(x,uf),b=UFfind(y,uf);
    UFunion(a,b,uf);   
}

int friends()
{
    int m,n,x,y,ans=0;
    char ch;
    scanf("%d%d",&n,&m);
    int e[n];
    for(int i=0;i<=n;i++)e[i]=0;
    UFset uf=UFinit(n);
    for(int i=0;i<m;i++){
        scanf("%s%d%d",&ch,&x,&y);
        if(ch=='E'){
            if(e[x])uni(y,e[x],uf);
            else e[x]=y;
            if(e[y])uni(x,e[y],uf);
            else e[y]=x;
        }
        else uni(x,y,uf);
    }
    for(int i=1;i<=n;i++){
        int j=UFfind(i,uf);
        if(j==i)ans++;
    }
    UFfree(uf); 
    return ans;
}


int main()
{
	cout<<friends()<<endl;
	return 0;
}
