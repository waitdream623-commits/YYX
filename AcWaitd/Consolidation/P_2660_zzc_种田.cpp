#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x,y;
  cin>>x>>y;
  ll ret=0;
  while (x>0&&y>0)
  {
    if(x>y)swap(x,y);
    // 能获得x为边正方形个数
    ll cnt=y/x;//记得用ll;
    ret+=x*4*cnt;
    y%=x;
  }
  cout<<ret;
  return 0;
}
