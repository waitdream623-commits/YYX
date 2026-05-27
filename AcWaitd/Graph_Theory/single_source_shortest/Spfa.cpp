//按顺序对所有边进行松弛操作，可以处理带负边权，当不再处理后，退出循环
#include <cstring>
#include <iostream>
#include <queue>
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
bool st[N];//可能重复加入队列
void spfa()
{

    memset(dist, INF, sizeof dist);
    queue<int>q;
    dist[s]=0;//起始位置
    q.push(s);
    st[s]=1;//放入队列
    while(q.size())
        {
            int a=q.front();q.pop();
            st[a]=0;//拿出，后续可能更新
            for(auto&e:edge[a])
            {
                int b=e.first,w=e.second;
                if(dist[a]+w<dist[b])
                {
                    //该点进行了松弛操作，可能对其他有影响,加入队列
                    if(!st[b])//未入列才入列
                {
                     q.push(b);
                    st[b]=1;//标记防止后续重复加入
                }
                    dist[b]=dist[a]+w;
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
    edge[a].push_back({b,w});
  }
  spfa();
  for(int i=1;i<=n;i++)
  {
    cout<<dist[i]<<' ';
  }
  return 0;
}
