// 数组单元类型
typedef struct snode *link;/* 结点指针类型 */
typedef struct snode {
    ListItem element;/* 表中元素 */ 
    int next;/* 模拟指针的游标 */
} Snode;

