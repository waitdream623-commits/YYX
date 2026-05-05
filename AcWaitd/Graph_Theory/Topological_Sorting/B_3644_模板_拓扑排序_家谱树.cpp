#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 110;
vector<int>v[N];
int in[N];//记录入度
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  int x;//以读到0为一个节点结束
  for(int i=1;i<=n;i++)
  {
    while(cin>>x,x)
    {
      v[i].push_back(x);
      in[x]++;//记录入度
    }
  }
  //拓扑排序
  queue<int>q;
  //先加入入读为0
  for(int i=1;i<=n;i++)
  {
    if(in[i]==0)q.push(i);
  }
  //处理
  while(q.size())
  {
    int i=q.front();q.pop();
    cout<<i<<" ";
    for(auto&e:v[i])//将该点边删除
    {
      in[e]--;
      if(in[e]==0)q.push(e);//如果为零，加入队列
    }
  }
  return 0;
}
