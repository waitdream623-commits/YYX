//扩展域并查集
//分为同类，捕食，天敌
#include <iostream>
#include <type_traits>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int find(int x)
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unin(int a,int b)
{
  fa[find(b)]=find(a);
}
bool issame(int a,int b)
{
  return find(a)==find(b);
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;cin>>n>>m;
  //初始化
  for (int i = 1; i <=3*n; i++)
  {
    fa[i]=i;
  }
  
  int ret=0;
  while(m--)
  {
    int q,a,b;
    cin>>q>>a>>b;
    if(a>n||b>n)
    {
      ret++;
    }
    else if(q==1)//同类
    {
      //同类a，捕食a+n，天敌a+2n;
      //a->b,或者b->a;
      if(issame(b,a+n)||issame(a,b+n))ret++;
      else
      {
        unin(a,b);
        unin(a+n,b+n);
        unin(a+n+n,b+n+n);
      }
    }
    else//捕食a->b
    {
      //排除同类与b->a;
      if(issame(a,b)||issame(a,b+n))ret++;
      else
      {
        unin(a,b+n+n);
        unin(b,a+n);
        unin(a+n+n,b+n);
      }
    } 
  }
  cout<<ret;
  return 0;
}
