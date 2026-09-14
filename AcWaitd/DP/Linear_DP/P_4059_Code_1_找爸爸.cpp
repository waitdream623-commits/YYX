#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, m, n) for (int i = m; i <= n; ++i)

const int INF = 0x3f3f3f3f;
const int N = 3005;

// dp[i][j][0]: A[i] 与 B[j] 字符配对
// dp[i][j][1]: B 放空格，即 A[i] 与 '-' 配对 (来自 i-1, j)//j后面是空格，i位置一定是字符，所以往i-1找，j位置是空格，并没有用真实b中字符
// dp[i][j][2]: A 放空格，即 '-' 与 B[j] 配对 (来自 i, j-1)
int dp[N][N][3];
int d[5][5];

// 严格按照题目输入的顺序：A=1, T=2, G=3, C=4
int get_id(char c) {
    if (c == 'A') return 1;
    if (c == 'T') return 2;
    if (c == 'G') return 3;
    if (c == 'C') return 4;
    return 0;
}

void solve() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) return;

    rep(i, 1, 4) {
        rep(j, 1, 4) {
            cin >> d[i][j];
        }
    }

    int F, B; // F 为开辟代价 A，B 为延续代价 B
    cin >> F >> B;

    int n = s1.size();
    int m = s2.size();

    // 转为 1-based 下标，避免越界
    s1 = " " + s1;
    s2 = " " + s2;

    // 全局初始化为负无穷
    rep(i, 0, n) {
        rep(j, 0, m) {
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
        }
    }

    // 起点初始化
    dp[0][0][0] = 0;

    // 边界：第 0 行和第 0 列连续空格的代价
    rep(i, 1, n) {
        dp[i][0][1] = -F - (i - 1) * B;
    }
    rep(j, 1, m) {
        dp[0][j][2] = -F - (j - 1) * B;
    }

    // DP 递推
    rep(i, 1, n) {
        rep(j, 1, m) {
            int score = d[get_id(s1[i])][get_id(s2[j])];

            // 1. 状态 0：两字符配对，来自 (i-1, j-1) 的任意合法状态
            int prev0 = max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]});
            if (prev0 > -INF / 2) {
                dp[i][j][0] = prev0 + score;
            }

            // 2. 状态 1：B 放空格 (A 消耗字符，来自 i-1, j)
            // 延续只需 -B；新开辟需 -F
            int cont1 = dp[i - 1][j][1] - B;
            int open1 = max(dp[i - 1][j][0], dp[i - 1][j][2]) - F;
            dp[i][j][1] = max(cont1, open1);

            // 3. 状态 2：A 放空格 (B 消耗字符，来自 i, j-1)
            int cont2 = dp[i][j - 1][2] - B;
            int open2 = max(dp[i][j - 1][0], dp[i][j - 1][1]) - F;
            dp[i][j][2] = max(cont2, open2);
        }
    }

    // 统计最终三种形态的最大值
    int ans = max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}