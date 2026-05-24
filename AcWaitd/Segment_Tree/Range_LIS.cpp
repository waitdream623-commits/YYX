#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

// ================================================================
// 区间最长上升子序列（LIS，不连续，可跳着选）
// 如 [1,5,3,4,8] 可选出 [1,3,4,8]
// 每次查询 O(k log k)，k = r-l+1
//
// 注：通用 [l,r] LIS 查询没有简单 O(log n) 做法，
//     若 n,q ≤ 5000 用本做法；若 n,q ≤ 1e5 且查询为
//     [1,R] 形式，可用离线 BIT 做到 O((n+q) log n)。
// ================================================================

int a[N];

// ==================== LIS 的 DP 思想 ====================
//
// ▎阶段一：O(n²) 基础 DP
//
//   定义 dp[i] = 以第 i 个元素结尾的最长上升子序列长度
//
//   转移方程：
//     dp[i] = max( dp[j] + 1 )   对所有 j < i 且 a[j] < a[i]
//     （如果没有这样的 j，dp[i] = 1）
//
//   最终答案 = max(dp[1..n])
//
//   示例：a = [2, 1, 5, 3, 4]
//     i=1, a=2: dp[1]=1                       [2]
//     i=2, a=1: 前面没有 <1 的 → dp[2]=1       [1]
//     i=3, a=5: j=1(2<5)→dp=2; j=2(1<5)→dp=2
//               dp[3]=max(2,2)=2               [1,5] 或 [2,5]
//     i=4, a=3: j=2(1<3)→dp=2 → dp[4]=2       [1,3]
//     i=5, a=4: j=2(1<4)→dp=2; j=4(3<4)→dp=3
//               dp[5]=3                         [1,3,4]
//     答案 = 3
//
//   O(n²) 瓶颈：每个 i 都要扫描前面所有 j，太慢。
//
// ▎阶段二：O(n log n) 优化 — patience sorting（耐心排序）
//
//   核心洞察：我们关心的不是"以谁结尾"，而是——
//     "长度为 L 的上升子序列，最小的末尾值是多少？"
//
//   定义 tails[L] = 长度为 L 的上升子序列的 **最小可能末尾值**
//
//   tails 数组始终 **单调递增**（反证：若 tails[3] ≥ tails[4]，
//   则长度为4的子序列去掉最后一个元素得到的长度为3的子序列
//   末尾值 < tails[4] ≤ tails[3]，矛盾）
//
//   遍历每个 x = a[i]：
//     在 tails 中二分查找第一个 ≥ x 的位置 pos
//     （即找到"末尾值 ≥ x 的最短子序列"）
//
//     如果 pos 不存在（x 比所有 tails 都大）：
//       → x 可以接在任何子序列后面，形成更长的子序列
//       → tails.push_back(x)
//
//     如果 pos 存在：
//       → 用 x 替换 tails[pos]，因为 x ≤ tails[pos]，
//         等长的子序列有了更小的末尾值，对未来更有利
//
//   最终 LIS 长度 = tails.size()
//
// ▎图解 patience sorting
//
//   a = [2, 1, 5, 3, 4, 8, 2]
//
//   x=2: tails=[] → pos不存在 → tails=[2]
//   x=1: tails=[2] → pos=0(tails[0]=2≥1) → 替换 → tails=[1]
//        （长度为1的子序列末尾从2优化到1）
//   x=5: tails=[1] → pos不存在(1<5) → tails=[1,5]
//        （5接在1后面，形成长度2的子序列 [1,5]）
//   x=3: tails=[1,5] → pos=1(tails[1]=5≥3) → 替换 → tails=[1,3]
//        （长度2的子序列末尾从5优化到3：[1,3] 比 [1,5] 更好）
//   x=4: tails=[1,3] → pos不存在(3<4) → tails=[1,3,4]
//        （4接在3后面：[1,3,4] 长度3）
//   x=8: tails=[1,3,4] → pos不存在(4<8) → tails=[1,3,4,8]
//        （8接在4后面：[1,3,4,8] 长度4）
//   x=2: tails=[1,3,4,8] → pos=1(tails[1]=3≥2) → 替换 → tails=[1,2,4,8]
//        （长度2的子序列末尾从3优化到2）
//
//   最终 tails.size() = 4 ✓
//
//   ⚠️ 注意：tails 数组本身 **不一定是** 真实的 LIS 序列！
//   它只是维护"各长度的最小末尾值"。要还原具体序列需额外记录。
// ================================================================

// patience sorting：O(m log m) 求 LIS 长度
int lis(vector<int>& arr) {
    vector<int> tails;  // tails[L] = 长度 L+1 的上升子序列的最小末尾值
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else                   *it = x;
    }
    return tails.size();
}

int query_lis(int l, int r) {
    vector<int> sub(r - l + 1);
    for (int i = l; i <= r; i++) sub[i - l] = a[i];
    return lis(sub);
}

// ============================ 样例 ============================
/*
输入：
7 3
2 1 5 3 4 8 2
1 7
3 6
2 5
输出：
4
4
3
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query_lis(l, r) << '\n';
    }
    return 0;
}
