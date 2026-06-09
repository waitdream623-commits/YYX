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
    int l,r,sum,max,lmax,rmax;
}tr[N<<2];
int a[N];
void pushup(node&p,node&l,node&r)
{
    p.max=max(max(l.max,r.max),l.rmax+r.lmax);
    p.lmax=max(l.lmax,l.sum+r.lmax);
    p.rmax=max(r.rmax,r.sum+l.rmax);
    p.sum=l.sum+r.sum;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,a[l],a[l],a[l],a[l]};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(tr[p],tr[lc],tr[rc]);
}
void modify(int p,int x,int s)
{
    int l=tr[p].l,r=tr[p].r;
    if(l==r)
    {
        tr[p]={l,l,s,s,s,s};
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,s);
    else modify(rc,x,s);
    pushup(tr[p],tr[lc],tr[rc]);


}
node query(int p,int x,int y)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    return tr[p];
    int mid=(l+r)>>1;
    if(y<=mid)return query(lc,x,y);//只有左边有
    if(x>mid)return query(rc,x,y);//只有右边有

    node ret,L,R;
    if(x<=mid)L=query(lc,x,y);
    if(y>mid)R=query(rc,x,y);
    pushup(ret,L,R);
    return ret;

}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);

    while(q--)
    {

        int k;cin>>k;
        if(k==1)
        {
            int a,b;cin>>a>>b;
            if(a>b)swap(a,b);
            cout<<query(1,a,b).max<<"\n";
        }
        else
        {
            int p,s;cin>>p>>s;
            modify(1,p,s);
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
