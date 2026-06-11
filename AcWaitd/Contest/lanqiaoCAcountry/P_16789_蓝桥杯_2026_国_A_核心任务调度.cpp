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

    int t,w,k;
}a[N];
bool cmp(struct node&a,struct node&b)
{
    if(a.t!=b.t)return a.t<b.t;
    else
    {
        if(a.k!=b.k)return a.k>b.k;
        return a.w>b.w;
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].w>>a[i].k;
    }
    sort(a+1,a+1+n,cmp);
    ll sum=0;
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].k)ret++;
        sum+=a[i].w;
        while(a[i].t==a[i+1].t&&i<=n)i++;
    }
    cout<<ret<<" "<<sum;
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
