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
int a[N];
//使用并查集？，每个集合的数，
int fa[N];
int find(int x)
{
    return fa[x] == x?x:fa[x] =find(fa[x]);
}
void un(int y,int x)
{
    int fx = find(x),fy = find(y);
    if(fx!=fy)
    {
        fa[fx] = fy;
    }
}
bool vis[N];
set<int>st[N];
int cnt=0;
void wait()
{
    int n , m;
    cin  >> n >> m;
    rep(i,1,n)
    {
        cin >> a[i];
        fa[i] = i;
    }
    // rep(i,1,n)
    // {
    //     if(!vis[i])
    //     {
    //         ++cnt;
    //         int x = i;
    //         st[i].insert(i);
    //         while(!vis[x])
    //         {
    //             vis[x] =1;
    //              x = a[x];
    //             un(i,x);
    //             st[i].insert(x);
    //         }
    //     }
    // }
    rep(i,1,m)
    {
        int ans = -1e9;
        int a,b;cin >> a >> b;
        cout << n<<'\n';
        // int fx= find(a);
        // st[fx].insert(a);
        // int fy= find(b);
        // st[fy].insert(b);
        // for(auto i = st[fy].rbegin();i!=st[fy].rend();++i)
        // {
        //     if(st[fx].count(*i))//最大在前，找到相同即可
        //     {
        //         ans = max(*i,ans);
        //         break;
        //     }
        // }
        // cout << ans<<"\n";

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
