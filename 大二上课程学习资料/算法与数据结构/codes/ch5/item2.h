
typedef double Item;
typedef Item* addr;

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) { Item t = A; A = B; B = t; }
#define compswap(A, B) if (less(B,A)) swap(A,B)

void ItemShow(Item x)
{
   printf("%d \n", x);
}
