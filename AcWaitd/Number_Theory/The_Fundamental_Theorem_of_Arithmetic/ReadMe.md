## 分解质因数

### 算术基本定理
任意大于 1 的正整数 $n$ 可唯一分解为：
$$n = p_1^{\alpha_1} \cdot p_2^{\alpha_2} \cdot \ldots \cdot p_k^{\alpha_k}$$
其中 $p_1 < p_2 < \cdots < p_k$ 为质数，$\alpha_i \ge 1$。

### 对于阶乘分解质因数
**公式推导**：$n!$ 中质因子 $p$ 的个数为：
$$v_p(n!) = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \cdots = \sum_{k=1}^{\infty} \left\lfloor \frac{n}{p^k} \right\rfloor$$

**直观理解（以 $n=10,\ p=2$ 为例）**：
$$
v_2(10!) = \left\lfloor \frac{10}{2} \right\rfloor + \left\lfloor \frac{10}{4} \right\rfloor + \left\lfloor \frac{10}{8} \right\rfloor = 5 + 2 + 1 = 8
$$
- $10/2=5$：$1\sim10$ 中每个 2 的倍数贡献一个因子 2
- $10/4=2$：$4=2^2$ 需要再筛一次（第二个因子 2），$8=2^3$ 同理
- $10/8=1$：$8=2^3$ 还有第三个因子 2

> 即每个数中的 $p$ 因子被逐次剥离，$n/p$ 去掉第一个 $p$，$n/p^2$ 去掉第二个 $p$，以此类推。

两种做法：
- 对每个数单独分解质因数
- 对每个质数 $p$，统计 $1\sim n$ 中 $p$ 的倍数、$p^2$ 的倍数……

---

## 约数个数与约数之和

设 $n = p_1^{\alpha_1} p_2^{\alpha_2} \cdots p_k^{\alpha_k}$（标准分解式）。

### 约数个数公式
$$d(n) = (\alpha_1 + 1)(\alpha_2 + 1) \cdots (\alpha_k + 1) = \prod_{i=1}^{k} (\alpha_i + 1)$$

**推导**：$n$ 的任意约数 $d$ 形如 $d = p_1^{\beta_1} p_2^{\beta_2} \cdots p_k^{\beta_k}$，其中 $0 \le \beta_i \le \alpha_i$。每个 $\beta_i$ 有 $(\alpha_i + 1)$ 种选择，乘法原理即得。

### 约数之和公式
$$\sigma(n) = \frac{p_1^{\alpha_1+1} - 1}{p_1 - 1} \cdot \frac{p_2^{\alpha_2+1} - 1}{p_2 - 1} \cdots \frac{p_k^{\alpha_k+1} - 1}{p_k - 1} = \prod_{i=1}^{k} \frac{p_i^{\alpha_i+1} - 1}{p_i - 1}$$

**推导**：将 $(1 + p_i + p_i^2 + \cdots + p_i^{\alpha_i})$ 展开相乘，每一项对应一个约数。由等比数列求和得 $\frac{p_i^{\alpha_i+1}-1}{p_i-1}$。

### 注意
- 约数总是成对出现：若 $d \mid n$，则 $\frac{n}{d} \mid n$；当 $d \ne \frac{n}{d}$ 时视为两个不同约数
- 整数 $n$ 的约数个数上限为 $2\sqrt{n}$（因为每个 $\le \sqrt{n}$ 的约数对应一个 $\ge \sqrt{n}$ 的约数）
- **试除法**：复杂度 $O(\sqrt{n})$，适合单独求一个数的约数
- **倍数法**：枚举 $i$ 从 $1$ 到 $n$，将 $i$ 加入其所有倍数 $i, 2i, 3i, \ldots$ 的约数列表中，复杂度 $O(n \log n)$，适合批量求 $1\sim n$ 所有数的约数

---

## 求解约数个数和（$1\sim n$ 所有数的约数个数之和）

$$\sum_{i=1}^{n} d(i) = \sum_{i=1}^{n} \left\lfloor \frac{n}{i} \right\rfloor$$

**推导**：$1\sim n$ 中 $i$ 的倍数有 $\lfloor n/i \rfloor$ 个。每个数 $j$ 的约数个数等于 $j$ 是多少个数的倍数。交换求和顺序：
$$\sum_{j=1}^{n} d(j) = \sum_{j=1}^{n} \sum_{i \mid j} 1 = \sum_{i=1}^{n} \sum_{j=1,\, i\mid j}^{n} 1 = \sum_{i=1}^{n} \left\lfloor \frac{n}{i} \right\rfloor$$
可用整除分块（数论分块）在 $O(\sqrt{n})$ 内求解。

## 欧拉函数

**定义**：$\varphi(n)$ 表示 $1\sim n$ 中与 $n$ 互质的数的个数。

**计算公式**：设 $n = p_1^{\alpha_1} p_2^{\alpha_2} \cdots p_k^{\alpha_k}$，则：
$$\varphi(n) = n \cdot \prod_{i=1}^{k} \left(1 - \frac{1}{p_i}\right) = n \cdot \frac{p_1-1}{p_1} \cdot \frac{p_2-1}{p_2} \cdots \frac{p_k-1}{p_k}$$

