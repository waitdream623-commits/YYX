//repeat
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
vector<PII>edge1[1100],edge2[1100];//需要存反图
ll ret;
bool st[N];//标记是否入队，spfa;
int dist[N];//记录距离
void spfa(vector<PII>edge[])
{
    for(int i=1;i<=n;i++)
    {
      dist[i]=INF;
    }
    dist[1]=0;
    queue<int>q;
    q.push(1);
    st[1]=1;
    while (q.size())
    {
      int x=q.front();q.pop();
      st[x]=0;
      for(auto&e:edge[x])
      {
        int y=e.first,w=e.second;
       if(dist[x]+w<dist[y])
       {
        if(!st[y])
        {
          q.push(y);
          st[y]=1;
        }
        dist[y]=dist[x]+w;
       }
      }

    }

}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=m;i++)//读取的是边的个数
  {
    int a,b,w;
    cin>>a>>b>>w;
    edge1[a].push_back({b,w});
    edge2[b].push_back({a,w});

  }
  //去
  spfa(edge1);
  for(int i=1;i<=n;i++)
  {
    ret+=dist[i];
  }
  //回来
  spfa(edge2);
  for(int i=1;i<=n;i++)
  {
    ret+=dist[i];
  }
  cout<<ret;
  return 0;
}

// #include <functional>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// int n,m;
// bool st[N];//标记该点是否更新过
// ll ret;//
// int dist[N];//每个点距离起始点最近
// void dijk(vector<PII>edge[])
// {
//     for (int i = 1; i <=n; i++)
//     {
//       dist[i]=INF;
//       st[i]=0;
//     }
  
//     dist[1]=0;
//     //小根堆维护找最近
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     q.push({0,1});//默认第一位排序,第一位为距离，第二位为节点
    
//     while (q.size()) 
//     {
//       auto a=q.top();q.pop();
//       int x=a.first,y=a.second;
//       if(st[y])continue;//重复节点
//       st[y]=1;//此时该点已经处理完，找不到更近，反证法
//       for(auto&e:edge[y])
//       {
//         int z=e.first,w=e.second;
//         if(dist[y]+w<dist[z])
//         {
//           dist[z]=dist[y]+w;
//           q.push({dist[z],z});

//         }
//       }
//     }
// }
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cin>>n>>m;
// vector<PII>edge1[1100],edge2[1100];
//   for(int i=1;i<=m;i++)
//   {
//     int a,b,w;
//     cin>>a>>b>>w;
//     edge1[a].push_back({b,w});
//     edge2[b].push_back({a,w});


//   }
//   //去
//   dijk(edge1);
//   for(int i=1;i<=n;i++)ret+=dist[i];
//     //每个点到i;反向图
//    dijk(edge2);
//   for(int i=1;i<=n;i++)ret+=dist[i];
//   cout<<ret;
//   return 0;
// }
