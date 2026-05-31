#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e5 + 10;
int a[N];
int f[N];
//单点查询
//每个数，的改变与所处位置，首项与公差
//将首项大小与位置与公差记录为结构体，以懒标记
struct node{
    ll l,r,sum,d;

}tr[N<<2];
void pushup(int p)
{
    tr[p].sum=tr[lc].sum+tr[rc].sum;

}
void build(int p,int l,int r)
{
    tr[p]={l,r,f[l],0};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(p);
}
void lazy(int p,ll d)
{
    int l=tr[p].l,r=tr[p].r;
    tr[p].sum+=(r-l+1)*d;
    tr[p].d+=d;

}
void pushdown(int p)
{
   ll d=tr[p].d;
    lazy(lc,d);
    lazy(rc,d);
    tr[p].d=0;
}
void modify(int p,int x,int y,ll d)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        lazy(p,d);
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid)modify(lc,x,y,d);

    if(y>mid)modify(rc,x,y,d);
    pushup(p);//记得向上返回，只是满足包含关系取消往下
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
    int mid=(l+r)>>1;
    ll sum=0;
    if(x<=mid) sum+=query(lc,x,y);
    if(y>mid) sum+=query(rc,x,y);
    return sum;
   
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i]-a[i-1];
    }
    build(1,1,n);
    while(m--)
    {
        int op;cin>>op;
        if(op==1)
        {
            ll l,r,k,d;cin>>l>>r>>k>>d;
            modify(1,l,l,k);
            if(r>l)
            modify(1,l+1,r,d);
            if(r+1<=n)
            modify(1,r+1,r+1,-(k+(r-l)*d));
        }
        else
        {
            int x;cin>>x;
            cout<<query(1,1,x)<<endl;
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


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e5 + 10;
// int a[N];
// //单点查询
// //每个数，的改变与所处位置，首项与公差
// //将首项大小与位置与公差记录为结构体，以懒标记
// struct no{
//     ll l,r,sum,k,d;

// }tr[N<<2];
// void pushup(int p)
// {
//     tr[p].sum=tr[lc].sum+tr[rc].sum;

// }
// void build(int p,int l,int r)
// {
//     tr[p]={l,r,a[l],0,0};
//     if(l==r)return;
//     int mid=(l+r)>>1;
//     build(lc,l,mid);build(rc,mid+1,r);
//     pushup(p);
// }
// void lazy(int p,ll k,ll d)
// {
//     int l=tr[p].l,r=tr[p].r;
//     tr[p].sum+=(k+k+(r-l)*d)*(r-l+1)/2;//等差数列求和
//     tr[p].k+=k;
//     tr[p].d+=d;

// }
// void pushdown(int p)
// {
//     ll k=tr[p].k,d=tr[p].d;
//     lazy(lc,k,d);
//     lazy(rc,k+((tr[p].r+tr[p].l)/2+1-tr[p].l)*d,d);
//     tr[p].k=tr[p].d=0;
// }
// void modify(int p,int x,int y,ll k,ll d)
// {
//     int l=tr[p].l,r=tr[p].r;
//     if(x<=l&&r<=y)
//     {
//         lazy(p,k+(l-x)*d,d);
//         return;
//     }
//     pushdown(p);
//     int mid=(l+r)>>1;
//     if(x<=mid)modify(lc,x,y,k,d);
//     //if(y>mid)modify(rc,x,y,k+(mid+1-x)*d,d);//确切操作为包含在内时，会在lazy内更行为正确值

//     if(y>mid)modify(rc,x,y,k,d);
//     pushup(p);//记得向上返回，只是满足包含关系取消往下
//     return;
// }
// ll query(int p,int x)
// {
//     int l=tr[p].l,r=tr[p].r;
//     if(l==r)return tr[p].sum;
//     pushdown(p);
//     int mid=(l+r)>>1;
//     if(x<=mid) return query(lc,x);
//     else
//     return query(rc,x);
   
// }
// void solve()
// {
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     build(1,1,n);
//     while(m--)
//     {
//         int op;cin>>op;
//         if(op==1)
//         {
//             ll l,r,k,d;cin>>l>>r>>k>>d;
//             modify(1,l,r,k,d);
//         }
//         else
//         {
//             int x;cin>>x;
//             cout<<query(1,x)<<endl;
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;  // 多测时取消注释
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
