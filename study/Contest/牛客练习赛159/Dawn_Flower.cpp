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
    rep(i,1,n)cin >> a[i];
    //预处理
    vector<vector<int>>l(n+1);//预处理前缀
    rep(i,1,n)
    {
        if(a[i]+i<=n)
        l[a[i]+i].push_back(i);
    }
    // //从末尾开始
    //  vector<int> f(n+1, -1);
    // vector<int> pre(n+1, -1);

    // auto dfs = [&](auto&& dfs, int i) -> int
    // {
    //     if(i == 0)return 0;
    //     if(f[i] != -1)return f[i];

    //     f[i] = INF;  // 暂时无法划分
    //     int target = i-a[i];
    //     if(target < 1)return f[i];

    //     for(int e : l[target])
    //     {
    //         int cost = dfs(dfs, e-1);

    //         if(cost != INF && cost+1 < f[i])
    //         {
    //             f[i] = cost+1;
    //             pre[i] = e-1;  // 最后一段是 [e,i]
    //         }
    //     }

    //     return f[i];
    // };

    // int k = dfs(dfs, n);
    // if(k == INF)
    // {
    //     cout << -1 << '\n';
    //     return;
    // }

    // vector<int> ans;
    // for(int i = n; i > 0; i = pre[i])
    // {
    //     ans.push_back(i);  // i 是当前段的右端点
    // }

    // reverse(ans.begin(), ans.end());

    // cout << k << '\n';
    // for(int e : ans)cout << e << ' ';
    // cout << '\n';
    const int BAD = 1'000'000'000;
    vector<int> f(n+1, BAD), pre(n+1, -1);
    vector<int> best(n+1, BAD), bestPre(n+1, -1);

    f[0] = 0;
    rep(i,1,n)
    {
        // i 当右端点，找指向同一格的最优左端点
        int target = i-a[i];
        if(target >= 1 && best[target] != BAD)
        {
            f[i] = best[target]+1;
            pre[i] = bestPre[target];
        }

        // i 当左端点，登记给之后的右端点用
        target = i+a[i];
        if(target <= n && f[i-1] < best[target])
        {
            best[target] = f[i-1];
            bestPre[target] = i-1;
        }
    }
    if(f[n]==1e9)
    {
        cout << -1<<'\n';
    }
    else
    {
        vector<int>ans;
        for(int i = n;i>0;i= pre[i])
        {
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << '\n';
        for(auto e: ans)cout << e << ' ';
        cout << '\n';

    }
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
