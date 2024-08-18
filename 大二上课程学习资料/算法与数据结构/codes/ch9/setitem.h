
typedef int SetItem;/* 有序集元素类型 int */
typedef SetItem* addr;

void SetItemShow(SetItem x)
{
   printf("%d ",x);
}

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {SetItem t=A;A=B;B=t;}
#define compswap(A,B) if(less(B,A))swap(A,B)
