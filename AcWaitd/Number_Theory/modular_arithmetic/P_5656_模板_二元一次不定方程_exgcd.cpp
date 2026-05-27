#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll exgcd(ll a,ll b,ll&x,ll&y)
{
  if(b==0)
  {
    x=1,y=0;
    return a;
  }
  
  ll x1,y1;
  //先求解x1，y1
  ll d=exgcd(b,a%b,x1,y1);
  x=y1,y=x1-a/b*y1;
  return d;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while (t--)
  {
    ll a,b,c;
    ll x,y;
    cin>>a>>b>>c;
    ll d = exgcd(a,b,x,y);//保留最大公约数，求通解
    if(c%d!=0){
      cout<<-1<<endl;
      continue;
    }
    else
    {
      x=x*c/d,y=y*c/d;//特解
      ll dx=b/d,dy=a/d;
    //判断是否存在正整数解
    //当x>0;x>=1
    ll k1 = ceil((double)(-x + 1) / dx); // ✅ 强制转为 double
    ll k2 = floor((double)(y - 1) / dy); // ✅ 强制转为 double
    if(k1>k2)//无正数解
    {
      cout<<x+k1*dx<<' '<<y-k2*dy<<endl;
    }
    else
    {
      cout<<k2-k1+1<<' '<<x+k1*dx<<' '<<y-k2*dy
      <<" "<<x+k2*dx<<' '<<y-k1*dy<<endl;
    }
    }
  }

  return 0;
}
