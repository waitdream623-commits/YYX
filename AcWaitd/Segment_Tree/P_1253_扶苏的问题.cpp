#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N];
struct node{
    ll l,r,max,add,update;//st标记是否执行重置,先执行重置，后执行加法
    bool st;
}tr[N<<2];
void pushup(int p)
{
    tr[p].max=max(tr[lc].max,tr[rc].max);
}
void build(int p,int l,int r)
{
    tr[p]={l,r,a[l],0,0,0};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p);
}
void lazy(int p,bool st,ll update,ll add)//op==1,为修改，op==2为增加,修改时，将add重置
{
   if(st)
   {
    tr[p].st=st;
    tr[p].max=update;
    tr[p].add=0;
    tr[p].update=update;

   }
   //可以先小处理重置，再加
   tr[p].max+=add;
   tr[p].add+=add;
}
void pushdown(int p)
{
    if(tr[p].st==0&&tr[p].add==0)return;
    lazy(lc,tr[p].st,tr[p].update,tr[p].add);//下发信息，此层更新
    lazy(rc,tr[p].st,tr[p].update,tr[p].add);
    tr[p].st=tr[p].update=tr[p].add=0;
}
void modify(int p,int x,int y,bool st,ll update,ll add)//开ll
{
    int l=tr[p].l,r=tr[p].r;
    if(l>=x&&r<=y)
    {
        lazy(p,st,update,add);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(p);
     if(y>mid)modify(rc,x,y,st,update,add);
    if(x<=mid)modify(lc,x,y,st,update,add);
    pushup(p);
}
ll query(int p,int x,int y)
{
     int l=tr[p].l,r=tr[p].r;
    if(l>=x&&r<=y)
    {
        return tr[p].max;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    ll mx=-1e18;//可能减去，导致很小
    if(y>mid)mx=max(mx,query(rc,x,y));
    if(x<=mid)mx=max(mx,query(lc,x,y));
    return mx;

}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int op,l,r;cin>>op>>l>>r;
        if(op==3)
        {
            cout<<query(1,l,r)<<endl;
        }
        else if(op==1)
        {
            int x;cin>>x;
            modify(1,l,r,1,x,0);//表示重置为x，加0
        }
        else
        {
            int x;cin>>x;
            modify(1,l,r,0,0,x);
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
