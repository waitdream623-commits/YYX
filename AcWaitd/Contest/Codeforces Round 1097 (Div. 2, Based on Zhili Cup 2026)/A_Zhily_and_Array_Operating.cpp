#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
while (t--)
{
    int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  for(int i=n;i>1;i--)
  {
    if(a[i]>=0)
    {
      a[i-1]+=a[i];
    }
  }
  int ret=0;
  for(int i=1;i<=n;i++)
  {
    if(a[i]>0)ret++;
  }
  cout<<ret<<endl;
}

  return 0;
}
