#include <bits/stdc++.h>
using namespace std;

// ==================== 类型别名 ====================
using ll  = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// ==================== 常用宏 ====================
#define rep(i, a, b)    for (int i = (a); i <= (b); ++i)
#define per(i, a, b)    for (int i = (a); i >= (b); --i)
#define all(x)          (x).begin(), (x).end()
#define sz(x)           (int)(x).size()
#define pb              push_back
#define eb              emplace_back
#define fi              first
#define se              second
#define nl              '\n'

// ==================== 常量 ====================
const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 998244353;          // 常见模数，题面有则改
const int N   = 2e5 + 10;           // 根据题目调整

// ==================== Debug ====================
#ifdef LOCAL
#define debug(x)        cerr << #x << " = " << (x) << nl
#define debugv(v)       { cerr << #v << " = ["; for (auto _i : v) cerr << _i << ' '; cerr << "]" << nl; }
#else
#define debug(x)
#define debugv(v)
#endif

// ==================== 快读（可选） ====================
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read_ll() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

// ==================== 常用小函数 ====================
ll qpow(ll a, ll b, ll m = MOD) {
    ll r = 1; a %= m;
    while (b) { if (b & 1) r = r * a % m; a = a * a % m; b >>= 1; }
    return r;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// ==================== 全局变量 ====================
int n, m;
ll a[N];

// ==================== solve ====================
void solve() {
    // 每组测试用例的代码写在这里
}

// ==================== main ====================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int T = 1;
    cin >> T;                     // 单测时注释掉这行
    while (T--) {
        solve();
    }

    return 0;
}
