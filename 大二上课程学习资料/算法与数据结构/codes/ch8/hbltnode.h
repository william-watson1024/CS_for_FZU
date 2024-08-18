
#ifndef HBLTNode_
#define HBLTNode_

typedef struct hbltnode *ltlink;/* 左偏树的结点指针类型 */
typedef struct hbltnode{/* 左偏树的结点类型 */
      int s;/* 结点高度 */
      SetItem element;/* 有序集元素 */
      ltlink left,/* 左子树指针 */   
             right;/* 右子树指针 */  
}HBLTNode;

ltlink NewHBLTnode(SetItem x, int s)
{/* 创建新结点 */
    ltlink p=(ltlink)malloc(sizeof(HBLTNode));
    p->element=x;
    p->s=s;
    p->left=0;
    p->right=0;
    return p;
}

typedef struct hblt *MinHBLT;/* 极小化左偏树指针类型 */
typedef struct hblt{/* 极小化左偏树结构 */
    ltlink root;/* 根结点指针 */ 
}HBLT;

#endif
