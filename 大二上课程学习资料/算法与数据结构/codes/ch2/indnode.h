// 间接寻址链表结点

typedef struct indlist *List;/* 表指针类型 */
typedef struct indlist{/* 表结构类型 */
      int n,/* 表长 */
          curr;/* 当前位置 */
      int maxsize;/* 数组上界 */
      addr *table;/* 存储表元素指针的数组 */ 
}Indlist;


addr NewNode()
{
    return (addr)malloc(sizeof(addr));
}

List ListInit();
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);


