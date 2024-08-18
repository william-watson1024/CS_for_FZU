/* 左偏高树 */

#ifndef MinHBLT_
#define MinHBLT_

#include "hbltnode.h"
#include "qitem1.h"
#include "lqueue.h"

#define swap(A,B) {ltlink t=A;A=B;B=t;}

MinHBLT HBLTInit()
{/* 创建一棵空树 */
   MinHBLT H=(MinHBLT)malloc(sizeof *H);
   H->root=0;
   return H;
}

bool HBLTEmpty(MinHBLT H)
{/* 是否空树 */
    return H->root==0;
}

SetItem HBLTMin(MinHBLT H)
{/* 最小元素 */
   if(H->root==0)return 0;
   return H->root->element;
}

ltlink Concatenate(ltlink x, ltlink y)
{/* 左偏树的合并运算 */
   if(!y)return x;/* y是空树 */
   if(!x)return y;/* x是空树 */
   /* x和y均非空 */
   if(less(y->element,x->element))swap(x,y);
   /* 此时有x->element >= y->element */
   x->right=Concatenate(x->right,y);
   if(!x->left){/* x的左子树为空树 */
      /* 交换其左、右子树 */
      x->left=x->right;
      x->right=0;
      x->s=1;
   }
   else{/* 若x的左子树高则交换其左、右子树 */
      if(x->left->s>x->right->s)swap(x->left,x->right);
      x->s=x->right->s+1;
   }
   return x;
}

void HBLTConc(MinHBLT H,MinHBLT T)
{/* 合并左偏树 */
   H->root=Concatenate(H->root,T->root);
   T->root=0;
}

void HBLTInsert(SetItem x,MinHBLT H)
{/* 插入运算 */
   ltlink q=NewHBLTnode(x,1);
   H->root=Concatenate(H->root,q);
}

SetItem DeleteMin(MinHBLT H)
{/* 删除并返回最小元 */
   if(H->root==0)return 0;
   SetItem x=H->root->element; /* 最小元 */
   ltlink L=H->root->left;
   ltlink R=H->root->right;
   free(H->root);
   H->root=Concatenate(L,R);
   return x;
}

MinHBLT BuildHBLT(SetItem a[],int n)
{/* 左偏高树的建树算法 */
   Queue Q=QueueInit();
   MinHBLT H=HBLTInit();
   /* 初始化左偏高树队列 */
   for(int i=1;i<=n;i++){
      /* 创建单结点树 */
      ltlink q=NewHBLTnode(a[i],1);
      EnterQueue(q,Q);
   }
   /* 依队列顺序合并左偏高树 */
   for(int i=1;i<=n-1;i++){
      /* 从队列中删除两棵左偏高树并合并之 */
      ltlink b=DeleteQueue(Q);
      ltlink c=DeleteQueue(Q);
      b=Concatenate(b,c);
      /* 合并后的新左偏高树入队 */
      EnterQueue(b,Q);
   }
   if(n)H->root=DeleteQueue(Q);
   return H;
}

void HBLTOut(ltlink t)
{/* 输出左偏高树 */
   if(t){
      HBLTOut(t->left);
      HBLTOut(t->right);
      SetItemShow(t->element);
   }
}

#endif
