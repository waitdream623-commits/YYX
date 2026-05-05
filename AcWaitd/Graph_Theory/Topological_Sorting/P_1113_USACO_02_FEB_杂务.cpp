#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
vector<int>v[N];
int in[N];
int out[N];
int f[N];
int t[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    t[a]=b;//直接存储在该点
    int x;
    while(cin>>x,x)
    {
      v[x].push_back(a);
      out[x]++;
      in[a]++;
    }
  }
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
      if(in[i]==0)
      {
        q.push(i);
        f[i]=t[i];
      }
  }

  while (q.size())  
  {
    int a=q.front();q.pop();
    //删边
    for(auto&e:v[a])
    {
      f[e]=max(f[a]+t[e],f[e]);
      in[e]--;
      if(in[e]==0)
      {
        q.push(e);
      }
    }
  }
  //多个图
  int ret=0;
  for(int i=1;i<=n;i++)
  {
    if(out[i]==0)ret=max(ret,f[i]);
  }
  cout<<ret;
  return 0;
}
