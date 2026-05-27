#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N = 1e6 + 10;
int INF=0x3f3f3f3f;
int n,m;
struct node
{
    int x,y,w;
}st[N];//存储边的信息
int fa[N];//并查集
int find(int a)
{
    return fa[a]==a?a:fa[a]=find(fa[a]);
}
bool cmp(node&a,node&b)
{
    return a.w<b.w;
}
int kk()
{   
    int ret=0;
    //对边排序
    sort(st+1,st+1+m,cmp);
    int cnt=0;//计数，可能存在不连通的图
    //加边
    for(int i=1;i<=m;i++)
    {
        int a=st[i].x,b=st[i].y,c=st[i].w;
        int fx=find(a),fy=find(b);
        if(fx!=fy)
        {
            fa[fx]=fy;
            cnt++;
            ret+=c;
        }
    }
    return cnt==n-1?ret:INF;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>st[i].x>>st[i].y>>st[i].w;
  }
  //并查集初始化
  for(int i=1;i<=n;i++)fa[i]=i;
  int ret=kk();
  if(ret==INF)cout<<"orz";
  else
  cout<<ret;
  return 0;
}
