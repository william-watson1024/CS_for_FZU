#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef double num;
const int maxn=51111;

typedef struct recnode *Rectangle;

typedef struct recnode
{
    int x,y,h,w;/* (x,y)是矩形左下角点的坐标；h是矩形的高；w是矩形的宽。*/
}Recnode;

Rectangle RecInit()
{
    Rectangle R=(Rectangle)malloc(sizeof *R);
    R->x=0; R->y=0; R->h=0; R->w=0;
    return R;
}

void RecSet(int x, int y, int h, int w, Rectangle R)
{
    R->x=x; R->y=y; R->h=h; R->w=w;
}

int GetHeight(Rectangle R)
{
    return R->h;
}

int GetWidth(Rectangle R)
{
    return R->w;
}

double c(double x);

int max(int x,int y)
{
    return x>y?x:y;
}

float max(float x,float y)
{
   return x>y?x:y;
}

num max(num x,num y)
{
   return x>y?x:y;
}

void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}

void swap(float *x, int *y)
{
   float temp = *x;
   *x = *y;
   *y = temp;
}

void swap(long *x, int *y)
{
   long temp = *x;
   *x = *y;
   *y = temp;
}

void swap(num *x, int *y)
{
   num temp = *x;
   *x = *y;
   *y = temp;
}

int factorial(int n)
{
    if (n==0) return 1;
    return n*factorial(n-1);
}

int fibonacci(int n)
{
   if (n<=1) return 1;
   return fibonacci(n-1)+fibonacci(n-2);
}

int f[maxn];
int fibonacci1(int n)
{
   f[0]=f[1]=1;
   for(int i=2;i<=n;i++)f[i]=f[i-1]+f[i-2];
   return f[n];
}

int fibonacci2(int n)
{
    f[0]=f[1]=1;
    while(--n)f[n&1]=f[0]+f[1];
    return f[1];
}

void perm(int list[], int k, int m)
{/* 产生list[k:m]的所有排列 */
   if(k==m){/* 已排定 */
      for (int i=0;i<=m;i++) printf ("%d ",list[i]);
      printf ("\n");
    }
    else /* 递归产生排列 */
       for(int i=k;i<=m;i++){
          swap(&list[k],&list[i]);
          perm(list,k+1,m);
          swap(&list[k],&list[i]);
        }
}

double s(double x)
{
    if (-0.005<x && x<0.005) return x-x*x*x/6;
    return 2*s(x/2)*c(x/2);
}

double c(double x)
{
    if (-0.005<x && x<0.005) return 1.0-x*x/2;
    return 1.0-2*s(x/2)*s(x/2);
}

int **malloc2d(int r,int c)
{
    int **t=(int **)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)t[i]=(int *)malloc(c*sizeof(int));
    return t;
}

int main()
{
    int k,m,n,*p,**x;
    n=8;
    p=&n;
    k=*p;
    float *y=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)y[i]=i+3;
    for(int i=0;i<n;i++)printf("%f \n",y[i]);
    
    m=10;
    n=8;
    x=malloc2d(m,n);
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)x[i][j]=i*j;
    for (int i=0;i<m;i++){
      for (int j=0;j<n;j++)printf("%d ",x[i][j]);
      printf ("\n");
    }
      
    Recnode rr;
    Rectangle R;
    R=&rr;
    //R = RecInit();
    //RecSet(1, 1, 2, 3, R);
    rr.x=1; rr.y=1; rr.h=12; rr.w=13;
    printf("h=%d  w=%d \n",GetHeight(R),GetWidth(R));
    printf("x=%d  y=%d \n",R->x,R->y);
    printf("h=%d  w=%d \n",rr.h,rr.w);
    
    char *str;
    /* 为字符串分配内存 */
    if ((str=(char *)malloc(10))==0){
        printf("内存不足 \n");
        exit(1);/* 退出 */
    }
    strcpy(str, "Hello");
    /* 显示字符串 */
    printf("字符串 %s\n", str);
    /* 释放内存 */
    free(str);

    for(int i=1;i<11;i++)printf ("%d ",fibonacci(i));
    printf ("\n");
    n=3;
    int *z=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)z[i]=i+1;
    perm(z,0,n-1);
	return 0;
}
