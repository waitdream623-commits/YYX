#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
struct cow
{
  int p,c;
}a[N];
bool cmp(cow a,cow b)
{
  return a.p<b.p;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;cin>>m>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i].p>>a[i].c;
  }
  ll ret=0;
  sort(a+1,a+1+n,cmp);
  for(int i=1;i<=n;i++)
  {
    if(m>=a[i].c)
    {
      m-=a[i].c;
      ret+=a[i].c*a[i].p;
    }
    else
    {
       ret+=a[i].p*m;
       break;
    }
  }
  cout<<ret;
  return 0;
}
