/* ¸³È¨±ß */

#define maxE 1000

typedef struct edge{ 
    int u; 
    int v; 
    WItem w;
}Edge;

typedef Edge Item;
typedef Item* addr;

#define key(A) (A.w)
#define less(A,B) (key(A)<key(B))
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {Item t=A;A=B;B=t;}
#define compexch(A,B) if(less(B,A))exch(A,B)


