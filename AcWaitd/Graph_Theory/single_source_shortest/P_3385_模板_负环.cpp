//按顺序对所有边进行松弛操作，可以处理带负边权，当不再处理后，退出循环
//BF 算法判断负环
//• 执⾏ n 轮松弛操作，如果第 n 轮还存在松弛操作，那么就有负环。
//spfa 算法判断负环
//• 维护⼀个 cnt 数组记录从起点到该点所经过的边数，如果 cnt[i] >= n ，说明有负环。
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
int n,m;//节点，边，起始
int dist[N];
void bf()
{
    memset(dist, INF, sizeof dist);
    dist[1]=0;//起始位置
    int ret=0;
    for(int u=1;;u++)//最多n-1条边，进行n-1轮，每轮至少完成一条边松弛操作；
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
        if(u>=n)
        {
          ret=1;
          break;//存在负环，一直进行松弛操作
        }
    }
    if(ret)cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

   // edge->clear();//清空，仅仅清空edge[0]
    // 正确的多组测试数据清空方式
  for (int i = 1; i <= n; i++) {
    edge[i].clear();
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
int t;cin>>t;
while (t--)
{
    cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
      
    edge[a].push_back({b,w});
    if(w>=0)
    {
    edge[b].push_back({a,w});
    }
  }
  bf();
}

  return 0;
}
