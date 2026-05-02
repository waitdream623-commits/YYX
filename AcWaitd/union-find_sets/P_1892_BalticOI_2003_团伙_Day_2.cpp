//扩展域并查集
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int find(int x)
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
//将朋友域作为根节点
void unin(int a,int b)
{
    fa[find(b)]=find(a);
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  int m;cin>>m;
  //初始化
  for(int i=1;i<=2*n;i++)fa[i]=i;//i+n为敌人域

  while(m--)
  {
    char c;int a,b;
    cin>>c>>a>>b;
    //朋友，没说朋友敌人是敌人
    if(c=='F')unin(a,b);
    else//敌人
    {
      unin(a,b+n);
      unin(b,a+n);
    }
  }
//找有几个团伙，仅遍历朋友域
int ret=0;
for(int i=1;i<=n;i++)
{
  if(fa[i]==i)ret++;
}
cout<<ret;
  return 0;
}
