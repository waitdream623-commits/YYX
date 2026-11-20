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
const int N = 1e6 + 10,MOD =998244353;
int cnt[N];
ll qpow(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return ans;
}
void wait()
{
    int n,k;
    cin >> n >> k;
    rep(i,1,n)
    {
        int x;cin >> x;
        cnt[i]=x;;
    }
    sort(cnt+1,cnt+1+n);
    map<int,int>mp;
    rep(i,1,n)
    {
        mp[cnt[i]]++;
    }
    ll ans = 1;
    int p = 0;
    auto dfs = [&](int i)->ll
    {
        if(i>n)
        {
            return 0;
        }
        int r = i+mp[cnt[i]]-1;
        //不选第i位，
        if(cnt[i]==p+1)
        ans += (pow(2,n-r+1)-1)*pow(cnt[i]+1,k);
        else
        {
            //此时选不选后续结果固定
            ans +=
        }
    };
    cout << ans<<'\n';
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
