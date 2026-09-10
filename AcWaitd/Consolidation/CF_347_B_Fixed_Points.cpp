#include <bits/stdc++.h>
#include <map>
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
map<int,int>mp;
void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int b;cin>>b;
        mp[i]=b;
        if(i==b)
        cnt++;

    }
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        if(mp[i]!=i)//不是一一对应的
        {int x=mp[i];
        if(mp[x]==i)
        flag=1;}
    }
    if(cnt<n)
    {
        if(flag)
        {
            cout<<cnt+2;

        }
        else
        cout<<cnt+1;
    }
    else
    cout<<cnt;
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
