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
vector <int> edges[N];
int a[N];
int f[N][30];
int g[N][30];
void dfs1(int x, int fa)
{
    rep(i,0,20)f[x][i]=a[x];
    for(auto e:edges[x])
    {
        if(e==fa)continue;
        dfs1(e,x);
        for(int i=1;i<=20;i++)
        {
            f[x][i]+=f[e][i-1];
        }
    }
}

void dfs2(int x,int fa)
{
    for(auto e: edges[x])
    {
        if(e==fa)continue;
        g[e][0]=a[e];
        g[e][1]=f[e][1]+a[x];
        for(int i=2;i<=20;i++)
        {
            g[e][i]=f[e][i]+g[x][i-1]-f[e][i-2];
        }
        dfs2(e,x);
    }
}
void wait()
{
    int n;cin >> n;
    int k;cin>> k;

    rep(i,1 , n-1)
    {
        int a, b;
        cin>> a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);

    }   
    rep(i,1 ,n)
    {
        cin>> a[i];
    }
    dfs1(1,-1);
    for(int i = 0; i <= k; i++) g[1][i] = f[1][i];//第一个根，需要信息提前整合，其余根，在递归前整合完毕传到下面
    dfs2(1,-1);
    for(int i=1;i<=n;i++)
    cout<<g[i][k]<<"\n";

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
