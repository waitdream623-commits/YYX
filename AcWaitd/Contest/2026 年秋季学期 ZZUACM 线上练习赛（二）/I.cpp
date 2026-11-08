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
void wait()
{
    ll a , b;cin >> a >> b;
    //b中必定有a的所有1位
    ll t = a^b;
    for(int i = 0;i<=32;i++)
    {
        if((((a>>i)&1)==1)&&(((b>>i)&1)==0))
        {
            cout << 0 <<'\n';
            return;
        }
    }
    ll ans = 1;
    while(t)
    {
        if(t&1)
        {
           ans*=2;
        }
        t>>=1;
    }
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
