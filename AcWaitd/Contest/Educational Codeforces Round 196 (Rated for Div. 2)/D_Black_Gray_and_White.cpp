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
int fa[N];
int find(int x)
{
    // return x==fa[x]?x:fa[x]=find(fa[x]);
    int t = x;
    while(t!=fa[t])
    {
        t = fa[t];
    }
    while(x!=fa[x])
    {
        int p = x;
        x=fa[x];
        fa[p] = t;//最上层
    }
    return t;
}
void un(int a,int b)
{
    int fx = find(a),fy = find(b);
    if(a!=b)
    {
        fa[fx] = fy;
    }
}
int start;
int k;
int n;
bool dfs(int x,int f)
{
    fa[x] = x;
    for(auto e:edge[x])
    {
        if(e==f)continue;
        if(dfs(e,x))
        {
            return true;
        }
        un(e,x);
    }
    int t = k-x;
    if(t>=1&&t<=n&&t!=start)
    if(find(k-x)==start)//不能等于自身
    return true;

    return false;
}
void wait()
{
    cin >> n;
    rep(i,1,n)
    {
        edge[i].clear();
    }
    rep(i,1,n-1)
    {
        int a,b;cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    if(n%2==0)
    {
        cout << n+1<<'\n';
        return;
    }
    //三种情况
    // k =n,n+1,n+2;
    k = n;
    start = n;
    rep(i,1,n)
    {
        fa[i] = i;
    }
    if(dfs(start,-1))
    {
        cout << k<<'\n';
        return;
    }
     rep(i,1,n)
    {
        fa[i] = i;
    }
      k = n+1;
    start = (n+1)/2;
    if(dfs(start,-1))
    {
        cout << k<<'\n';
        return;
    }
     rep(i,1,n)
    {
        fa[i] = i;
    }
      k = n+2;
    start = 1;
    if(dfs(start,-1))
    {
        cout << k<<'\n';
        return;
    }
    cout << n<<'\n';//3种都没有更优秀
   
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
