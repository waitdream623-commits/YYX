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
int a[N];
void wait()
{
    int n,k;cin >> n >> k;
    if(k>=0)
    {
            ll ans=0;
            ll sum=0;
            rep(i,1,n)
            {
                ll x;
                cin >> x;
                sum = max(sum+x,x);
                ans = max(ans,sum);
            }
            cout << max(ans,ans*k)<<'\n';
    }
    else
    {
          ll ans=1e9;
            ll sum=1e9;
            rep(i,1,n)
            {
                ll x;
                cin >> x;
                sum = min(sum+x,x);
                ans = min(ans,sum);
            }
            cout << max(ans,ans*k)<<'\n';
    }
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
