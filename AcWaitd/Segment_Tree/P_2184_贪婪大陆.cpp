#include <bits/stdc++.h>
#include <type_traits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
//放炸弹区间加一种类，如何快速统计
//使用前缀和处理，一个维护区间起点数目，一个维护区间终点数目，询问[l,r]种类，等价询问，起点[1,r]-终点[1,l-1];
struct no{
    ll l,r,cnt[2],ly[2];
}tr[N<<2];

void pushup(int p,int o)
{
    tr[p].cnt[o]=tr[lc].cnt[o]+tr[rc].cnt[o];
}
void build(int p,int l,int r)
{
    tr[p]={l,r,{0,0},0};
    if(l==r)return;
    ll mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    //不用push,都为0
}
void lazy(int p,int add,int o)
{
    tr[p].cnt[o]+=add;
    tr[p].ly[o]+=add;//注意是加上

}
void pushdown(int p,int o)
{
    if(tr[p].ly[o]==0)return;
    lazy(rc,tr[p].ly[o],o);
    lazy(lc,tr[p].ly[o],o);
    tr[p].ly[o]=0;
}
void modify(int p,int x,int y,int o)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        lazy(p,1,o);
        return;
    }
    pushdown(p,o);
    int mid=(l+r)>>1;
    if(x<=mid)
    modify(lc,x,y,o);//传入原始边界
    if(y>mid)
    modify(rc,x,y,o);
    pushup(p,o);
}
ll query(int p,int x,int y,int o)
{
       int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        return tr[p].cnt[o];
    }
    pushdown(p,o);
    int mid=(l+r)>>1;
    ll sum=0;
     if(x<=mid)
    sum+=query(lc,x,y,o);//传入原始边界
    if(y>mid)
    sum+=query(rc,x,y,o);
    return sum;
}
void solve()
{
    int n,m;cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            modify(1,l,l,0);//起点为0
            modify(1,r,r,1);
        }
        else
        {
            cout<<query(1,1,r,0)-query(1,1,l-1,1)<<endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
