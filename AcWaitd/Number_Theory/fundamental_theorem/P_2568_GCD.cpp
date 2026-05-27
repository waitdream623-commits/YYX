#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e7 + 10;
int n;
int cnt,p[N];
ll f[N];//前缀和（欧拉函数）
int phi[N];
bool st[N];
void getphi()
{
  phi[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(!st[i])
    {
        phi[i]=i-1;
        p[++cnt]=i;
    }
    for(int j=1;1ll*i*p[j]<=n;j++)
    {
      int x=i*p[j];
      st[x]=true;
      if(i%p[j]==0)
      {
        phi[x]=p[j]*phi[i];
        break;

      }
      else
      {
        phi[x]=phi[p[j]]*phi[i];
      }
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  getphi();
  for(int i=1;i<=n;i++)f[i]=phi[i]+f[i-1];
  ll ret=0;
  for(int i=1;i<=cnt;i++)
  {
    ret+=f[n/p[i]]*2-1;
  }
  cout<<ret;
  return 0;
}
