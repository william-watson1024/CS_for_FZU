// 序列树
/* 
使用时前置语句 
#include "seqtree.h"
*/

#include <math.h> 
#include <memory.h>

const int maxn=51111;

typedef struct seqnode {/* 序列树结点类型 */
    int left,/* 标准子序列左端 */
        right;/* 标准子序列右端 */
    int sum;/* 标准子序列和 */
    int min;/* 标准子序列最小值 */
    int max;/* 标准子序列最小值 */
    int lazyset;/* 延迟更新值 */
    int lazyadd;/* 延迟更新增减值 */
}Sqnode;

Sqnode *tree=(Sqnode *)malloc((2*maxn)*sizeof(Sqnode));/* 序列树结点数组 */

int seqm,seqn,seqh;

unsigned clp20(unsigned x)
{/* 上舍入到最近的2的整数幂 */
    x=x|(x/2);
    x=x|(x>>2);
    x=x|(x>>4);
    x=x|(x>>8);
    x=x|(x/26);
    return x+1;
}

int clp2(int x)
{/* 上舍入到最近的2的整数幂 */
    int k=log2(x);
    int y=1<<k;
    if(x==y)return y;
    else return y<<1;
}

int clp(int x)
{/* 上舍入到最近的2的整数幂 */
    int k=log2(x);
    if(x==(1<<k))return k;
    else return k+1;
}

int left(int pos)
{/* pos 标准区间左端 */
    int k=log2(pos);
    int j=pos-(1<<k);
    return j*(1<<(seqh-k))+1;
}

int right(int pos)
{/* pos 标准区间右端 */
    int k=log2(pos);
    int j=pos-(1<<k);
    return (j+1)*(1<<(seqh-k));
}

void update(int pos)
{
    tree[pos].sum=tree[2*pos].sum+tree[2*pos+1].sum;
    tree[pos].min=min(tree[2*pos].min,tree[2*pos+1].min);
    tree[pos].max=max(tree[2*pos].max,tree[2*pos+1].max);
}

void change(int pos,int v,int t)
{/* 更新结点信息 */
    if(t)tree[pos].sum+=v;
    else tree[pos].sum=v;
    tree[pos].min=tree[pos].max=tree[pos].sum;
    tree[pos].lazyset=0;tree[pos].lazyadd=0;
}

void read(int pos)
{/* 读入点信息 */
    int s=0;
    scanf("%d",&s);
    change(pos,s,0);
}

void outtree(int pos)
{/* 输出树结构 */
    //int l=tree[pos].left,r=tree[pos].right;
    int l=left(pos),r=right(pos);
    int s=tree[pos].sum,m=tree[pos].min,x=tree[pos].max;
    int se=tree[pos].lazyset,ad=tree[pos].lazyadd;
    printf("pos=%d l=%d r=%d\n",pos,l,r);
    printf("pos=%d left=%d right=%d\n",pos,left(pos),right(pos));
    printf("sum=%d min=%d max=%d se=%d ad=%d\n",s,m,x,se,ad);
	if(l==r)return ;
	int mid=(l+r)/2;
	outtree(2*pos);
	outtree(2*pos+1);
}

void outtree()
{/* 输出树结构 */
    for(int pos=1;pos<=2*seqm-1;pos++){
        int l=left(pos),r=right(pos);
        int s=tree[pos].sum,m=tree[pos].min,x=tree[pos].max;
        int se=tree[pos].lazyset,ad=tree[pos].lazyadd;
        printf("pos=%d l=%d r=%d\n",pos,l,r);
        printf("sum=%d min=%d max=%d se=%d ad=%d\n",s,m,x,se,ad);
    }
}

void build(int l,int r,int pos)
{/* 建立序列树结构 */
    tree[pos].left=l;tree[pos].right=r;
    cout<<"pos="<<pos<<" l="<<l<<" r="<<r<<endl;
    if(l==r){
        if(l<=seqn)read(pos);
        else change(pos,0,0);
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,2*pos);
    build(mid+1,r,2*pos+1);
    update(pos);
}

