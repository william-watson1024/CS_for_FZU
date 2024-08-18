// 集合链表结点 

typedef struct node *link;/* 表结点指针类型 */
struct node{/* 表结点类型 */
    SetItem element;/* 集合元素 */ 
    link next;/* 指向下一结点的指针 */
}Node;

typedef struct list *Set;/* 集合链表指针类型 */
typedef struct list{/* 集合链表类型 */
    link first;/* 链表表首指针 */
}LSet;

link NewNode()
{
    return (link)malloc(sizeof(Node));
}
