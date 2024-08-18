/* 链表合并排序算法 */
/* 
使用时前置语句 
#include "item.h"
#include "linkmsort.h"
*/

#include "node.h"
#include "qitem.h"
#include "lqueue.h"

link merge(link a,link b)
{/* 链表合并 */
    Node head;
    link c=&head;
    while(a && b)
      if(less(a->element,b->element)){c->next=a;c=a;a=a->next;}
      else{c->next=b;c=b;b=b->next;}
    c->next=(!a)?b:a;
    return head.next;
}

link mergesort(link c)
{/* 链表合并排序算法 */
    link a,b;
    if(!c->next)return c;
    a=c;b=c->next;
    while(b && b->next){c=c->next;b=b->next->next;}
    b=c->next;c->next=0;
    return merge(mergesort(a),mergesort(b));
}

link mergesort1(link t)
{
    link u;
    Queue q;
    for(q=QueueInit();t;t=u){ 
        u=t->next; 
        t->next=0; 
        EnterQueue(t,q); 
    }
    t=DeleteQueue(q);
    while(!QueueEmpty(q)){ 
        EnterQueue(t,q); 
        t=merge(DeleteQueue(q), 
        DeleteQueue(q)); 
    }
    return t;
}

