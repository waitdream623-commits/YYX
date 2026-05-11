#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
int t[210];//记录修复时间
int cnt;//标记k能到哪儿
int f[210][210];//i->j距离，随k更新
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>t[i];
  //初始化
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        f[i][j]=0x3f3f3f3f;
      }
      f[i][i]=0;//自己到自己,放在外层，防止被覆盖
    }
  for(int i=1;i<=m;i++)
  {
      int a,b,w;
      cin>>a>>b>>w;
      a++,b++;
      f[a][b]=f[b][a]=min(f[a][b],w);
  
  }
  //f初始化

  int q;cin>>q;
  while(q--)
  {
    int x,y,end;cin>>x>>y>>end;
    x++,y++;//存储从1开始
    int a=cnt;
    while(a<=n&&t[a]<=end)a++;//找到此时已经修复了几个点
    //此时比endd大
    a--;
    //Floyd
    //此时将前a个加入f表中
    cnt++;
    for(int k=cnt;k<=a;k++)
    {
      for(int i=1;i<=n;i++)
      {
        if(f[i][k]==INF)continue;
        for(int j=1;j<=n;j++)
        {
          f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
      }
    }
    if(t[x]>end||t[y]>end||f[x][y]==0x3f3f3f3f)cout<<-1<<endl;
    else
    cout<<f[x][y]<<endl;
    cnt=a;
  }
  return 0;
}
