#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//邻接矩阵存储
int f[110][110];
int n,m;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //初始化
  memset(f, 0x3f, sizeof f);
  cin>>n>>m;
  for(int i = 1;i <= m; i++)
  {
    int a,b,w;
    cin>> a >> b >> w;
    //无向
    //处理重边
    f[a][b]=f[b][a]=min(f[a][b],w);
    
  }
  for(int i=1;i<=n;i++)//初始化
  f[i][i]=0;

  //状态转移方程，f[k][i][j],表示，可用1~k的节点，i到j最短距离
  //f[k][i][j]=min(f[k-1][i][j],f[k-1][i][k]+f[k-1][k][j])
  //可压缩
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
      }
    }
  }

  for(int i=1;i <= n;i++)
  {
    for(int j = 1;j <= n;j++)
    cout<<f[i][j]<< " ";

    cout<<endl;
  }
  return 0;
}
