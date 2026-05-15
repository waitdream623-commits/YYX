//找到最小环大小
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n;
int a[N];
vector<int>edge[N];
int in[N];
bool st[N];
int dfs(int x)
{
  if(st[x])return 0;
  ll ret=1;
  st[x]=true;
  for(auto&e:edge[x])
  {
    if(!st[e])  
    ret+=dfs(e);
  }
  return ret;
}
//全局bfs，对每个点bfs，找到自己后结束
int dist[N];
int minroad=0x3f3f3f3f;
void bfs(int s)
{
    vector<int>dist(n+1,-1);
    queue<int>q;
    q.push(s);
    dist[s]=0;
    while (q.size())
    {
      int a=q.front();q.pop();
      if(dist[a]>minroad)break;//不满足
      for(auto&e:edge[a])
      {
        //返现了一条指回起点的边
        if(e==s)
        {
          minroad=min(minroad,dist[a]+1);
          break;
        }
        else if(dist[e]==-1)//没访问过
        {
          dist[e]=dist[a]+1;
          q.push(e);
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
    int t;cin>>t;

    edge[i].push_back(t);
    in[t]++;
  }
// queue<int>q;
// for(int i=1;i<=n;i++)
// {
//   if(in[i]==0)q.push(i);
// }
// while (q.size())
// {
//     int a=q.front();q.pop();
//     st[a]=true;//排除在外
//     for(auto&e:edge[a])
//     {
//       in[e]--;
//       if(in[e]==0)q.push(e);
//     }
// }
// int ret=0x3f3f3f3f;
// for(int i=1;i<=n;i++)
// {
//   if(!st[i])ret=min(dfs(i),ret);
// }
// cout<<ret;
for(int i=1;i<=n;i++)
{
  bfs(i);

}
cout<<minroad;
  return 0;
}
