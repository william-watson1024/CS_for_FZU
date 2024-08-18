// √∞≈›≈≈–Ú
/* 
 π”√ ±«∞÷√”Ôæ‰ 
#include "item.h"
#include "bubble.h"
*/

void sort(Item a[],int l,int r)
{ /* √∞≈›≈≈–ÚÀ„∑® */
    for(int i=l+1;i<=r;i++)
      for(int j=i;j>l;j--)
        compswap(a[j-1],a[j]);
}
