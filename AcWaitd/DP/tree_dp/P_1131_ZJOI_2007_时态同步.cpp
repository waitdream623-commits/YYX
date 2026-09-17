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
ll mx[N];//记录根节点到子的最大距离
vector<PII> edges[N];
ll f[N];//记录需要次数
bool st[N];//
void dfs(int x,int fa)
{
    for(auto e: edges[x])
    {
        if(e.first==fa)continue;
        dfs(e.first ,x);
        mx[x]=max(mx[x],e.second+mx[e.first]);
        
    }
    for(auto e: edges[x])
    {
        if(e.first==fa)continue;
        //dfs(e.first ,x);不能写在此处，第一次调用完，回处理完，回到上层，进行第二次循环，会再次调用
        
        f[x]+=mx[x]-mx[e.first]-e.second+f[e.first];//加上到达该字节点距离加上该子作为修正后需要次数
        //不用再次递归
        // st[x]=1;
        // if(!st[x])
        // dfs(e.first ,x);//超时，如何只会调用一次
    }
}
void wait()
{
    int n ,s;cin >> n >>s;
    rep(i,1,n-1)
    {
        int a,b,v;cin >> a >>b >>v;
        edges[a].push_back({b,v});
        edges[b].push_back({a,v});

    }
    dfs(s,-1);
    cout<< f[s];
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
