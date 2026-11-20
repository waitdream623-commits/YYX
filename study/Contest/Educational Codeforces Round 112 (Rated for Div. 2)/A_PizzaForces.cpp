#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
ll a[] = {6,8,10};
ll b[] = {15,20,25};
void wait()
{
    ll n;cin >> n;
    ll ans = 0;
    if(n>100)
    {
        ans+=((n/10)-5)*25;
        n-=((n/10)-5)*10;
    }
    vector<ll>f(n*2+1,1e18);
    f[0]=0;
    for(int i = 0;i<=2;i++)
    {
        for(ll j = 0;j<=n*2;j++)//完全背包
        {
            f[j] = min(f[j],f[max(0ll,j-a[i])]+b[i]);
        }
    }
    rep(i,n,n*2)
    {
        if(f[i]!=1e18)
        {
            ans+=f[i];
            break;
        }
    }
    cout << ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
