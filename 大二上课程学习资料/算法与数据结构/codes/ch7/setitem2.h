/* ×Ö·û´®ÔªËØÀàĞÍ */

#define Msize 100
#define maxsize 10001
#define eq(A,B) (strcmp(A->name,B->name)==0)

typedef struct node *NameRecord;/* ×Ö·û´®ÔªËØÀàĞÍÖ¸Õë */
typedef struct node{/* ×Ö·û´®ÔªËØ½á¹¹ */
     char name[Msize];/* ×Ö·û´®ÔªËØ */
     //char *name;
     int count;/* ×Ö·û´®¼ÆÊı */
  }Namenode;

NameRecord NewName(char *s)
{/* ĞÂ×Ö·û´®ÔªËØ */
    NameRecord p;
    //if((p=(NameRecord)malloc(sizeof(Namenode)))==0)printf("Exhausted memory.\n");
    p=(NameRecord)malloc(sizeof(Namenode));
    strcpy(p->name,s);
    p->count=1;
    return p;
}

typedef NameRecord SetItem;
typedef SetItem* addr;

void SetItemShow(SetItem x)
{
   printf("%s   %d \n", x->name,x->count);
}
