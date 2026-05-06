#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
ll a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,t;cin>>n>>t;
  //尽可能公母交替出现，每次确定后一组后，改组能产生鸡蛋就确定；
  for(int i=1;i<=n;i++)cin>>a[i];
  ll ret=0;
  for(int i=2;i<=n;i++)
  {
    //存在a[i]>t;此时ret+负数
    //ret+=t-(max(a[i],a[i-1]));
      int x=t-(max(a[i],a[i-1]));
      if(x>=0)ret+=x;
  }
  if(ret<0)cout<<0;
    else
  cout<<ret;
  return 0;
}
