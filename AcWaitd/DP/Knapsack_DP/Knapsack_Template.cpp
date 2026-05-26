/**
 * 背包 DP 模板合集
 * 
 * 核心思想：dp[i][j] = 前 i 个物品，背包容量为 j 时的最优解
 * 优化：滚动数组（倒序枚举 j 实现 01 背包，正序枚举实现完全背包）
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. 01 背包（每个物品最多选 1 次）
// ==============================
// 倒序枚举 j，保证每个物品只用一次
int knapsack01(int n, int W, vector<int>& w, vector<int>& v) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {  // 倒序！
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[W];
}

// ==============================
// 2. 完全背包（每个物品可选无限次）
// ==============================
// 正序枚举 j，允许同物品多次使用
int knapsackComplete(int n, int W, vector<int>& w, vector<int>& v) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = w[i]; j <= W; j++) {  // 正序！
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[W];
}

// ==============================
// 3. 多重背包（每个物品有 cnt[i] 个）
// ==============================
// 方法一：二进制拆分 → 转化为 01 背包
int knapsackMultiple(int n, int W, vector<int>& w, vector<int>& v, vector<int>& cnt) {
    vector<int> nw, nv;
    for (int i = 0; i < n; i++) {
        int k = 1;
        while (k <= cnt[i]) {
            nw.push_back(w[i] * k);
            nv.push_back(v[i] * k);
            cnt[i] -= k;
            k <<= 1;
        }
        if (cnt[i] > 0) {
            nw.push_back(w[i] * cnt[i]);
            nv.push_back(v[i] * cnt[i]);
        }
    }
    return knapsack01(nw.size(), W, nw, nv);
}

// ==============================
// 4. 分组背包（每组最多选 1 个物品）
// ==============================
// 枚举组 → 枚举容量（倒序）→ 枚举组内物品
int knapsackGroup(int W, vector<vector<pair<int,int>>>& groups) {
    vector<int> dp(W + 1, 0);
    for (auto& g : groups) {
        for (int j = W; j >= 0; j--) {  // 倒序！
            for (auto& [w, v] : g) {
                if (j >= w) dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    return dp[W];
}

// ==============================
// 5. 方案数 / 计数背包
// ==============================
// 求恰好装满背包的方案数
int knapsackCount(int n, int W, vector<int>& w) {
    vector<long long> dp(W + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {  // 01 版本倒序
            dp[j] += dp[j - w[i]];
        }
    }
    return dp[W];
}
