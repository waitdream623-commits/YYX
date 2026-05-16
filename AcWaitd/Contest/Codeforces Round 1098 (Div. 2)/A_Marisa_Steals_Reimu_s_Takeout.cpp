#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
int t;cin>>t;
while (t--)
{
    int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x==0)
    {
      a[0]++;
    }
    if(x==1)
    {
      a[1]++;
    }
    if(x==2)
    {
      a[2]++;
    }
  }
  ll ret=a[0];
  int tmp=min(a[1],a[2]);
  ret+=tmp;
  a[1]-=tmp;
  a[2]-=tmp;
  if(a[1])
  ret+=a[1]/3;
  else
  {
    ret+=a[2]/3;
  }
  cout<<ret<<endl;
 // 清空
 a[0]=a[1]=a[2]=0;
}

  return 0;
}
