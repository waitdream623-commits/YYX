# P5656 二元一次不定方程 (exgcd)

## 问题
求 $ax + by = c$ 的**正整数解**（$x > 0,\ y > 0$）：
- 无解输出 `-1`
- 有解输出：解的个数、最小 $x$、最小 $y$、最大 $x$、最大 $y$

---

## 核心推导

### 1. 扩展欧几里得求特解

先用 exgcd 求 $ax_0 + by_0 = \gcd(a, b)$ 的一组解 $(x_0, y_0)$。

若 $c \bmod \gcd(a, b) \ne 0$，则无解。

否则缩放得到 $ax + by = c$ 的特解：
$$x_0' = x_0 \cdot \frac{c}{g},\quad y_0' = y_0 \cdot \frac{c}{g}$$

### 2. 通解形式

令 $dx = \dfrac{b}{\gcd(a, b)},\quad dy = \dfrac{a}{\gcd(a, b)}$，则通解为：
$$\begin{cases} x = x_0' + dx \cdot t \\ y = y_0' - dy \cdot t \end{cases} \quad (t \in \mathbb{Z})$$

---

## 两种求最小正整数解的方法

### 方法一：取模调整（求最小非负 x）

> 利用通解的周期性，直接算出第一个 $x \ge 1$ 的 $t$。

```cpp
ll x0, y0, g = exgcd(a, b, x0, y0);
ll dx = b / g, dy = a / g;

// 缩放到 c
x0 *= c / g, y0 *= c / g;

// 把 x 调整到 [0, dx) 范围内（取模）
ll t = (x0 % dx + dx) % dx;  // x0 可能是负数
x0 -= t * dx;                // x0 变成最小非负
y0 += t * dy;                // y0 对应变化

// x0 可能为 0，需要向上再走一步
if (x0 <= 0) x0 += dx, y0 -= dy;
// 此时 x0 ≥ 1，若 y0 ≤ 0 则无正整数解
```

### 方法二：不等式区间（求 t 的范围）

> 用 $x>0$ 和 $y>0$ 夹出 $t$ 的取值范围。

```cpp
ll x0, y0, g = exgcd(a, b, x0, y0);
ll dx = b / g, dy = a / g;
x0 *= c / g, y0 *= c / g;

// x = x0 + dx·t > 0  →  t > -x0/dx
//   →  t ≥ ceil((-x0 + 1) / dx)   ⚠️ 必须转 double！
ll k1 = ceil( (double)(-x0 + 1) / dx );

// y = y0 - dy·t > 0  →  t < y0/dy
//   →  t ≤ floor((y0 - 1) / dy)   ⚠️ 必须转 double！
ll k2 = floor( (double)(y0 - 1) / dy );

if (k1 > k2) 无解;
else {
    解的个数 = k2 - k1 + 1;
    x_min = x0 + dx * k1;  y_max = y0 - dy * k1;
    x_max = x0 + dx * k2;  y_min = y0 - dy * k2;
}
```

---

## 错误分析

### 错误 1：exgcd 返回 1 而不是 gcd
`gcd` 返回值写成了 `1`，应返回 `a`（当 `b=0` 时）。

### 错误 2：ceil / floor 对整数除法失效 ⭐
```cpp
// ❌ 错误：整数除法先向零取整，ceil/floor 完全白写
ll k1 = ceil((-x + 1) / dx);   // (-x+1) 和 dx 都是整数，先做整数除法！

// ✅ 正确：强制转 double
ll k1 = ceil((double)(-x + 1) / dx);
ll k2 = floor((double)(y - 1) / dy);
```
> C++ 中两个整数相除先执行整数除法（向零取整），结果再传给 `ceil`/`floor`，此时已经是整数，函数成了摆设。