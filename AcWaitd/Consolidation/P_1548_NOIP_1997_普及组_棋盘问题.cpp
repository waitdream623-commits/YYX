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
  int n,m;cin>>n>>m;
  //正方形
  ll ret1=0;
  for(int i=0;i<min(n,m);i++)
  {
    if(n-i>0&&m-i>0)
    ret1+=(n-i)*(m-i);

  }
cout<<ret1<<' ';
ll ret2=0;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    ret2+=(n-i+1)*(m-j+1);
  }

}
cout<<ret2-ret1;

  return 0;
}
