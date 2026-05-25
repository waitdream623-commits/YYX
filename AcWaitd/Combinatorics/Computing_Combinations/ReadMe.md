# 求解组合数方法

## 基础知识

| 公式 | 说明 |
|------|------|
| $\displaystyle C_n^m = \frac{n!}{m!(n-m)!}$ | 阶乘定义 |
| $\displaystyle C_n^m = \frac{n \times (n-1) \times \dots \times (n-m+1)}{m \times (m-1) \times \dots \times 1}$ | 展开形式 |
| $\displaystyle C_n^m = C_n^{\,n-m}$ | 对称性（$0 \le m \le n$） |

### 特殊情况

- $A_n^0 = C_n^0 = 1$，$0! = 1$
- $C_n^1 = C_n^{\,n-1} = n$
- 当 $m > n$ 时，$A_n^m = C_n^m = 0$

### 二项式定理

$$(a+b)^n = \sum_{k=0}^{n} C_n^k \, a^{\,n-k} \, b^{\,k}$$

**示例**：$(a+b)^3 = C_3^0 a^3 + C_3^1 a^2 b + C_3^2 a b^2 + C_3^3 b^3$

### 常用组合恒等式

| 恒等式 | 说明 |
|--------|------|
| $C_n^m = C_{n-1}^{m} + C_{n-1}^{m-1}$ | 递推公式（杨辉三角） |
| $\displaystyle\sum_{k=0}^{n} C_n^k = 2^n$ | 二项式系数和 |
| $\displaystyle\sum_{k=0}^{n} (-1)^k C_n^k = 0$ | 交错和 |
| $\displaystyle\sum_{k\text{ 偶}} C_n^k = \sum_{k\text{ 奇}} C_n^k = 2^{n-1}$ | 奇偶项和 |
| $C_n^k \cdot C_k^m = C_n^m \cdot C_{n-m}^{\,k-m}\;(k \ge m)$ | 组合积公式 |

---

## 方式一：循环

### 适用条件
- **类型**：求单个组合数
- **复杂度**：$O(m)$，利用对称性可降至 $O(\min(m, n-m))$
- **场景**：$m$ 很小，$n$ 特别大；或无法预处理时
- **注意**：要求 $p > n$（$p$ 为模数）。若 $p \le n$，分子或分母可能含 $p$ 的倍数导致取模后为 $0$，分母的逆元不存在。此时应使用 Lucas 定理（方式四）

### 原理
直接按定义式计算分子 $\prod_{i=n-m+1}^{n} i$ 与分母 $m!$，并用费马小定理（$p$ 为质数）求逆元。

