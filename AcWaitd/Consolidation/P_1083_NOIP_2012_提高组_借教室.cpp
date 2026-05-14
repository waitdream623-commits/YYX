#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int t[N];
int f[N];//差分数组
struct node
{
  int d,l,r;
}a[N];
int n,m;
bool cheack(int r)
{
  //初始化差分
  for(int i=1;i<=n;i++)
  {
    f[i]=t[i]-t[i-1];
  }
  //操作
  for(int i=1;i<=r;i++)
  {
    f[a[i].l]-=a[i].d;
    f[a[i].r+1]+=a[i].d;

  }
  //统计是否有不满足

  for(int i=1;i<=n;i++)
  {
    f[i]+=f[i-1];
    if(f[i]<0)return false;
  }
  return true;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>t[i];
    f[i]=t[i]-t[i-1];
  
  }
  for(int i=1;i<=m;i++)
  {
   cin>>a[i].d>>a[i].l>>a[i].r;
  }
//二分
int l=1,r=m;
while(l<r)
{
  int mid=(l+r)/2;
  if(cheack(mid))l=mid+1;
  else
  r=mid;
}
if(cheack(m))cout<<0;
else
cout<<-1<<endl<<l;
  return 0;
}
