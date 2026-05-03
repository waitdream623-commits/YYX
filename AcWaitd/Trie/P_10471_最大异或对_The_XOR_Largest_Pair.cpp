#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10;
int tree[32*N][2];//每一个数32位
int idx;
int e[32*N];//方法一存储，每条路最终结果
int a[N];
void insert(int a)
{
  int cur=0;
  // int i=31;//移位
  // int tmp=a;
  // while(tmp)//优先存储高位，方便后续优先匹配高位
  // {
  //   int path=0;
  //   if((tmp&(1<<i))==1)path=1;
  //   tmp<<=1;//去掉高位
  //   i--;
  //   if(tree[cur][path]==0)tree[cur][path]=++idx;
  //   //cur往下
  //   cur=tree[cur][path];
  // }
  // //最后存储该路
  // e[cur]=a;
  for(int i=31;i>=0;i--)//大于等于零
  {
    int path=(a>>i)&1;
    if(tree[cur][path]==0)tree[cur][path]=++idx;
    cur=tree[cur][path];
  }
  //结束
  e[cur]=a;

}
int find(int a)//传入a，找到他的最优解
{ 
    int cur=0;
    int ret=0;//第二种方法
    for(int i=31;i>=0;i--)
    {
      int path=(a>>i)&1;
      //贪心找最优解，走相反路
      if(tree[cur][path^1])//存在
      {
        ret|=(1<<i);
        cur=tree[cur][path^1];
      }
      else//不存在
      {
        //ret该位为零
        cur=tree[cur][path];
      }
    }
//return e[cur]^a;
//第二种方法
return ret;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];insert(a[i]);
  }
  int ret=0;
  for(int i=1;i<=n;i++)
  {
    ret=max(find(a[i]),ret);
  }
  cout<<ret;
  return 0;
}
