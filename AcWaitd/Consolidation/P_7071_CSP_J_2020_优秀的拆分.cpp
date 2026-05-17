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
  int n;
  cin>>n;
  //二进制判断最后一位
  if(n&1==1)
  {
    cout<<-1;
    return 0;
  }
  int a[32];
    int tmp=2;
    int pos=0;
  //从大到小输出
  
    for(int i=1;i<=32;i++)
    {
      if(n&(1<<i))a[++pos]=tmp;
      tmp*=2;
    }
  for(int i=pos;i>0;i--)
  {
    cout<<a[i]<<' ';
  }
  return 0;
}
