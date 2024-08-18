/* 极小化堆 */
/* 
使用时前置语句 
#include "setitem.h"
#include "minheap.h"
*/

#ifndef MinHeap_
#define MinHeap_

typedef struct minheap *Heap;/* 极小化堆指针类型 */
typedef struct minheap {/* 极小化堆 */
      int last,/* 最后一个单元 */ 
          maxsize;/* 堆数组的最大长度 */ 
      SetItem *heap;/* 元素数组 */
}Minheap;

Heap MinHeapInit(int HeapSize)
{/* 创建一个空堆 */
   Heap H=(Heap)malloc(sizeof *H);
   H->maxsize=HeapSize;
   H->heap=(SetItem *)malloc((H->maxsize+1)*sizeof(SetItem));
   H->last=0;
   return H;
}

int HeapSize(Heap H)
{/* 堆的大小 */ 
   return H->last;
}

SetItem HeapMin(Heap H)
{/* 堆中最小元 */ 
    if(H->last==0)return 0;/* 空堆 */
    else return H->heap[1];/* 堆中最小元 */
}

void HeapInsert(SetItem x,Heap H)
{/* 堆插入运算 */
   if(H->last==H->maxsize)return;/* 堆已满 */
   /* 从堆底开始搜索元素x的插入位置 */
   int i=++H->last;
   while(i!=1 && less(x,H->heap[i/2])){
        H->heap[i]=H->heap[i/2];/* 元素下移 */
        i/=2;/* 向上搜索 */
    }
    H->heap[i]=x;
}

SetItem DeleteMin(Heap H)
{/* 抽取堆中最小元 */ 
   if(H->last==0)return 0;/* 堆已空 */;
   SetItem x=H->heap[1];/* 堆中最小元 */
   /* 重构堆 */
   SetItem y=H->heap[H->last--]; /* 堆中最后一个元素 */
   /* 从堆顶开始搜索元素y的位置 */
   int i=1, /* 堆的当前位置 */
       ci=2; /* i的儿子结点在堆中位置 */
   while(ci<=H->last){ /* 搜索y的插入位置 */
      if(ci<H->last && less(H->heap[ci+1],H->heap[ci]))ci++;
      /* 可在heap[i]处插入否 */ 
      if(!less(H->heap[ci],y))break;/* 可插入 */ 
      /* 不可插入 */ 
      H->heap[i]=H->heap[ci];/* 儿子结点上升 */
      i=ci;/* 当前结点下降 */
      ci*=2;
   }
   H->heap[i]=y;
   return x;
}

Heap BuildHeap(SetItem a[],int size,int arraysize)
{/* 将数组a调整为一个堆 */
   Heap H=MinHeapInit(arraysize);
   H->heap=a;
   H->last=size;
   H->maxsize=arraysize;
   for(int i=H->last/2;i>=1;i--){
      SetItem y=H->heap[i]; /* 堆顶 */ 
      /* 调整y的位置 */
      int c=2*i; /* 结点i的左儿子结点 */
      while(c<=H->last){
         if(c<H->last &&  less(H->heap[c+1],H->heap[c]))c++;
         /* 可在heap[c/2]处插入y否 */
         if(!less(H->heap[c],y))break;/* 可插入 */ 
         /* 不可插入 */
         H->heap[c/2]=H->heap[c];/* heap[c]上升 */
         c*=2;/* 当前结点c下降 */
      }
      H->heap[c/2]=y;
   }
   return H;
}

void HeapOut(Heap H)
{/* 输出堆 */
   for(int i=1;i<=H->last;i++)printf("  %d",H->heap[i]);
   printf( "\n");
}

void HeapSort(SetItem a[],int n)
{/* 堆排序算法 */
   Heap H=BuildHeap(a,n,n);/* 建初始堆 */
   /* 从堆中逐次抽取最小元 */
   for(int i=n-1;i>=1;i--){
      SetItem x=DeleteMin(H);
      a[i+1]=x;
   }
}

#endif
