// 栈结点 

typedef struct snode *slink;/* 栈结点指针类型 */
typedef struct snode{/* 栈结构 */
    StackItem element;/* 栈元素 */ 
    slink next;/* 下一结点指针 */ 
}StackNode;

slink NewStackNode()
{
    return (slink)malloc(sizeof(StackNode));
}

typedef struct lstack *Stack;/* 栈指针类型 */
typedef struct lstack{/* 栈结构 */
    slink top;/* 栈顶指针 */
}Lstack;


