#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void wait() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));

    auto dfs = [&](auto&& dfs, int l, int r) -> int {
        if (l > r) return 0;
        if (l == r) return 1;

        int& ans = memo[l][r];
        if (ans != -1) return ans;

        ans = r - l + 1;
        if ((s[l] == '(' && s[r] == ')') ||
            (s[l] == '[' && s[r] == ']')) {
            ans = dfs(dfs, l + 1, r - 1);
        }

        for (int k = l; k < r; ++k) {
            ans = min(ans, dfs(dfs, l, k) + dfs(dfs, k + 1, r));
        }
        return ans;
    };

    cout << dfs(dfs, 0, n - 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    const int n = static_cast<int>(s.size());
    // dp[l][r] 是补齐闭区间 [l, r] 的最少插入次数。空区间为 0。
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        // 合法括号串的长度必须是偶数。
        const int lowerBound = len % 2;//理论最小值
        for (int l = 0; l + len <= n; ++l) {
            const int r = l + len - 1;
            int best = len;

            if ((s[l] == '(' && s[r] == ')') ||
                (s[l] == '[' && s[r] == ']')) {
                best = dp[l + 1][r - 1];
            }

            for (int k = l; k < r && best > lowerBound; ++k) {//提前终止
                best = min(best, dp[l][k] + dp[k + 1][r]);
            }
            dp[l][r] = best;
        }
    }

    cout << dp[0][n - 1] << '\n';
}
