
#ifndef HBLTNode_
#define HBLTNode_

typedef struct hbltnode *ltlink;/* 左偏树的结点指针类型 */

typedef struct hbltnode {/* 左偏树的结点类型 */
      int s;/* 结点高度 */
      SetItem element;/* 有序集元素 */
      ltlink left,/* 左子树指针 */   
             right;/* 右子树指针 */  
}HBLTNode;

typedef struct hblt *MaxHBLT;/* 极大化左偏树指针类型 */
typedef struct hblt{/* 极大化左偏树结构 */
    ltlink root;/* 根结点指针 */ 
}HBLT;

ltlink NewHBLTnode(SetItem x,int s)
{
    ltlink p=(ltlink)malloc(sizeof(HBLTNode));
    p->element=x;
    p->s=s;
    p->left=0;
    p->right=0;
    return p;
}

#endif
