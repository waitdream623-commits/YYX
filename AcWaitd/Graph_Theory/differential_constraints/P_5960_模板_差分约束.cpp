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
int head[N];  // 以 u 为起点的第一条边编号，0 表示没有
int to[N];    // 这条边的终点
int nxt[N];   // 同起点的下一条边编号
int val[N];   // 这条边的边权
int cnt;
void add(int a,int b,int v)  // 加一条 a -> b，权为 v 的边
{
    to[++cnt] = b;       // 终点是 b
    val[cnt] = v;        // 边权是 v
    nxt[cnt] = head[a];  // 接在"旧表头"前面（头插法）
    head[a] = cnt;       // 自己成为新的表头
}
int dist[N];
bool vis[N];
int sz[N];//记录负环
int n ,m;

void spfa(int s)
{
    queue<int>q;//松弛过后的加入队列
    memset(dist,0x3f,sizeof dist);
    q.push(s);
    vis[s] = 1;
    dist[s] = 0;
    while(q.size())
    {
        auto a = q.front();
        q.pop();
        vis[a] = 0; // 出队要清标记：dist 变小后还能再次入队（SPFA 的灵魂）
        for(int i = head[a];i;i = nxt[i])
        {
            int y = to[i];
            if(dist[to[i]] > dist[a] + val[i])
            {
                dist[to[i]] = dist[a] + val[i];
                if(!vis[y])
                {
                    // sz 数的是"入队次数"（放 if 里面），不是被松弛的次数
                    // 有超级源点0，总点数是 n+1；入队次数达到 n+1（即 > n）→ 负环
                    if(++sz[y] > n)
                    {
                        cout << "NO";
                        return;
                    }
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        cout << dist[i]<< " ";
    }

}
void wait()
{
    cin >> n >> m;
    rep(i,1,m)
    {
        int a,b,w;
        cin >> a >> b >>w;
        add(b,a,w);
    }
    //超级源点跑负环
    rep(i,1,n)
    {
        add(0,i,0);
        
    }
    spfa(0);

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
