#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e5 + 10,M=2e6+10;//m表示边数，可能高度相等，存储双边
//有高度要求，为单向图，因为可以回溯，为最小生成树，
//需要记录加入边数，计算景点数
int h[N];
//用邻接矩阵存储不了
vector<PII>v[N];
int n,m;
int cnt;
ll ret;
bool st[N];//dfs时候标记经过
struct node
{
  int a,b,w;
}sa[M];//存边
int pos;//记录存到边个数
void dfs(int u)
{
  cnt++;
  st[u]=true;
  for(auto&e:v[u])
  {
    int a=e.first,b=e.second;
    //加入图。访问可以到达景点，将边加入
    ++pos;
    sa[pos].a=u,sa[pos].b=a,sa[pos].w=b;
    //后判断，尽管已经访问过，将该点边全部加入，找最优解
    if(!st[a])dfs(a);
  }
}
int fa[N];
int find(int a)
{
  return fa[a]==a?a:fa[a]=find(fa[a]);
}
bool cmp(node&a,node&b)
{
  //优先找高的，尽可能多加入点
  int h1=h[a.b],h2=h[b.b];
  if(h1!=h2)return h1>h2;
  else
  return a.w<b.w;
}
void kk()
{
  sort(sa+1,sa+1+pos,cmp);

  for(int i=1;i<=pos;i++)
  {
    int x=sa[i].a,y=sa[i].b,w=sa[i].w;
    int fx=find(x),fy=find(y);
    //没有连接
    if(fx!=fy)
    {
      fa[fx]=fy;
      ret+=w;
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>h[i];
    fa[i]=i;//并查集初始化
  }
  for(int i=1;i<=m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    //根据高度存储单向边
    //两个if，相同存储双边
    if(h[a]>=h[b])v[a].push_back({b,w});
    if(h[a]<=h[b])v[b].push_back({a,w});
  }
  //求可到达景点数
  //初始为1号景点，可能各个景点不连通，dfs探索
  dfs(1);
  cout<<cnt<<" ";
  //求最小花费

  kk();
  cout<<ret;
  
  return 0;
}
