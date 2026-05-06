#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll ret;
int a[N];
bool st[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    int mx=0;
    int c=0;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      mx=max(a[i],mx);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
      st[a[i]]=1;//加入前缀
      c=max(a[i],c);//标记最大前缀
      for(int j=0;j<=N;j++)//找最小未出现
      {
        if(!st[j])
        {
          ret+=j+c;
          break;
        }

      }
    }
    memset(st, 0, sizeof st);
    cout<<ret<<endl;
    ret=0;
    c=0;
  }
  
  return 0;
}
