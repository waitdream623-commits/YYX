# 搜索 (Search)

> 📋 训练计划 → `templates/search-plan.md`
> 📝 模板代码 → `Search_Template.cpp`

## 目录结构

```
Search/
├── dfs_backtracking/     ← DFS 回溯（全排列、组合、N皇后）
├── grid_floodfill/       ← 网格搜索（连通块、记忆化）
├── bfs_shortest/         ← BFS 最短路（无权图、多源BFS）
├── bfs_state/            ← BFS 状态搜索（八数码）
├── search_advanced/      ← 进阶（IDDFS、A*，大二）
├── Search_Template.cpp   ← 模板代码
└── ReadMe.md             ← 本文件
```

---

## 搜索完整知识图谱

```
搜索 (Search)
├── 🟢 1. DFS 回溯基础          ← dfs_backtracking/
│   ├── 全排列（vis + 回溯）
│   ├── 组合（start 参数去重）
│   ├── 子集（选/不选二叉树）
│   └── N皇后（对角线剪枝）
│
├── 🟢 2. 网格搜索 Flood Fill   ← grid_floodfill/
│   ├── 连通块计数（四方向/八方向）
│   ├── 包围区域（边界染色）
│   ├── 记忆化搜索（滑雪）
│   └── 岛屿/细胞计数
│
├── 🟡 3. BFS 最短路            ← bfs_shortest/
│   ├── 无权图最短路径（dist 数组）
│   ├── 分层 BFS（按层处理）
│   ├── 多源 BFS（多个起点同时扩散）
│   └── 0-1 BFS（deque，边权 0 或 1）
│
├── 🟡 4. 状态搜索              ← bfs_state/
│   ├── 八数码（字符串编码 + BFS）
│   ├── 华容道 / 推箱子
│   └── 双向 BFS（起点终点同时搜）
│
└── 🔴 5. 搜索优化（进阶）      ← search_advanced/（大二再碰）
    ├── 剪枝（可行性、最优性）
    ├── 迭代加深 DFS (IDDFS)
    ├── 折半搜索 (Meet in the Middle)
    └── A* / IDA*（启发式搜索）
```

### 学习优先级

| 优先级 | 板块 | 蓝桥杯 | ICPC | 建议时间 |
|--------|------|--------|------|----------|
| 🔥🔥🔥 | DFS 回溯 | 填空主力 | 基础 | 大一 |
| 🔥🔥🔥 | Flood Fill | 编程常考 | 基础 | 大一 |
| 🔥🔥🔥 | BFS 最短路 | 编程常考 | 基础 | 大一 |
| 🔥🔥 | 状态搜索 | 偶尔考 | 常考 | 大一暑假 |
| 🔥 | 搜索优化 | 不考 | 常考 | 大二 |

---

## DFS/BFS 核心区分

| | DFS | BFS |
|---|-----|-----|
| 数据结构 | 递归（隐式栈） | queue |
| 适用 | 求所有解、连通块 | 求最短路径/最少步数 |
| 空间 | O(深度)，通常较小 | O(广度)，可能很大 |
| 剪枝 | 可以提前 return | 难以剪枝 |
| 蓝桥填空 | ⭐⭐⭐ 主力 | ⭐ 偶尔用 |
| 蓝桥编程 | ⭐⭐ 连通块 | ⭐⭐⭐ 最短路 |

---

## 核心模板速查

### DFS 回溯 — 全排列
```cpp
vis[i]=1; path.push_back(i); dfs();
path.pop_back(); vis[i]=0;          // 回溯！忘了就死循环
```

### DFS 回溯 — 组合（升序去重）
```cpp
void dfs(int start) {
    for(int i=start; i<=n; i++) {
        comb.push_back(i);
        dfs(i+1);                   // i+1 保证不重复
        comb.pop_back();
    }
}
```

### 网格四方向
```cpp
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
```

### 记忆化 DFS
```cpp
if (memo[x][y] != -1) return memo[x][y];
int best = 1;
for (int d=0; d<4; d++) {
    int nx=x+dx[d], ny=y+dy[d];
    if (边界/障碍) continue;
    best = max(best, 1 + dfs(nx, ny));
}
return memo[x][y] = best;
```

### BFS 最短路
```cpp
queue<State> q; q.push({sx, sy, 0});
vis[sx][sy] = true;
while (!q.empty()) {
    auto [x, y, step] = q.front(); q.pop();
    if (x == tx && y == ty) return step;
    for (int d=0; d<4; d++) {
        int nx=x+dx[d], ny=y+dy[d];
        if (边界||vis||障碍) continue;
        vis[nx][ny] = true;
        q.push({nx, ny, step+1});
    }
}
```

### BFS 状态搜索（八数码）
```cpp
unordered_map<string, int> dist;
queue<string> q;
q.push(start); dist[start] = 0;
while (!q.empty()) {
    string s = q.front(); q.pop();
    int pos = s.find('0');
    int x=pos/3, y=pos%3;
    for (int d=0; d<4; d++) {
        int nx=x+dx[d], ny=y+dy[d];
        if (nx<0||nx>=3||ny<0||ny>=3) continue;
        string ns = s;
        swap(ns[pos], ns[nx*3+ny]);
        if (!dist.count(ns)) {
            dist[ns] = dist[s] + 1;
            q.push(ns);
        }
    }
}
```

---

## 搜索题调试技巧

```
1. BFS 先在小数据上打印队列状态，确认扩散方向
2. DFS 回溯题先写 3x3 小样例验证
3. 网格题：边界条件最容易错，多加一句 assert
4. 记忆化搜索：先把递归写对，再加 memo
5. 状态搜索：确认状态编码唯一，不会冲突
```

---

## 当前进度

| 板块 | 状态 |
|------|------|
| DFS 回溯基础 | 🔜 5/27 进行中 |
| 网格 Flood Fill | ⬜ |
| BFS 最短路+状态 | ⬜ |
| 搜索进阶 | ⬜（大二） |
