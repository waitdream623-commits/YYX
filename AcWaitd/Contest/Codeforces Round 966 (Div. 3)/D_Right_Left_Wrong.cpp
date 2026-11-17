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
#define int long long
ll a[N];
void wait()
{
    int n;
    cin >> n;
    rep(i,1,n)
    {
        int x;cin >> x;
        a[i] = x+a[i-1];
    }
    string x;cin >> x;
    vector<int>L,R;
    int l = -1,r=-1;
    for(int i = 0;i<n;i++)
        {
            if(x[i]=='L')
            {
                if(l==-1)
                {
                    l=i+1;
                }
                L.push_back(i+1);
            }
            if(x[i]=='R')
            {
                r = i+1;
                R.push_back(i+1);
            }
        }
    ll ans = 0;
    sort(R.rbegin(),R.rend());
    int i = 0,j=0;
    //先加内部再加外部，也可以从外部往内部处理 
    while(l<r&&i<L.size()&&j<R.size())
    {
        ans+=a[r]-a[l-1];
        l = L[++i];
        r = R[++j];

    }   
    cout << ans<<'\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
