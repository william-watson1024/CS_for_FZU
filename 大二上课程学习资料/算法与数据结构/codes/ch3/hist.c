
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stackitem.h"
#include "stack.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)


namespace area{
const int maxn=1155555;
int n,h[maxn];

int histo()
{
    Stack stk=StackInit(n);
    int i=0,mx=0;
    while(i<n){
        if(StackEmpty(stk)||h[StackTop(stk)]<=h[i])Push(i++,stk);
        else{
            int tmp=StackTop(stk);
            Pop(stk);
            int a=h[tmp]*(StackEmpty(stk)?i:i-StackTop(stk)-1);
            if(mx<a)mx=a;
        }
    }
    /* 计算栈中剩余的非减序列的a[i] */ 
    while(!StackEmpty(stk)){
        int tmp=StackTop(stk);
        Pop(stk);
        int a=h[tmp]*(StackEmpty(stk)?i:i-StackTop(stk)-1);
        if(mx<a)mx=a;
    }
    return mx;
}

int comp()
{
    int i=0,r;
    while(scanf("%d",&r)==1)h[i++]=r;
    n=i;
    cout <<histo();
    return 0;
}
}
 
int main()
{
	area::comp();
	return 0;
}
