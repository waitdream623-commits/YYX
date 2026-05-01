#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int find(int x)
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool issame(int x,int y)
{
  return find(x)==find(y);
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,p;cin>>n>>m>>p;
  //初始化
  for(int i=1;i<=n;i++)fa[i]=i;
  while(m--)
  {
    int a,b;
    cin>>a>>b;
    //连接关系
    fa[find(a)]=find(b);
  }
  while(p--)
  {
    int a,b;
    cin>>a>>b;
    if(issame(a,b))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
