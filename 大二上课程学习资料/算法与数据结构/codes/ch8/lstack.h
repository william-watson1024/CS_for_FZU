// 用指针实现栈
/* 
使用时前置语句 
#include "stackitem.h"
#include "lstack.h"
*/

#include "stacknode.h"

Stack StackInit();
int StackEmpty(Stack S);
int StackFull(Stack S);
StackItem StackTop(Stack S);
void Push(StackItem x, Stack S);
StackItem Pop(Stack S);

Stack StackInit()
{
   Stack S=(Stack)malloc(sizeof *S);
   S->top=0;
   return S;
}

int StackEmpty(Stack S)
{
   return S->top==0;
}

StackItem StackTop(Stack S)
{/* 前提：栈非空 */
    return S->top->element;
}

void Push(StackItem x, Stack S)
{
    slink p=NewStackNode();
    p->element=x;
    p->next=S->top;
    S->top=p;
}

StackItem Pop(Stack S)
{/* 前提：栈非空 */
    StackItem x=S->top->element;
    slink p=S->top;
    S->top=p->next;
    free(p);
    return x;
}

