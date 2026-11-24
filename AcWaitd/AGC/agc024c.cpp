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
    ll ans = 0;
    bool f = 0;
    rep(i,1,n)
    {
        cin >> a[i];
        if(f)
        continue;
        if((a[i]-a[i-1]>=2)||a[i]>i-1)//后者小于前者没有差值要求
        {
            f = 1;
        }
        else
        {
            if(a[i]>a[i-1])
            {
                ans++;
            }
            else if(a[i]==a[i-1])
            {
                ans+=a[i];
            }
            else//a[i]<a[i-1]
            {
                ans+=a[i];
            }
        }

    }
    if(f)
    {
        cout << -1;
    }
    else
    cout << ans<<'\n';
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
