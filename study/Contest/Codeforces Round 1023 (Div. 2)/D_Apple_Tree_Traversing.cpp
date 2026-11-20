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
vector<int>edge[N];
void wait()
{
    int n; cin >> n;
    rep(i,1,n)
    {
        edge[i].clear();
    }
    rep(i,1,n-1)
    {
        int x,y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);

    }
    vector<char>vis(n+1,1);//标记还未删除的节点
    vis[0] = 0;
    vector<array<int,3>>ans;
    vector<int>last(n+1,0),dist(n+1,0);//每组测试只分配一次
    int a = 1;
    while(a <= n)
    {
        //直径可能不经过 a，只有 a 已经被删除时才继续向右找
        if(!vis[a])
        {
            a++;
            continue;
        }
        last[a] = 0;
        dist[a] = 0;
        queue<int>q;
        q.push(a);
        vector<int>node;
        while(q.size())
        {
            int x = q.front();
            q.pop();
            node.push_back(x);

            for(auto e:edge[x])
            {
                if(e==last[x]||!vis[e])continue;//跳过已删除的节点和父节点
                dist[e]=dist[x]+1;
                q.push(e);
                last[e] = x;
            }
        }
        int start = a;//只在当前连通块中选最远点，同距离时选较大编号
        for(auto e:node)
        {
            if(dist[e] > dist[start] ||
             (dist[e] == dist[start] && e > start))
                start = e;
            last[e] = 0;
        }

        q.push(start);
        dist[start] = 0;
         while(q.size())
        {
            int x = q.front();
            q.pop();
            for(auto e:edge[x])
            {
                if(e==last[x]||!vis[e])continue;
                dist[e]=dist[x]+1;
                q.push(e);
                last[e] = x;
            }
        }
        //找到直径
        int end = start;
         for(auto e:node)
        {
            if(dist[e] > dist[end] ||
            (dist[e] == dist[end] && e > end))
             end = e;
        }
        int cnt = 1;
        for(int i = end;i!=start;i=last[i])
        {
            cnt++;
            vis[i] = 0;
        }
        vis[start] = 0;
        //不同连通块的处理顺序不保证字典序，收集后统一排序
        //cout << cnt <<' '<<max(start,end)<<" "<<min(start,end)<<' ';
        ans.push_back({cnt, max(start,end), min(start,end)});

    }
    // 全部处理结束后
    sort(ans.rbegin(), ans.rend());
    for(auto [x,y,z]:ans)
    {
        cout << x << ' '<< y<<' '<<z<<' ';
    }

    cout << '\n';
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
