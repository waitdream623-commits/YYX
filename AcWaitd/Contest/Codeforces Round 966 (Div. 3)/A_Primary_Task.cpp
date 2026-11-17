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
    int n;cin >> n;
    string x;
    rep(i,1,n)
    {
        cin >> x;
        int sz = x.size();
        if(x.size()>=3)
        {
            if(x[0]=='1'&&x[1]=='0')
            {
                int t = 0;
                if(x[2]!='0')
                rep(i,2,sz-1)
                {
                    t = t*10+(x[i]-'0');
                }
                if(t>=2)
                {
                    cout << "YES\n";
                    continue;
                }
            }
        }
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
