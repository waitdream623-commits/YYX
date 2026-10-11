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
//每条路线可以选择是否使用免费机会，多维护一维度
//扩点，分为不使用免费次数，和使用
vector<PII>edge[20000];
bool vis[20000][11];
int dist[20000][11];
void wait()
{
    int n, m, k;
     cin >> n >> m >> k;
     int s ,t; cin >> s >>t;

    rep(i,1,m)
    {
        int x, y ,w;
        cin >> x >>y >>w;
        edge[x].push_back({y,w});
        edge[y].push_back({x,w});
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>hp;
    memset(dist,0x3f,sizeof dist);//初始化
    hp.push({0,s,k});//距离，地点，免费次数
    dist[s][k] = 0;
    while(hp.size())
    {
        auto [d,x,c] = hp.top();
        hp.pop();
        if(vis[x][c])continue;
        vis[x][c] =1;
        if(x == t){
            cout << d;
            break;
        }
        if(c>0)//使用免费次数
        {
            for(auto [y,w]: edge[x])
            {
                if(!vis[y][c-1]&&dist[y][c-1] > d )
                {
                    dist[y][c-1] = d;
                    hp.push({d,y,c-1});
                }
            }
        }
        //不使用免费
        for(auto [y,w]: edge[x])
            {
                if(!vis[y][c]&&dist[y][c] > d +w)
                {
                    dist[y][c] = d + w;
                    hp.push({dist[y][c],y,c});
                }
            }

    }
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
