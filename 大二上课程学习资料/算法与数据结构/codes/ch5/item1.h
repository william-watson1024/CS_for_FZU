/* 带权中位数结点 */

typedef struct node{
    double element;/* 元素值 */ 
    double weight;/* 元素权值 */ 
} Node;

typedef Node Item;/* 带权中位数结点类型 */
typedef Item* addr;/* 带权中位数结点指针类型 */

#define key(A) (A.element)/* 结点元素值 */
#define less(A,B) (key(A) < key(B))/* 按结点元素值比较 */
#define eq(A,B) (!less(A,B) && !less(B,A))/* 按结点元素值相等 */
#define swap(A,B) { Item t=A; A=B; B=t; }/* 结点交换 */
#define compswap(A,B) if(less(B,A)) swap(A,B)/* 比较后结点交换 */

void ItemShow(Item x)
{
   printf("%f \n", x.element);
}
