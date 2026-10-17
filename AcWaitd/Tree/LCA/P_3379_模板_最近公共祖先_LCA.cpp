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
const int N = 5e5 + 10;   // P3379: n <= 5e5，按题开数组才不 MLE
vector<int>edge[N];
int deep[N];
const int LIMIT = 19;     // 2^19 = 524288 >= 最大深度 5e5
int st[N][LIMIT + 1];
void dfs(int x,int fa)
{
    if(fa == -1)
    {
        deep[x] = 1;
        st[x][0] = x;
    }
    else
   {
     deep[x] = deep[fa] +1;
    st[x][0] = fa;
   }
    
    for(int i = 1;i<=LIMIT;i++)
    {
        st[x][i] = st[st[x][i-1]][i-1];
    }
    for(auto e:edge[x])
    {
        if(e == fa)continue;
        dfs(e,x);
    }
}
int query(int x,int y)
{
    if(deep[x] < deep[y]) swap(x,y);   // 保证 x 更深，否则"移到同层"这步会失效
    //先移到同层
    for(int i = LIMIT ; i>=0;i--)
    {
        if(deep[x] - (1<<i) <deep[y])continue;
        x = st[x][i];
    }
    if(x==y)
    return x;
    for(int i = LIMIT;i>=0;i--)
    {
        // 根节点的 st 是自己，越界跳会双双停到根，自然相等被跳过，不用再防下溢
        if(st[x][i] == st[y][i])continue;
        x= st[x][i],y= st[y][i];
    }
    return st[x][0];//往上走一步
}
void wait()
{
    int n, m ,s;
    cin >> n >> m >> s;
    rep(i,1,n-1)
    {
        int a , b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);

    }
    dfs(s,-1);
    rep(i,1,m)
    {
        int a, b;
        cin >> a >> b;
       cout <<  query(a,b)<< "\n";
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
