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
ll a[20];
void build()
{
    ll i = 0;
    a[i]=1;
    rep(i,1,15)
    {
        a[i] = a[i-1]*i;
    }
}
ll dfs(ll t ,int i )
{
    if(i==0)
    {
        int k = 0;
        while(t)
        {
            if(t&1)
            {
                k++;
            }
            t>>=1;
        }
        return k;
    }
    ll ans = 1e9;
    if(t>=a[i])
    {
        ans=dfs(t-a[i],i-1)+1;
    }
    ans  = min(ans,dfs(t,i-1));//不选
    return ans;

}
void wait()
{
    ll n;cin >> n;
    cout << dfs(n,15)<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
