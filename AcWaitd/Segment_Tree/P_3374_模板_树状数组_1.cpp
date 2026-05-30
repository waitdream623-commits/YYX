#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
#define lc p<<1
#define rc p<<1|1
int n,m;
int a[N];
struct node{
    int l,r;
    ll sum;
}tr[N<<2];//开四倍
void push(int p)
{
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,0};//初始化，记录区间，方便后面
    if(l==r)
    {
        tr[p].sum=a[l];//找到节点
        return;//忘记返回
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);//左子树
    build(rc,mid+1,r);//右子树
    push(p);
    return;
}
void modify(int p,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tr[p].sum+=val;
        return;//返回
    }
    int mid=(l+r)>>1;
    if(pos<=mid)modify(lc,l,mid,pos,val);
    else
    {
        modify(rc,mid+1,r,pos,val);
    }
    //返回时更新
    push(p);
    return;
}
ll query(int p,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr)
    {
        return tr[p].sum;
    }
    int mid=(l+r)>>1;
    ll t=0;
    if(ql<=mid)
    {
        t+=query(lc,l,mid,ql,qr);
    }
    if(qr>mid)    
    {
        t+=query(rc,mid+1,r,ql,qr);
    }
    return t;

}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int p;cin>>p;
        if(p==1)
        {
            int x,k;cin>>x>>k;
            modify(1,1,n,x,k);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
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
