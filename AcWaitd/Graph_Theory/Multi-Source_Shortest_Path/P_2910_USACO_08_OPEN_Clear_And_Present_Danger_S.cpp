#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int f[110][110];
int p[N];
int n,m;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>p[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>f[i][j];//k==0;
    }
  }
  //floyd
  ll ret=0;
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
  for(int i=2;i<=m;i++)
  {
    int a=p[i-1],b=p[i];
    ret+=f[a][b];
  }
  cout<<ret;
  return 0;
}
