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
//每个位置维护最大与最小
ll f[N][2];
ll a[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    ll smin = a[1];
    ll smax = a[1];
    f[1][0] = a[1];//小
    f[1][1] = a[1];//大
    ll ans = a[1];
    for(int i = 2;i <= n; i++)
        {
            f[i][0] = min({a[i], a[i] - smax,a[i] + smin});
            f[i][1] = max({a[i], a[i] - smin,a[i] + smax});//分三种情况
            //新前缀和,
            long long newmin = min({a[i]+smin,a[i],a[i]+2*smin});
            long long newmax = max({a[i]+smax,a[i],a[i]+2*smax});
            smin = newmin;
            smax = newmax;
            ans = max(ans,f[i][1]);
        }
        cout <<ans<<"\n";

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
