#include <iostream>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(n%2==0)
{
    for(int i=0;i<n;i++)
  {
    cout<<s[i];
     if(i%2==1&&i<n-1)cout<<"-";
  }
}
   else
   {
    cout<<s[0]<<s[1]<<s[2];
    if(n>3)cout<<"-";//如果长度仅为3
    for(int i=3;i<n;i++)
    {
        cout<<s[i];
     if(i%2==0&&i<n-1)cout<<"-";
    }
   }
  return 0;
}
