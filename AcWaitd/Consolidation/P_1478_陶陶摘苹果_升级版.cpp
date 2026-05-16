#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
PII apple[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,s;
  cin>>n>>s;
  int a,b;
  cin>>a>>b;
  for(int i=1;i<=n;i++)
  {
    cin>>apple[i].second>>apple[i].first;
  }
  sort(apple+1,apple+1+n);
  ll ret=0;
  for(int i=1;i<=n;i++)
  {
    if(apple[i].second>a+b)continue;
    if(s<0)break;
    if(apple[i].first<=s)
    {
      s-=apple[i].first;
    ret++;
    }
  }
  cout<<ret;
  return 0;
}