void treeinit(int nn)
{/* 初始化 */
	seqn=seqm=nn;
	seqh=clp(seqn);
    seqm=1<<seqh;
    memset(tree,0,(2*maxn)*sizeof(Sqnode));
    seqm=seqn;
	build(1,seqm,1);
}

void treeinit1(int nn)
{/* 初始化 */
	seqn=seqm=nn;
    memset(tree,0,(2*maxn)*sizeof(Sqnode));
	build(1,nn,1);
}

void inst(int k,int v,int t,int pos)
{
    int l=tree[pos].left,r=tree[pos].right;
    //int l=left(pos),r=right(pos);
    if(l==r){
        change(pos,v,t);
        return ;
    }
    int mid=(l+r)/2;
    if(k<=mid)inst(k,v,t,2*pos);
    else inst(k,v,t,2*pos+1);
    update(pos);
}

void inst(int k,int v,int t,int pos,int l,int r)
{/* 不需left和right */
    if(l==r){
        change(pos,v,t);
        return ;
    }
    int mid=(l+r)/2;
    if(k<=mid)inst(k,v,t,2*pos,l,mid);
    else inst(k,v,t,2*pos+1,mid+1,r);
    update(pos);
}

void push(int pos,int len) 
{
    int c=tree[pos].lazyset;
    int d=tree[pos].lazyadd;
    if(c){
        tree[2*pos].lazyset=tree[2*pos+1].lazyset=c;
        tree[2*pos].sum=c*(len-(len/2));
        tree[2*pos].min=tree[2*pos].max=c;
        tree[2*pos+1].sum=c*(len/2);
        tree[2*pos+1].min=tree[2*pos+1].max=c;
        tree[pos].lazyset=0;
    }
    if(d){
        tree[2*pos].lazyadd+=d;
        tree[2*pos+1].lazyadd+=d;
        tree[2*pos].sum+=d*(len-(len/2));
        tree[2*pos].min+=d;tree[2*pos].max+=d;
        tree[2*pos+1].sum+=d*(len/2);
        tree[2*pos+1].min+=d;tree[2*pos+1].max+=d;
        tree[pos].lazyadd=0;
    }
}

int qsum(int lft,int rht,int pos)
{
    int l=tree[pos].left,r=tree[pos].right;
    //int l=left(pos),r=right(pos);
    if(lft<=l && r<=rht)return tree[pos].sum;
	push(pos,r-l+1);
    int mid=(l+r)/2;
	int ret=0;
	if(lft<=mid)ret+=qsum(lft,rht,2*pos);
	if(rht>mid)ret+=qsum(lft,rht,2*pos+1);
	return ret;
}

int qsum(int lft,int rht,int pos,int l,int r)
{/* 不需left和right */
	if(lft<=l && r<=rht)return tree[pos].sum;
	push(pos,r-l+1);
	int mid=(l+r)/2;
	int ret=0;
	if(lft<=mid)ret+=qsum(lft,rht,2*pos,l,mid);
	if(rht>mid)ret+=qsum(lft,rht,2*pos+1,mid+1,r);
	return ret;
}

int qmax(int lft,int rht,int pos)
{
    int l=tree[pos].left,r=tree[pos].right;
    //int l=left(pos),r=right(pos);
	if(lft<=l && r<=rht)return tree[pos].max;
	push(pos,r-l+1);
	int mid=(l+r)/2;
	int ret=INT_MIN;
	if(lft<=mid)ret=qmax(lft,rht,2*pos);
	if(rht>mid)ret=max(ret,qmax(lft,rht,2*pos+1));
	return ret;
}

