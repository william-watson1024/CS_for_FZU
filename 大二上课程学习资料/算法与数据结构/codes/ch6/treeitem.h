/* 树元素类型 */
typedef int TreeItem;/* 树元素类型 */
typedef TreeItem* Treeaddr;/* 树元素指针类型 */

void TreeItemShow(TreeItem x)
{
   printf("%d \n", x);
}

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {TreeItem t=A;A=B;B=t;}
#define compswap(A,B) if(less(B,A))swap(A,B)
