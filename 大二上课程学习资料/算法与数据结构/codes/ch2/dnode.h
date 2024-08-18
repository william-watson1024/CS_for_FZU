// 循环双链表结构

typedef struct node *link;/* 双链表结点指针类型 */
typedef struct node {/* 双链表结点类型 */
    ListItem element;/* 表元素 */
    link left,/* 链表左结点指针 */ 
         right;/* 链表右结点指针 */ 
} Node;

typedef struct dlist *List;/* 循环双链表指针类型 */
typedef struct dlist{/* 循环双链表结构 */
    int n;/* 表长 */
    link header,/* 链表表首指针 */
         curr;/* 链表当前结点指针 */
}Dlist;

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


