#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  //判断有多少组
  int i=1;
  while (i*(i+1)/2<=n)i++;
  i--;//找到完整组数
  ll ret=0;
  for(int j=1;j<=i;j++)
  {
    ret+=pow(j,2);
  }
  //加上剩下的
  ret+=(n-i*(i+1)/2)*(i+1);
  cout<<ret;
  
  return 0;
}
