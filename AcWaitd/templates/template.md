# 错例
- [ ] `int` 会不会溢出？ → 换 `long long`
- [ ] 数组开够了吗？ → `const int N = xxx + 10`
- [ ] 多测清空了吗？ → 全局变量、队列、栈、vector
- [ ] 模运算做了吗？ → `(a + b) % MOD`
- [ ] 输出格式：空格？换行？末尾空格？Yes/YES？
- [ ] 0-indexed vs 1-indexed 搞混了没？
- [ ] 类型混用了嘛
- [ ] 运算符优先级，位运算运算优先级很低
- [ ] memset 按字节填值，-1 的十六进制是 0xFFFFFFFF，每个字节是 0xFF填完后每个 int（4 字节）变成 0xFFFFFFFF → 二补码表示即 -1 

# 一、基础模板

## 快读快写
```cpp
// 关闭同步：ios::sync_with_stdio(false); cin.tie(nullptr);
// 换行用 '\n' 而非 endl
```
```cpp
// 快读函数（整数，替代 scanf，约快 2~3 倍）
inline int read() {
    int x = 0, f = 1; 
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
// 快写函数（整数，递归实现）
inline void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
// 用法：int n = read(); print(ans);
```

## 二分

### 整数二分 — 左边界（左边满足，右边不满足）
```cpp
数组:    [ F, F, F, T, T, T, T ]
索引:      1  2  3  4  5  6  7
                  ↑
              分界点 (第一个 T)
while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else            l = mid + 1;
}
```

### 整数二分 — 右边界（左边不满足，右边满足）
```cpp
适用场景：TTTTFFFF → 找最后一个 T
while (l < r) {
    int mid = (l + r + 1) / 2; // +1 防死循环
    if (check(mid)) l = mid;
    else            r = mid - 1;
}
```

### 浮点数二分
```cpp
while (r - l > 1e-8) {        // 也可固定迭代 100 次
    double mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else            l = mid;
}
```

### STL 二分
```cpp
int pos = lower_bound(a, a + n, x) - a; // 第一个 >= x
int pos = upper_bound(a, a + n, x) - a; // 第一个 > x
```

---

## 高精度（vector 实现，倒序存：个位在 [0]）

### 加法
```cpp
vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10); t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}
```

### 减法（A >= B）
```cpp
vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1; else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```

### 乘低精度
```cpp
vector<int> mul(vector<int>& A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10); t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```

### 除低精度
```cpp
vector<int> div(vector<int>& A, int b, int& r) {
    vector<int> C; r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b); r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```

---

## 前缀和 / 差分

### 一维前缀和
```cpp
int a[N], pre[N];
// 预处理
for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
// 查询 [l, r] 的和
int sum = pre[r] - pre[l - 1];
```

### 二维前缀和
```cpp
int a[N][N], s[N][N];
// 预处理
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
// 查询 (x1,y1) ~ (x2,y2) 的和
int sum = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
```

### 一维差分
```cpp
int a[N], d[N]; // d 为差分数组
// 区间 [l, r] 加上 val
d[l] += val;
d[r + 1] -= val;
// 还原原数组
for (int i = 1; i <= n; i++) a[i] = a[i - 1] + d[i];
```

### 二维差分
```cpp
int d[N][N]; // 差分数组
// 子矩阵 (x1,y1) ~ (x2,y2) 加上 val
d[x1][y1] += val;
d[x2 + 1][y1] -= val;
d[x1][y2 + 1] -= val;
d[x2 + 1][y2 + 1] += val;
// 还原原数组（二维前缀和）
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
// 此时 d[i][j] 即为变化后的 a[i][j]
```

## 离散化
```cpp
vector<int> v; // 存所有待离散化的值
sort(all(v));
v.erase(unique(all(v)), v.end());
int id = lower_bound(all(v), x) - v.begin() + 1; // 1-indexed
```

---

# 二、数论

代码沿用竞赛模板中的 `using namespace std;` 和 `using ll = long long;`。有取模的题先确认模数和数据范围。

