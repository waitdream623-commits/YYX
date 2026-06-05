# 树形 DP

## 核心模式：DFS 后序遍历

```cpp
void dfs(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        // 用子节点的 dp 值更新当前节点
    }
}
```

## 三大模型

### 1. 最大独立集（P1352 没有上司的舞会）
- `dp[u][0]` = 不选 u，子树最大值
- `dp[u][1]` = 选 u，子树最大值
- 转移：`dp[u][0] += max(dp[v][0], dp[v][1])`，`dp[u][1] += dp[v][0]`
- 答案：`max(dp[root][0], dp[root][1])`

### 2. 树形背包（P2014 选课）
- 先选父才能选子
- `dp[u][j]` = 子树 u 选 j 门
- 倒序枚举容量，类似 01 背包

### 3. 树的直径（最长路径）
```cpp
int ans = 0;
int dfs(int u, int fa) {
    int d1 = 0, d2 = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;//不走回头路
        int d = dfs(v, u) + 1;
        if (d > d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    ans = max(ans, d1 + d2);
    return d1;
}
```

## 题单

### 基础（2题）

| 题号 | 题目 | 模型 | 难度 |
|------|------|------|------|
| P1352 | 没有上司的舞会 | 最大独立集 | ⭐⭐ |
| P1122 | 最大子树和 | 基础树形 DP | ⭐⭐ |

### 进阶（6题）

| 题号 | 题目 | 模型 | 难度 |
|------|------|------|------|
| P2016 | 战略游戏 | 最小点覆盖 | ⭐⭐⭐ |
| P2899 | [USACO08JAN] Cell Phone Network | 最小支配集 | ⭐⭐⭐ |
| P4084 | [USACO17DEC] Barn Painting | 树上染色 | ⭐⭐⭐ |
| P1131 | [ZJOI2007] 时态同步 | 贪心+树形 DP | ⭐⭐⭐ |
| P3047 | [USACO12FEB] Nearby Cows | 换根 DP | ⭐⭐⭐ |
| P3574 | [POI2014] FAR-FarmCraft | 树上排序+DP | ⭐⭐⭐⭐ |

### 难题（2题）

| 题号 | 题目 | 模型 | 难度 |
|------|------|------|------|
| P2387 | [JSOI2010] LUK-Triumphal arch | 二分+树形 DP | ⭐⭐⭐⭐ |
| P2014 | 选课 | 树形背包 | ⭐⭐⭐ |
