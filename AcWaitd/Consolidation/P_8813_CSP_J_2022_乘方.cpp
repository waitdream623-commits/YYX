#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//快速幂
void quickpow(int a,int b)
{
  ll cnt=a;
  ll ret=1;
    while (b)
    {
      if(b&1)ret=ret*cnt;
      //不仅 ret 要防爆，底数 cnt 也要防爆！
      if(cnt>1e9)
      {
        cout<<-1;
        return;
      }
      cnt=cnt*cnt;
      b>>=1;//去掉一位
      if(ret>1e9)
      {
        cout<<-1;
        return;
      }
    }
    cout<<ret;
    return;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b;cin>>a>>b;
  quickpow(a,b);
  return 0;
}
