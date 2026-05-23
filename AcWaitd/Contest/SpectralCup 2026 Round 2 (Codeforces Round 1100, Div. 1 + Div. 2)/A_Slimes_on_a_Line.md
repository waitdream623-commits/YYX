# A. Slimes on a Line

## 题意
有 `n` 个史莱姆在一条直线上，第 `i` 个在位置 `a_i`。每次操作选择一个整数 `x`，所有史莱姆向 `x` 方向移动一格（小于 `x` 则 +1，大于 `x` 则 -1，等于则不动）。求最少操作次数使所有史莱姆到达同一位置。

## 解题思路
- 每次操作选一个位于当前 `[min, max]` 之间的 `x`，则最小值 +1，最大值 -1，范围缩小 2。
- 因此答案为 **`ceil((max - min) / 2)`**，即 `(mx - mn + 1) / 2`。
- 只需扫描一遍找出最小值和最大值，无需去重，也无需计算平均值。

## 原代码错误分析

| 问题 | 说明 |
|------|------|
| **多测不清空 set** | 全局 `set<int> mp` 在每组测试后未清空，导致后续测试中 `pos` 可能为 0，触发 `ret / pos` **除零崩溃**，只输出一次结果。 |
| **算法错误** | 用**平均值**作为汇合点试探，但本题最优策略是缩小范围，答案为 `ceil((max-min)/2)`，与平均值无关。 |
| **只查两个候选点** | 即使以平均值为中心，最优汇合点也不一定在 `avg` 或 `avg+1` 上。 |
| **类型混杂** | `cnt` 为 `int`，但 `x - a[1]` 为 `ll`，存在隐式窄化风险。 |
| **多余去重** | 本题只关心全局最值，去重不改变结果但徒增复杂度。 |

## 正确代码
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int mn = 1001, mx = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        cout << (mx - mn + 1) / 2 << '\n';
    }
    return 0;
}
```
