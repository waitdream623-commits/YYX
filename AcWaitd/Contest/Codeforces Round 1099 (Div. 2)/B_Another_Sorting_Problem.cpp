#include <iostream>
#include <cmath>
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
    int n;cin>>n;
    ll max=0,index=0;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      if(i==n)
      {
        continue;
      }
      if(a[i]>=max)//找到最大
      {
        max=a[i];
        index=i;
      }
    }
    //判断最大后面是否有序
    bool flag=0;
    for(int i=index+1;i<n;i++)
    {
      if(a[i+1]<a[i])//不是有序
      {
        flag=1;
        break;
      }
    }
    if(flag)
    {
      cout<<"NO"<<endl;
      continue;
    }
    //求最小增量
    int k=a[index]-a[index+1];
    //找前面，依据最小增量是否能满足
    //前面最大增量的最小
    int mn=a[index]-a[index-1];
    for(int i=2;i<index;i++)
    {
      
      if(a[i]<a[i-1])
      {
  
        if(a[i]+k>=a[i-1]){
          if(a[i+1]>a[i]&&a[i+2]<a[i+1])mn=min(mn,a[i+1]-a[i]);//找到转折点
          if(mn<k){
            flag=1;
            break;
          }
        
          continue;
        }
       
        //此时不满足，k需要增加
        if(a[i-1]-a[i]>mn)
        {
          flag=1;
          break;
        }
        else
        {
          k=a[i-1]-a[i];
          mn=min(mn,a[i+1]-a[i]);
        }

      }
    }
    if(flag)
    {
      cout<<"NO"<<endl;
    }
    else
    cout<<"YES"<<endl;
  }
  
  return 0;
}
