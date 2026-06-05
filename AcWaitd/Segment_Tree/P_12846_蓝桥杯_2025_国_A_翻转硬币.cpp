#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
struct node{
    ll l,r,s[4],la[4];
}tr[N<<2];
int a[N];
void pushup(int p,int op)
{
    tr[p].s[op]=tr[lc].s[op]+tr[rc].s[op];
}
void build(int p,int l,int r)
{
    tr[p]={l,r,{0,0,0,a[l]},{0,0,0,0}};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p,3);
}
void lazy(int p,int o)//全部lazy
{
    int l=tr[p].l,r=tr[p].r;//把信息懒下来，仅更新这一层
    if(o==3)
    {
    tr[p].s[o]=(r-l+1)-tr[p].s[o];
    }
    else
    {
    tr[p].s[o]=(r-l+1)/(o+1)-tr[p].s[o];
    }
    tr[p].la[o]=(tr[p].la[o]+1)%2;//进行了一次操作，需要加一
}
void pushdown(int p,int op)
{
    if(tr[p].la[op])
    {
        lazy(lc,op);
        lazy(rc,op);
        tr[p].la[op]=0;
    }
}
void modify(int p,int x,int y,int op)
{
     int l=tr[p].l,r=tr[p].r;
     if(l>=x&&r<=y)
     {
        lazy(p,op);
        return;
     }
     int mid=(l+r)>>1;
     if(l<=mid)modify(lc,x,y,op);
     if(r>mid)modify(rc,x,y,op);
     pushup(p,op);
}
int query(int p,int x,int y)
{
       int l=tr[p].l,r=tr[p].r;
     if(l>=x&&r<=y)
     {
        
        
     }
     int mid=(l+r)>>1;
     if(l<=mid)modify(lc,x,y,op);
     if(r>mid)modify(rc,x,y,op);
     pushup(p,op);
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int op,x,y;cin>>op>>x>>y;
        if(op==4)
        {
            cout<<query(1,x,y);
            cout<<"\n";

        }
        else
        modify(1,x,y,op);
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
