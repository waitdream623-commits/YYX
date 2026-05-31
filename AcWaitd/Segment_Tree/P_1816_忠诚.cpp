#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
#define lc p<<1
#define rc p<<1|1
int a[N];
struct node
{
    ll l,r,sum;
}tr[N<<2];
void pushup(int p)
{
    tr[p].sum=min(tr[rc].sum,tr[lc].sum);
    return;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,a[l]};
    if(l==r)return;
    ll mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p);
    return;
}
ll query(int p,int x, int y)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)return tr[p].sum;
    int mid=(l+r)>>1;
    ll sum=INF;
    if(x<=mid)sum=min(sum,query(lc,x,y));
    if(y>mid)sum=min(sum,query(rc,x,y));
    return sum;
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<query(1,l,r)<<" ";
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
