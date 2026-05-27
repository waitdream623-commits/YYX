//时间复杂度O(N根号N)
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int c[N];
int pos;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int t=i;
    for(int j=2;j<=i/j;j++)
    {
      
      int cnt=0;
      while(t%j==0)
      {
          t/=j;
          cnt++;
      }
      c[j]+=cnt;
    }
    if(t>1)c[t]++;
  }
  for(int i=1;i<=n;i++)
  {
    if(c[i])
    {
      cout<<i<<' '<<c[i]<<endl;
    }
  }
  return 0;
}
