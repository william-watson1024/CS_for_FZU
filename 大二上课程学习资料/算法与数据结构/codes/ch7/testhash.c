/* 测试散列表 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setitem.h"
#include "hash.h"
//#include "linkedhash.h"

int hash(SetItem x)
{
   return x%11;
}

int hash1(char* x)
{/* 字符串的散列函数 */
   int len,i,j=0;
   len=strlen(x);
   for(i=0;i<len;i++)j+=x[i];
   return j%101;
}

int main()
{
    int j;
    HashTable h=HTInit(11,hash);
    //OpenHashTable h=HTInit(11,hash);
    HTInsert(80,h);
    HTInsert(40,h);
    HTInsert(65,h);
    HTOutput(h);
    
    scanf("%d",&j);
    HTInsert(58,h);
    HTInsert(24,h);
    HTOutput(h);
    scanf("%d",&j);
    
    HTInsert(2,h);
    HTInsert(13,h);
    HTInsert(46,h);
    HTInsert(16,h);
    HTInsert(7,h);
    HTInsert(21,h);
    
    HTOutput(h);
    scanf("%d",&j);
    
    HTDelete(16,h);
    HTDelete(7,h);
    printf("HTMember(16,h)  %d\n",HTMember(16,h));
    
    HTOutput(h);
    return 0;
}
