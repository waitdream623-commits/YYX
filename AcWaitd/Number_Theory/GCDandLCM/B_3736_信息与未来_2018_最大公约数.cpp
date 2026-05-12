#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int gcd(int a,int b)
{
  if(!b)return a;
  else return gcd(b,a%b);
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,b,c;
  cin>>a>>b>>c;
  cout<<gcd(a,gcd(b,c));
  return 0;
}
