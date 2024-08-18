// 指针队列结点 

typedef struct qnode *qlink;/* 队列结点指针类型 */
struct qnode{/* 队列结点 */
    QItem element;/* 队列元素 */
    qlink next;/* 指向下一结点的指针 */
}Qnode;

qlink NewQNode()
{
    return (qlink)malloc(sizeof(Qnode));
}

typedef struct lque *Queue;/* 队列指针类型 */
typedef struct lque{/* 队列结构 */
      qlink front;/* 队首指针 */
      qlink rear;/* 队尾指针 */
}Lqueue;


Queue QueueInit();
int QueueEmpty(Queue Q);
QItem QueueFirst(Queue Q);
QItem QueueLast(Queue Q);
void EnterQueue(QItem x, Queue Q);
QItem DeleteQueue(Queue Q);
