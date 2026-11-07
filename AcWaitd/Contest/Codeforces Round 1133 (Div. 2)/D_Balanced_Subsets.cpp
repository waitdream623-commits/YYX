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
using ll = long long;
const int MOD = 998244353;

ll qpow(ll a, ll b)
{
    a = (a % MOD + MOD) % MOD;
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 要求 a % MOD != 0
ll inv(ll a)
{
    return qpow(a, MOD - 2);
}

vector<ll> fac, ifac;

void initComb(int n)
{
    fac.resize(n + 1);
    ifac.resize(n + 1);

    fac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = fac[i-1] * i % MOD;

    ifac[n] = inv(fac[n]);
    for(int i = n; i >= 1; i--)
        ifac[i-1] = ifac[i] * i % MOD;
}

// n 不能超过 initComb 时预处理的上限
ll C(int n, int k)
{
    if(k < 0 || k > n)return 0;
    return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
}
int a[N];
int memo[600005][8][3];
int cacu(int x)
{
    int ans   = 0;
    while(x)
    {
        if(x&1)ans++;
        x>>=1;
    }
    return ans;
}
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    // ll ans = 0;
    // ans += n + (n-1)*n/2;
    // ans %= MOD;
    //集合大于2的
    //必然有两个不稳地，最后两个，因此前面必须要与后面有联系

    int mx = a[n];
    vector<int> exists(mx + 1, 0);
    rep(i,1,n)exists[a[i]] = 1;

    memset(memo, -1, sizeof(memo[0]) * (mx + 1));
    //m记录连续三位位置，cnt 记录不稳地个数
    auto dfs = [&](auto&& dfs, int x, int m, int cnt) -> int
    {
        if(x == 0)return 1;  // 所有数都处理完了，这条路线算一种

        int& res = memo[x][m][cnt];
        if(res != -1)return res;

        int ne = (m << 1) & 7;//只保留三位

        // 不选 x，下一轮的最低位是 0
        res = dfs(dfs, x - 1, ne, cnt);

        // 可以选 x 时，再加上选它的方案数
        if(exists[x] && (cnt < 2 || cacu(m) == 2))
        {
            res += dfs(dfs, x - 1, ne | 1, min(2, cnt + 1));//选了x放在第一位
            if(res >= MOD)res -= MOD;
        }

        return res;
    };

    int ans = dfs(dfs, mx, 0, 0);
    cout << (ans - 1 + MOD) % MOD << '\n';//q掉空集
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
