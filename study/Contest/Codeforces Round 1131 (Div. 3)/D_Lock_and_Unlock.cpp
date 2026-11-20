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
ll a[N];
int cnt[N];
int n;
PII f(int m)
{
    ll ans1=0,ans2=0;

     int pl = lower_bound(a+1,a+1+n,m-1)-a+1;
    int pr = lower_bound(a+1,a+1+n,m+1)-a-1;
    int tmpr=0;
    int tmpl=0;
    while(pl !=1&&pr!=n)
    {
    if(pl<n-pr+1)
    {
        int end = upper_bound(a+1,a+1+n,a[pr+1]+tmpr)-a-1;
        ans1+=pl*(a[pr+1]-a[pr]);
        pr+=end-pr;
        ans2+=a[pr+1]-a[pr];
        tmpr+=a[pr+1]-a[pr];//右边累加减
    }
    else
    {
        int end = lower_bound(a+1,a+1+n,a[pl]-tmpl)-a-1;
        ans1+=(n-pr+1)*(a[pl]-a[pl-1]);
        pl = end;
        ans2+=a[pl]-a[pl-1];//c操作次数
        tmpl+=a[pl]-a[pl-1];//左边累加
    }
    }
    return {ans1,ans2};
}
void wait()
{
//     cin >> n;
//     ll l = 1e18,r = -1e18;
//     rep(i,1,n)
//     {cin >> a[i];
//         l = min(l,a[i]);
//         r = max(r,a[i]);
//     }
//     sort(a+1,a+1+n);
//    while(l<r)
//    {
//         int mid = (l+r)>>1;
//         if(f(mid)<=f(mid+1))
//         {
//             r=mid;
//         }
//         else
//         {
//             l=mid+1;
//         }
//    }
//    auto [ans1,ans2] = f(l);
//     cout << ans1<<' '<<ans2<<"\n";

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    ll m = a[(n + 1) / 2];
    ll ans1 = 0;

    for(int i = 1; i <= n; i++)
        ans1 += abs(a[i] - m);

    ll ans2 = a[n] - a[1];

    cout << ans1 << ' ' << ans2 << '\n';
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
