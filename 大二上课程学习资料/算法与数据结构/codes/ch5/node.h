/* 单链表结点类型 */

typedef struct node *link;/* 单链表结点指针类型 */
typedef struct node{
    Item element;/* 待排序元素 */
    link next;/* 下一结点指针 */
}Node;

link NewNode()
{/* 产生新结点 */
    return (link)malloc(sizeof(Node));
}
