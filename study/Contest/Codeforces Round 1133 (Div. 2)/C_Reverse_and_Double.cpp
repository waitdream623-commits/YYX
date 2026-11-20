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
void wait1()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n <= 1) {
        cout << 0 << '\n';
        return;
    }

    // gap[i] 是 a[i] 和 a[i + 1] 之间的差值。
    vector<ll> gap(n), prefix(n), suffix(n + 1);
    int pos = 1;
    for (int i = 1; i < n; ++i) {
        gap[i] = abs(a[i] - a[i + 1]);
        prefix[i] = max(prefix[i - 1], gap[i]);
        if (gap[i] > gap[pos]) pos = i;
    }
    for (int i = n - 1; i >= 1; --i) {
        suffix[i] = max(suffix[i + 1], gap[i]);
    }

    ll ans = gap[pos];  // 可以不做操作。
    auto check = [&](int l, int r, ll insideMax) {
        ll cost = 2 * insideMax;
        if (l > 1) {
            cost = max({cost, prefix[l - 2], abs(a[l - 1] - 2 * a[r])});
        }
        if (r < n) {
            cost = max({cost, suffix[r + 1], abs(2 * a[l] - a[r + 1])});
        }
        ans = min(ans, cost);
    };

    // 要降低 gap[pos]，它必须是操作区间的一条边界。
    ll insideMax = 0;
    for (int l = pos; l >= 1; --l) {
        if (l < pos) insideMax = max(insideMax, gap[l]);
        check(l, pos, insideMax);
    }
    insideMax = 0;
    for (int r = pos + 1; r <= n; ++r) {
        if (r > pos + 1) insideMax = max(insideMax, gap[r - 1]);
        check(pos + 1, r, insideMax);
    }
    cout << ans << '\n';
}
const int N = 1e6+10;
int a[N];
void wait2()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n <= 1) {
        cout << 0 << '\n';
        return;
    }

    vector<ll> gap(n), prefix(n), suffix(n + 1);
    int pos = 1;
    for (int i = 1; i < n; ++i) {
        gap[i] = abs(1LL * a[i] - a[i + 1]);
        prefix[i] = max(prefix[i - 1], gap[i]);
        if (gap[i] >= gap[pos]) pos = i;
    }
    for (int i = n - 1; i >= 1; --i) {
        suffix[i] = max(suffix[i + 1], gap[i]);
    }

    ll ans = gap[pos];

    // 向右扫描 [pos + 1, r]。
    ll midmax = 0;
    for (int r = pos + 1; r <= n; ++r) {
        if (r > pos + 1) midmax = max(midmax, 2 * gap[r - 1]);
        const ll difl = abs(a[pos] - 2LL * a[r]);
        const ll difr = r < n ? abs(a[r + 1] - 2LL * a[pos + 1]) : 0;
        const ll outsideRight = r < n ? suffix[r + 1] : 0;
        ans = min(ans, max({difl, difr, midmax, prefix[pos - 1], outsideRight}));
    }

    // 向左扫描 [l, pos]。
    midmax = 0;
    for (int l = pos; l >= 1; --l) {
        if (l < pos) midmax = max(midmax, 2 * gap[l]);
        const ll difl = l > 1 ? abs(a[l - 1] - 2LL * a[pos]) : 0;
        const ll difr = abs(a[pos + 1] - 2LL * a[l]);
        const ll outsideLeft = l > 1 ? prefix[l - 2] : 0;
        ans = min(ans, max({difl, difr, midmax, outsideLeft, suffix[pos + 1]}));
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait1();
    }
    return 0;
}
