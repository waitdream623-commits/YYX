/**
 * 区间 DP 模板合集
 * 
 * 核心思想：dp[l][r] = 区间 [l, r] 上的最优解
 * 枚举模式：
 *   1. 枚举区间长度 len（从小到大）
 *   2. 枚举左端点 l
 *   3. 计算右端点 r = l + len - 1
 *   4. 枚举分割点 k（l <= k < r）
 * 
 * 常见题型：石子合并、矩阵链乘、回文子序列、涂色问题
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. 石子合并（相邻合并，求最小/最大代价）
// ==============================
// dp[l][r] = 合并 [l,r] 的最小代价
// dp[l][r] = min(dp[l][k] + dp[k+1][r]) + sum[l..r]   for k in [l, r-1]
int stoneMerge(vector<int>& a) {
    int n = a.size();
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i-1];
    auto getSum = [&](int l, int r) { return sum[r] - sum[l-1]; };
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    
    for (int len = 2; len <= n; len++) {           // 枚举长度
        for (int l = 1; l + len - 1 <= n; l++) {   // 枚举左端点
            int r = l + len - 1;
            for (int k = l; k < r; k++) {           // 枚举分割点
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + getSum(l, r));
            }
        }
    }
    return dp[1][n];
}

// ==============================
// 2. 石子合并（环形 → 拆环成链，复制一倍）
// ==============================
int stoneMergeCircle(vector<int>& a) {
    int n = a.size();
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n; i++) b[i] = a[i % n];
    
    vector<int> sum(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i-1] + b[i-1];
    auto getSum = [&](int l, int r) { return sum[r] - sum[l-1]; };
    
    vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1, INT_MAX / 2));
    for (int i = 1; i <= 2 * n; i++) dp[i][i] = 0;
    
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + getSum(l, r));
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[i][i + n - 1]);
    return ans;
}

// ==============================
// 3. 矩阵链乘（最少乘法次数）
// ==============================
// dp[l][r] = min(dp[l][k] + dp[k+1][r] + p[l-1]*p[k]*p[r])
int matrixChain(vector<int>& p) {  // p 为维度数组，p[0..n]
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                int cost = dp[l][k] + dp[k+1][r] + p[l-1] * p[k] * p[r];
                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }
    return dp[1][n];
}

// ==============================
// 4. 最长回文子序列（区间 DP 版本）
// ==============================
// dp[l][r] = s[l..r] 中最长回文子序列长度
int longestPalindromeSubseq(string& s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (s[l-1] == s[r-1])
                dp[l][r] = dp[l+1][r-1] + 2;
            else
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
        }
    }
    return dp[1][n];
}
