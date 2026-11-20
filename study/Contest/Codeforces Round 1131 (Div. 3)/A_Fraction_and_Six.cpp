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
void wait()
{
    int n, m;
    cin >> n  >> m;
    string x,t;cin >> x>>t;
    string tmp;
    vector<bool>vis(m+1,0);
    for(auto e:x)
    {
        bool f=0;
        for(int j = 0;j<t.size();j++)
        {
            if(!vis[j]&&e==t[j])
            {
                f=1;
                vis[j]=1;
                break;
            }
        }
        if(!f)
        tmp+=e;
    }
    if(n-m!=3)//分数化简为 six
{
    cout<<"NO\n";
    return;
}
    if(tmp.size()==3)
    {
        if((tmp[0]=='s'&&tmp[1]=='i'&&tmp[2]=='x')||
        (tmp[0]=='s'&&tmp[1]=='x'&&tmp[2]=='i')
    ||(tmp[0]=='i'&&tmp[1]=='s'&&tmp[2]=='x')||
(tmp[0]=='i'&&tmp[1]=='x'&&tmp[2]=='s')||
(tmp[0]=='x'&&tmp[1]=='s'&&tmp[2]=='i')||
(tmp[0]=='x'&&tmp[1]=='i'&&tmp[2]=='s'))
cout<<"YES\n";
  else
    cout << "NO\n";
    return;
    }
    
  
    else
    cout << "NO\n";
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
