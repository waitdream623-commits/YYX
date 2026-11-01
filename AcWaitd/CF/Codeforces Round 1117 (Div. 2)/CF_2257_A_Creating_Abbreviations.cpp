#include <bits/stdc++.h>
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
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
void wait()
{
    int n,m;
    cin >> n >>m;
    map<char,int>mp;
    string s;
    rep(i,1,n)
    {
        cin  >> s;
        mp[s[0]]++;
    }
    int flag=1;
    rep(i,1,m)
    {
        cin>>s;
        for(auto e:s)
        {
            char x=tolower(e);
            if(mp[x]==0)
            {
                flag=0;//需要读完，不能直接返回
            }

        }
        mp[tolower(s[0])]++;

    }
    if(flag)
    cout<< " YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