**性质**：
- 若 $p$ 为质数，则 $\varphi(p) = p-1$，$\varphi(p^k) = p^k - p^{k-1}$
- $\varphi$ 是积性函数：若 $\gcd(a, b)=1$，则 $\varphi(ab) = \varphi(a) \cdot \varphi(b)$
- $\sum_{d \mid n} \varphi(d) = n$

### 试除法求单个 $\varphi(n)$（$O(\sqrt{n})$）
~~~cpp
ll getphi(int x) {
    ll ret = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret = ret / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ret = ret / x * (x - 1);
    return ret;
}
~~~

### 线性筛求 $1\sim n$ 所有 $\varphi(i)$（$O(n)$）
~~~cpp
void getphi(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            phi[i] = i - 1;
            p[++cnt] = i;
        }
        for (int j = 1; 1ll * i * p[j] <= n; j++) {
            int x = i * p[j];
            st[x] = true;
            if (i % p[j] == 0) {
                phi[x] = p[j] * phi[i];  // p[j] 已在 i 中出现
                break;
            } else {
                phi[x] = phi[p[j]] * phi[i]; // 积性
            }
        }
    }
}
~~~

### 线性筛推导说明
- 当 $i \bmod p_j = 0$：$p_j$ 是 $i$ 的最小质因子，$\varphi(i \cdot p_j) = p_j \cdot \varphi(i)$
- 当 $i \bmod p_j \ne 0$：$p_j$ 与 $i$ 互质，由积性 $\varphi(i \cdot p_j) = \varphi(p_j) \cdot \varphi(i) = (p_j-1) \cdot \varphi(i)$

---

## 欧拉定理与扩展

### 欧拉定理
若 $\gcd(a, m) = 1$，则：
$$a^{\varphi(m)} \equiv 1 \pmod{m}$$

### 费马小定理（欧拉定理特例，$m$ 为质数 $p$）
$$a^{p-1} \equiv 1 \pmod{p}$$

### 扩展欧拉定理（欧拉降幂）
用于处理指数极大的幂运算（如 $a^b \bmod m$）：

$$
a^b \equiv
\begin{cases}
a^{b \bmod \varphi(m)} \pmod{m}, & \gcd(a, m) = 1 \\[6pt]
a^b \pmod{m}, & \gcd(a, m) \ne 1,\ b < \varphi(m) \\[6pt]
a^{(b \bmod \varphi(m)) + \varphi(m)} \pmod{m}, & \gcd(a, m) \ne 1,\ b \ge \varphi(m)
\end{cases}
$$

> 简记：$b \ge \varphi(m)$ 时，$a^b \equiv a^{b \bmod \varphi(m) + \varphi(m)} \pmod{m}$

**应用**：指数过大时（如指数以幂塔形式给出），配合秦九韶算法逐位读取指数并取模。例题：P5091（模板）、P4139（上帝与集合的正确用法）。

---

## 求逆元

### 方法一：快速幂（费马小定理）
- **条件**：$\gcd(a, p) = 1$ 且 $p$ 为质数
- **公式**：$a^{-1} \equiv a^{p-2} \pmod{p}$
- 使用快速幂 $O(\log p)$ 求解，例题：P11465、序列求和

### 方法二：扩展欧几里得
- **条件**：$\gcd(a, m) = 1$（无需 $m$ 为质数）
- 求解 $ax + my = 1$，则 $x \bmod m$ 即为 $a$ 的逆元

### 方法三：线性递推（求 $1\sim n$ 所有逆元）
**递推公式推导**：

设模数为质数 $p$，对任意 $i \in [2, n]$，令 $p = k \cdot i + r$，其中 $k = \lfloor p/i \rfloor$，$r = p \bmod i$（$0 < r < i$）。

$$
\begin{aligned}
k \cdot i + r &\equiv 0 \pmod{p} \\
r &\equiv -k \cdot i \pmod{p}
\end{aligned}
$$

两边同乘 $i^{-1} \cdot r^{-1}$：

$$
\begin{aligned}
i^{-1} &\equiv -k \cdot r^{-1} \pmod{p} \\
i^{-1} &\equiv -\left\lfloor \frac{p}{i} \right\rfloor \cdot (p \bmod i)^{-1} \pmod{p}
\end{aligned}
$$

取正数表达（保证结果非负）：
$$\text{inv}[i] = p - \left\lfloor \frac{p}{i} \right\rfloor \cdot \text{inv}[p \bmod i] \bmod p$$

~~~cpp
inv[1] = 1;
for (int i = 2; i <= n; i++) {
    inv[i] = p - (p / i) * inv[p % i] % p;
}
~~~
时间复杂度 $O(n)$，例题：P3811。

---

## 扩展欧几里得定理

### 问题描述
求不定方程 $ax + by = \gcd(a, b)$ 的一组整数解 $(x, y)$。例题：P5656（求二元一次方程的通解）。

### 算法推导

**核心递推**：由欧几里得算法 $\gcd(a, b) = \gcd(b, a \bmod b)$，假设已知子问题的一组解：