| 要做什么 | 用哪个板子 | 条件或复杂度 |
| --- | --- | --- |
| 求公约数、公倍数 | `std::gcd`、`lcm_nonneg` | 公倍数必须能用 `ll` 表示 |
| 求模幂 | `qpow` | `O(log e)`，指数非负 |
| 求一个逆元 | `inv_prime` 或 `inv_exgcd` | 质数模可用快速幂，一般模数先检查互质 |
| 解 `a*x ≡ c (mod m)` | `solve_congruence` | 有解时给出最小非负解和周期 |
| 求 `1..n` 的逆元 | `init_inv` | 质数模且 `n < p`，`O(n)` |
| 多次查询组合数 | `init_comb`、`C` | 质数模且 `n < MOD`，查询 `O(1)` |
| 小范围任意模数组合数 | `pascal` | `O(n²)`，只做加法 |
| 批量筛质数 | `linear_sieve` 或 `eratosthenes` | 前者附最小质因子，后者只标记质数 |
| 分解、约数、欧拉函数 | `factorize`、`divisors`、`phi` | 试除，最坏 `O(√x)` |

## 快速幂与取模

下面的乘法适用于正模数不超过 `INT_MAX`，两个余数用 `ll` 相乘。模数更大时，乘法中间值要用 `__int128` 或按题目范围另处理。

```cpp
ll norm(ll x, ll mod)
{
    x %= mod;
    if(x < 0)x += mod;
    return x;
}

ll qpow(ll a, ll e, int mod)
{
    a = norm(a, mod);
    ll res = 1 % mod;
    while(e > 0)
    {
        if(e & 1)res = res * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return res;
}
```

## gcd、lcm 与扩展欧几里得

`std::gcd(a,b)` 返回最大公约数。计算 LCM 时先除再乘，结果仍须在类型范围内。对非负的 `a,b`，`exgcd` 返回 `g=gcd(a,b)`，同时求出一组 `a*x+b*y=g` 的解。若要求 `a*x+b*y=c`，先检查 `g | c`，再把系数乘以 `c/g`。这里假设 `a,b` 不同时为零。

```cpp
ll lcm_nonneg(ll a, ll b)
{
    if(a == 0 || b == 0)return 0;
    return a / std::gcd(a, b) * b;
}

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}
```

## 逆元与线性同余

模意义下用 `a * inv(b) % mod` 表示除以 `b`，前提是 `gcd(b,mod)=1`。下面约定求逆元时 `mod > 1`。线性同余的解为 `first + k*step`，其中 `k` 是任意整数。

```cpp
// mod 为质数，且 a % mod != 0
ll inv_prime(ll a, int mod)
{
    return qpow(a, mod - 2, mod);
}

// mod 可以是合数。返回 -1 表示逆元不存在
ll inv_exgcd(ll a, int mod)
{
    ll x, y;
    if(exgcd(norm(a, mod), mod, x, y) != 1)return -1;
    return norm(x, mod);
}

// 解 a*x ≡ c (mod m)，要求 m > 0
bool solve_congruence(ll a, ll c, int m, ll& first, ll& step)
{
    ll x, y;
    ll g = exgcd(norm(a, m), m, x, y);
    if(c % g != 0)return false;

    step = m / g;
    first = norm(norm(c / g, step) * norm(x, step), step);
    return true;
}

// p 是质数，且 1 <= n < p
vector<ll> init_inv(int n, int p)
{
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for(int i = 2; i <= n; i++)
        inv[i] = p - (p / i) * inv[p % i] % p;
    return inv;
}
```

例如 `inv_exgcd(3,8)=3`，而 `inv_exgcd(2,8)=-1`。解 `6x ≡ 8 (mod 14)` 得到 `first=6, step=7`。

## 组合数

阶乘法要求 `MOD` 是质数且 `maxN < MOD`。多测按总上限初始化一次。下面的 `C(n,k)` 要求有效的 `n` 已经预处理。若 `n >= MOD`，阶乘可能变成零而没有逆元。模数是小质数时可以考虑 Lucas。范围小且模数任意时，用下面的杨辉三角。

```cpp
const int MOD = 998244353;
vector<ll> fac, ifac;

void init_comb(int maxN)
{
    fac.resize(maxN + 1);
    ifac.resize(maxN + 1);

    fac[0] = 1;
    for(int i = 1; i <= maxN; i++)
        fac[i] = fac[i - 1] * i % MOD;

    ifac[maxN] = inv_prime(fac[maxN], MOD);
    for(int i = maxN; i >= 1; i--)
        ifac[i - 1] = ifac[i] * i % MOD;
}

ll C(int n, int k)
{
    if(k < 0 || k > n)return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

// init_comb(200000) 后，C(5, 2) == 10
vector<vector<int>> pascal(int n, int mod)
{
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    c[0][0] = 1 % mod;
    for(int i = 1; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1 % mod;
        for(int j = 1; j < i; j++)
            c[i][j] = (1LL * c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    return c;
}
```

