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
typedef pair<ll,ll>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
vector<PII>edge[N];
ll dist[N];
bool vis[N];
void wait()
{
    ll n, m, k;
    cin >> n >> m >> k;
    rep(i,1,m)
    {
        int x, y ,w;
        cin >> x >> y >> w;
        edge[x].push_back({y,w});
    }
    int s , e;
    cin >> s >> e;

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});
    memset(dist,0x3f,sizeof dist);
    dist[s] = 0;
    while(q.size())
    {
        auto [d,x] = q.top();
        q.pop();
        if(vis[x])continue;
        if(x == e)
        {
            cout << dist[e] - k;
            return ;
        }
        vis[x] = 1;
        for(auto [y,w]: edge[x])
        {
            if(!vis[y]&&dist[y] > dist[x] + w + k)//需要加上中转花费
            {
                dist[y] = dist[x] + w + k;
                q.push({dist[y],y});
            }
        }
    }
    cout << -1;
    return ;

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
