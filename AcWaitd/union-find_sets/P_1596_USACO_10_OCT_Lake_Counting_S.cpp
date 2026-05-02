//二维一维转化
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
char g[110][110];
int fa[N];
//方位向量，只需要向下探索，右，下，左下，右下
int dx[]={0,1,1,-1};
int dy[]={1,1,0,1};
//使用find找到最终头，再连
int find(int x)
{
  return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unin(int x,int y)
{
  fa[find(x)]=find(y);
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>g[i][j];
    }
  }
  //初始化,二维化一维
  for(int i=0;i<n*m;i++)fa[i]=i;
  //并查集操作，相邻
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(g[i][j]=='.')continue;
      for(int k=0;k<4;k++)
      {
        int x=i+dx[k],y=j+dy[k];
        if(x<n&&y<m&&x>=0&&g[x][y]=='W')
        {
          unin(x*m+y,i*m+j);
          //fa[x*m+y]=fa[i*m+j];没有找到最终头，可能导致同一片区域两个头
        }
      }
    }
  }
  //遍历有多少个集合
  int ret=0;
  for(int i=0;i<n*m;i++)
  {
    int x=i/m,y=i%m;
      if(g[x][y]=='W'&&fa[i]==i)
     {
       ret++;
     }
  }
 cout<<ret;
  return 0;
}