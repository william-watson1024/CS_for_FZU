// 序列树
/* 
使用时前置语句 
#include "seqtree.h"
*/

#include <math.h> 
#include <memory.h>

const int maxn=101111;

int seqn;
int xx[maxn];

typedef struct seqnode {/* 序列树结点类型 */
    int mx;
    int lx;
    int rx;
}Sqnode;

Sqnode *tree=(Sqnode *)malloc((2*maxn)*sizeof(Sqnode));/* 序列树结点数组 */

void update(int pos,int l,int r)
{
    int mid=(l+r)/2;
    tree[pos].mx=max(tree[2*pos].mx,tree[2*pos+1].mx); //更新mx
    if(xx[mid]<xx[mid+1])//满足条件左右子树可以合并
       tree[pos].mx=max(tree[pos].mx,tree[2*pos].rx+tree[2*pos+1].lx);
    tree[pos].lx=tree[2*pos].lx; //更新lx
    if(tree[pos].lx==mid-l+1 && xx[mid]<xx[mid+1])
       tree[pos].lx+=tree[2*pos+1].lx;//左子树是满的,满足条件左右子树可以合并
    tree[pos].rx=tree[2*pos+1].rx; //更新rx
    if(tree[pos].rx==r-mid && xx[mid]<xx[mid+1])
       tree[pos].rx+=tree[2*pos].rx;//右子树是满的,满足条件左右子树可以合并
}

void build(int l,int r,int pos)
{/* 建立序列树结构 */
	if(l==r){
        tree[pos].mx=tree[pos].lx=tree[pos].rx=1;
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,2*pos);
	build(mid+1,r,2*pos+1);
	update(pos,l,r);
}

void treeinit(int nn)
{/* 初始化 */
	seqn=nn;
    memset(tree,0,(2*maxn)*sizeof(Sqnode));
	build(0,nn-1,1);
}

void inst(int k,int v,int t,int pos,int l,int r)
{
    if(l==r){
		if(t)xx[l]+=v;
		else xx[l]=v;
		tree[pos].mx=tree[pos].lx=tree[pos].rx=1;
		return ;
	}
	int mid=(l+r)/2;
	if(k<=mid)inst(k,v,t,2*pos,l,mid);
	else inst(k,v,t,2*pos+1,mid+1,r);
	update(pos,l,r);
}

int qsum(int lft,int rht,int pos,int l,int r)
{
    if(lft<=l && r<=rht)return tree[pos].mx;
    int mid=(l+r)/2;
    if(rht<=mid)return qsum(lft,rht,2*pos,l,mid);
    if(lft>mid)return qsum(lft,rht,2*pos+1,mid+1,r);
    int ret=max(qsum(lft,rht,2*pos,l,mid),qsum(lft,rht,2*pos+1,mid+1,r));
    //计算[mid+1,rht]与[mid+1,r]相交部分
    int lx=min(rht-mid,tree[2*pos+1].lx);
    //计算[lft,mid]与[l,mid]相交部分
    int rx=min(mid-lft+1,tree[2*pos].rx);
    if(xx[mid]<xx[mid+1])ret=max(ret,lx+rx);
    return ret;
}

void insert(int k,int v)
{
    inst(k,v,0,1,0,seqn-1);
}

void add(int k,int v)
{
    inst(k,v,1,1,0,seqn-1);
}

int query(int lft,int rht)
{
    return qsum(lft,rht,1,0,seqn-1);
}
