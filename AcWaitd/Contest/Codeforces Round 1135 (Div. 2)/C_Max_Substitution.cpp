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
const int N = 1e6 + 10,MOD = 1e9+7;
int a[N];
ll qpow(int a,int b)
{
    ll x = a;
    ll ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans*=x;
            ans%=MOD;
        }
        x*=x;
        x%=MOD;
        b>>=1;
    }
    return ans;
}
void wait()
{
    int n;cin >> n;
    rep(i,1,n)cin >> a[i];
    sort(a+1,a+1+n,greater<int>());
    ll ans = 1;
    rep(i,1,n)
    {
        if(i+1<=n&&a[i]==a[i+1])break;
        ans=(ans+qpow(a[i]-1, i))% MOD;
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
