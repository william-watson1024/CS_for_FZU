#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setitem2.h"
#include "hash.h"
#include "strfreq.h"

void Output(HashTable H)
{
   for(int i=0;i<H->size;i++) 
      if(H->state[i]==0)SetItemShow(H->ht[i]);
}

void strfreq(char *fname)
{
    FILE *fp=stdin;
    NameRecord rec,str;
    char s[Msize];
    HashTable HF=HTInit(maxsize,hash);
    //fp=fopen(fname,"r");
    str=NewName(s);
    while(!feof(fp)){
        fscanf(fp,"%s",str->name);
        int i=FindMatch(str,HF);
        if(i<HF->size)HF->ht[i]->count++;
        else{
            rec=NewName(str->name);
            HTInsert(rec,HF);
        }
    }
    Output(HF);
}

int main()
{
   char *s=(char *)"strings.txt";
   strfreq(s);
   return 0;
}

/* test.in
Columbus Washington Napoleon Washington Lee Grant
Washington Lincoln Grant Columbus Washington
*/

/* test.out
Lee   1 
Grant   2 
Lincoln   1 
Napoleon   1 
Columbus   2 
Washington   4 
*/
