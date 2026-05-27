#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
PII pos[N];
vector<PII>edge[N];
int s,t;
//找s—>t最短距离
double dist[N];
bool st[N];//标记是否已经更新过
void dijk()
{
  //memset(dist, INF, sizeof dist);
  for(int i=1; i<=n; i++) dist[i] = 1e18;
  dist[s]=0;
  priority_queue<PII,
  vector<PII>,greater<PII>>q;
  q.push({dist[s],s});
  while(q.size())
  {
    //拿出最近
    int a=q.top().second;q.pop();
    st[a]=1;
    //如果处理到t点可以退出
    if(a==t)
    {
      //格式化输出
      cout<<fixed<<setprecision(2)<<dist[t];
      //printf("%.2f",dist[t]);
      return;
    }
    for(auto&e:edge[a])
    {
      int b=e.second;double w=e.first;
      if(st[b])continue;//已经处理过了
      if(dist[a]+w<dist[b])
      {
        dist[b]=dist[a]+w;
        q.push({dist[b],b});
        
      }
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>pos[i].first>>pos[i].second;
  }
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    double x=sqrt(pow(pos[a].first-
      pos[b].first,2)+pow(pos[a].second-pos[b].second,2));
    edge[a].push_back({x,b});//先距离，后节点
    //双向图
    edge[b].push_back({x, a});
  }
  cin>>s>>t;
  dijk();
  return 0;
}
