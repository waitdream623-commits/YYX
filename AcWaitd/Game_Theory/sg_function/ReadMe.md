# SG 函数（Sprague-Grundy 函数）

## 核心概念

将博弈分解为若干个**独立子博弈**，每个子博弈的 SG 值定义为：

$$
SG(x) = \operatorname{mex}\{\,SG(y) \mid x \to y \,\}
$$

其中 $\operatorname{mex}$ 表示集合中**未出现的最小非负整数**。

**Sprague-Grundy 定理**：
$$
\text{整个博弈的 SG 值} = SG_1 \oplus SG_2 \oplus \cdots \oplus SG_n
$$
先手必败 $\iff$ 总 SG 值为 $0$。

## 解题步骤
- 求mex值，将子问题加入unordered_map,去重，再从0枚举，找未出现过的
1. **划分子博弈**：将游戏分解为若干个互不影响的独立部分
2. **计算每个子博弈的 SG 值**：从终态反向递推或 DFS + 记忆化
3. **异或合并**：总 SG 为 $0$ 则先手必败

## 常见 SG 打表模式

```cpp
int sg[N];
bool vis[N];
void get_sg(int n) {
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 1; j <= m && i - j >= 0; j++)  // 所有合法转移
            vis[sg[i - j]] = 1;
        for (int j = 0;; j++)
            if (!vis[j]) { sg[i] = j; break; }
    }
}
```

## 今日题单

| 题号 | 题目 | 关键点 |
|------|------|--------|
| — | 移棋子游戏 | SG 模板，DAG 上计算 SG |
| — | Cutting Game | 二维分割，子博弈异或 |
