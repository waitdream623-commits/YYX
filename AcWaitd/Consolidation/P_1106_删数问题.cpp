#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//尽量留前导0；留小数在前面，优先处理高位大数
string s;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>s;
  int k;cin>>k;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]<s[i+1])
    {
      s.erase(i+1);
      k--;
    }
    else
    {
      s.erase(i);
      k--;
    }
  }
  return 0;
}
