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
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
void wait1()
{
    ll a,x,k;
    cin >> a>> x >> k;
    ll lg = log2(x);
    ll t = k*(lg+1);
    ll s = t*x;
    ll d = s+a-qpow(2,lg)+1;
    ll l = 1 ,r = 30*(k+1);
    while(l<r)
    {
        ll mid = (l+r)>>1;
        if(d+x*mid<=qpow(2,mid)-1)
        {
            r = mid;
        }
        else
        l=mid+1;
    }
    s+=x*l;
    cout << s <<'\n';
}
void wait2()
{
    ll a, x, k;
    cin >> a >> x >> k;

    ll t = k + 1;
    ll l = 1, r = 30 * t;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        ll p = mid / t, cnt = mid % t;//尽可能平均分配
        ll s = (t - cnt) * ((1LL << p) - 1)+cnt *((1LL << (p + 1))-1);

        if(a +x * mid <= s)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << a +x*(l - 1)<< '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait2();
    }
    return 0;
}
