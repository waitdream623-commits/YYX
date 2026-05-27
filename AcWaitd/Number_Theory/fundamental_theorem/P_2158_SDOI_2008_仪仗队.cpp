#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int cnt,p[N];
bool st[N];
int phi[N];
int n;
void getphi()
{
  phi[1]=1;
  for(int i=2;i<=n;i++)
  {
    if(!st[i])
    {
      p[++cnt]=i;
      phi[i]=i-1;

    }
    for(int j=1;1ll*i*p[j]<=n;j++)
    {
      int x=i*p[j];
      st[x]=true;//和数
      if(i%p[j]==0)
      {
        phi[x]=p[j]*phi[i];
        break;
      }
      else
      {
        //phi[x]=(p[j]-1)*phi[i];
        phi[x]=phi[p[j]]*phi[i];

      }
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  if(n==1)cout<<0;
  else
  {
    getphi();
    ll ret=0;
    for(int i=1;i<=n-1;i++)
    {
      ret+=phi[i];
    }
    cout<<ret*2+1;
  }
  return 0;
}
