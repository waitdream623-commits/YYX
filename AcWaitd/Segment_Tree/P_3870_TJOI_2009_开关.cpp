#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
//开着为1，关着为0；
struct node{
    ll l,r,cnt,ly;
}tr[N<<2];
void lazy(int p,int ly)//ly只可能是0与1，传过来排除了0；
{
    int l=tr[p].l,r=tr[p].r;
    tr[p].cnt=r-l+1-tr[p].cnt;//模拟开关灯
    tr[p].ly=(tr[p].ly+ly)%2;//关键
}
void pushup(int p)
{
    tr[p].cnt=tr[lc].cnt+tr[rc].cnt;

}
void build(int p,int l,int r)
{
    tr[p]={l,r,0,0};
    if(l==r)return;
    ll mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p);

}
void pushdown(int p)
{
    int a=tr[p].ly;
    if(a==0)return;

    lazy(rc,a);
    lazy(lc,a);
    tr[p].ly=0;
}
void modify(int p,int x,int y)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        lazy(p,1);
        return;
    }
    pushdown(p);
    ll mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y);
    if(y>mid)modify(rc,x,y);
    pushup(p);

}
ll query(int p,int x,int y)
{
     int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
      
        return tr[p].cnt;
    }
    pushdown(p);
    ll mid=(l+r)>>1;
    ll sum=0;
    if(x<=mid)sum+=query(lc,x,y);
    if(y>mid)sum+=query(rc,x,y);
    return sum;

}
void solve()
{
    int n,m;cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        int op;cin>>op;
        int l,r;
        cin>>l>>r;
        if(op==0)
        {
        
            modify(1,l,r);
        }
        else
        {
            cout<<query(1,l,r)<<endl;
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
