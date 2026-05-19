#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int p[N];
int cnt;
bool st[N];
int n;
void getprime()
{
  for(int i=1;i<=n;i++)
  {
      if(!st[i])p[++cnt]=i;
      for(int j=1;1ll*i*p[j];j++)
      {
        st[i*p[j]]=true;
        if(i%p[j]==0)break;
      }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  ll ret=0;
  for(int i=1;i<=n;i++)
  {
    ret+=n/i;
  }
  cout<<ret;
  return 0;
}
