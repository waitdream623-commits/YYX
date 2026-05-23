#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e8 + 10;
ll inv[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,p;
  cin>>n>>p;
  inv[1]=1;
  cout<<1<<endl;
  for(int i=2;i<=n;i++)
  {
      inv[i]=p-(p/i*inv[p%i])%p;
      cout<<inv[i]<<'\n';
  }
  return 0;
}
