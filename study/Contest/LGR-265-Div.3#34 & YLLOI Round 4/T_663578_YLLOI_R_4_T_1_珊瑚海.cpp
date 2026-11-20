#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,d;cin>>n>>m>>d;
  if(n*(d+1)>m)cout<<-1;
  else
  {
    int r=m-n*(d+1);
    if(r<=n)cout<<r;
    else
    {
      cout<<n+(r-n)/(d+1);
    }
  }
  return 0;
}
