#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1

//需要乘与加，
//每次lazy时，先乘后加，如果之前存在加，此时执行乘，需要将add乘以倍数,mul乘以倍数，
//对于加，只需要变化add,
const int N = 1e5 + 10;
int a[N];
struct node{
    ll l,r,sum,add,mul;
}tr[N<<2];

int n,m;
void pushup(int p)
{
    tr[p].sum=(tr[lc].sum+tr[rc].sum)%m;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,a[l],0,1};//乘法初始化为1
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p);
}
void lazy(int p, ll ad, int ml) {
    //len 升级为 ll，防止 ad * len 时在 32 位下溢出
    ll len = tr[p].r - tr[p].l + 1;
    tr[p].sum = (tr[p].sum * ml + ad * len%m) % m;
    tr[p].add = (tr[p].add * ml + ad) % m;
    tr[p].mul = tr[p].mul * ml % m;
}
void pushdown(int p)
{
    if(tr[p].add==0&&tr[p].mul==1)return;
    lazy(lc,tr[p].add,tr[p].mul);
    lazy(rc,tr[p].add,tr[p].mul);
    tr[p].add=0,tr[p].mul=1;
}
void modify(int p,int x,int y,int ad,int ml)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        lazy(p,ad,ml);
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y,ad,ml);
    if(y>mid)modify(rc,x,y,ad,ml);
    pushup(p);
    return;
}
ll query(int p,int x,int y)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        return tr[p].sum;
    }
    pushdown(p);
    ll sum=0;
    int mid=(l+r)>>1;
    if(x<=mid)sum+=query(lc,x,y);
    if(y>mid)sum+=query(rc,x,y);
    return sum%m;
}
void solve()
{
    int p;
    cin>>n>>p>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(p--)
    {
        int op;cin>>op;
        if(op==1||op==2)
        {
            int x,y,k;
            cin>>x>>y>>k;
            if(op==2)
            modify(1,x,y,k,1);
            else
            {
                modify(1,x,y,0,k);
            }
        }
        else
        {
            int x,y;cin>>x>>y;
            cout<<query(1,x,y)<<endl;
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
