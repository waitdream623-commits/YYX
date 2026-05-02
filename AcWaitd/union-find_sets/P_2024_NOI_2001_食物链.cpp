//带权并查集
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int fa[N];
int d[N];//距离
int find(int x)
{
  if(fa[x]==x)return x;
  int t=find(fa[x]);
  d[x]+=d[fa[x]];
  return fa[x]=t;
}
void un(int a,int b,int w)
{
  int fx=find(a),fy=find(b);
  //如果已经相同，说明已经处理过，不需要更新距离
  if(fx!=fy)
  {
    //a吃b，连接到b
  fa[fx]=fy;
  //更新距离,从a到fx加上到fy==从a到b加上到fy
  d[fx]=d[b]+w-d[a];
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;cin>>n>>k;
  //初始化
  for(int i=1;i<=n;i++)fa[i]=i;
  int ret=0;
  while (k--)
  {
    int q,a,b;
    cin>>q>>a>>b;
    int fx=find(a),fy=find(b);
    if(a>n||b>n)ret++;
    else if(q==1)//相同
    {
      //如果fx!=fy,说明第一次遇到
      if(fx==fy&&((d[b]-d[a])%3+3)%3!=0)ret++;
      else
      {
        un(a,b,0);
      }
    }
    else
    {
      //a吃b
      //判断之前数据
       if(fx==fy&&((d[b]-d[a])%3+3)%3!=1)ret++;
       else
       un(a,b,2);//a连接上b，a为b的天敌，权重为2
    }
  }
  cout<<ret;
  return 0;
}


// //扩展域并查集
// //分为同类，捕食，天敌
// #include <iostream>
// #include <type_traits>
// using namespace std;
// typedef long long ll;
// const int N = 1e6 + 10;
// int fa[N];
// int find(int x)
// {
//   return fa[x]==x?x:fa[x]=find(fa[x]);
// }
// void unin(int a,int b)
// {
//   fa[find(b)]=find(a);
// }
// bool issame(int a,int b)
// {
//   return find(a)==find(b);
// }
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n,m;cin>>n>>m;
//   //初始化
//   for (int i = 1; i <=3*n; i++)
//   {
//     fa[i]=i;
//   }
  
//   int ret=0;
//   while(m--)
//   {
//     int q,a,b;
//     cin>>q>>a>>b;
//     if(a>n||b>n)
//     {
//       ret++;
//     }
//     else if(q==1)//同类
//     {
//       //同类a，捕食a+n，天敌a+2n;
//       //a->b,或者b->a;
//       if(issame(b,a+n)||issame(a,b+n))ret++;
//       else
//       {
//         unin(a,b);
//         unin(a+n,b+n);
//         unin(a+n+n,b+n+n);
//       }
//     }
//     else//捕食a->b
//     {
//       //排除同类与b->a;
//       if(issame(a,b)||issame(a,b+n))ret++;
//       else
//       {
//         unin(a,b+n+n);
//         unin(b,a+n);
//         unin(a+n+n,b+n);
//       }
//     } 
//   }
//   cout<<ret;
//   return 0;
// }
