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
const int N = 1e6 + 10 , MOD = 998244353;
ll f(ll n)
{
    if (n <= 1) return n;
    ///找最大的 i，使得 2^i - 1 <= n
    ll i = 0,j =63;
    while(i<j)
    {
        int mid = (i+j+1)>>1;
        if ((1LL << mid) - 1 <= n)//double会溢出，不能用pow
        {
            i = mid;
        }
        else
        {
            j=mid-1;
        }
    }
    ll t = (1LL << i) - 1;

    if (t == n) return i;

    //加到下一个
    ll nt = (1LL << (i + 1)) - 1;
    ll ans = i + 1 + nt - n;

    // 加到 t，减一重置，递归处理
    if (i > 1)//不能是1，否则无限递归
        ans = min(ans, i + 1 + f(n - t + 1));//减一也算次数
    return ans;
}
void wait()
{
    // ll l ,r ;
    // cin >> l >> r;
    // //二分找比l大的k
    // int i = 0,j = 63;
    // while(i<j)
    // {
    //     int mid = (i+j)>>1;
    //     if(pow(2,mid)-1<l)
    //     {
    //         i = mid+1;
    //     }
    //     else
    //     {
    //         j=mid;
    //     }
    // }
    // //执行i次
    // ll t = pow(2,i)-1;
    // ll ans = 1e18;
    // ans = min(ans,t-l+i);

    // if(t>=r)
    // {
    //     ll a0 = t-r+i;
    //     ll a1 = t-l+i;
    //     ans = (ans + (a0 + a1 ) % MOD   * (r - l + 1)/2%MOD ) % MOD;
    // }
    // else
    // {
    //     int rt = l;
    //         while(t<r)
    //     {
            
    //         ans = (ans + (ll)(i + i + t - rt) % MOD   * (t - rt + 1)/2  )% MOD;
    //         i++;
    //         rt = t;//上一个t位置
    //         t=pow(2,i)-1;
    //     }
    //     //t>r;
    //      ll a0 = t-r+i;
    //     ll a1 = t-rt+1;//上一个i位置的下一个
    //     ans = (ans + (a0 + a1) % MOD  * ((r-rt) % MOD)/2) % MOD;
    // }
    // cout << ans % MOD << '\n';
    ll l, r;
    cin >> l >> r;

    ll ans = 0;
    for (ll n = l; n <= r; ++n)
    {
        ans += f(n);
        ans %= MOD;
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
