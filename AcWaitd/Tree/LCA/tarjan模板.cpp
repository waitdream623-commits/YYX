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
vector<int>edge[N];
vector<PII>qu[N];//需要记录问题下标，存入结果
int ans[N];
int fa[N];
bool vis[N];
int find(int x)
{
    return fa[x] == x?x:fa[x] = find(fa[x]);
}
void tarjan(int x, int f)
{
    vis[x] = 1;//标记点是否访问过
    for(auto e:edge[x])
    {
        if(e==f)continue;
        tarjan(e,x);
        fa[e] = x;//将子树的集合与根相连
    }
    //处理完子树，查询
    for(auto [e,idx]:qu[x])//x的查询祖先
    {
        if(vis[e])//访问过e
        {
            ans[idx] = find(e);//找e的代表根，即为公共祖先
        }
    }
}
void wait()
{
    int n , m,s;
    cin >> n >> m >> s;
    rep(i,1,n-1)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        fa[i] = i;
    }
    fa[n] = n;
    rep(i,1,m)//问题链
    {
             int a, b;
        cin >> a >> b;
        qu[a].push_back({b,i});
        qu[b].push_back({a,i});
    }
    
    tarjan(s,-1); 
    rep(i,1,m)
    {
        cout << ans[i]<< '\n';
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
