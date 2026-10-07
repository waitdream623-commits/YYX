// #include <algorithm>
// #include <iostream>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// int fa[N];
// int find(int a)
// {
//   return fa[a]==a?a:fa[a]=find(fa[a]);
// }
// struct node
// {
//     int w,x,y;
// }na[N];
// int n,a;
// int pos;//存储边数
// int cnt,ret;
// bool cmp(node a,node b)
// {
//   return a.w<b.w;
// }
// void kk()
// {
//   sort(na+1,na+1+pos,cmp);

//   for(int i=1;i<=pos;i++)
//   {
//       int x=na[i].x,y=na[i].y,w=na[i].w;
//       int fx=find(x),fy=find(y);
//       if(fx!=fy)
//       {
//         cnt++;
//         fa[fx]=fy;
//         ret+=w;
//       }
//   }
// }
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cin>>a>>n;
//   for(int i=1;i<=n;i++)
//   {
//     fa[i]=i;
//     for(int j=1;j<=n;j++)
//     {
//       int w;cin>>w;
//       //为i—>j，只需要存边，存一半
//       if(i>=j||w>a||w==0)continue;
//       na[++pos].w=w;
//       na[pos].x=i;
//       na[pos].y=j;
//     }
//   }
//   kk();
//   cout<<ret+(n-cnt)*a;
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
//输入为邻接矩阵，如果优惠大于a直接将边权改为a
//切入点必须以a来购买，再跑一次
//存边，实现对边权值排序，连接x-y
struct node{
  int w,x,y;
};
vector<node>edge;
int ans;
int cnt;
int fa[N];
    int a, b;

void build()
{
    for(int i=1;i<=b;i++)fa[i]=i;
}
int find(int x)
{
  return x==fa[x]?x:fa[x]=find(fa[x]);
}
void kk()
{
  build();
    sort(edge.begin(), edge.end(),[](auto a, auto b)->bool{return a.w<b.w;});
    for(auto e:edge)
    {
      auto [w,a,b]=e;
      if(find(a)!=find(b))
      {
        cnt++;
        ans+=w;
        fa[find(a)]=find(b);
      }
    }
}
void wait()
{
    cin>>a >> b;
    //可以加一个虚拟点，将所有点连接起来，边权为a，此时整体求最小生成树
    rep(i, 1,b)
    {
      rep(j,1,b)//有权值为零无优惠，权值大于a，这些点不存，最后统计连接了多少个ans = ans+(b-cnt)*a
      {
        int x; cin >> x;
        //只需要存一半
        if(i==j||x==0||x>a)continue;
        edge.push_back({x,i,j});
        //上述特殊处理
        

      }
    }
    kk();
    //第一个原价a,连接cnt个，所以总共应该是b-cnt个a
    cout<< ans+(b-cnt)*a;
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
