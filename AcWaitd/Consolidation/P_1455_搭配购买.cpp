//无向图，多个连通块，求出每个连通块消耗与价值
//并查集
#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e4 + 10;
int c[N],v[N];
int n,m,w;
int f[11000];
int g[N];//需要初始化
map<int, int>mp1,mp2;//存储每个集合的消耗与价值
int find(int x)
{
  if(g[x]==x)return x;
  return g[x]=find(g[x]);
}
void un(int a,int b)
{
  int fa=find(a),fb=find(b);
  if(fa!=fb)
  {
    g[fb]=fa;//fa是头
    v[fa]+=v[fb];
    c[fa]+=c[fb];
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m>>w;
  for(int i=1;i<=n;i++)
  {
    g[i]=i;//自己指向自己表示，为一个集合头
    cin>>c[i]>>v[i];
  }
  //处理每个搭配
  for(int i=1;i<=m;i++)
  {
    int a,b;
    cin>>a>>b;
    un(a,b);
  }

  //动态规划，01背包
  for(int i=1;i<=n;i++)
  {
    if(g[i]==i)
    for(int j=w;j>=c[i];j--)
    {
      // //不要第i个
      // f[j]=f[j];
      // //要
      // if(j-mp1[t[i]]>=0)
      f[j]=max(f[j],f[j-c[i]]+v[i]);
    }
  }
  cout<<f[w];
  return 0;
}
