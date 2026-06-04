#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
//爆搜，插头dp
//至少有一个格子在边界上
//搜索边界线划分，不从边角顶点进入
//访问到边即ans++;
//从上面，下面，左面，右面走，会重复
//出口同为行或者列
//答案除以2
int n,m;
vector<PII>dir={{0,1},{0,-1},{1,0},{-1,0}};
ll ans;
bool vis[10][10];
const int N = 1e6 + 10;
void dfs(int x,int y)
{
    if(!x||!y||x==n|y==m)
    {
        ans++;
        return;
    }
    vis[x][y]=1;

    for(auto [dx,dy]:dir)
    {
        int nx=x+dx,ny=y+dy;
        if(vis[nx][ny])continue;
        dfs(nx,ny);
    }
    vis[x][y]=0;//外界回溯，否则可能第一次进入不能回溯
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        vis[i][0]=1;
        dfs(i,1);//只能往下走，第一步
        vis[i][0]=0;
    }
      for(int i=1;i<m;i++)
    {
        vis[0][i]=1;
        dfs(1,i);
        vis[0][i]=0;
    }
    // 下面边界（从 y=m-1 往下走到右，实际上是从边界往内走一步）
for (int i = 1; i < n; i++) {
    vis[i][m] = 1;
    dfs(i, m - 1);
    vis[i][m] = 0;
}

// 右面边界
for (int i = 1; i < m; i++) {
    vis[n][i] = 1;
    dfs(n - 1, i);
    vis[n][i] = 0;
}
    cout<<ans/2;
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
