#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<string,string>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
PII v[N];
map<string,int>mp;
map<string,int>mpst;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        {
            string a,b;
            cin>>a>>b;
            v[i]={a,b};
            int x;cin>>x;
            mp[a]=mp[b]=x;
        }
    for(int i=1;i<=k;i++)
        {
            string a;cin>>a;
            int op;cin>>op;
            if(op==1)
            {
                mp[a]+=520;
                mpst[a]=1;
            }
            else
            {
                 mp[a]-=520;
                mpst[a]=-1;
            }
        }
    priority_queue<pair<int,int>>q1;//大根堆
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
    for(int i=1;i<=n;i++)
        {
            int tmp=mp[v[i].first]+mp[v[i].second];
            if(mpst[v[i].first]==1||mpst[v[i].second]==1)
            q1.push({tmp,i});
            if(mpst[v[i].first]==-1||mpst[v[i].second]==-1)
            q2.push({tmp,i});
            
        }
    for(int i=1;i<=3;i++)
        {
            int a=q1.top().second,b=q1.top().first;q1.pop();
            cout<<v[a].first<<" "<<v[a].second<<' '<<b<<endl;
            if(q1.empty())break;
        }
        for(int i=1;i<=3;i++)
        {
            int a=q2.top().second,b=q2.top().first;q2.pop();
            cout<<v[a].first<<" "<<v[a].second<<' '<<b<<endl;
            if(q2.empty())break;

        }
  return 0;
}
