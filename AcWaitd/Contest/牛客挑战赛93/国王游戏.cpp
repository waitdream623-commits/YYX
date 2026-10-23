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
//看第i次游戏，第i点前面是否又会被转换点
//前面夺取，可能被前面再次夺取，需要考虑
vector<int>edge[N];
bool vis[N];
void wait()
{
    int n ,m ;
    cin  >> n >> m;
    rep(i,1,m)
    {
        int x, y;
        cin >> x >>y;
        edge[x].push_back(y);
    }
    for(int i = 1 ; i<=n;i++)
    {
        for(auto e:edge[i])
        {
            if(e<=i)continue;
            if(vis[i])continue;//会被前面夺取，变成-1；
            vis[e]=1;//标记后面的点；
        }
    }
    rep(i,1,n)
    {
        if(!vis[i])cout << 1<<'\n';
        else
        cout << 0 << '\n';
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
