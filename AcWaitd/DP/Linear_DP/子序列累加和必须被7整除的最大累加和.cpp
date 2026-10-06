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
//定义状态dp[i][j]表示，1-i中，模数为j的最大值
void wait()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //初始化，如果有些余数不存在
    vector<array<long long,7>> dp(n+1);
for (auto& r : dp) r.fill(-1);                    // -1 = 不可达
dp[0][0] = 0;                     
    for(int i=1; i <= n; ++i)
    {
        for(int j=0;j<7;j++)
        {
            //不选本身
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            //选呢
            long long p = dp[i-1][((j - a[i] % 7) + 7) % 7];
        if (p != -1) dp[i][j] = max(dp[i][j], p + a[i]); 
    }
    }
    cout << dp[n][0];

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
