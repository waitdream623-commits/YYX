#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
bool st[N];
//用存储，直接判断st[i],i是否为素数
int p[N],cnt;
void getprime()
{
  for(int i=2;i<=N;i++)//从2开始
  {
    if(!st[i])
    {
      p[++cnt]=i;
      for(ll j=1ll*i*i;j<=N;j+=i)
      {
        st[j]=true;
      }
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  getprime();
  int a;
 while(cin>>a,a)
  {  
    for(int j=1;j<=cnt;j++)
    {
      if(!st[a-p[j]])
      {
        cout<<a<<' '<<"= "<<p[j]<<" + "<<a-p[j]<<endl;
        break;
      }
    }
  }

  return 0;
}
