#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int c[N];
int p[N];
int cnt;
int n;
bool st[N];
void getprime()
{
  for(int i=2;i<=n;i++)
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
  cin>>n;
  getprime();
  //枚举每个素数的倍数
  for(int i=1;i<=cnt;i++)
  {
    int s=0;
   for(ll j=p[i];j<=n;j*=p[i])//不开long long见祖宗
   {
    s+=n/j;//10/2==5；去掉第一个2，10/4，去掉第二个2；4=2*2需要筛两遍
   }
   cout<<p[i]<<' '<<s<<endl;
  }
  return 0;
}
