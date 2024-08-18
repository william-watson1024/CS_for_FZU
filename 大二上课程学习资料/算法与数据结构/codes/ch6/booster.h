/* booster 结构 */ 
typedef struct booster{
    int D,/* 叶结点信号衰减量 */
        d;/* 父结点信号衰减量 */
    int boost;/* 信号增强装置标志 */
}Booster;

void showboost(Booster x)
{
    printf("%  d   %d   %d \n", x.boost,x.D,x.d);
}

/*
D(i)=0；
for(i的每一儿子结点j){
    if(D(j)+d(j))>tolerence)在结点j放置一个信号增强装置;
    else D(i)=max(D(i),D(j)+d(j));
}
*/
