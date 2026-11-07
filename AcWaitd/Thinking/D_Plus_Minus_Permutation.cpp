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
ll gcd(ll a,ll b)
{
    return b == 0?a:gcd(b,a%b);
}
void wait()
{
    ll n ,x ,y;cin >> n >> x >> y;
    //找最小公倍数
    ll d = x*y/gcd(x,y);
    ll t1 = n/x,t2 = n/y;
    ll t3 = n/d;
    ll ans = 0;
    ans+=1LL*(n+n-(t1-t3)+1)*((t1-t3))/2-1LL*(1+(t2-t3))*(t2-t3)/2;
    cout << ans << '\n';
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
