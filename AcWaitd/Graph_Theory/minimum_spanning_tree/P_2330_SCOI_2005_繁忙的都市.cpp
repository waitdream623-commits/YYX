// #include <algorithm>
// #include <iostream>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// const int N = 1e6 + 10;
// int INF=0x3f3f3f3f;
// int n,m;
// struct node
// {
//     int x,y,w;
// }st[N];//存储边的信息
// int fa[N];//并查集
// int find(int a)
// {
//     return fa[a]==a?a:fa[a]=find(fa[a]);
// }
// bool cmp(node&a,node&b)
// {
//     return a.w<b.w;
// }
// int kk()
// {   
//     int ret=0;
//     //对边排序
//     sort(st+1,st+1+m,cmp);
//     int cnt=0;//计数，可能存在不连通的图
//     //加边
//     for(int i=1;i<=m;i++)
//     {
//         int a=st[i].x,b=st[i].y,c=st[i].w;
//         int fx=find(a),fy=find(b);
//         if(fx!=fy)
//         {
//             fa[fx]=fy;
//             cnt++;
//             ret=max(ret,c);
//         }
//     }
//     return ret;
// }
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cin>>n>>m;
//   for(int i=1;i<=m;i++)
//   {
//     cin>>st[i].x>>st[i].y>>st[i].w;
//   }
//   //并查集初始化
//   for(int i=1;i<=n;i++)fa[i]=i;
//   int ret=kk();
  
//   cout<<n-1<<' ';
//   cout<<ret;
//   return 0;
// }
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
int n,m;
bool vis[N];
vector<PII>edges[N];//无向图
void wait()
{
    cin >> n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >>a>>b >>c;
        edges[a].push_back({c,b});
        edges[b].push_back({c,a});
    }
    int cnt=0;
    int mx=-1e9;
    auto prim = [&]()->void
    {
        priority_queue<PII,vector<PII>,greater<PII>>q;//按照第一个小根堆排
        //加入第一个点
        vis[1]=true;
        cnt=0;
        for(auto [w,b]:edges[1])
        {
            if(!vis[b])
            {
                q.push({w,b});
            }
        }
        while(q.size()&&cnt<n-1)//取出最近的且没有加入过的点
        {
            auto [w,b]=q.top();
            q.pop();
            if(vis[b])continue;
            cnt++;
            mx =max(mx,w);
            vis[b]=true;
            for(auto e:edges[b])q.push(e);//扩展邻居
            //if(cnt==n)break;
        }


    };
    prim();
    cout<< cnt <<' '<<mx;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
