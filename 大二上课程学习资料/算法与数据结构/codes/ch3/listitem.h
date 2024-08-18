typedef int ListItem; /* 表元素类型 int */
typedef ListItem* addr;/* 表元素指针类型 */
#define eq(A,B) (A==B) /* 元素相等 */

void ItemShow(ListItem x)
{/* 输出表元素 */
   printf("%d \n", x);
}
