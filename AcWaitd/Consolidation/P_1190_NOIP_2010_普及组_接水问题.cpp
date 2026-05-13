#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m;
int a[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  cin>>a[i];;
//小根堆，并且记录最大值
priority_queue<int,vector<int>,greater<int>>q;
//先入堆
int ret=0;
int i=0;
for(i=1;i<=m;i++)
{
  q.push(a[i]);
  ret=max(ret,a[i]);
}
for(;i<=n;i++)
{
  //拿出最小，累加后再加入
  int b=q.top();q.pop();
  b+=a[i];
  ret=max(ret,b);
  q.push(b);
}
cout<<ret;
  return 0;
}
