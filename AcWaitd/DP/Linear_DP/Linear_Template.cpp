/**
 * 线性 DP 模板合集
 * 
 * 核心思想：状态沿一维线性推进，常见模式：
 *   dp[i] = 以 i 结尾的最优解
 *   dp[i] = max/min(dp[i-1] + a[i], a[i])  ← 状态转移
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. 最大子段和
// ==============================
// dp[i] = max(dp[i-1] + a[i], a[i])
int maxSubarray(vector<int>& a) {
    int n = a.size();
    int cur = a[0], ans = a[0];
    for (int i = 1; i < n; i++) {
        cur = max(cur + a[i], a[i]);
        ans = max(ans, cur);
    }
    return ans;
}

// ==============================
// 2. 最长上升子序列 LIS（O(n²)）
// ==============================
// dp[i] = 以 a[i] 结尾的 LIS 长度
// dp[i] = max(dp[j] + 1)  for j < i, a[j] < a[i]
int lis_n2(vector<int>& a) {
    int n = a.size(), ans = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// ==============================
// 3. 最长上升子序列 LIS（O(n log n) 贪心+二分）
// ==============================
// d[k] = 长度为 k 的 LIS 的最小末尾值
int lis_nlogn(vector<int>& a) {
    vector<int> d;
    for (int x : a) {
        auto it = lower_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}

// ==============================
// 4. 最长公共子序列 LCS（O(n²)）
// ==============================
// dp[i][j] = a[1..i] 与 b[1..j] 的 LCS 长度
int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// ==============================
// 5. 编辑距离（Levenshtein）
// ==============================
// dp[i][j] = a 的前 i 个字符 → b 的前 j 个字符的最小操作次数
int editDistance(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }
    return dp[n][m];
}

// ==============================
// 6. 最长不下降子序列（非严格上升）
// ==============================
int lnds_nlogn(vector<int>& a) {
    vector<int> d;
    for (int x : a) {
        auto it = upper_bound(d.begin(), d.end(), x);  // 用 upper_bound！
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}
