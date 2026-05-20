#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e7 + 10;
bool st1[N];//筛小素数
bool st2[N];
int p[N],cnt;
ll l,r;
void getprime()
{
  ll n=sqrt(r);
  for(int i=2;i<=n;i++)//只需要枚举到r
  {
    if(!st1[i])p[++cnt]=i;
    for(int j=1;1ll*i*p[j]<=n;j++)
    {
        st1[i*p[j]]=true;
        if(i%p[j]==0)break;
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //如果从1开始；无法筛掉，因为是线性筛，最小肯定是2的倍数
  cin>>l>>r;
  l=max(2ll,l);//类型统一
  getprime();
  for(int i=1;i<=cnt;i++)
  {
    
    for(ll j=(l+p[i]-1)/p[i]*p[i];j<=r;j+=p[i])//此处开ll，可能超int
    //因此里面l+p[i]也可能超int
    {
        if(j==p[i])continue;//一倍；
        st2[j-l+1]=true;
    }
  }
  ll ret=0;
  for(int i=1;i<=r-l+1;i++)
  {
    if(!st2[i])ret++;
  }
  cout<<ret;
  return 0;
}
//错误代码

// #include <iostream>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// int p[N];
// bool st[N];//需要转换
// int cnt;
// int n;
// void get_prime()
// {
//   for(int i=1;i<=n/i;i++)
//   {
//     if(!st[i])p[++cnt]=i;
//     for(int j=1;1ll*i*p[j]<=n;j++)
//     {
//       st[i*p[j]]=true;
//       if(i%p[j]==0)break;
//     }
//   }
// }
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int l,r;cin>>l>>r;
// get_prime();
// cout<<cnt;
//   return 0;
// }
