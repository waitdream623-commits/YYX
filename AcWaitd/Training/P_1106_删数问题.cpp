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
  string tmp;
  while(k--)
  {
    int p=0;
    for(int i=0;s[i]<=s[i+1];i++)//每次删除找到前面比后面大的数
    {
      p++;
    }
    s.erase(p,1);
  }
   
  //处理前导零
  while(s[0]=='0'&&s.size()>1)s.erase(0,1);
  cout<<s;
  return 0;
}
