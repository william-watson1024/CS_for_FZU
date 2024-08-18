// 用指针实现队列
/* 
使用时前置语句 
#include "qitem.h"
#include "lqueue.h"
*/

#include "qnode.h"

Queue QueueInit()
{
   Queue Q=(Queue)malloc(sizeof *Q);
   Q->front=Q->rear=0;
   return Q;
}

int QueueEmpty(Queue Q)
{
    return Q->front==0;
}

QItem QueueFirst(Queue Q)
{/* 前提：队列非空 */
    return Q->front->element;
}

QItem QueueLast(Queue Q)
{/* 前提：队列非空 */
    return Q->rear->element;
}

void EnterQueue(QItem x, Queue Q)
{
    qlink p=NewQNode();/* 创建一个新结点 */
    p->element=x;
    p->next=0;
    /* 队尾插入新结点 */
    if(Q->front)Q->rear->next=p;/* 队列非空 */
    else Q->front=p;/* 队列空 */
    Q->rear=p;
}

QItem DeleteQueue(Queue Q)
{/* 前提：队列非空 */
	QItem x = Q->front->element; /* 将队首元素存于x中 */
    /* 删除队首结点 */
    qlink p=Q->front;
    Q->front=Q->front->next;
    free(p);
    return x;
}
