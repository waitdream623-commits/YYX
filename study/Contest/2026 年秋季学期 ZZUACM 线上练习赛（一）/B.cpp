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
char x[1000][1000];
bool vis[1100][1000];
int in[10000][1000];//入度为零
int d[]={-1,0,1,0,-1};
    int n,m;
vector<array<int,3>>ans;
int cnt;
vector<PII>edge[1000][1000];
void bfs(int si, int sj)
{
    queue<PII> bq;
    bq.push({si, sj});
    vis[si][sj] = 1;
    while (!bq.empty())
    {
        auto [i, j] = bq.front();
        bq.pop();
        cnt++;
        rep(k, 0, 3)
        {
            int nx = i + d[k], ny = j + d[k + 1];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (vis[nx][ny] || x[nx][ny] != '#') continue;
            vis[nx][ny] = 1;
            in[i][j]++;
            in[nx][ny]++;
            edge[i][j].push_back({nx, ny});
            edge[nx][ny].push_back({i, j});
            bq.push({nx, ny});
        }
    }
}
queue<PII>q;
void dfs2(int si, int sj)
{
    queue<array<int,4>> tq;  // 存 {当前点x, 当前点y, 父点x, 父点y}
    tq.push({si, sj, -1, -1});
    while (!tq.empty())
    {
        auto [cx, cy, px, py] = tq.front();
        tq.pop();
        if (in[cx][cy] == 1) q.push({cx, cy});
        for (auto& [a, b] : edge[cx][cy])
        {
            if (a == px && b == py) continue;
            tq.push({a, b, cx, cy});
        }
    }
}
void wait()
{
    cin >> n >>m;
    rep(i,1,n)
    rep(j,1,m)cin >> x[i][j];
    ll sum=0;
    rep(i,1,n)
    rep(j,1,m)
    {
        if(x[i][j]=='#'&&!vis[i][j])
        {
            cnt=0;
            bfs(i,j);
            ans.push_back({i,j,cnt});
            sum +=cnt-1;
        }
    }
    cout << sum<<'\n';
    if(sum == 0)return;
    for(auto& [x,y,c]:ans)
    {
        while(q.size())
        q.pop();
        dfs2(x,y);//输出删除顺序，从度为1开始
        while(q.size())
        {
            if(q.size()==1)break;
            auto [a,b] = q.front();
            q.pop();
            cout << a<< " "<<b<<'\n';
            for(auto [nx,ny]:edge[a][b])
            {
                if(--in[nx][ny]==1)q.push({nx,ny});
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
