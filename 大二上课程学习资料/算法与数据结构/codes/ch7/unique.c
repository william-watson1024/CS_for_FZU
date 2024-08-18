/* 元素唯一性问题 */

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "setitem.h"
#include "hash.h"
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)

const int maxn=2000;

int hash(SetItem x)
{
   return x%70571;
}
 
bool unique(int a[],int n)
{
   HashTable h=HTInit(maxn,hash);
   for (int i=0;i<n;i++){
      if (HTMember(a[i],h))return false;
      HTInsert(a[i],h);
   }
   return true;
}
 
int main()
{   
    int a[]={9,8,2,6,1,8,5,3,4,7};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<unique(a,n);
    cin>>n;
    return 0;
}
