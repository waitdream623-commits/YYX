/**
 * 搜索模板合集 — DFS + BFS
 * 
 * DFS 适用场景：全排列、组合、子集、棋盘、连通块、记忆化搜索
 * BFS 适用场景：最短路（无权图）、分层遍历、最少步数、状态搜索
 */

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 一、DFS 基础模板
// ============================================================

// 1.1 全排列（1~n 的所有排列）
int n;
vector<int> path;
vector<bool> vis;

void dfs_permutation() {
    if ((int)path.size() == n) {
        for (int x : path) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        path.push_back(i);
        dfs_permutation();
        path.pop_back();      // 回溯！
        vis[i] = false;       // 回溯！
    }
}

// 1.2 组合（从 1~n 中选 m 个数，升序去重）
int m;
vector<int> comb;

void dfs_combination(int start) {  // start 保证升序去重
    if ((int)comb.size() == m) {
        for (int x : comb) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i <= n; i++) {
        comb.push_back(i);
        dfs_combination(i + 1);    // i+1 保证不重复选
        comb.pop_back();
    }
}

// 1.3 子集（选或不选，2^n 种）
vector<int> subset;
void dfs_subset(int idx, vector<int>& a) {
    if (idx == (int)a.size()) {
        for (int x : subset) cout << x << " ";
        cout << "\n";
        return;
    }
    // 不选 a[idx]
    dfs_subset(idx + 1, a);
    // 选 a[idx]
    subset.push_back(a[idx]);
    dfs_subset(idx + 1, a);
    subset.pop_back();
}

// ============================================================
// 二、网格 DFS（连通块 / Flood Fill）
// ============================================================

int H, W;
vector<string> grid;
vector<vector<bool>> visited;

const int dx[4] = {0, 0, 1, -1};   // 四方向
const int dy[4] = {1, -1, 0, 0};

void dfs_grid(int x, int y) {
    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (visited[nx][ny] || grid[nx][ny] == '#') continue;  // # 是障碍
        dfs_grid(nx, ny);
    }
}

int count_components() {
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {  // . 是空地
                dfs_grid(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

// ============================================================
// 三、记忆化搜索（滑雪 P1434）
// ============================================================

vector<vector<int>> height, memo;
int H, W;

int dfs_ski(int x, int y) {
    if (memo[x][y] != -1) return memo[x][y];  // 记忆化
    int best = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (height[nx][ny] >= height[x][y]) continue;  // 只能往低处滑
        best = max(best, 1 + dfs_ski(nx, ny));
    }
    return memo[x][y] = best;
}

// ============================================================
// 四、BFS 基础模板（无权最短路 / 最少步数）
// ============================================================

// 4.1 网格 BFS（起点到终点的最短步数）
struct State {
    int x, y, step;
};

int bfs_grid(int sx, int sy, int tx, int ty) {
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    queue<State> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = true;
    
    while (!q.empty()) {
        auto [x, y, step] = q.front(); q.pop();
        if (x == tx && y == ty) return step;
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (vis[nx][ny] || grid[nx][ny] == '#') continue;
            vis[nx][ny] = true;
            q.push({nx, ny, step + 1});
        }
    }
    return -1;  // 不可达
}

// 4.2 BFS 分层遍历（每层统一处理）
void bfs_level_order(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int sz = q.size();           // 当前层的节点数
        for (int i = 0; i < sz; i++) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {  // 未访问
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        // 这里 dist 对应当前层数
    }
}

// ============================================================
// 五、BFS 状态搜索（八数码 / 华容道类）
// ============================================================

// 将状态编码为字符串，用 unordered_map 记录距离
int bfs_state(string start, string target) {
    if (start == target) return 0;
    unordered_map<string, int> dist;
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    
    // 定义状态转移（以八数码为例）
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        string s = q.front(); q.pop();
        int d = dist[s];
        int pos = s.find('0');       // 空格位置
        int x = pos / 3, y = pos % 3; // 3×3 网格
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            string ns = s;
            swap(ns[pos], ns[nx * 3 + ny]);
            if (dist.count(ns)) continue;
            if (ns == target) return d + 1;
            dist[ns] = d + 1;
            q.push(ns);
        }
    }
    return -1;
}

// ============================================================
// 六、DFS 剪枝技巧总结
// ============================================================
/*
 * 1. 可行性剪枝：当前状态已不可能到达目标 → return
 * 2. 最优性剪枝：当前代价已 ≥ 已知最优解 → return
 * 3. 搜索顺序优化：优先搜索分支少的节点（最小分支优先）
 * 4. 重复状态去重：哈希 / vis 数组
 * 5. 迭代加深 (IDDFS)：限制深度，逐层加深
 */

// ============================================================
// 七、DFS vs BFS 选择指南
// ============================================================
/*
 * 用 DFS 的情况：
 *   - 求所有方案（全排列、组合、子集）
 *   - 连通块 / Flood Fill
 *   - 树的前中后序遍历
 *   - 记忆化搜索（DP 的递归写法）
 *   - 回溯（八皇后、数独）
 *
 * 用 BFS 的情况：
 *   - 求最短路径 / 最少步数（无权图）
 *   - 分层遍历（树的层序遍历）
 *   - 状态空间搜索（八数码、魔方）
 *   - 扩散问题（腐烂的橘子、洪水填充最少时间）
 */
