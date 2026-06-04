#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e3 + 10;
ll x[N],y[N],z[N];
ll fa[N];
ll find(ll x)
{
  if(fa[x]==x)return x;
  return fa[x]=find(fa[x]);
}
void un(ll a,ll b)
{
  ll fx=find(a),fy=find(b);
  if(fx!=fy)
  {
    fa[fy]=fx;
  }
}

ll calculate(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}
void calc_un(ll n,ll r)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      ll d=calculate(x[i],y[i],z[i],x[j],y[j],z[j]);
      if(d<=4*r*r)
      {
        un(i,j);
      }
    }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;cin>>t;
  while (t--)
  {
    ll n,h,r;
    cin>>n>>h>>r;
    ll hmin=0x3f3f3f3f,hmax=0;
    //连通，并查集，集合中包含连接上下表面
  //初始化
  char st[N];
    for(int i=1;i<=n;i++)
    {
      fa[i]=i;
      st[i]='0';//初始化，重置，以免影响下一轮
      cin>>x[i]>>y[i]>>z[i];
      if(z[i]+r>=h)st[i]='a';
      if(z[i]-r<=0)st[i]='b';//标记能连通上下
     // 如果一个球既连上又连下（直径>=高度），特殊处理
      if (z[i] + r >= h && z[i] - r <= 0) st[i] = 'c';
      hmin=min(hmin,z[i]);
      hmax=max(hmax,z[i]);
    }
    if(hmax+r<h||hmin-r>0)
    {
      cout<<"No"<<endl;
      continue;
    }
    
    calc_un(n,r);//处理集合
    //遍历每个集合
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
      if(fa[i]==i)q.push(i);
    }
    int flag1=0;int flag2=0;
    while (q.size())
  {
    int a=q.front();q.pop();
    flag1=0;flag2=0;
    for(int i=1;i<=n;i++)
    {
       if(find(i)==a)
       {
         if(st[i]=='a'){
          flag1=1;
        }
        if(st[i]=='b')
        {
          flag2=1;
        }
        if(st[i]=='c')//连接上下表面
        {
          flag1=flag2=1;
        }
        if(flag1&&flag2)
        {
            cout<<"Yes"<<endl;
            break;
        }
       }
    }
     if(flag1&&flag2)
        {
            break;
        }
  }
   if(!flag1||!flag2)
   {
    cout<<"No"<<endl;
   }
       
  
  }
  
  return 0;
}
