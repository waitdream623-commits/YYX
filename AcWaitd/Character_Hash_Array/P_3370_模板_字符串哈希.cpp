//可以采用单独求哈希
//也可以用set去重
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
ull a[N];
int p=1331;
string s;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    for(auto e:s)
    {
      a[i]=a[i]*p+e;
    }
  }
  sort(a,a+n);
  //int ret=unique(a,a+n)-a;
  int ret=1;
  for(int i=1;i<n;i++)
  {
    if(a[i]!=a[i-1])ret++;
  }
  cout<<ret;
  return 0;
}
