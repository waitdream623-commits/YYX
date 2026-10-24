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
int dist[N];
int vis[N];
//遇到1后续不用遍历
vector<int>edge[N];
void dfs(int x,int f)
{
    for(auto e:edge[x])
    {
        if(e==f)continue;
        dist[e] = dist[x] +1;
        if(e==1)continue;
        vis[e] = 1;//有效操作
        dfs(e,x);
    }
}
void wait()
{
    int n,k;
    cin >> n >>k;
    rep(i,1,n)
    {
        edge[i].clear();
         vis[i]=0;
        dist[i] = 0;
    }
    rep(i,1,n-1)
    {
        int x,y;
        cin  >>x >>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
       
       

    }
    dfs(n,-1);
    int ans = dist[1];
    while(k--)
    {
        int x;cin >> x;
        if(vis[x])//只会留一条有效操作
        {
            ans = max(ans,dist[x]+1);
        }
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
