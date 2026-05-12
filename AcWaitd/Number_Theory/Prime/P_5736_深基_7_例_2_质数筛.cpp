#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
void is_prime(int a)
{
  if(a<=1)return;

  for(int i=2;i<=a/i;i++)//必须从2开始
  {
    if(a%i==0)return;
  }
  cout<<a<<' ';
  return;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a;cin>>a;
    is_prime(a);
  }

  return 0;
}
