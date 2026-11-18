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
    return b==0?a:gcd(b,a%b);
}
void wait()
{
    int n;cin >> n;
    string s;cin >> s;
    int po = 0,ne = 0;
    for(auto e:s)
    {
        if(e=='+')
        {
            po++;
        }
        else
        ne++;
    }
    ll m ;cin >> m;
    while(m--)
    {
        ll a,b;cin >> a >> b;
        if(ne==po)
        {
            cout << "YES\n";
            continue;
        }
        if(a==b)
        {
            cout << "NO\n";
            continue;
        }
        ll d = abs(ne-po);
        ll d2 = gcd(a,b);
        a/=d2;b/=d2;
        ll d3 = abs(a-b);
        //且至少够k组
        if(d%d3==0)
        {
            ll k = d/d3;
            ll t = max(a,b);
            if(t*k<=max(ne,po)&&min(a,b)*k<=min(ne,po))//能拿出这么多组，此处可能乘法溢出
            {cout << "YES\n";
            continue;}
        }
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
     //cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
