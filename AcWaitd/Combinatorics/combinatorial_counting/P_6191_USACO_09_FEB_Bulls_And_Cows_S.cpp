#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10,p=5000011;
ll qpow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=ret*a%p;
        b>>=1;
        a=a*a%p;

    }
    return ret;
}
ll f[N],g[N];
void init()
{
    f[0]=1;
    for(int i=1;i<=N;i++)f[i]=i*f[i-1]%p;
    g[N]=qpow(f[N],p-2,p);
    for(int i=N-1;i>=0;i--)
    {
        g[i]=(i+1)*g[i+1]%p;
    }
}
ll get_c(ll a,ll b)
{
    return f[a]*g[a-b]%p*g[b]%p;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    init();
    ll sum=0;
    for(int i=0;i<=n-(i-1)*k;i++)
    {
        sum=(sum+get_c(n-(i-1)*k,i))%p;
    }
    cout<<sum;
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
