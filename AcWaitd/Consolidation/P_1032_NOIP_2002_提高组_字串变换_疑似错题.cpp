#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
string a,b;
string x[80],y[80];
unordered_map<string,int>dist;
int pos=1;
int bfs()
{
  queue<string>q;
  q.push(a);
  dist[a]=0;
  while (q.size())
  {
    string tmp=q.front();
    q.pop();
    if(dist[tmp]>=10)return -1;
    //变
    for(int i=1;i<=pos;i++)
    {
        
      
      int start=0;
      //可能now中含有多个a[i];
      while ((start=tmp.find(x[i],start))!=-1)
      {
        
       string now=tmp;//每次需要重置为起始
        now.replace(start,x[i].size(),y[i]);
        start++;
        if(dist.count(now))continue;//之前加入过了
        dist[now]=dist[tmp]+1;
        if(now==b)return dist[now];//找到了
        q.push(now);
        //now=tmp;//同理需要重置，应该放在最后重置,// 【悲剧发生】：被 continue 截胡了，这行代码根本没执行！
      }
      
    }
  }
  
  return -1;//执行完毕没找到
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>a>>b;
  
  while (cin>>x[pos]>>y[pos])
  {
   pos++;
  }
  pos--;//多加了一个
  int ret=bfs();
  if(ret==-1)cout<<"NO ANSWER!";
  else
  cout<<ret;
  return 0;
}
