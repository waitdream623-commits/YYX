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
#define rep(i,m,n) for(ll i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
array<ll,3>a[N];
ll pres[N];
void wait()
{
    int n;cin >>n;
    rep(i,1,n)
    {
        int x,b,c;
        cin >> x >> b>>c;
        a[i]={x,b,c};
        pres[i] = pres[i-1]+c;
    }
    vector<ll>f(n+1,0);
    rep(i,1,n)
    {
        f[i] = f[i-1]-a[i][2];//不选减去
        int l = i-a[i][0],r= i-1;
        if(l>r)//空区间
        {   
            f[i] = max(f[i],f[i-1]+a[i][1]);//都可以选，这里f[i]已经是不选的值
            continue;
        }
        else if(l<=0)//选
        {
            f[i] = max(f[i],a[i][1] - pres[r]);
            continue;
        }
        f[i] = max(f[i],f[l-1]+a[i][1]-(pres[r]
        -pres[l-1]));
    }
    cout << f[n];
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
