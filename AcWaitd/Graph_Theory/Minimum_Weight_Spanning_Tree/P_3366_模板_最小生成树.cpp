#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
int edge[5010][5010];
int n,m;
bool st[N];//标记是否入树
int dist[N];//距离生成树距离
int prim()
{
  memset(dist, 0x3f3f3f3f, sizeof dist);
  dist[1]=0;//初始点
  int ret=0;
  for(int i=1;i<=n;i++)//加入n个节点
  {
    //找到最近距离的节点
    int t=0;
    for(int j=1;j<=n;j++)//遍历所有
    {
      if(!st[j]&&dist[j]<dist[t])
      t=j;
    }
    //将其加入生成树
    if(dist[t]==0x3f3f3f3f)return 0x3f3f3f3f;
    st[t]=true;
    ret+=dist[t];
    //将与t节点相连且距离更近加入
    for(int j=1;j<=n;j++)
    {
        dist[j]=min(edge[t][j],dist[j]);
    }
  }
    return ret;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  memset(edge, 0x3f3f3f3f, sizeof edge);
  for(int i=1;i<=m;i++)
  {
    int a,b,w;cin>>a>>b>>w;
    //可能存在重边情况
    edge[a][b]=edge[b][a]=min(edge[a][b],w);
    
  }
  int ret=prim();
  if(ret==0x3f3f3f3f)cout<<"orz";
  else
  cout<<ret;
  return 0;
}
