#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
class Solution {
public:
    int fa[100010];
    int find(int x)
    {
        return fa[x] == x?x:fa[x] = find(fa[x]);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    //     //依照时间排序，对于零时刻，开始，标记知晓秘密人，如果后续，遍历每个meetings，有标记的均加入集合；
    //     //对于同时发生，如果后续连接，前面还得处理，应该遍历两边或者将时间相同的并在一起
    //     sort(meetings.begin(),meetings.end(),[](auto a,auto b){return a[2] < b[2];});
    //     vector<bool>vis(n,0);
    //     vis[firstPerson] = 1;
    //     vis[0] = 1;
    //     int m = meetings.size();
    //     int start = 0;
    //     int end = 0;
    //     // for(auto e:meetings)
    //     // {
    //     //     cout << e[0]<<' '<<e[1]<<" "<<e[2]<<endl;
    //     // }
    //     for(int i = 0; i < m;i++)
    //     {
    //         auto e = meetings[i];
    //         int x = e[0], y = e[1];
    //         vis[x] = vis[x]|vis[y];
    //         vis[y] = vis[x]|vis[y];
    //         if(i!=0&&e[2]==meetings[i-1][2])//处理相同时间
    //         {
    //             auto  t = meetings[i-1];
    //             vis[t[1]] = vis[t[1]]|vis[t[0]];//shi'd
    //             vis[t[0]] = vis[t[0]]|vis[t[1]];
    //         }
    //         // if(i+1<n&&e[2]!=meetings[i+1][2])
    //         // {
    //         //     end = i+1;
    //         //     //再次遍历
    //         //     for(int j = start; j < end;j++)
    //         //     {
    //         //          auto e = meetings[j];
    //         //         int x = e[0], y = e[1];
    //         //         vis[x] = vis[x]|vis[y];
    //         //         vis[y] = vis[x]|vis[y];
    //         //     }
    //         //     start = end;
    //         // }

            
    //     }
    //     vector<int>ans;
    //     for(int i = 0;i<n;i++)
    //     {
    //         if(vis[i])
    //         {
    //             ans.push_back(i);
    //         }
    //     }
    //     return ans;
    // }
    //上述处理同一时间，不能单纯再次遍历，如果遍历后出现新标记，可能需要再次遍历一次，
    //应该对同一时间建立无向图，并第一次遍历将已经标记的，加入队列作为遍历开始，结束后清楚图
    // 按时间分组，为本组所有会议建立临时无向图。
    // 将本组参与者中已知晓秘密的人去重后加入队列，作为多源 BFS 起点。
    // BFS 中发现未知晓秘密的邻居，就标记并入队，继续传播。
    // 本组结束后，只清空本组参与者的邻接表和本组访问标记；
    // 永久保留“是否知晓秘密”的状态。
    //或者使用并查集，先连接两者，对于同一时间，需要再次遍历解绑，因为后续时间这些已经失效，对于能够知道的第一次遍历就连接在一起，对于集合不与0的集合一块的解绑，
    vector<int>sz(n,0);
    for(int i = 0; i<n;i++){
        fa[i] = i;
        sz[i] = 1;
    }
    
    auto un = [&](int x,int y)->void
    {
        if(find(x) != find(y))
        {
            fa[fa[x]] = fa[y];//头连接在头上
          //  sz[fa[y]] += sz[fa[x]];//记录大小其实没必要
        }
    };
        sort(meetings.begin(),meetings.end(),[](auto a,auto b){return a[2] < b[2];});
        vector<bool>vis(n,0);
        vis[firstPerson] = 1;
        vis[0] = 1;
        un(0,firstPerson);
        int m = meetings.size();
        int start = 0;
        int end = 0;
        // for(auto e:meetings)
        // {
        //     cout << e[0]<<' '<<e[1]<<" "<<e[2]<<endl;
        // }
        for(int i = 0; i < m;i++)
        {
            auto e = meetings[i];
            int x = e[0], y = e[1];
            un(x,y);
            //最后一位怎么处理，与前面相同或者不同，相同的话，
            if(i == m-1&&e[2]==meetings[i-1][2])//与前面相同
            {
                 end = i+1;
                //再次遍历
                for(int j = start; j < end;j++)
                {
                     auto t = meetings[j];
                    if(find(t[0])!=find(0))//其余已经全部并入0的集合；
                    {
                        //断联
                        fa[t[0]] = t[0];
                        fa[t[1]] = t[1];
                        sz[t[0]] = 1;
                        sz[t[1]] = 1;
                    }
                    
                }
                start = end;
            }
            //不同的话就自己一个。un处理了
            if(i+1<m&&e[2]!=meetings[i+1][2])//特殊处理最后一位m-1,不对，万一最后一位与前面时间相同；
            {
                end = i+1;
                //再次遍历
                for(int j = start; j < end;j++)
                {
                     auto t = meetings[j];
                    if(find(t[0])!=find(0))//其余已经全部并入0的集合；
                    {
                        fa[t[0]] = t[0];
                        fa[t[1]] = t[1];
                        sz[t[0]] = 1;
                        sz[t[1]] = 1;
                    }
                    
                }
                start = end;
            }
        }
        vector<int>ans;
        for(int i = 0;i < n;i++)
        {
            //cout <<find(i)<<' ';
            if(find(i) == find(0))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
       vector<string> grid;
       grid.push_back ("@fedcbBCDEFaA");
       Solution s;
       s.findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson);
    }
    return 0;
}
