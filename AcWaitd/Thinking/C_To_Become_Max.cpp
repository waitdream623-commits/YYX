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
ll a[N],s[N];
void wait()
{
    ll n,k;cin >> n >> k;
    ll ans = 0;

    rep(i,1,n)
    {
       
        cin >> a[i];
      
       ans = max(ans,a[i]);
    }
    //枚举起始位置和终止位置
    for(int i = n;i>0;i--)//终止位置,如果终止位置前面也比他大，终止位置也可以增大
    {
        // for(int j = 1;j<=i;j++)//起始位置
        // {
        //     int len = i-j+1;
        //     ll t = (a[i]+len-1+a[i])*(len)/2-(s[i]-s[j-1]);//需要消耗，如果范围内有比要求还要大的怎么办，说明此时可以跳过，直接以大的为终止
        //     if(i+1<=n)
        //     {
        //         int x = a[i+1]-a[i]+1;//可以全员增加
        //         int add  = (k-t)/len;
        //         len+=min(x,add);//随便加在一个数值上，不严谨，意味着，整体加一
        //     }
        //     if(t<=k)
        //     {
        //         ans = max(a[i]+len-1,ans);
        //     }
        // }
        ll sum = 0;
        for(int j = i-1;j>=1;j--)//逆着枚举
        {
             int len = i-j+1;
             int add = (a[i]+len-1)-a[j];
             if(add <0)
             {
                ;
             }
             else
             sum+=add;

            if(i+1<=n)
            {
                int x = a[i+1]-a[i]+1;//可以全员增加,区间内可能有比抬高后的值要大
                int add  = (k-sum)/len;
                len+=min(x,add);//随便加在一个数值上，不严谨，意味着，整体加一
            }
            if(sum<=k)
            {
                ans = max(a[i]+len-1,ans);
            }
        }
    }
    cout << ans <<'\n';
}
void wait2() {
    int n;
    ll k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }

    for (int i = n; i >= 2; --i) {
        ll sum = 0, mx = 0;

        for (int j = i - 1; j >= 1; --j) {
            ll len = i - j;  // 待加高的位置是 [j, i-1]
            sum += a[j] + j;
            mx = max(mx, a[j] + j);

            // 取右端点能支撑的上限和预算上限中的较小值。
            ll h = min(a[i] + i, (k + sum) / len);

            if (h > mx) {
                ans = max(ans, h - j);
            }
        }
    }

    cout << ans << '\n';
    
}
void wait3() {
    int n;
    ll k;
    cin >> n >> k;

    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    auto checkFrom = [&](int i, ll x) {
        ll sum = 0, need = x;
        for (int j = i; j <= n; ++j) {
            if (a[j] >= need) return true;  // 找到原本就够高的支撑点
            if (j == n) return false;      // 最后一个位置不够高，且不能加

            sum += need - a[j];
            if (sum > k) return false;
            --need;
        }
        return false;
    };

    auto check = [&](ll x) {
        for (int i = 1; i <= n; ++i) {
            if (checkFrom(i, x)) return true;
        }
        return false;
    };

    ll l = mx, r = mx + k;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait3();
    }
    return 0;
}
