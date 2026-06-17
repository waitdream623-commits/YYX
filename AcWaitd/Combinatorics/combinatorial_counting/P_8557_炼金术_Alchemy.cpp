#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10,mod=998244353;
//对于此题，因为每个金属，都有2的k次方-1种熔炉组合产生；
//总组合为每个金属挑选一种
ll qpow(ll a,ll b,ll p)
{
    ll ret=1;
    while(b)
    {
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<qpow(qpow(2,k,mod)-1,n,mod);
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