$$b \cdot x' + (a \bmod b) \cdot y' = \gcd(b, a \bmod b) = \gcd(a, b)$$

将 $a \bmod b = a - \left\lfloor \frac{a}{b} \right\rfloor \cdot b$ 代入：

$$
\begin{aligned}
b \cdot x' + \left(a - \left\lfloor \frac{a}{b} \right\rfloor \cdot b\right) \cdot y' &= \gcd(a, b) \\
a \cdot y' + b \cdot \left(x' - \left\lfloor \frac{a}{b} \right\rfloor \cdot y'\right) &= \gcd(a, b)
\end{aligned}
$$

与 $ax + by = \gcd(a, b)$ 对比系数得：

$$
\boxed{x = y',\quad y = x' - \left\lfloor \frac{a}{b} \right\rfloor \cdot y'}
$$

**递归边界**：当 $b = 0$ 时，$\gcd(a, 0) = a$，此时 $a \cdot 1 + 0 \cdot 0 = a$，即 $x = 1,\ y = 0$。

### 通解形式
若 $(x_0, y_0)$ 是 $ax + by = \gcd(a, b)$ 的一组特解，则通解为：
$$
\begin{cases}
x = x_0 + \dfrac{b}{\gcd(a, b)} \cdot t \\[8pt]
y = y_0 - \dfrac{a}{\gcd(a, b)} \cdot t
\end{cases}
\quad (t \in \mathbb{Z})
$$

对于 $ax + by = c$（$c$ 是 $\gcd(a, b)$ 的倍数），将特解乘以 $\dfrac{c}{\gcd(a, b)}$ 即可。

### 代码实现
~~~cpp
// 返回 gcd(a, b)，同时求出 x, y 使得 ax + by = gcd(a, b)
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x); // 注意 x, y 位置交换
    y -= a / b * x;               // y = x' - (a/b) * y'
    return d;
}
~~~

**注意**：递归调用时 `exgcd(b, a%b, y, x)`，传参顺序为 `(y, x)`——这是因为回溯时 $x \gets y'$，而 $y'$ 是上一层递归的 $y$（此处实参为 $x$），利用了引用传参的交换技巧。

---

### 两种求最小正整数解的方法

**问题**：求 $ax + by = c$ 的所有正整数解（$x > 0,\ y > 0$），或求最小/最大的 $x, y$。例题：P5656。

设已由 exgcd 得到缩放后的特解 $(x_0, y_0)$，令 $dx = \dfrac{b}{\gcd(a, b)},\ dy = \dfrac{a}{\gcd(a, b)}$。

---

#### 方法一：取模调整（求最小正 x）

> 直接算出第一个 $x \ge 1$ 的通解参数 $t$，简单直观。

$$
\begin{aligned}
x &= x_0 + dx \cdot t \\
\text{令 } x &\in [1, dx] \text{，则 } t = \left\lceil \frac{1 - x_0}{dx} \right\rceil
\end{aligned}
$$

用取模实现更简洁（免去 ceil）：

```cpp
ll dx = b / g, dy = a / g;
x0 *= c / g, y0 *= c / g;

// 把 x0 调整到 [0, dx) 范围
ll t = (x0 % dx + dx) % dx;
x0 -= t * dx;
y0 += t * dy;

// 确保 x ≥ 1
if (x0 <= 0) x0 += dx, y0 -= dy;
// 此时若 y0 ≤ 0 则无正整数解
```

---

#### 方法二：不等式区间（求 t 的范围）

> 同时约束 $x>0$ 和 $y>0$，得到 $t$ 的上下界。

由通解 $x = x_0 + dx \cdot t,\ y = y_0 - dy \cdot t$：

$$
\begin{cases}
x > 0 \implies t > -\dfrac{x_0}{dx} \implies t \ge \left\lceil \dfrac{-x_0 + 1}{dx} \right\rceil = k_1 \\[8pt]
y > 0 \implies t < \dfrac{y_0}{dy} \implies t \le \left\lfloor \dfrac{y_0 - 1}{dy} \right\rfloor = k_2
\end{cases}
$$

若 $k_1 \le k_2$，则解的个数为 $k_2 - k_1 + 1$；
- $t = k_1$ 时 $x$ 最小、$y$ 最大
- $t = k_2$ 时 $x$ 最大、$y$ 最小

```cpp
ll dx = b / g, dy = a / g;
x0 *= c / g, y0 *= c / g;

// ⚠️ 必须转 double，否则整数除法先向零取整
ll k1 = ceil( (double)(-x0 + 1) / dx );
ll k2 = floor((double)( y0 - 1) / dy );

if (k1 > k2) 无解;
else {
    cnt = k2 - k1 + 1;
    x_min = x0 + dx * k1;  y_max = y0 - dy * k1;
    x_max = x0 + dx * k2;  y_min = y0 - dy * k2;
}
```

> **常见错误**：`ceil(-x+1)/dx` 中 `-x+1` 和 `dx` 均为整数，C++ 先做整数除法（向零取整），`ceil`/`floor` 完全失效。必须 `(double)` 强转！
