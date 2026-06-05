#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N];
vector<int>edge[N];
int f[N];//表示以i为根的最大值
void dfs(int x,int fa)
{
    f[x]=a[x];
    for(auto e:edge[x])
    {
        if(e==fa)continue;
        dfs(e,x);
        if(f[e]>=0)
        {
            f[x]+=f[e];
        }
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);

    }
    dfs(1,0);//第二个参数为父节点，不能返回
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i]);
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
