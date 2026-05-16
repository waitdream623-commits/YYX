#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll cnt;
ll a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    ll b;cin>>b;
    cnt+=b;
    a[i]=cnt-1;//时间从0开始，这是结束时间
  }
  while(q--)
  {
    ll t;cin>>t;
    int p=lower_bound(a+1,a+1+n,t)-a;
    //p为大于t的位置且小于p+1
    cout<<p<<endl;
  }
  return 0;
}
