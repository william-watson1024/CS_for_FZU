// 游标表结构 
typedef struct slist *List;/* 游标表指针类型 */
typedef struct slist{/* 游标表结构 */
      int first,/* 表首结点游标 */
          curr,/* 当前结点游标 */
          last;/* 表尾结点游标 */
      Space s;
}Slist;

List ListInit(int size);
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);


