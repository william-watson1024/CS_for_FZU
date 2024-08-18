// ¿®∫≈∆•≈‰
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackitem.h"
#include "lstack.h"

void Parenthsis(char expr[])
{
    Stack ss=StackInit();
    int n=strlen(expr);
    for(int i=1;i<=n;i++){
        if(expr[i-1]=='(')Push(i,ss);
        else if(expr[i-1]==')'){
            if(StackEmpty(ss))printf("Œª÷√%d¥¶µƒ”“¿®∫≈≤ª∆•≈‰\n",i);
            else printf("%d %d\n",Pop(ss),i);
        }
    }
    while(!StackEmpty(ss))printf("Œª÷√%d¥¶µƒ◊Û¿®∫≈≤ª∆•≈‰\n",Pop(ss));
}

int main()
{
    char a[100];
    scanf("%s",a);
    printf("∆•≈‰µƒ¿®∫≈ «\n");
    Parenthsis(a);
    return 0;
}

/* test.in
(d+(a+b)*c*(d+e)-f))(()
*/

/* test.out
∆•≈‰µƒ¿®∫≈ «
4 8
12 16
1 19
Œª÷√20¥¶µƒ”“¿®∫≈≤ª∆•≈‰
22 23
Œª÷√21¥¶µƒ◊Û¿®∫≈≤ª∆•≈‰
*/

