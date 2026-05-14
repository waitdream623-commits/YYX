//找到最小环大小
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int n;
int a[N];
vector<int>edge[N];
int in[N];
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int t;cin>>t;

    edge[i].push_back(t);
    in[t]++;
  }
queue<int>q;
for(int i=1;i<=n;i++)
{
  if(in[i]==0)q.push(i);
}
while (q.size())
{
    int a=q.front();q.pop();
    n--;
    for(auto&e:edge[a])
    {
      in[e]--;
      if(in[e]==0)q.push(e);
    }
}
cout<<n;
  return 0;
}
