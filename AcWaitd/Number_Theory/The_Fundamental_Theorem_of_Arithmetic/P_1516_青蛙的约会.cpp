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
  ll d=exgcd(b,a%b,x1,y1);
  x=y1,y=x1-a/b*y1;
  return d;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x,y,n,m,l;
  cin>>x>>y>>m>>n>>l;
  ll a=m-n;ll b=l;
  ll c=y-x;
  if(a<0)
  {
    a=-a;
    c=-c;
  }
ll t, t1;
ll d = exgcd(a, b, t, t1); // 判断是否有解

if (c % d == 0)
{
  ll dx = b / d;
  // 关键修复：先除以 d，并且步步取模防止溢出
  t = (t % dx) * ((c / d) % dx) % dx; 
  
  // 转化为最小正整数解
  cout << (t % dx + dx) % dx;
}
else
{
  cout << "Impossible";
}
  return 0;
}