## 质数判定与筛法

只有少量数时可试除。需要批量判断时筛到上限。埃氏筛返回是否为质数，线性筛同时存 `lp[x]`（最小质因子），可用来反复除掉因子。

```cpp
bool is_prime(ll x)
{
    if(x < 2)return false;
    for(ll i = 2; i <= x / i; i++)
        if(x % i == 0)return false;
    return true;
}

vector<bool> eratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    if(n >= 1)prime[1] = false;

    for(int i = 2; i <= n / i; i++)
        if(prime[i])
            for(ll j = 1LL * i * i; j <= n; j += i)
                prime[j] = false;
    return prime;
}

vector<int> linear_sieve(int n, vector<int>& lp)
{
    lp.assign(n + 1, 0);
    vector<int> primes;
    for(int i = 2; i <= n; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            primes.push_back(i);
        }

        for(int p : primes)
        {
            if(p > lp[i] || 1LL * i * p > n)break;
            lp[i * p] = p;
        }
    }
    return primes;
}
```

## 质因数分解、约数与欧拉函数

下面三个函数的输入均为正整数。若 `x = ∏p^e`，约数个数为 `∏(e+1)`。计算欧拉函数时，每种质因子只扣一次。

```cpp
vector<pair<ll,int>> factorize(ll x)
{
    vector<pair<ll,int>> factors;
    for(ll p = 2; p <= x / p; p++)
    {
        if(x % p != 0)continue;
        int e = 0;
        while(x % p == 0)
        {
            x /= p;
            e++;
        }
        factors.push_back({p, e});
    }
    if(x > 1)factors.push_back({x, 1});
    return factors;
}

vector<ll> divisors(ll x)
{
    vector<ll> d, upper;
    for(ll i = 1; i <= x / i; i++)
    {
        if(x % i != 0)continue;
        d.push_back(i);
        if(i != x / i)upper.push_back(x / i);
    }
    d.insert(d.end(), upper.rbegin(), upper.rend());
    return d;
}

ll phi(ll x)
{
    ll res = x;
    for(auto [p, e] : factorize(x))
        res -= res / p;
    return res;
}
```

