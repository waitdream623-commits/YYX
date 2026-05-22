#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e7 + 10;
int p[N],cnt;
int phi[N];
bool st[N];
// 无限大，此时，a的b次方要大p；
void getphi()
{ 
  phi[1]=1;
  for(int i=2;i<=N;i++)
  {
    if(!st[i])
    {
      phi[i]=i-1;
      p[++cnt]=i;
    }
    for(int j=1;1ll*i*p[j]<=N;j++)
    {
      ll x=i*p[j];
      st[x]=true;
      if(i%p[j]==0)
      {
        phi[x]=p[j]*phi[i];
        break;
      }
      else
      {
        phi[x]=(p[j]-1)*phi[i];
      }
    }
  }
  
}
ll qpow(ll a,ll b,ll p)
{
  ll cnt=a,ret=1;
  while (b)
  {
    if(b&1)ret=(ret*cnt)%p;
    cnt=(cnt*cnt)%p;
    b>>=1;
  }
  return ret;
}
ll dfs(int p)
{
  if(p==1)
  {
    return 0;
  }
  return qpow(2,dfs(phi[p])+phi[p],p);

}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  getphi();
  while (t--)
  {
    int p;cin>>p;
    cout<<dfs(p)<<endl;
  }
  
  return 0;
}
