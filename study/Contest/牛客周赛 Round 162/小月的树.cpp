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
vector<pair<int,char>>edges[N];
string s;
//bool  dp[N];//记录孩子与根是否相同
int ans;
// void dfs1(int x, int fa)
// {
//     for(auto e:edges[x])
//     {
//         auto [a,b]=e;
//         if(a==fa)continue ;
//         dfs1(a,x);
//         if(b!=s[x-1])
//         dp[x]=true;//需要删除；
//     }
// }
bool dp[N];//子树中是否存在不一样点

void dfs1(int x, int fa)
{
    for(auto [a,b] : edges[x])
    {
        if(a == fa) continue;

        dfs1(a,x);

        if(dp[a] || s[a-1] != s[x-1])
            dp[x] = true;
    }
}
//递归前处理，如果该点dp为true，前父亲与其不同，就删除；
void dfs2(int x,int fa)
{
    if(fa != -1)
    {
        if(s[x-1] != s[fa-1] && dp[x])
            ans++;
    }
    //如果只有叶子节点不同
    if(edges[x].size()==0&&dp[fa])
    {
        ans++;
        dp[fa]=false;//删根更优
    }
     for(auto e:edges[x])
    {
        auto [a,b]=e;
        if(a==fa)continue ;
        dfs2(a,x);
    }
}
void wait()
{
    int n;cin>>n;
    
    cin>>s;
    rep(i,1,n-1)
    {
        int a,b; cin >> a>> b;
        edges[a].push_back({b,s[b-1]});
        edges[b].push_back({a,s[a-1]});

    }
    dfs1(1,-1);
    dfs2(1,-1);
    if(ans==0)ans=1;
    cout<<ans;
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
