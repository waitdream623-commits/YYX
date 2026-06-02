#include <bits/stdc++.h>
using namespace std;

int INF = 0x3f3f3f3f;
int c[210][210];
int p[1100];
int f[2][210][210]; // 空间降维：从 194MB 优化至 0.35MB

void solve() {
    int n, m; 
    if (!(cin >> n >> m)) return;

    // 读入代价矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    
    // 读入请求序列
    p[0] = 3; // 初始第三个员工在 3
    for (int i = 1; i <= m; i++) cin >> p[i];

    // 初始化滚动数组
    memset(f, 0x3f, sizeof f);
    f[0][1][2] = 0; // 0时刻，另外两个员工在 1 和 2

    for (int i = 0; i < m; i++) { // 关键修复：只枚举到 m-1
        int cur = i & 1;
        int next = (i + 1) & 1;
        
        // 极其重要：由于是滚动数组，转移前必须把下一层清空为 INF（防旧数据污染）
        memset(f[next], 0x3f, sizeof f[next]);

        int p_curr = p[i];     // 当前请求位置（即第三个员工所在位置）
        int p_next = p[i + 1]; // 下一个请求目标位置

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (f[cur][j][k] == INF) continue; // 过滤无效状态

                //核心拦截：当前三人的位置必须两两互不相同
                if (j == k || j == p_curr || k == p_curr) continue;

                // 【决策 1】在 p_curr 的员工前往 p_next
                // 留下的员工在 j 和 k。他们都不能与新位置 p_next 重合！
                if (j != p_next && k != p_next) {
                    f[next][j][k] = min(f[next][j][k], f[cur][j][k] + c[p_curr][p_next]);
                }

                // 【决策 2】在 k 的员工前往 p_next
                // 留下的员工在 j 和 p_curr。他们都不能与新位置 p_next 重合！
                if (j != p_next && p_curr != p_next) {
                    f[next][j][p_curr] = min(f[next][j][p_curr], f[cur][j][k] + c[k][p_next]);
                }

                // 【决策 3】在 j 的员工前往 p_next
                // 留下的员工在 p_curr 和 k。他们都不能与新位置 p_next 重合！
                if (p_curr != p_next && k != p_next) {
                    f[next][p_curr][k] = min(f[next][p_curr][k], f[cur][j][k] + c[j][p_next]);
                }
            }
        }
    }

    // 在最终完成第 m 个请求的层中统计最优解
    int ans = INF;
    int last = m & 1;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            ans = min(ans, f[last][j][k]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T; // 根据题目实际多测情况决定
    while (T--) {
        solve();
    }
    return 0;
}