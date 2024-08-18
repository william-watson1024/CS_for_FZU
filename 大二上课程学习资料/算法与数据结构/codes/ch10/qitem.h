// 队列元素类型

typedef int QItem;/* 队列元素类型 */ 
typedef QItem* Qaddr;/* 队列元素指针类型 */ 

void QItemShow(QItem x)
{/* 输出队列元素 */
   printf("%d ", x);
}

#define eq(A,B) (A==B)
