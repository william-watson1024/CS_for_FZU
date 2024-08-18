// 单链表结点 

typedef struct node *link;/* 表结点指针类型 */
typedef struct node{/* 表结点类型 */
    ListItem element;/* 表元素 */ 
    link next;/* 指向下一结点的指针 */
} Node;

typedef struct llist *List;/* 单链表指针类型 */
typedef struct llist{/* 单链表类型 */
    link first,/* 链表表首指针 */
         curr,/* 链表当前结点指针 */
         last;/* 链表表尾指针 */
}Llist;

link NewNode()
{
    return (link)malloc(sizeof(Node));
}

List ListInit();
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);


