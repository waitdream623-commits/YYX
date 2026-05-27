//卡复杂度
//优化，非负可以用优先队列优化找最小距离点
//dijkstra加小根堆优化
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int dist[N];
vector<PII>v[N];
bool st[N];
int n,m,s;
priority_queue<PII,vector<PII>,greater<PII>>q;//小根堆
void dijk(int s)
{
 for(int i=0;i<=n;i++)dist[i]=INF;//从零开始，后续找最近是从0下标开始比较
  dist[s]=0;//起始节点
  q.push({0,s});
  while (q.size())
  {
    int a=q.top().first,b=q.top().second;q.pop();
    if(st[b])continue;//这里优化，可能加入重复节点
    st[b]=1;
    for(auto&e:v[b])
    {
      
      int x=e.first,y=e.second;
      
      if(dist[b]+y<dist[x])
      {
        dist[x]=dist[b]+y;//松弛操作
        q.push({dist[x],x});
      }
    }
  }
  
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m>>s;
  for(int i=1;i<=m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    v[a].push_back({b,w});
  }
  dijk(s);
  for(int i=1;i<=n;i++)
  {
    cout<<dist[i]<<" ";
  }
  return 0;
}
