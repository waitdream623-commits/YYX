//合并使用并查集，距离使用带权并查集
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int d[N];
int cnt[N];
int find(int x)
{
  if(fa[x]==x)return x;
  int t = find(fa[x]);
  d[x]+=d[fa[x]];
  return fa[x]=t;
}
//合并放在b所在列的最后
void un(int a,int b)
{
  int fx=find(a),fy=find(b);
  //相等不用合并
  if(fx!=fy)
  {
    fa[fx]=fy;
    //为等于，尽管d[fx]==0;
    d[fx]=cnt[fy];//a的头放在fy列最后，找fy大小
    cnt[fy]+=cnt[fx];
  }
}
void query(int a,int b)
{
  int fx=find(a),fy=find(b);
  if(fx!=fy)cout<<-1<<endl;
  else
  {
    cout<<abs(d[b]-d[a])-1<<endl;
  }

}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  //初始化
  for (int  i=1;i<=30000;i++) 
  {
    fa[i]=i;cnt[i]=1;
  }
  
  while (t--)
  {
    char c;int x,y;
    cin>>c>>x>>y;
    if (c=='M')
    {
      un(x,y);
    }
    else
    {
      query(x,y);
    }
    
  }
  
  return 0;
}
