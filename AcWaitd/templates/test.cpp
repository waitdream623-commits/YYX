#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<string,string>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
PII v[N];
map<string,int>mp;
map<string,int>mpst;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 string s="QLXPR";
 for(int i=1;i<=26;i++)
 {
    for(int j=0;j<=4;j++)
    {
        cout<<char(s[j]-i);
    }
    cout<<endl;
 }
  return 0;
}
