#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int n,m;
//查最上节点，以判断是否在同一个集合
int find(int x)
{
  if(fa[x]==x)return x;
  //将途中节点均指向单独的父节点
  //按秩合并
  else return fa[x]=find(fa[x]);
}
void un(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    //将x头连接到y的头
    fa[fx]=fy;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  //初始化，每个人单独成应该集合
  for(int i=1;i<=n;i++)fa[i]=i;
  //操作
  while(m--)
  {
    int z,x,y;
    cin>>z>>x>>y;
    if(z==1)un(x,y);
    if(z==2)
    {
      if(find(x)==find(y))cout<<"Y"<<endl;
      else cout<<"N"<<endl;
    }
  }
  return 0;
}
