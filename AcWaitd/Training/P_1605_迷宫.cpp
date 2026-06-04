#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int maze[10][10];
int sx,sy,fx,fy;
vector<PII>dir={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,t;
bool vis[10][10];
void dfs(int x,int y,int&ret)
{
    vis[x][y]=1;
    if(x==fx&&y==fy)
    {
        ret++;
        return;        
    }
    for(auto [dx,dy]:dir)
    {
        int nx=x+dx,ny=y+dy;
        if(nx<1||ny<1||nx>n||ny>m)continue;
        if(maze[nx][ny]||vis[nx][ny])continue;
        dfs(nx,ny,ret);
        //回溯
        vis[nx][ny]=0;
    }

}
void solve()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    while(t--)
    {
        int a,b;cin>>a>>b;
        maze[a][b]=1;

    }
    int ans=0;
    dfs(sx,sy,ans);
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
