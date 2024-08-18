
#define RADIX 10 //基数

void  out(int a[],int l,int r)
{
    for(int i=l;i<=r;++i)printf("%3d ",a[i]);
    printf("\n");
}

void countsort(int a[],int b[],int l,int r,int p)
{/* 按位计数排序 */
    int cnt[RADIX]={0};/* 清空桶计数器 */
    for(int i=l;i<=r;i++)cnt[a[i]/p%RADIX]++;/* 桶计数 */
    /* cnt[i]中存放的是a[l,r]中键值p位等于i的元素个数 */
    for(int i=1;i<RADIX;i++)cnt[i]+=cnt[i-1];
    /* cnt[i]中存放的是a[l,r]中键值p位小于或等于i的元素个数 */
    for(int i=r;i>=l;i--)b[--cnt[a[i]/p%RADIX]]=a[i];
    /* 回写a[l,r] */
    for(int i=l;i<=r;i++)a[i]=b[i-l];
}

void RadixSort(int a[],int n)
{
	int maxv=0,pow=1;
	int *b=(int *)malloc(sizeof(int)*(n+1));
	for(int i=0;i<n;i++)if(a[i]>maxv)maxv=a[i];
	/* maxv 是a中最大整数，用于确定while循环的次数 */
	while(maxv/pow>0){
		int cnt[RADIX]={0};/* 清空桶计数器 */
		for(int i=0;i<n;i++)cnt[a[i]/pow%RADIX]++;/* 桶计数 */
        for(int i=1;i<RADIX;i++)cnt[i]+=cnt[i-1];/* 前缀和 */
		/* 按照桶位置排序 */
		for(int i=n-1;i>=0;i--)b[--cnt[a[i]/pow%RADIX]]=a[i];
        for(int i=0;i<n;i++)a[i]=b[i];/* 回写a */
        pow*=RADIX;/* 进位 */
	}
    free(b);
}

void RadixSort1(int a[],int l,int r)
{
    int maxv=0,pow=1;
    int *b=(int *)malloc(sizeof(int)*(r+1));
    for(int i=l;i<=r;i++)if(a[i]>maxv)maxv=a[i];
    /* maxv 是a[l,r]中最大整数，用于确定while循环的次数 */
    while(maxv/pow>0){
       int cnt[RADIX]={0};/* 清空计数器 */
       for(int i=l;i<=r;i++)cnt[a[i]/pow%RADIX]++;/* 按位计数 */
       for(int i=1;i<RADIX;i++)cnt[i]+=cnt[i-1];/* 前缀和 */
       /* 按位排序 */
       for(int i=r;i>=l;i--)b[--cnt[a[i]/pow%RADIX]]=a[i];
       for(int i=l;i<=r;i++)a[i]=b[i-l];/* 回写a */
       pow*=RADIX;/* 进位 */
    }
    free(b);
}

void RadixSort(int a[],int l,int r)
{
    int maxv=0,pow=1;
    int *b=(int *)malloc(sizeof(int)*(r+1));
    for(int i=l;i<=r;i++)if(a[i]>maxv)maxv=a[i];
    /* maxv 是a[l,r]中最大整数，用于确定while循环的次数 */
    while(maxv/pow>0){
        countsort(a,b,l,r,pow);/* 按位计数排序 */
        pow*=RADIX;/* 进位 */
    }
    free(b);
}

void sort(int a[],int l,int r)
{
    RadixSort(a,l,r);
    //out(a,l,r);
}

void sort(int a[],int n)
{
    //RadixSort(a,n);
    RadixSort(a,0,n-1);
}