int qmax(int lft,int rht,int pos,int l,int r)
{/* 不需left和right */
	if(lft<=l && r<=rht)return tree[pos].max;
	push(pos,r-l+1);
	int mid=(l+r)/2;
	int ret=INT_MIN;
	if(lft<=mid)ret=qmax(lft,rht,2*pos,l,mid);
	if(rht>mid)ret=max(ret,qmax(lft,rht,2*pos+1,mid+1,r));
	return ret;
}

int qmin(int lft,int rht,int pos)
{
    int l=tree[pos].left,r=tree[pos].right;
    //int l=left(pos),r=right(pos);
	if(lft<=l && r<=rht)return tree[pos].min;
	push(pos,r-l+1);
	int mid=(l+r)/2;
	int ret=INT_MAX;
	if(lft<=mid)ret=qmin(lft,rht,2*pos);
	if(rht>mid)ret=min(ret,qmin(lft,rht,2*pos+1));
	return ret;
}

int qmin(int lft,int rht,int pos,int l,int r)
{/* 不需left和right */
	if(lft<=l && r<=rht)return tree[pos].min;
	push(pos,r-l+1);
	int mid=(l+r)/2;
	int ret=INT_MAX;
	if(lft<=mid)ret=qmin(lft,rht,2*pos,l,mid);
	if(rht>mid)ret=min(ret,qmin(lft,rht,2*pos+1,mid+1,r));
	return ret;
}

void modi(int lft,int rht,int c,int l,int r,int pos)
{
	//printf("lft=%d rht=%d c=%d l=%d r=%d pos=%d\n",lft,rht,c,l,r,pos);
    if(lft<=l && r<=rht){
        tree[pos].lazyset=c;
        tree[pos].sum=c*(r-l+1);
        tree[pos].min=tree[pos].max=c;
        return;
	}
	push(pos,r-l+1);
	int mid=(l+r)/2;
	if(lft<=mid)modi(lft,rht,c,l,mid,2*pos);
	if(rht>mid)modi(lft,rht,c,mid+1,r,2*pos+1);
	update(pos);
}

void incr(int lft,int rht,int c,int l,int r,int pos)
{
	//printf("lft=%d rht=%d c=%d l=%d r=%d pos=%d\n",lft,rht,c,l,r,pos);
    if(lft<=l && r<=rht){
        tree[pos].lazyadd+=c;
		tree[pos].sum+=c*(r-l+1);
		tree[pos].min+=c;tree[pos].max+=c;
        return;
	}
	push(pos,r-l+1);
    int mid=(l+r)/2;
	if(lft<=mid)incr(lft,rht,c,l,mid,2*pos);
	if(rht>mid)incr(lft,rht,c,mid+1,r,2*pos+1);
	update(pos);
}

void modify(int lft,int rht,int c)
{
	//printf("lft=%d rht=%d c=%d\n",lft,rht,c);
    modi(lft,rht,c,1,seqm,1);
}

void increase(int lft,int rht,int c)
{
	//printf("lft=%d rht=%d c=%d\n",lft,rht,c);
	incr(lft,rht,c,1,seqm,1);
}

void insert(int k,int v)
{
    //inst(k,v,0,1);
    inst(k,v,0,1,1,seqn);
    //inst(k,v,0,1,1,seqm);
}

void add(int k,int v)
{
    //inst(k,v,1,1);
    inst(k,v,1,1,1,seqn);
    //inst(k,v,1,1,1,seqm);
}

int querysum(int lft,int rht)
{
    //printf("lft=%d rht=%d seqn=%d \n",b[i]);
    //return qsum(lft,rht,1);
    return qsum(lft,rht,1,1,seqn);
    //return qsum(lft,rht,1,1,seqm);
}

int querymin(int lft,int rht)
{
    //return qmin(lft,rht,1);
    return qmin(lft,rht,1,1,seqn);
    //return qmin(lft,rht,1,1,seqm);
}

int querymax(int lft,int rht)
{
    //return qmax(lft,rht,1);
    return qmax(lft,rht,1,1,seqn);
    //return qmax(lft,rht,1,1,seqm);
}

