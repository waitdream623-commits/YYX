# 网格 Flood Fill — 训练记录

## 已刷题目

| 题号 | 题目 | 核心技巧 | 状态 |
|------|------|----------|------|
| P1434 | [SHOI2002] 滑雪 | 记忆化 DFS：`if(f[x][y]) return f[x][y]`，天然单向不回溯 | ✅ |

---

## 记忆化 DFS 核心框架

```cpp
int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];   // 算过就直接返回
    int best = 1;                   // 至少包含自己
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (越界 || 不满足条件) continue;
        best = max(best, dfs(nx, ny) + 1);
    }
    return f[x][y] = best;
}
```

**关键区别**：记忆化搜索不需要 `st` 数组，因为：

- 单向移动（高度严格递减）→ 不可能走回头路 → 天然 DAG
- `f[x][y]` 非零即表示已计算完成 → 相当于访问标记
