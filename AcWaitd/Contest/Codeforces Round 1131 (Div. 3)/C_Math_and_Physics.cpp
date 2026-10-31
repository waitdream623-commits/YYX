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
int a[N];
void wait()
{
    int n;
    cin >> n;
    bool f=0;
    rep(i,1,n)
    {
        cin >> a[i];
        if(a[i]>1)f=1;
    }
    if(!f)
    {
        cout << -1 <<'\n';
        return;
    }
    if(n==1)
    {
        cout << a[1]<<'\n';
        return;
    }
    //对于2 1 4   5；1 2 4  6；
    //说明中间有1要特殊处理
    //2 3 4 1 1 5 //防止两边逸散
    //中间不能全为1
    ll ans = 0;
    int t = 0;
    bool fl=0;
    rep(i,1,n)
    {
        
        ans+=a[i];
        if(i>=2&&i<=n-1&&!fl)
        {
            if(a[i]>1)
            {
                fl=1;
            }
        }
    }
    if(!fl&&n!=2)ans-=n-2;;//中间全为1
    cout << ans-1<<'\n';
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
