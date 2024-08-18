/* 链表集合 */
/* 
使用时前置语句 
#include "setitem.h"
#include "linkedset.h"
*/

#ifndef LinkedSet_
#define LinkedSet_

#include "setnode.h"

Set SetInit()
{/* 创建一个空集合 */
   Set S=(Set)malloc(sizeof *S);
   S->first=0;
   return S;
}

int SetEmpty(Set S)
{/* 判定集合是否为空 */
   return S->first==0;
}

int SetSize(Set S)
{/* 集合大小 */
   link current=S->first;
   int len=0;
   while(current){
     len++;
     current=current->next;
   }
   return len;
}

void SetAssign(Set A,Set B)
{/* 集合赋值运算 */
    link a,b,c;
    b=B->first;
    A->first=0;
    if(b){
        A->first=NewNode();
        a=A->first;
        a->element=b->element;
        a->next=0;
        b=b->next;
    }
    while(b){
        c=NewNode();
        c->element=b->element;
        c->next=0;
        b=b->next;
        a->next=c;
        a=c;
    }
}

Set SetInter(Set A,Set B)
{/* 交集运算 */
    Set tmp=SetInit();
    link a=A->first;
    link b=B->first;
    link p=NewNode();
    link q=p;
    while(a&&b){
       if(a->element==b->element){
            link r=NewNode();
            r->element=a->element;
            r->next=0;
            p->next=r;
            p=r;
            a=a->next;
            b=b->next;
        }
        else if(a->element<b->element)a=a->next;
        else b=b->next;
    }
    if(p!=q)tmp->first=q->next;
    free(q);
    return tmp;
}

void SetInsert(SetItem x,Set S)
{/* 插入运算 */
    link p=S->first;
    link q=p;
    while(p && p->element<x){
        q=p;
        p=p->next;
    }
    if(p && p->element==x)return;
    link r=NewNode();
    r->element=x;
    r->next=p;
    if(p==q)S->first=r;
    else q->next=r;
}

void SetDelete(int k, Set S)
{/* 删除运算 */
    if(k<1 ||!S->first)return;
    link p=S->first;
    if(k==1)S->first=S->first->next;
    else{/* q指位置k-1处 */ 
       link q=S->first;
       for(int i=1;i<k-1 && q;i++)q=q->next;
       if(!q || !q->next)return;
       p=q->next;/* 位置k处 */ 
       q->next=p->next;
    }/* 从表中删除 */
    free(p);
}

void SetOut(Set S)
{
   link current;
   for(current=S->first;current;current=current->next)
      SetItemShow(current->element);
}

#endif
