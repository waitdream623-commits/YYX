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
  ll n;
 while (cin>>n)
  {
    ll a=qpow(6,MOD-2);
    n%=MOD;
    ll ret=1;
    ret=(ret*n)%MOD;
    ret=(ret*(n+1))%MOD;
    ret=(ret*(2*n+1))%MOD;
    //ret/6;求逆元
    //if(ret%6==0)
    //cout<<ret/6<<endl;
    //else{
    ret=(ret*a)%MOD;
    cout<<ret<<endl;
   // }
  }
  
  return 0;
}
