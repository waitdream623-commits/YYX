#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
ll a[31],px[32];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
    for(int i=0;i<=32;i++)
  {
    a[i]=pow(2,i);
  }

  while(t--)
  {
    ll n,x;cin>>n>>x;
    for(int i=0;i<=31;i++)
    {
        px[i]=pow(x,i);
    }
    if(x>n){
      //判断n是否为2的次幂
      if((n&(n-1))==0)cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
    }
    else
    {
      if(x==n)cout<<"Yes"<<endl;
      else if(x==1)cout<<"No"<<endl;
      else
      {
        int flag=1;
        if(x==2)
        {
          if(n%2)cout<<"No"<<endl;
          else
          cout<<"Yes"<<endl;
        }
        
        //去掉二进制
        else
        {
          
          for(int i=31;i>=0;i--)
          {
            if((n&(1<<i)))
            {
              //去掉该位，剩下需要匹配
              int tmp=n^(1<<i);
              int j=31;
              while (tmp<px[j]-1)j--;
              tmp-=px[j]-1;
              flag=0;
            }
            }
          }
          //没有匹配
          if(flag)
          cout<<"No"<<endl;
        }
      }
  }

  return 0;
}
