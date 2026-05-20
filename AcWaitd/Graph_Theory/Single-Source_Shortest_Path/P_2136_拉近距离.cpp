// //存在负边权，只能用bf或者spfa
// //需要判断是否存在负环，bf循环次数，spfa动态规划记录cnt[N]是否大于n-1
// //存边权需要存负数

//减少w
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
vector<PII>v[N];
int dist[N];
int n,m;
bool bf(int s)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
    for(int i=1;i<=n;i++)//多一次
    {
        bool flag=0;
        for(int j=1;j<=n;j++)
        {
            if(dist[j]==INF)continue;//不可能松弛
            for(auto&e:v[j])
            {
                int a=e.first,b=e.second;
                if(dist[j]+b<dist[a])
                {
                    dist[a]=dist[j]+b;
                    flag=1;
                }
            }
        }
        if(!flag)break;
        if(i==n)//说明存在负环
        {
            return false;
        }
    }
    return true;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    v[a].push_back({b,-w});//不是双向图
  }
  int ret=INF;
  if(!bf(1))
  {
        cout<<"Forever love";
        return 0;
  }
  ret=min(ret,dist[n]);
  if(!bf(n))
  {
        cout<<"Forever love";
        return 0;
  }
  ret=min(ret,dist[1]);
  
    cout<<ret;
   
  return 0;
}



// #include <cstring>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// typedef long long ll;
// typedef pair<int,int> PII;
// const int N = 1100;
// int INF = 0x3f3f3f3f;

// int n, m;
// vector<PII> edge[N]; // 使用邻接表，彻底告别幽灵边和超时
// int cnt[N];          // 标记经过的边数，用于判断负环
// bool st[N];          // 标记是否在队列中，避免重复进队
// int dist[N];

// // 将 spfa 封装，带返回值用于立刻判断是否存在负环
// bool spfa(int start)
// {
//     memset(dist, 0x3f, sizeof dist);
//     memset(cnt, 0, sizeof cnt);
//     memset(st, 0, sizeof st);
    
//     dist[start] = 0;
//     queue<int> q;
//     q.push(start);
//     st[start] = true;
    
//     while (q.size())
//     {
//         int a = q.front();
//         q.pop();
//         st[a] = false;
        
//         // 遍历所有从 a 发出的【真实的边】
//         for (auto& e : edge[a])
//         {
//             int i = e.first;
//             int w = e.second;
            
//             // 只要能拉近距离，就进行松弛
//             if (dist[a] + w < dist[i])
//             {
//                 dist[i] = dist[a] + w;
//                 cnt[i] = cnt[a] + 1; // 记录路径包含的边数
                
//                 // 关键修正：在松弛成功时，立刻判断当前点 i 是否经历了 >= n 条边
//                 if (cnt[i] >= n) return true; // 发现负环！
                
//                 if (!st[i])
//                 {
//                     q.push(i);
//                     st[i] = true;
//                 }
//             }
//         }
//     }
//     return false; // 队列正常跑完，无负环
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     if (!(cin >> n >> m)) return 0;
    
//     for (int i = 1; i <= m; i++)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         // 用 vector 存边天然支持重边。无需像你原本那样写 min，SPFA 会自动跑出最优解
//         edge[a].push_back({b, -w}); 
//     }
    
//     int ret = INF;
    
//     // 第一次探索：计算 1 到 n 的最短路
//     if (spfa(1)) {
//         cout << "Forever love\n";
//         return 0;
//     }
//     ret = min(ret, dist[n]);
    
//     // 第二次探索：计算 n 到 1 的最短路 (P2136 的专属题意防AK坑)
//     if (spfa(n)) {
//         cout << "Forever love\n";
//         return 0;
//     }
//     ret = min(ret, dist[1]);
    
//     cout << ret << "\n";
//     return 0;
// }