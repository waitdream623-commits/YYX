#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
string s;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>s;
  ll cnt=0;ll mod=11;
  cnt+=s[0]-'0';
  for(int i=2;i<=4;i++)
  {
    cnt=(cnt+i*(s[i]-'0'))%mod;
  }
  for(int i=6;i<=10;i++)
  {
    cnt=(cnt+(i-1)*(s[i]-'0'))%mod;
  }
  if(cnt==10)
  {
    if(s[12]=='X')
    cout<<"Right";
    else
    {
      s.replace(12,1,"X");
      cout<<s;
    }
  }
  else
  {
    if(cnt==s[12]-'0')
   cout<<"Right";
    else
    {
     for(int i=0;i<s.size()-1;i++)
     cout<<s[i];
     cout<<cnt;
    }
  }
  return 0;
}
