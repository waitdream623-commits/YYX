#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
vector<int>ed[N];
int f[N];
bool vis[N];
bool st[N];
void dfs(int x)
{
    vis[x]=true;
    for(auto e:ed[x])
    {
        if(!vis[e])
        {
            dfs(e);
            f[x]+=f[e];
        }
    }
    if(f[x]%2==0)st[x]=1;
}
ll cnt;
bool v[N];
int dfs2(int x)
{
    int c=1;
    v[x]=true;
    for(auto e:ed[x])
    {
        if(v[e])continue;
        if(st[e])
        {
            c+=dfs2(e);
        }
    }
    return c;
}
void solve()
{
    int n;cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)f[i]=1;
    while(cin>>a>>b)
    {
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs(1);
    
    ll ret=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(!v[i]&&st[i])
        {
            cnt=dfs2(i);
            if(cnt!=0)
            {
                ret+=(cnt)*(cnt-1);
                flag=1;
            }
        }
    }
    if(flag)
    {
        cout<<ret;
    }
    else
    
    cout<<0;
    
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
