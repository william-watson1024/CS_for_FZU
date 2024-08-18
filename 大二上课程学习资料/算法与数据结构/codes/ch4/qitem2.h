// 队列元素类型

typedef struct pnode *Pos;/* 位置结点指针类型 */
struct pnode{/* 位置结点 */
    int row,/* 行 */ 
        col;/* 列 */
}Pnode;

typedef Pos QItem;/* 队列元素类型 */ 
typedef QItem* Qaddr;/* 队列元素指针类型 */ 

Pos NewPos()
{
    return (Pos)malloc(sizeof(Pnode));
}

void QItemShow(QItem x)
{
   printf("%d  %d\n", x->row,x->col);
}

