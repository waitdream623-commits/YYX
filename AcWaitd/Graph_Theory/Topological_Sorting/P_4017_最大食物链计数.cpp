#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10,MOD = 80112002;
vector<int>v[N];
int f[N];//路径dp
int in[N],out[N];//入度拓扑排序填表，出度多个食物网结果遍历
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int a,b;cin>>a>>b;
    v[a].push_back(b);
    in[b]++;
    out[a]++;
  }

  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(in[i]==0)
    {
      q.push(i);
      f[i]=1;//dp初始化；
    }
  }
  while(q.size())
  {
    int a=q.front();q.pop();
    //删边，此时f[a]已经填好
    for(auto&e:v[a])
    {
        f[e]=(f[e]+f[a]) % MOD;
        in[e]--;
        if(in[e]==0)q.push(e);
    }
  }
  int ret=0;
  //找每个食物网最后一个节点的dp值
  for(int i=1;i<=n;i++)
  {
    if(out[i]==0)ret=(ret+f[i]) % MOD;//记得取模
  }
  cout<<ret;
  return 0;
}