// 线段树
/* 
使用时前置语句 
#include "segtree.h"
*/

#include <memory.h>

const int maxn=28010;

typedef struct intv
{/* 线段结点类型 */
	int low,/* 线段左端点下标 */
        high;/* 线段右端点下标 */
}Intv;

typedef struct stnode *link;/* 线段树结点指针类型 */ 
typedef struct stnode {/* 线段树结点类型 */
    int left,/* 标准线段左端 */
        right;/* 标准线段右端 */
    int count;/* 正则覆盖计数 */
    int clq;/* 线段集最大团 */
    float uni;/* 线段集并的长度 */
}Stnode;

Stnode *tree=(Stnode *)malloc((2*maxn)*sizeof(Stnode));/* 线段树结点数组 */

int nn,/* 线段结点总数 */
    mm;/* 线段总数 */
float *xx;/* 线段结点数组 */
intv *iset;/* 线段数组 */ 

void outtree(int n)
{/* 输出线段树结点数组 */
   for(int i=1;i<=2*n+1;i++) 
       printf("pos=%d l=%d r=%d count=%d\n",i,tree[i].left,tree[i].right,tree[i].count); 
}

void update(int pos)
{/* 更新用户信息 */
    int l=tree[pos].left,r=tree[pos].right;
    int cnt=tree[pos].count;
    float ret=(tree[pos].count)?xx[r]-xx[l]:0;
    if(r-l<=1){
        tree[pos].clq=cnt;
        tree[pos].uni=ret;
    }
    else{
        float unil=tree[pos*2].uni,unir=tree[pos*2+1].uni;
        int clql=tree[pos*2].clq,clqr=tree[pos*2+1].clq;
        tree[pos].clq=cnt+max(clql,clqr);
        if(cnt)tree[pos].uni=ret;
        else tree[pos].uni=unil+unir;
    }
}

void change(int pos,int k)
{/* 更新结点信息 */
    /* k=1为插入，k=-1为删除 */
    tree[pos].count+=k;
}

void build(int l,int r,int pos)
{/* 建立线段树结构 */
	tree[pos].left=l;
	tree[pos].right=r;
	if(l+1==r)return;
	int mid=(l+r)/2; 
	build(l,mid,pos*2);
	build(mid,r,pos*2+1);
}

void inst(intv r,int pos)
{/* 插入单个线段 */
    if(r.low<=tree[pos].left && tree[pos].right<=r.high)change(pos,1);
    else{
        int mid=(tree[pos].left+tree[pos].right)>>1;
        if(r.low<mid)inst(r,pos*2);
        if(r.high>mid)inst(r,pos*2+1);
    }
    update(pos);
}

void erase(intv r,int pos)
{/* 删除单个线段 */
    if(r.low<=tree[pos].left && tree[pos].right<=r.high)change(pos,-1);
    else{
        int mid=(tree[pos].left+tree[pos].right)>>1;
        if(r.low<mid)erase(r,pos*2);
        if(r.high>mid)erase(r,pos*2+1);
    }
    update(pos);
}

void insert()
{/* 插入线段集iset中所有线段 */
    for(int i=0;i<mm;i++)inst(iset[i],1);
}

void buildst(int n,int m,float *x,intv *s)
{/* 建立线段集s的线段树 */
    nn=n,mm=m;
    xx=x;
    iset=s;
    memset(tree,0,(2*maxn)*sizeof(Stnode));
    //outtree(nn);
    build(0,n-1,1);
    insert();
}

void quit()
{/* 释放线段树结点数组 */
    free(tree);
}

int stab(float x, int pos)
{/* 线段树穿刺计数 */
    int l=tree[pos].left,r=tree[pos].right,c=0;
    if(x>xx[l] && x<=xx[r])c+=tree[pos].count;
    if(r-l>1){
        int mid=(l+r)>>1;
        if(x<=xx[mid])c+=stab(x,pos*2);
        else c+=stab(x,pos*2+1);
    }
    return c;
}

float uni1(int pos)
{/* 线段并 */
    return tree[pos].uni;
}

float uni(int pos)
{/* 线段并 */
    int l=tree[pos].left,r=tree[pos].right;
    float ret=(tree[pos].count)?xx[r]-xx[l]:0; 
    if(r-l<=1 || (tree[pos].count))return ret;
    else return uni(pos*2)+uni(pos*2+1);
}

int maxclq(int pos)
{/* 线段集最大团 */
    int l=tree[pos].left,r=tree[pos].right,cnt=tree[pos].count;
    if(r-l<=1)return cnt;
    else return cnt+max(maxclq(pos*2),maxclq(pos*2+1));
}

int maxclq1(int pos)
{/* 线段集最大团 */
     return tree[pos].clq;
}
