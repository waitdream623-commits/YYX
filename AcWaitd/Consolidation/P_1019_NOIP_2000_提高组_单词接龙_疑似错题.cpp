#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
string s[30];
int vis[30];
int ans;
int n;
void dfs(string tmp)
{
    ans=max((int)tmp.size(),ans);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]>=2)continue;
        for(int j=1;j<min(tmp.size(),s[i].size());j++)//不能取等，否则成为包含关系
        {
            if(tmp.substr(tmp.size()-j)==s[i].substr(0,j))//从下标开始截取
            {
                ++vis[i];
                dfs(tmp.substr(0,tmp.size()-j)+s[i]);
                --vis[i];
            }
        }
    }
}
void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        vis[i]=0;
    }
    char a;cin>>a;
    for(int i=1;i<=n;i++)
    {
        if(s[i][0]==a)
        {
            ++vis[i];
            dfs(s[i]);
            --vis[i];
        }
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
