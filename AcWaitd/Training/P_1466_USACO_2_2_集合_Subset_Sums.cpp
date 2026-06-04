#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//首先求和为偶数
//转化为0/1背包，每个数选进去
//结果为凑出N/2的方案数再除以2
ll f[40][N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  ll s=(1+n)*n/2;
  if(s%2==1)
  {
    cout<<0;
    return 0;
  }
  f[0][0]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=s/2;j++)
    {
      f[i][j]=f[i-1][j];
      if(j>=i)
      {
        f[i][j]+=f[i-1][j-i];
      }
    }
  }
  cout<<f[n][s/2]/2;
  return 0;
}
