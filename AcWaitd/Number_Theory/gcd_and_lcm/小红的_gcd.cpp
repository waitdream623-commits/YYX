#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll gcd(int a,int b)
{
  if(!b)return a;
  return gcd(b,a%b);
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //秦九韶算法处理大数
  string s;
  ll a;
  cin>>s>>a;
//s>a;先算s%a
ll b=0;
for(int i=0;i<s.size();i++)
{
  b=(b*10+s[i]-'0')%a;
}
cout<<gcd(a,b);
  return 0;
}
