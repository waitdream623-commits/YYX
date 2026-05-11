#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x1f1f1f1f;
const int N = 1e6 + 10;
int n,m;
int edge[110][110],f[110][110];
int ret=INF;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  memset(f, INF, sizeof f);
  memset(edge, INF, sizeof edge);

  //初始化
  
  for(int i=1;i<=n;i++)
  {
    f[i][i]=edge[i][i]=0;
  }
  for(int i=1;i<=m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    edge[a][b]=edge[b][a]=f[a][b]=f[b][a]=min(f[a][b],w);
  }
  for(int k=1;k<=n;k++)
  {
    
    for(int i=1;i<k;i++)
    {
      for(int j=i+1;j<k;j++)
      {
        ret=min(f[i][j]+edge[i][k]+edge[k][j],ret);//保持类型一致
        
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        
      }
    }
  }
  if(ret==INF)cout<<"No solution.";
  else
  cout<<ret;

  return 0;
}
