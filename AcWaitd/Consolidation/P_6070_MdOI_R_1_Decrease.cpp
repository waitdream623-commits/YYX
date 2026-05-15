#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 5e3 + 10;
int f[N][N];
void insert(int x1,int y1,int x2,int y2,int k)
{
  f[x1][y1]+=k;
  f[x1][y2+1]-=k;
  f[x2+1][y1]-=k;
  f[x2+1][y2+1]+=k;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++)//读取每一份不为零，不是二维读取
  {
   
    int x,y,z;
    cin>>x>>y>>z;
    insert(x,y,x,y,z);
  }
  //枚举矩形k*k左上角,将其变为0；
  ll ret=0;
  for(int i=1;i<=n-k+1;i++)
  {
    for(int j=1;j<=n-k+1;j++)
    {
      if(!f[i][j])continue;
      ret+=abs(f[i][j]);

      int x2=i+k-1,y2=j+k-1;
     insert(i,j,x2,y2,-f[i][j]);

    }
  }
  //遍历是否全部为0
  int flag=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
  {
   if(f[i][j])
   {
    flag=1;
   }
  }
  }
  if(flag)
  cout<<-1;
  else
  cout<<ret;
  return 0;
}
