#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 3e6 + 10;
int tree[N][62],p[N],e[N];
int index;
int get_num(char c)
{
  if(c>='a'&&c<='z')return c-'a';
  if(c>='A'&&c<='Z')return c-'A'+26;
  return c-'0'+52;
}
void pushs(string&s)
{
  int cur=0;//从顶层开始
  p[cur]++;
  for(auto e:s)
  {
    int path=get_num(e);
    if(tree[cur][path]==0)//说明没有存储e这个字符
    {
      tree[cur][path]=++index;//开辟空间
    }
    //往下一层走
    cur=tree[cur][path];
    //经过
    p[cur]++;

  }
  //到达最终
  e[cur]++;
}
//查询相同前缀个数
int find_pre(string&s)
{
  int cur=0;
  for(auto e:s)
  {
    int path = get_num(e);
    if(tree[cur][path]==0)return 0;//没找到
    //找到了匹配字符，继续往下
    cur=tree[cur][path];
  }
  //最终,p存储的为通过此路个数，即相同前缀
  return p[cur];
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while(t--)
  {
    
    int n,m;cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        pushs(s);

    }
    for(int i=1;i<=m;i++)
    {
      cin>>s;
      cout<<find_pre(s)<<endl;
    }
    //清空,memset超时
    // memset(tree,0,sizeof tree);
    // memset(p,0,sizeof p);
    // memset(e,0,sizeof e);
    // index=0;
    for(int i=0;i<=index;i++)//从0开始
    {
      p[i]=0;
      e[i]=0;
      for(int j=0;j<62;j++)tree[i][j]=0;
    }
    index=0;

  }
  return 0;
}