矩阵快速幂在本文件「五、动态规划」下。容斥、组合计数与博弈公式见 [Craving 数学部分](../../study/Craving.md#数学)。

---

# 三、数据结构

## 并查集 (DSU)
```cpp
int fa[N], sz[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    fa[b] = a; sz[a] += sz[b];
}
// 初始化：for i=1..n: fa[i]=i, sz[i]=1
```

## 单调栈
```cpp
// 右边第一个更大的下标（没有则为 0）
int a[N], ans[N];
stack<int> st;
for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] < a[i]) // 改成 > 即为更小
        ans[st.top()] = i, st.pop();
    st.push(i);
}
```

## 单调队列（滑动窗口最值）
```cpp
// 长度为 k 的滑动窗口，求每个窗口的最小值
int a[N];
deque<int> q; // 存下标，保持队内单调递增
for (int i = 1; i <= n; i++) {
    // 1. 弹出队首过期元素
    if (!q.empty() && q.front() < i - k + 1) q.pop_front();
    // 2. 维护单调性（求最小值用 >，求最大值用 <）
    while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
    q.push_back(i);
    // 3. 取答案（窗口形成后）
    if (i >= k) ans[i - k + 1] = a[q.front()];
}
```

## 线段树

> 二叉树结构，O(log n) 单点/区间操作。空间开 **4×N**。
> 节点 p：左儿子 `p<<1`，右儿子 `p<<1|1`，mid = (l+r)>>1。

### 基础版：单点修改 + 区间求和

```cpp
ll a[N], tree[N << 2];

void pushup(int p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

// 建树：build(1, 1, n)
void build(int p, int l, int r) {
    if(l == r) { tree[p] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

// 单点修改：将 a[pos] 改为 val
void update(int p, int l, int r, int pos, ll val) {
    if(l == r) { tree[p] = val; return; }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(p << 1, l, mid, pos, val);
    else           update(p << 1 | 1, mid + 1, r, pos, val);
    pushup(p);
}

// 区间查询 [ql, qr] 的和
ll query(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree[p];
    int mid = (l + r) >> 1; ll sum = 0;
    if(ql <= mid) sum += query(p << 1, l, mid, ql, qr);
    if(qr >  mid) sum += query(p << 1 | 1, mid + 1, r, ql, qr);
    return sum;
}
```

### 懒标记版：区间加法 + 区间求和

```cpp
ll a[N], tree[N << 2], lazy[N << 2];

void pushup(int p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

// ★ 下传懒标记：经过节点时必须先 pushdown
void pushdown(int p, int l, int r) {
    if(lazy[p] == 0) return;
    int mid = (l + r) >> 1;
    int left_len = mid - l + 1, right_len = r - mid;
    // 左儿子
    tree[p << 1] += lazy[p] * left_len;
    lazy[p << 1] += lazy[p];
    // 右儿子
    tree[p << 1 | 1] += lazy[p] * right_len;
    lazy[p << 1 | 1] += lazy[p];
    lazy[p] = 0;  // 清除当前标记
}

void build(int p, int l, int r) {
    if(l == r) { tree[p] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

// 区间加：[ml, mr] 每个元素 +val
void update(int p, int l, int r, int ml, int mr, ll val) {
    if(ml <= l && r <= mr) {          // 完全覆盖 → 打懒标记
        tree[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    pushdown(p, l, r);                // ★ 先下传
    int mid = (l + r) >> 1;
    if(ml <= mid) update(p << 1, l, mid, ml, mr, val);
    if(mr >  mid) update(p << 1 | 1, mid + 1, r, ml, mr, val);
    pushup(p);
}

// 区间查询（带懒标记）
ll query(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree[p];
    pushdown(p, l, r);                // ★ 查询前先下传
    int mid = (l + r) >> 1; ll sum = 0;
    if(ql <= mid) sum += query(p << 1, l, mid, ql, qr);
    if(qr >  mid) sum += query(p << 1 | 1, mid + 1, r, ql, qr);
    return sum;
}
```

### 区间最值版（RMQ，无懒标记）

```cpp
int a[N], maxv[N << 2];

void pushup(int p) { maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]); }

void build(int p, int l, int r) {
    if(l == r) { maxv[p] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

int query_max(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return maxv[p];
    int mid = (l + r) >> 1;
    int res = -0x3f3f3f3f;  // 极小值
    if(ql <= mid) res = max(res, query_max(p << 1, l, mid, ql, qr));
    if(qr >  mid) res = max(res, query_max(p << 1 | 1, mid + 1, r, ql, qr));
    return res;
}
// 求最小值：max → min，初始值改为 0x3f3f3f3f
```

## 树状数组 (Fenwick Tree / BIT)

> 比线段树更轻量，仅支持**单点加 + 前缀和**（可通过差分扩展为区间加）。代码量少、常数极小。

```cpp
ll tr[N]; // 树状数组，下标从 1 开始

int lowbit(int x) { return x & -x; }

// 单点加：a[pos] += val
void add(int pos, ll val, int n) {
    for (; pos <= n; pos += lowbit(pos))
        tr[pos] += val;
}

// 前缀和：a[1] + ... + a[pos]
ll sum(int pos) {
    ll res = 0;
    for (; pos > 0; pos -= lowbit(pos))
        res += tr[pos];
    return res;
}

// 区间查询 [l, r]
ll query(int l, int r) { return sum(r) - sum(l - 1); }
```
> **注意**：树状数组天然支持单点修改 + 区间求和。若需区间修改 + 单点查询，对差分数组建 BIT；若需区间修改 + 区间查询，维护两个 BIT。

## ST 表（静态 RMQ）
```cpp
int f[N][20], Log2[N];
void init_st(int a[], int n) {
    Log2[0] = -1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = a[i];
        Log2[i] = Log2[i >> 1] + 1;
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
int query_st(int l, int r) {
    int k = Log2[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
```

## 字符串哈希

> 将字符串映射为一个整数（哈希值），从而在 $O(1)$ 内判断两个子串是否相等。  
> **常用场景**：判断子串相等、最长公共前缀(LCP)、回文串判定、字符串匹配（替代 KMP）。

```cpp
typedef unsigned long long ull;
const ull P = 131;          // 基数，也可用 13331
ull h[N], p[N];             // h[i]: 前缀 s[1..i] 的哈希, p[i]: P^i

void init_hash(string& s, int n) {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + s[i - 1];  // 看作 P 进制数
        p[i] = p[i - 1] * P;
    }
}

// 子串 s[l..r] 的哈希值 (1-indexed)
ull get_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

// 判断两个子串是否相等
bool same(int l1, int r1, int l2, int r2) {
    return get_hash(l1, r1) == get_hash(l2, r2);
}

// 求两个后缀的最长公共前缀长度（二分 + 哈希）
int lcp(int a, int b) { // 后缀 a 和 b 的 LCP
    int l = 0, r = min(n - a + 1, n - b + 1);
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (get_hash(a, a + mid - 1) == get_hash(b, b + mid - 1))
            l = mid;
        else r = mid - 1;
    }
    return l;
}
```

> **注意**：单哈希可能被卡，必要时用双哈希（两对不同 P 和 MOD）或使用 `unsigned long long` 自然溢出（等效模 $2^{64}$）。

---

# 四、图论

## 最短路

### Dijkstra（堆优化，正权图，O(m log n)）
```cpp
vector<PII> g[N]; // {v, w}
int dist[N]; bool vis[N];
void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue; vis[u] = true;
        for (auto [v, w] : g[u])
            if (dist[v] > d + w)
                dist[v] = d + w, pq.push({dist[v], v});
    }
}
```

### BFS（无权图，O(n+m)）
```cpp
vector<int> g[N]; int dist[N];
void bfs(int s) {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u])
            if (dist[v] == -1)
                dist[v] = dist[u] + 1, q.push(v);
    }
}
```

### SPFA（可负权，判负环，O(km)）
```cpp
vector<PII> g[N];
int dist[N], cnt[N]; bool inq[N];
bool spfa(int s, int n) { // true=无负环
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    dist[s] = 0; q.push(s); inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return false;
                if (!inq[v]) q.push(v), inq[v] = true;
            }
        }
    }
    return true;
}
```

### Floyd（全源，O(n³)）
```cpp
for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
// 初始化：f[i][i]=0, 有边 f[u][v]=w, 其他 INF
```

## 拓扑排序（Kahn，O(n+m)）
```cpp
vector<int> g[N]; int in[N];
vector<int> topo_sort(int n) {
    vector<int> res; queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.pb(u);
        for (int v : g[u])
            if (--in[v] == 0) q.push(v);
    }
    return res; // size() < n 则有环
}
```

## 倍增求 LCA
```cpp
vector<int> g[N]; int dep[N], fa[N][20];
void dfs(int u, int father) {
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; (1 << i) <= dep[u]; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : g[u])
        if (v != father) dfs(v, u);
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = 0; d; i++, d >>= 1)
        if (d & 1) u = fa[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
// 树上第 k 祖先：for(i=0;k;i++,k>>=1) if(k&1) u=fa[u][i];
```

## Kruskal 最小生成树（O(m log m)）
```cpp
struct Edge { int u, v, w; } e[M]; // M 为边数
bool cmp(Edge a, Edge b) { return a.w < b.w; }

ll kruskal(int n, int m) { // 返回 MST 总权值，不连通返回 -1
    sort(e + 1, e + 1 + m, cmp);
    // 并查集初始化：for i=1..n: fa[i]=i
    ll res = 0; int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int u = find(e[i].u), v = find(e[i].v);
        if (u != v) {
            fa[u] = v;
            res += e[i].w;
            if (++cnt == n - 1) return res;
        }
    }
    return -1; // 不连通
}
```

---

# 五、动态规划

## 背包 DP

> `dp[i][j]` 表示前 i 件物品、容量为 j 时的最大价值。

### 01 背包（每件物品最多选一次）
```cpp
// 二维原版：dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i])
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];                       // 不选第 i 件
        if (j >= w[i])
            dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); // 选第 i 件
    }
// 答案：dp[n][m]
```
```cpp
// 优化版（一维，倒序）：dp[j] 等价于 dp[i-1][j]，倒序防止物品被重复选
for (int i = 1; i <= n; i++)
    for (int j = m; j >= w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
```

### 完全背包（每件物品无限次）
```cpp
// 二维原版：dp[i][j] = max(dp[i-1][j], dp[i][j - w[i]] + v[i])
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];                       // 不选第 i 件
        if (j >= w[i])
            dp[i][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]); // 选第 i 件（还可再选）
    }
// 答案：dp[n][m]
```
```cpp
// 优化版（一维，正序）：正序让 dp[j-w[i]] 已包含本轮更新，等价于 dp[i][j-w[i]]
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= m; j++)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
```

### 多重背包（第 i 件最多 s[i] 次）
```cpp
// 朴素二维：枚举选 k 件
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        for (int k = 0; k <= s[i] && k * w[i] <= j; k++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
```
```cpp
// 优化版：二进制拆分 → 01 背包（一维倒序）
for (int i = 1; i <= n; i++) {
    int vv = v[i], ww = w[i], k = s[i];
    for (int t = 1; t <= k; t <<= 1) {
        for (int j = m; j >= t * ww; j--)
            dp[j] = max(dp[j], dp[j - t * ww] + t * vv);
        k -= t;
    }
    if (k) for (int j = m; j >= k * ww; j--)
        dp[j] = max(dp[j], dp[j - k * ww] + k * vv);
}
```

---

## 矩阵快速幂（线性递推加速）

> 属于 **DP 优化**。完整版（动态矩阵 / k 维状态 / 不取模变形 / 踩坑清单）
> → `../DP/dp_optimization/matrix_pow/Matrix_Pow_Template.cpp`

**适用前提（缺一不可）**：转移是**线性**的（无 min/max、无乘法项）、系数与 $n$ **无关**、阶数 $k$ **固定**。

```cpp
const ll MOD = 1e9 + 7;      // 题面有则改

template <int K>
struct Mat {
    ll a[K][K];
    explicit Mat(bool I = false) {
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++) a[i][j] = 0;
        if (I) for (int i = 0; i < K; i++) a[i][i] = 1;
    }
    Mat operator*(const Mat& o) const {
        Mat r;
        for (int i = 0; i < K; i++)
            for (int t = 0; t < K; t++) {
                if (!a[i][t]) continue;                        // 稀疏剪枝
                for (int j = 0; j < K; j++)
                    r.a[i][j] = (r.a[i][j] + a[i][t] * o.a[t][j]) % MOD;
            }
        return r;
    }
};

template <int K>
Mat<K> mat_qpow(Mat<K> b, ll e) {
    Mat<K> r(true);             // ★ 单位矩阵，不是全 0
    while (e) { if (e & 1) r = r * b; b = b * b; e >>= 1; }
    return r;
}

// 1 维 k 阶：f[n] = c[0]*f[n-1] + ... + c[k-1]*f[n-k]，初值 f[1..k] = init[0..k-1]
template <int K>
ll linear_recurrence(array<ll, K> c, array<ll, K> init, ll n) {
    if (n <= K) return init[n - 1] % MOD;                             // ★ 边界必判
    Mat<K> A;
    for (int j = 0; j < K; j++) A.a[0][j] = (c[j] % MOD + MOD) % MOD; // 第 0 行 = 系数照抄
    for (int i = 1; i < K; i++) A.a[i][i - 1] = 1;                    // 第 i 行 = 上一行右移一格
    A = mat_qpow(A, n - K);                                           // ★ 指数是 n-K
    ll ans = 0;
    for (int i = 0; i < K; i++) ans = (ans + A.a[0][i] * init[K - 1 - i]) % MOD;
    return ans;                     // A^(n-K) 第 0 行 · [f[k], f[k-1], ..., f[1]]ᵀ
}
```

**构造口诀**：第 0 行照抄递推系数，第 1 行起每行把上一行右移一格。

| 坑 | 正确做法 |
|----|----------|
| 快速幂起点写成全 0 | 必须是**单位矩阵** |
| 忘判 `n <= k` | 直接返回初值，否则下标越界 |
| 指数写成 `n` / `n-1` | 用状态向量 $S_k$ 时为 `n - k`（换初值要同步改） |
| 行/列向量混用 | 本模板是**列向量** $S_n = A S_{n-1}$；改行向量要转置 |
| 模数 ≥ $10^{10}$ 还用 ll 相乘 | 用 `__int128` 中转 |

> $n \le 10^6$、$k \le 3$ 时**别上矩阵**——$\log n \cdot k^3$ 常数比直接递推还大。

