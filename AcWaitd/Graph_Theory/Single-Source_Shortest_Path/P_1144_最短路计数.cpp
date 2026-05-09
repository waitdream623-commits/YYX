#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 2e6 + 10,MOD = 100003;
int n,m;
vector<int>edge[N];
int dist[N];
int f[N];
bool st[N];//标记是否完成
void dijsktra()
{
    for(int i=1;i<=n;i++)
    {
      dist[i]=INF;
    }
    dist[1]=0;
    f[1]=1;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    while(q.size())
    {
      int a=q.top().second;q.pop();
      if(st[a])continue;
      st[a]=1;
      for(auto&e:edge[a])
      {
        if(dist[a]+1<dist[e])
        {
          dist[e]=dist[a]+1;
          f[e]=f[a];
          q.push({dist[e],e});
        }
        else if (dist[a]+1==dist[e])//此处为else if 如果为if,上面不能改f
        {
          f[e]=(f[e]+f[a])%MOD;
        }
        
      }
    }

}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;
    cin>>a>>b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dijsktra();
  for(int i=1;i<=n;i++)
  {
    cout<<f[i]<<endl;
  }
  return 0;
}
