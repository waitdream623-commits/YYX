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
int dp[N][2];//dp[i][0]表示不选根节点，1表示选，之后的最大快乐值,i选了，子节点就不会选了
vector<int>edge[N];
int a[N];
void dfs(int x)
{
    dp[x][1]=a[x];
    dp[x][0]=0;
    for(auto e:edge[x])
    {
        dfs(e);
        dp[x][0]+=max(dp[e][1],dp[e][0]);
        dp[x][1]+=dp[e][0];
    }
}
int f[N];
void wait()
{
    int n;cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    rep(i,1,n-1)
    {
        int x,y;cin >> x >> y;
        edge[y].push_back(x);
        f[x]=y;
    }
    //找根节点
    int root=1;
    while(f[root]!=0)root = f[root];
    dfs(root);
    cout<<max(dp[root][0],dp[root][1]);
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
