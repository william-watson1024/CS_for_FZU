// 用循环数组实现队列
/* 
使用时前置语句 
#include "qitem.h"
#include "queue.h"
*/

typedef struct aque *Queue;/* 队列指针类型 */
typedef struct aque{/* 队列结构 */
      int maxsize;/* 循环数组大小 */
      int front;/* 队首游标 */
      int rear;/* 队尾游标 */
      QItem *queue;/* 循环数组 */
}Aqueue;

Queue QueueInit(int size);
int QueueEmpty(Queue Q);
int QueueFull(Queue Q);
QItem QueueFirst(Queue Q);
QItem QueueLast(Queue Q);
void EnterQueue(QItem x, Queue Q);
QItem DeleteQueue(Queue Q);

Queue QueueInit(int size)
{
   Queue Q=(Queue)malloc(sizeof *Q);
   Q->queue=(QItem *)malloc(size*sizeof(QItem));
   Q->maxsize=size;
   Q->front=Q->rear=0;
   return Q;
}

int QueueEmpty(Queue Q)
{
    return Q->front==Q->rear;
}

int QueueFull(Queue Q)
{
    return(((Q->rear+1)%Q->maxsize==Q->front)?1:0);
}

QItem QueueFirst(Queue Q)
{/* 前提：队列非空 */
    return Q->queue[(Q->front+1)%Q->maxsize];
}

QItem QueueLast(Queue Q)
{/* 前提：队列非空 */
    return Q->queue[Q->rear];
}

void EnterQueue(QItem x, Queue Q)
{
    Q->rear=(Q->rear+1)%Q->maxsize;
    Q->queue[Q->rear]=x;
}

QItem DeleteQueue(Queue Q)
{/* 前提：队列非空 */
    Q->front=(Q->front+1)%Q->maxsize;
    return Q->queue[Q->front];
}

void OutQueue(Queue Q)
{
    for(int i=Q->front;i!=Q->rear;i=(i+1)%Q->maxsize)
        QItemShow(Q->queue[(i+1)%Q->maxsize]);
}

