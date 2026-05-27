#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int fa[N];
int find(int a)
{
  return fa[a]==a?a:fa[a]=find(fa[a]);
}
struct node
{
    int w,x,y;
}na[N];
int n,a;
int pos;//存储边数
int cnt,ret;
bool cmp(node a,node b)
{
  return a.w<b.w;
}
void kk()
{
  sort(na+1,na+1+pos,cmp);

  for(int i=1;i<=pos;i++)
  {
      int x=na[i].x,y=na[i].y,w=na[i].w;
      int fx=find(x),fy=find(y);
      if(fx!=fy)
      {
        cnt++;
        fa[fx]=fy;
        ret+=w;
      }
  }
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>a>>n;
  for(int i=1;i<=n;i++)
  {
    fa[i]=i;
    for(int j=1;j<=n;j++)
    {
      int w;cin>>w;
      //为i—>j，只需要存边，存一半
      if(i>=j||w>a||w==0)continue;
      na[++pos].w=w;
      na[pos].x=i;
      na[pos].y=j;
    }
  }
  kk();
  cout<<ret+(n-cnt)*a;
  return 0;
}
