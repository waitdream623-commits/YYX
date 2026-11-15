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
    int n;cin >> n;
    rep(i,1,n-1)
    {
        cin >> a[i];
    }
    int l = 1,r = a[1];
    auto f = [&](int x)->int
    {
        int mx = x;
        rep(i,1,n-1)
        {
            x = a[i]-x;
            mx = max(x,mx);
            if(x<0)
            {
                return -1;
            }
        }
        return mx;
    };
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(f(mid)<f(mid+1))
        {
            r = mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << f(l);
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
