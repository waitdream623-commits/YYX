//并查集加离散化！！！！
#include <algorithm>
#include <iostream>
//#include <map>
//哈希表查询更快
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int a[2*N];
int pos;
//连等的最终结果
int find(int x)
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unin(int x,int y)
{
  fa[find(x)]=find(y);
}
bool issame(int x,int y)
{
  return find(x)==find(y);
}
struct node{
  int x,y,z;
}st[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while(t--)
  {
    int flag=0;
    int n;cin>>n;
   
    // for(int i=1;i<=n;i++)
    // {
    //   //x与y可能超过n，怎么存储（离散化）？
    //   int x,y,e;cin>>x>>y>>e;
    //   if(e==1)unin(x,y);
    //   //e==0,x与y必须不同根
    //   else if(issame(x,y))
    //   flag=1;
    // }
    //离散化
    for(int i=1;i<=n;i++)
    {

      cin>>st[i].x>>st[i].y>>st[i].z;
      a[++pos]=st[i].x;a[++pos]=st[i].y;
    }
    //存了2N个
    sort(a+1,a+pos+1);//左闭右开
    int end=unique(a+1,a+pos+1)-(a+1);//unique返回为最后一个
     //初始化fa
    for(int i=1;i<=end;i++)fa[i]=i;
    unordered_map<int, int>mp;
    for(int i=1;i<=end;i++)
    {
      mp[a[i]]=i;
    }
//第一步： 输入 1 3 0 (代表 1 ≠ 3)。代码此时检查 1 和 3，发现不在一个集合，通过。
//第二步： 输入 1 2 1 (代表 1 = 2)。代码将 1 和 2 合并。
//第三步： 输入 2 3 1 (代表 2 = 3)。代码将 2 和 3 合并。
///按照你的逻辑，程序最后会输出 YES。但实际上，1=2 且 2=3，这就意味着 1 必须等于 3，这与第一步的 1≠3 构成了绝对的矛盾！
//正确原则：必须先处理所有相等（e=1）的条件，把门派建好；然后再处理所有不等（e=0）的条件，去核查是否存在矛盾。
    // for(int i=1;i<=n;i++)
    // {
    //   if(st[i].z==1)unin(mp[st[i].x],mp[st[i].y]);
    // }
    // for(int i=1;i<=n;i++)
    // {
    //   if(st[i].z==0)
    //   if(issame(mp[st[i].x],mp[st[i].y]))
    //   flag=1;
    // }
    //使用lower_bound
    for(int i=1;i<=n;i++)
    {
      if(st[i].z==1)
      {
        auto xit=lower_bound(a+1,a+1+end,st[i].x)-a;
        auto yit=lower_bound(a+1,a+1+end,st[i].y)-a;
        unin(xit,yit);

      }
    }
    for(int i=1;i<=n;i++)
    {
      if(st[i].z==0)
      {
        auto xit=lower_bound(a+1,a+1+end,st[i].x)-a;
        auto yit=lower_bound(a+1,a+1+end,st[i].y)-a;
        if(issame(mp[st[i].x],mp[st[i].y]))
      flag=1;
      }
      
    }
    if(flag)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
  }
  return 0;
}
