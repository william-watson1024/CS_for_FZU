
typedef Huffman SetItem;
//typedef SetItem* addr;

#define key(A) (A.weight)
#define less(A,B) (key(A) < key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) { Item t = A; A = B; B = t; }

void SetItemShow(SetItem x)
{
   printf("  %d\n ", x.weight);
}
