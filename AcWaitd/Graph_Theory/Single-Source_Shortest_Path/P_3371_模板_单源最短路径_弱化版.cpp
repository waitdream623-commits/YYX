#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=2147483647;
const int N = 1e6 + 10;
int dist[N];
vector<PII>v[N];
bool st[N];
int n,m,s;
void dijk(int s)
{
 for(int i=0;i<=n;i++)dist[i]=INF;//从零开始，后续找最近是从0下标开始比较
  dist[s]=0;//起始节点
  for(int i=1;i<n;i++)
  {
    int u=0;
    for(int j=1;j<=n;j++)
    {
      if(!st[j]&&dist[j]<dist[u])u=j;//找到最近，第一次为起点
    }
    st[u]=1;

    for(auto&e:v[u])
    {
      int x=e.first,y=e.second;
      if(dist[u]+y<dist[x])
      dist[x]=dist[u]+y;//松弛操作
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
