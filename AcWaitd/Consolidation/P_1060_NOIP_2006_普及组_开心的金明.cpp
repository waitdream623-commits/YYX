#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e5 + 10;
int n,m;
int p[N],s[N];
ll f[N];//动态规划，01背包
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>m>>n;
for(int i=1;i<=n;i++)
{
  int a,b;cin>>a>>b;
  p[i]=a;s[i]=a*b;
}
for(int i=1;i<=n;i++)
{
  for(int j=m;j>=p[i];j--)
  {
    f[j]=max(f[j],f[j-p[i]]+s[i]);
  }
}
cout<<f[m];
  return 0;
}
