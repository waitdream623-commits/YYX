#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll gcd(int a,int b)
{
  return b?gcd(b,a%b):a;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  int a,b;
  cin>>a;
  a=abs(a);
  for(int i=2;i<=n;i++)
  {
    cin>>b;
    b=abs(b);
    a=gcd(a,b);//覆盖,b为更新输入
    
  }
  cout<<a;
  return 0;
}
