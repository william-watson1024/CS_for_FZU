/* ×Ö·û´®µÄÉ¢ÁÐº¯Êý */

int hash1(char* x)
{
   int j=0,len=strlen(x);
   for(int i=0;i<len;i++)j+=x[i];
   return j%maxsize;
}

int hash(NameRecord elem)
{
    return hash1(elem->name);
}

/*
unsigned long hash(NameRecord elem)
{
   unsigned long hashval = 0;
   // shift hashval left three bits and add in next character
   for(int i=0;i<strlen(elem.name);i++)
      hashval=(hashval<<3)+elem.name[i];
   return hashval;
}
*/
