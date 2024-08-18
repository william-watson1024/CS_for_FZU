/* 桶排序算法 */
/* 
使用时前置语句 
#include "item.h"
#include "binsort.h"
*/

#include "node.h"

#define m 10000

link binsort(link first)
{/* 桶排序算法 */
    int  b;/* 桶下标 */
    link bottom[m+1],top[m+1];
    link p=0;
    for(b=0;b<=m;b++)bottom[b]=0;/* 桶初始化 */
    for(;first;first=first->next){/* 将元素装入桶中 */
       b=first->element;
       if(bottom[b]){/* 桶非空 */
         top[b]->next=first;
         top[b]=first;}
       else bottom[b]=top[b]=first;/* 桶空 */
    }
    /* 按桶的顺序将桶中元素顺序连接在一起 */
    for(b=0;b<=m;b++)
       if(bottom[b]){/* 桶非空 */
          if(p)p->next=bottom[b];/* 不是第一个非空桶 */
          else first=bottom[b];/* 第一个非空桶 */
          p=top[b];
       }
    if(p)p->next=0;
    return first;
}


