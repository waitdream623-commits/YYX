#include <iostream>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
 ll a,m;
  string b;
ll getphi(int x)
{
  ll ret=x;
  for(int i=2;i<=x;i++)
  {
    if(x%i==0)
    {
      ret=ret/i*(i-1);
      while (x%i==0)
      {
        x/=i;
      }
      
    }
  }
  if(x>1)ret=ret/x*(x-1);
  return ret;
}
ll qpow(ll a,ll b)
{
  ll ret=1;
  ll cnt=a;
  while (b)
  {
    if(b&1)ret=(ret*cnt)%m;
    cnt=(cnt*cnt)%m;
    b>>=1;
  }
  return ret;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin>>a>>m>>b;
  //处理b；
  //先求欧拉函数,仅求一个数
  ll phi=getphi(m);
  ll bx=0;
  int flag=0;
  for(int i=0;i<b.size();i++)
  {
    
    // if(bx<phi)
    // {
    //   bx=bx*10+b[i]-'0';
    // }
    // else{
    //   flag=1;//第二种情况
    //   bx=bx%phi;
    // }
    
      bx=bx*10+b[i]-'0';
    if(bx>=phi)
      {flag=1;//第二种情况
      bx=bx%phi;}
  }
  if(flag)bx+=phi;
  cout<<qpow(a,bx);
  return 0;
}
