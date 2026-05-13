#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int p[N];
bool st[N];//需要转换
int cnt;
int n;
void get_prime()
{
  for(int i=1;i<=n/i;i++)
  {
    if(!st[i])p[++cnt]=i;
    for(int j=1;1ll*i*p[j]<=n;j++)
    {
      st[i*p[j]]=true;
      if(i%p[j]==0)break;
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int l,r;cin>>l>>r;
get_prime();
cout<<cnt;
  return 0;
}
