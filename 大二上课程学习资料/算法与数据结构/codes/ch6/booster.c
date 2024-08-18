/* 信号增强装置布局 */

#include <stdio.h>
#include <stdlib.h>
#include "booster.h"
#include "treeitem1.h"
#include "binary.h"

int tol=3;

void Place(btlink x)
{
    int deg;
    btlink y=x->left;
    x->element.D=0; /* 初始化结点x处的信号衰减量 */
    if(y){/* 从左子树计算 */
        deg=y->element.D + y->element.d;
        if(deg>tol){
            y->element.boost=1;
            x->element.D=y->element.d;
        }
        else x->element.D=deg;
    }
    y=x->right;
   if(y){/* 从右子树计算 */
       deg=y->element.D+y->element.d;
       if(deg>tol){
            y->element.boost=1;
            deg=y->element.d;
        }
        if(x->element.D<deg)x->element.D=deg;
    }
}

void comp()
{
   Booster a,b;
   BinaryTree T,U,V,W,X,Y;
   T=BinaryInit();
   U=BinaryInit();
   V=BinaryInit();
   W=BinaryInit();
   X=BinaryInit();
   Y=BinaryInit();

   a.d=2; a.D =0; a.boost=0;
   b.d=1; b.D=0; b.boost=0;
   MakeTree(a,U,X,X);
   MakeTree(b,V,U,X);
   MakeTree(a,U,X,X);
   MakeTree(a,W,U,X);
   b.d=3;
   MakeTree(b,U,V,W);
   MakeTree(a,V,X,X);
   b.d=1;
   MakeTree(b,W,X,X);
   MakeTree(a,Y,V,W);
   MakeTree(a,W,X,X);
   MakeTree(b,T,Y,W);
   b.d=0;
   MakeTree(b,V,T,U);
   PostOrder(Place,V->root);
   PostOut(V);
}

int main()
{
    comp();
    return 0;
}

/*
 0   0   2 
 0   0   1 
 1   2   2 
 0   0   2 
 0   2   1 
 0   0   2 
 0   2   1 
 0   0   2 
 1   2   2 
 1   3   3 
 0   3   0 
*/
