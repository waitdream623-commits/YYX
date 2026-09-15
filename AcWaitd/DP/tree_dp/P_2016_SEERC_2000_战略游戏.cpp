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
const int N = 1e6 + 10;
vector<int>edge[N];
int dp[N][2];//0表示该节点不选，1表示选；
void dfs(int x, int fa)
{
    dp[x][1]=1;
    dp[x][0]=0;
    for(auto e: edge[x])
    {
        if(e==fa)continue;
        dfs(e,x);
        dp[x][0]+=dp[e][1];
        dp[x][1]+=min(dp[e][0],dp[e][1]);
    }
}
void wait()
{
    int n; cin >> n;
    rep(i,1,n)
    {
        int a,m;cin >> a >>m;
        while(m--)
        {
            int x;cin>>x;
            edge[x].push_back(a);
            edge[a].push_back(x);
        }

    }
    dfs(0,0);
    cout<<min(dp[0][0],dp[0][1]);
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
