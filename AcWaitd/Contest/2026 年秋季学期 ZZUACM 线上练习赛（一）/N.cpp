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
    ll a, b,m;
    cin >> a >> b>>m;
    if(m<a+b)
    {
        cout <<0;
    }
    else
    {
        m -=a+b;

        ll t = 5*a+3*b;
    ll ans = 0;
    ans +=m/t*15;
    m-=m/t*t;
    if(m>0)
    {
        for(int i =1;i<=15;i++)
        {
            if(i%3==0)m-=a;
                if(i%5==0)m-=b;
            if(m<=0)
            {
                ans+=i;
                cout << ans;
                return;
            }
        }
    }
    cout << ans;
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
