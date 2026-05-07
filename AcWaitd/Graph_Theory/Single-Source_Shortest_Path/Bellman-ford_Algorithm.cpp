//按顺序对所有边进行松弛操作，可以处理带负边权，当不再处理后，退出循环
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
vector<PII>edge[N];
int n,m,s;//节点，边，起始
int dist[N];
void bf()
{

    memset(dist, INF, sizeof dist);
    dist[s]=0;//起始位置
    for(int u=1;u<n;u++)//最多进行n-1轮，每轮至少完成一条边松弛操作；
    {
        int flag=true;//是否进行松弛操作
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INF)continue;//此时他的边不可能进行松弛操作
            for(auto&e:edge[i])
            {
                int a=e.first,w=e.second;
                if(dist[i]+w<dist[a])
                {
                    flag=false;
                    dist[a]=dist[i]+w;
                }
            }
        }
        if(flag)break;//走了一圈，没有进行松弛操作


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
    edge[a].push_back({b,w});
  }
  bf();
  for(int i=1;i<=n;i++)
  {
    cout<<dist[i]<<' ';
  }
  return 0;
}
