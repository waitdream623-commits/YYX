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
int c[N];
void wait()
{
    int n; cin >> n;
    //memset(c,0,sizeof c);
    int m = 0;
    rep(i,1,n)
    {
        int x;cin >> x;
        c[x]++;
        m = max(x,m);
    }
    ll ans = 0;
    int r = 0;
    rep(i,1,m)
    {
        ans +=(c[i]+r)/i;
        r = (c[i]+r)%i;
        c[i] = 0;//清空数据
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
