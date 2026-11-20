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
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
//长度，相同匹配
int a[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    int m;cin >> m;
    while(m--)
    {
        string s;cin >> s;
        if(s.size()!=n)
        {
            cout << "NO\n";
            continue;
        }
        vector<set<int>>cnt(27);
        bool f=0;
        map<int,int>mp;

        for(int i = 0;i<n;i++)
        {
            int x = s[i]-'a';
            if(mp.count(a[i+1])&&x!=mp[a[i+1]])
            {
                f=1;
                break;
            }
            cnt[x].insert(a[i+1]);//可能a中多个相同
            mp[a[i+1]]=x;//强制配对
            if(cnt[x].size()>1)
            {
                f=1;
                break;
            }
        }
        vector<set<int>>cnt2(27);
        if(f)
        {
            cout << "NO\n";
        }
        else
        cout << "YES\n";
    }
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
