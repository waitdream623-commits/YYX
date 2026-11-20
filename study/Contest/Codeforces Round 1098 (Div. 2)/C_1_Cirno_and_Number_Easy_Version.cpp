#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while (t--)
  {
    ll x,n;cin>>x>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    sort(a+1,a+1+n);
  
   
    if(x==0)
    {
    cout<<abs(a[1]-x)<<endl;
    continue;
    }
      //将x拆分
    int ma[20];
     int t=x;
    int pos=1;
    while (t)
    {
      ma[pos++]=t%10;
      t/=10;
    }
    pos--;
    //比较
    ll tmin,tmax;
     for(int i=pos;i>0;i--)
     {
      tmin=tmin*10+a[1];
     }
      for(int i=pos;i>0;i--)
      {
      tmax=tmax*10+a[1];
      }
      if(x<=tmin)
      {
        cout<<min(tmin-x,x-tmax/10);
      }
      else if(x>=tmax)
      {
        cout<<min(x-tmax,tmin*10+a[1]-x);
      }

    for(int i=pos;i>0;i--)
    {
     
      ma[i]=min(abs(ma[i]-a[1]),abs(ma[i]-a[2]));
      if(i!=1&&ma[i]==0)continue;
      cout<<ma[i];
    }
   cout<<endl;
  }
  
  return 0;
}
