// 用数组实现栈
/* 
使用时前置语句 
#include "stackitem.h"
#include "stack.h"
*/

typedef struct astack *Stack;/* 栈指针类型 */
typedef struct astack{/* 栈结构 */
      int top,/* 栈顶 */
          maxtop;/* 栈空间上界 */
      StackItem *data;/* 存储栈元素的数组 */
}Astack;

Stack StackInit(int size);
int StackEmpty(Stack S);
int StackFull(Stack S);
StackItem StackTop(Stack S);
void Push(StackItem x, Stack S);
StackItem Pop(Stack S);

Stack StackInit(int size)
{
   Stack S=(Stack)malloc(sizeof *S);
   S->data=(StackItem *)malloc(size*sizeof(StackItem));
   S->maxtop=size;
   S->top=-1;
   return S;
}

int StackEmpty(Stack S)
{
    return S->top < 0;
}

int StackFull(Stack S)
{
    return S->top>=S->maxtop;
}

StackItem StackTop(Stack S)
{/* 前提：栈非空 */
   if(StackEmpty(S))return 0;
   return S->data[S->top];
}

void Push(StackItem x, Stack S)
{/* 前提：栈未满 */
    if(StackFull(S))return;
    S->data[++S->top]=x;
}

StackItem Pop(Stack S)
{/* 前提：栈非空 */
    if(StackEmpty(S))return 0;
    return S->data[S->top--];
}

void StackFree(Stack S)
{
    free(S->data);
    free(S);
}
