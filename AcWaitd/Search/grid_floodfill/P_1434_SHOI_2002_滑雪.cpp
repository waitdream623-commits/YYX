#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
int a[200][200];
int f[200][200];//记忆该点最远距离
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
//bool st[200][200];//不能往回走
int dfs(int x,int y)    
{
    int ret=1;//至少为1
    if(f[x][y])return f[x][y];

    for(int k=0;k<4;k++)
    {
        int nx=x+dx[k],ny=y+dy[k];
        if(nx>n||nx<1||ny>m||ny<1||a[nx][ny]>=a[x][y])
        {
            continue;
        }
        ret=max(dfs(nx,ny)+1,ret);//记得加1
        //st[nx][ny]=0;//回溯??不用回溯，天然单向
    }
    return f[x][y]=ret;//记录并返回
}
void slove()
{
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
             ret=max(dfs(i,j),ret);

        }

    }
    cout<<ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        slove();
    }
    return 0;
}
