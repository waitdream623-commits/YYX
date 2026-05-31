# 树状数组（Binary Indexed Tree / BIT）

## 核心操作（共 5 行代码）

```cpp
int n, tr[N];            // 1-indexed

void add(int x, int k) {                 // 单点加
    for (; x <= n; x += x & -x) tr[x] += k;
}

int sum(int x) {                         // 前缀和 [1, x]
    int s = 0;
    for (; x; x -= x & -x) s += tr[x];
    return s;
}

int range_sum(int l, int r) {            // 区间和 [l, r]
    return sum(r) - sum(l - 1);
}
```

## 与线段树对比

| | 树状数组 | 线段树 |
|--|---------|--------|
| 代码量 | 5 行 | 50+ 行 |
| 常数 | 极小 | 较大 |
| 可维护信息 | 和、积、异或等**可逆运算** | 和、max、min、GCD 等任意信息 |
| 区间修改 | 差分技巧实现 | 原生懒标记 |
| 适用场景 | 单点改+区间查、区间改+单点查 | 任意情况 |

## 应用

### P3374 单点修改 + 区间查询
```cpp
add(pos, val);               // 修改
cout << sum(r) - sum(l-1);   // 查询
```

### P3368 区间修改 + 单点查询（差分）
```cpp
// 用差分数组 d[i] = a[i] - a[i-1]
add(l, val);  add(r+1, -val);   // 区间 [l, r] 加 val
cout << sum(x);                  // 查询 a[x] = sum(d[1..x])
```

### P2184 贪婪大陆（起点+终点两个 BIT）
```cpp
add(bit_start, l, 1);    // 维护起点
add(bit_end, r, 1);      // 维护终点
cout << sum(bit_start, r) - sum(bit_end, l-1);  // 区间种数
```

## 原理（一句话）

`x & -x` 取最低位的 1，`tr[x]` 维护区间 `(x - lowbit(x), x]` 的信息。
