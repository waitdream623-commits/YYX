#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f,MOD=1000000007;
const int N = 1e6 + 10;
ll qpow(ll a,ll b)
{
  ll cnt=a,ret=1;
  while (b) 
  {
    if(b&1)ret=(ret*cnt)%MOD;
    cnt=(cnt*cnt)%MOD;
    b>>=1;

  }
  return ret;
  
  
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  ll n;
  //(1+k)的等比数列
 while (t--)
  {
    ll n,k;cin>>n>>k;
    ll ret=0;
    ret=(1+k);
    ll t=qpow(1+k,n);
    ret=(ret*(t-1))%MOD;
    ll a=qpow(k,MOD-2);
    ret=(ret*a)%MOD;
    cout<<ret<<endl;
   
  }
  
  return 0;
}
