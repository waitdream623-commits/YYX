#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e8 + 10;
int p[N];
bool st[N];
int cnt;//记录质数个数
int n;
void get_prime1()
{
  if(n<=1)return;
  for(int i=2;i<=n;i++)
  {
   if(!st[i])
   {
     p[++cnt]=i;
    for(int j=i*i;j<=n;j+=i)
    {
      st[j]=true;
    }
   }
  }
}
void get_prime2()
{
  

}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  get_prime();
  int q;cin>>q;
  while(q--)
  {
    int a;cin>>a;
    cout<<p[a]<<'\n';
  }
  return 0;
}