### 代码
~~~cpp
ll qpow(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

ll get_c(ll n, ll m, ll p) {
    if (m > n || m < 0) return 0;
    m = min(m, n - m);
    ll up = 1, down = 1;
    for (ll i = n - m + 1; i <= n; i++) up = up * (i % p) % p;
    for (ll i = 2; i <= m; i++) down = down * (i % p) % p;
    return up * qpow(down, p - 2, p) % p;
}
~~~

---

## 方式二：杨辉三角（递推）

### 适用条件
- **类型**：预处理所有 $C_n^m$，多次查询
- **复杂度**：$O(n^2)$ 预处理，$O(1)$ 查询
- **场景**：$n$ 较小（通常 $n \le 10^4$），需大量查询
- **注意**：仅用加法，无需模逆元

### 原理
$$C_n^m = C_{n-1}^{m} + C_{n-1}^{m-1}$$

边界：$C_n^0 = C_n^n = 1$

### 代码
~~~cpp
const int N = 10010;
const int MOD = 1e9 + 7;
int f[N][N];

void init(ll n,ll p)
{
    for(int i=0;i<=n;i++)
    {
        f[i][0]=1;//填每一行起始位置，j从1开始，防止越界，i=0;不会进入循环
        for(int j=1;j<=i;j++)
        {
            f[i][j]=(f[i-1][j]+f[i-1][j-1])%p;
        }
    }
}
// 查询: C[n][m]
~~~

---

## 方式三：预处理阶乘 + 逆元

### 适用条件
- **类型**：预处理后 $O(1)$ 查询
- **复杂度**：$O(n)$ 预处理，$O(1)$ 查询
- **场景**：$n$ 较大（通常 $n \le 10^6$ 或 $10^7$），模数 $p$ 为质数且大于n
- **注意**：需预处理阶乘及阶乘逆元

### 原理
$$C_n^m \equiv \frac{n!}{m!(n-m)!} \pmod p = fact[n] \times inv\_fact[m] \times inv\_fact[n-m] \pmod p$$

利用费马小定理 $a^{p-2} \equiv a^{-1} \pmod p$（$p$ 为质数）求逆元。
 inv_fact[i] = inv_fact[i + 1] * (i + 1)。
### 代码
~~~cpp
const int N = 1000010;
const int MOD = 1e9 + 7;
ll fact[N], inv_fact[N];

ll qpow(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = qpow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)//倒着推导
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll get_c(ll n, ll m, ll p) {
    if (m > n || m < 0) return 0;
    return fact[n] * inv_fact[m] % p * inv_fact[n - m] % p;
}
~~~

---

## 方式四：卢卡斯定理（Lucas）

### 适用条件
- **类型**：$n, m$ 极大时的组合数取模
- **复杂度**：$O(p \log_p n)$,$O(p+\log_pn)$
- **场景**：$n, m \le 10^{18}$，模数 $p$ 为较小质数（$p \le 10^5$）当p可能<n只能使用此
- **注意**：
  - $p$ 必须为质数；内部调用方式一（循环）求小组合数
  - 也可使用方案三优化，先求出c(0~p-1)，时间复杂度$O(p)$,总体$O(p+\log_pn)$

### 原理
将 $n, m$ 写成 $p$ 进制形式：
$$n = n_k p^k + \dots + n_1 p + n_0$$
$$m = m_k p^k + \dots + m_1 p + m_0$$

则：
$$C_n^m \equiv \prod_{i=0}^{k} C_{n_i}^{m_i} \pmod p$$

递归形式：
$$C_n^m \equiv C_{\lfloor n/p \rfloor}^{\lfloor m/p \rfloor} \times C_{n \bmod p}^{m \bmod p} \pmod p$$

### 代码
~~~cpp
ll qpow(ll a, ll b, ll p) { /* 同方式一 */ }

ll get_c_small(ll n, ll m, ll p) {
    if (m > n) return 0;
    m = min(m, n - m);
    ll up = 1, down = 1;
    for (ll i = n - m + 1; i <= n; i++) up = up * (i % p) % p;
    for (ll i = 2; i <= m; i++) down = down * (i % p) % p;
    return up * qpow(down, p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return lucas(n / p, m / p, p) * get_c_small(n % p, m % p, p) % p;
}
//方式二
const int N = 1000010;//0~p-1
ll fact[N], inv_fact[N];

ll qpow(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % p;
    inv_fact[n] = qpow(fact[n], p - 2, p);
    for (int i = n - 1; i >= 0; i--)//倒着推导
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % p;
}
ll get_v(ll n,ll m,ll p)
{
     if (m > n || m < 0) return 0;
    return fact[n]*inv_fact[n-m]%p*inv_fact[m]%p;
}
ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return lucas(n / p, m / p, p) * get_c(n % p, m % p, p) % p;
}
~~~

---

## 方法对比总结

| 方法 | 预处理 | 单次查询 | 适用 $n$ 范围 | 模数要求 | 适用场景 |
|------|--------|----------|---------------|----------|----------|
| **方式一：循环** | 无 | $O(\min(m,n{-}m))$ | $n$ 任意（$m$ 小） | $p$ 为质数 | 求单个组合数，$m$ 很小 |
| **方式二：杨辉三角** | $O(n^2)$ | $O(1)$ | $n \le 10^4$ | 无（纯整数/取模均可） | 小范围大量查询 |
| **方式三：阶乘+逆元** | $O(n)$ | $O(1)$ | $n \le 10^6$ | $p$ 为质数 | 中大规模 $O(1)$ 查询 |
| **方式四：卢卡斯定理** | 无 | $O(p \log_p n)$(方案一) $O(p+\log_pn)$(方案三)| $n,m \le 10^{18}$ | $p$ 为小质数（$\le 10^5$）<n时必须采用此 | $n,m$ 极大，$p$ 较小 |

- 注意n与m与p互质，如果不是，可能导致取模变为零，采用卢卡斯定理