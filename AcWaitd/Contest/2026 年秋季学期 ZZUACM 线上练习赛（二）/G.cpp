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
typedef pair<ll,ll>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
void wait()
{
    ll n , h; cin  >> n >> h;
    PII mn = {0,h};
    ll ans = 0;
    ll a= 0, b= 0;
    rep(i,1,n)
    {
        cin >> a >> b;
        auto [x,y] = mn;
        if(x==0||x*(b-h)>(y-h)*a)
        {
            ans ++ ;
            mn = {a,b};
        }
        
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
