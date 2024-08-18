// 集合的等价类划分算法

#include <stdio.h>
#include <stdlib.h>
#include "listitem.h"
#include "chain.h"
#include "stackitem.h"
#include "lstack.h"

void equiv()
{
    int a,b,n,r,*q,*out;
    Stack stack=StackInit();
    scanf("%d",&n);/* 输入集合中元素个数 */
    scanf("%d",&r);/* 输入等价性条件数 */
    /* 为集合中每个元素建立一个链表 */
    List *L=(List *)malloc((n+1)*sizeof(*L));
    for(int i=1;i<=n;i++)L[i]=ListInit();
    /* 顺序处理所给等价性条件 */
    for(int i=1;i<=r;i++){
        scanf("%d%d",&a,&b);/* 输入等价性条件 */
        ListInsert(0,b,L[a]);
        ListInsert(0,a,L[b]);
    }
    /* 对链表进行处理，找出所有隐含的等价关系 */
    out=(int *)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)out[i]=0;
    /* 输出等价类 */
    for(int i=1;i<=n;i++)
        if(!out[i]){/* 新等价类 */
            printf("等价类: %d ",i);
            out[i]=1;
            Push(i,stack);
            /* 从栈中取等价类中元素 */
            while(!StackEmpty(stack)) {
                int j=Pop(stack);
                /* L[j] 中元素属于同一等价类 */
                IterInit(L[j]);  /* 搜索游标 */
                q=CurrItem(L[j]);
                b=ListLength(L[j]);
                for(a=1;a<=b;a++){
                    if(!out[*q]) {  /* q属于同一等价类 */ 
                       StackShow(*q);
                       out[*q]=1;
                       Push(*q,stack);
                    }
                    IterNext(L[j]);
                    q=CurrItem(L[j]);
                }
            }
            printf("\n");
        }/* endif */
}

int main()
{
    equiv();
    return 0;
}

/* test.in 
10
7
1 6
2 5
4 1
9 2
7 10
8 5
7 9
*/

/* test.out

等价类: 1 4 6 
等价类: 2 9 5 8 7 10 
等价类: 3 
*/
