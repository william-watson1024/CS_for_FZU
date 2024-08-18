/* 二叉搜索树 */
/* 
使用时前置语句 
#include "treeitem.h"
#include "bstree.h"
*/

#ifndef BSTree_
#define BSTree_

#include "binary.h"

void InsertRebal(btlink v,BinaryTree T);
void DeleteRebal(btlink v, btlink p, BinaryTree T);

btlink NewBSnode(TreeItem x)
{
   btlink r;
   r=NewBNode();
   r->element=x;
   r->bal=0;
   r->left=0;
   r->right=0;
   r->parent=0;
   return r;
}

btlink GetBSnode(TreeItem x, btlink lptr, btlink rptr, btlink pptr)
{
   btlink r;
   r=NewBNode();
   r->element=x;
   r->bal=0;
   r->left=lptr;
   r->right=rptr;
   r->parent=pptr;
   return r;
}

btlink BSSearch(TreeItem x,BinaryTree T)
{
   btlink p=T->root;
   while(p) /* 查看p->element */
      if(less(x,p->element))p=p->left;
      else if(less(p->element,x))p=p->right;
      else break;
   return p;
}

int BSMember(TreeItem x,BinaryTree T)
{
   return BSSearch(x,T)?1:0;
}

btlink BSInsert(TreeItem x,BinaryTree T)
{/* 插入元素x */
   btlink p,r,pp=0;/* pp是p的父结点指针 */
   p=T->root;/* p为搜索指针 */
   /* 搜索插入位置 */
   while(p){/* 考察当前结点中存储的元素p->element */
      pp=p;/* 选择搜索子树 */
      if(less(x,p->element))p=p->left;
      else if(less(p->element,x))p=p->right;
      else return 0;
   }
   /* 待插入新结点 */
   r=NewBSnode(x);
   if(T->root){/* 当前树非空 */
      if(less(x,pp->element))pp->left=r;
      else pp->right=r;
      r->parent=pp;
      //InsertRebal(r,T);/* 插入后重新平衡 */
   }
   else T->root=r;/* 插入空树 */
   return r;
}

btlink BSInsertVisit(TreeItem x,void(*visit)(TreeItem u),BinaryTree T)
{/* 仅当x不在集合中时插入元素 */ 
   btlink p,r,pp=0;/* pp是p的父结点指针 */
   p=T->root;/* p为搜索指针 */
   while(p){/* 考察当前结点中存储的元素p->element */
      pp=p;
      if(less(x,p->element))p=p->left;
      else if(less(p->element,x))p=p->right;
      else{visit(p->element);return p;}/* 访问已存在元素 */
   }
   /* 待插入新结点 */
   r=NewBSnode(x);
   if (T->root) {/* 当前树非空 */
      if (less(x,pp->element)) pp->left=r;
      else pp->right=r;
      r->parent=pp;
      //InsertRebal(r,T);/* 插入后重新平衡 */
   }
   else T->root=r;/* 插入空树 */
   return r;
}

btlink BSDelete(TreeItem x,BinaryTree T)
{/* 删除元素x */
   btlink c,p,s,ps,pp=0;/* pp是p的父结点指针 */
   p=T->root;/* p为搜索指针 */
   while(p && !eq(p->element,x)){/* 搜索要删除的结点 */
      pp=p;
      if(less(x,p->element))p=p->left;
      else p=p->right;
   }
   if(!p)return 0;/* 未找到要删除的结点 */
   /* p是要删除的结点 */
   if(p->left && p->right){/* 处理p有2个儿子结点情形 */
      /* 变换成有1个或0个儿子结点情形 */
      /* 搜索p的左子树中的最大元素 */
      s=p->left;ps=p;/* ps是s的父结点指针 */
      while(s->right){/* 一直向右找最大元素 */
         ps=s;
         s=s->right;
      }
      /* 用s中最大元素替换p中的元素 */
      p->element=s->element;
      p=s;
      pp=ps;
   }
   /* 此时p最多只有1个儿子结点 */
   /* 将p的儿子结点指针保存在c中 */
   if(p->left)c=p->left;
   else c=p->right;
   /* 删除结点 p */
   if(p==T->root){
        T->root=c;
        if(c)c->parent=0;
   }
   else{/* 确定p是其父结点的左儿子结点还是右儿子结点 */
      if(p==pp->left){/* p是左儿子结点 */
        pp->left=c;
        p->left=p;/* 这一步为重新平衡作准备 */
      }
      else pp->right=c;/* p是右儿子结点 */
      if(c)c->parent=p->parent;
   }
   //DeleteRebal(c,p,T);/* 删除后重新平衡 */
   free(p);
   return c;
}

btlink CopyTree(btlink t)
{/* 复制树 */
   btlink newlptr,newrptr,newnode;
   if(t==0)return 0;
   if(t->left!=0)newlptr=CopyTree(t->left);
   else newlptr=0;
   if(t->right!=0)newrptr=CopyTree(t->right);
   else newrptr=0;
   newnode=GetBSnode(t->element,newlptr,newrptr,0);
   return newnode;
}

BinaryTree BSTCopy(BinaryTree T)
{/* 复制二叉搜索树 */
   btlink s;
   BinaryTree S=(BinaryTree)malloc(sizeof *S);
   if(T==0)return 0;
   s=CopyTree(T->root);
   S->root=s;
   return S;
}

void BSAscend(BinaryTree T)
{/* 按照递增序输出二叉搜索树元素 */
   InOut(T);
}

#endif
