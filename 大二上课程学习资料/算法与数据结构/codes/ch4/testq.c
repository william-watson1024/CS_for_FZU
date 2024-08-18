// 测试队列
 
#include <stdio.h>
#include <stdlib.h>
#include "qitem.h"
//#include "lqueue.h"
#include "queue.h"

int main()
{
   Queue pp,qq;
   pp=QueueInit(10);
   qq=QueueInit(10);
   //pp=QueueInit();
   //qq=QueueInit();

   printf("pp 空队列 %d \n", QueueEmpty(pp));
   printf("qq 空队列 %d \n", QueueEmpty(qq));

   //printf("pp 队列满  %d \n", QueueFull(pp));
   //printf("qq 队列满  %d \n", QueueFull(qq));

   EnterQueue(1,pp);
   EnterQueue(2,pp);
   EnterQueue(3,pp);
   EnterQueue(4,pp);
   EnterQueue(5,pp);

   EnterQueue(10,qq);
   EnterQueue(9,qq);
   EnterQueue(8,qq);
   EnterQueue(7,qq);
   EnterQueue(6,qq);

   if(!QueueEmpty(pp)) printf("pp 队首元素  %d \n", QueueFirst(pp));
   if(!QueueEmpty(qq)) printf("qq 队首元素  %d \n", QueueFirst(qq));

   if(!QueueEmpty(pp))printf("pp 队尾元素  %d \n", QueueLast(pp));
   printf("qq 队尾元素  %d \n", QueueLast(qq));

   printf("pp 空队列 %d \n", QueueEmpty(pp));
   printf("qq 空队列 %d \n", QueueEmpty(qq));

   if(!QueueEmpty(pp))printf("删除  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("删除  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("删除  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("删除  %d \n", DeleteQueue(pp));
   if(!QueueEmpty(pp))printf("删除  %d \n", DeleteQueue(pp));

   if(!QueueEmpty(qq))printf("删除  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("删除  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("删除  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("删除  %d \n", DeleteQueue(qq));
   if(!QueueEmpty(qq))printf("删除  %d \n", DeleteQueue(qq));

   if(!QueueEmpty(pp))printf("删除  %d \n", DeleteQueue(pp));
   QueueFree(pp);QueueFree(qq);
   return 0;

}
