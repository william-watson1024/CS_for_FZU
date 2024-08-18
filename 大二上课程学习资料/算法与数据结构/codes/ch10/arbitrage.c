/* Ì×»ãÎÊÌâ */

#include <ctime>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define rep(i,n)for(int i=0;i<=n;i++)
#define rep1(i,n)for(int i=1;i<=n;i++)
#define repD(i,n)for(int i=n;i;i--)

const int maxn=1000;
int n;
double a[maxn][maxn];


int arbitrage(double a[][maxn],int n)
{
    for(int k=0;k<n;k++)
       for(int i=0;i<n;i++)
          for(int j=0;j<n;j++){
             double tmp=a[i][k]*a[k][j];
             a[i][j]=(tmp>a[i][j])?tmp:a[i][j];
             if((i!=j)&&(a[i][j]*a[j][i]>1))return 1;
        }
    return 0;
}

int comp()
{
    n=100;
    srand(time(NULL));
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
          a[i][j]=((rand()% n)+1)*1.0/n;
    a[1][2]=0.7;
    a[2][6]=9.5;
    a[6][1]=0.16;
    printf("%d\n",arbitrage(a,n));
    return 0;
}


int main()
{
	comp();
	return 0;
}
