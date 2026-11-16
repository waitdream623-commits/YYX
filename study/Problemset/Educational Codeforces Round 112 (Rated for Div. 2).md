# Educational Codeforces Round 112 (Rated for Div. 2) · 1555

2026-11-16 VP 复盘。[比赛](https://codeforces.com/contest/1555)

## 完成情况与赛时卡点

| 题目 | 截图提交时间（北京时间） | 提交编号 | 结果与赛时思路 |
| --- | --- | --- | --- |
| A · PizzaForces | 11-16 18:41 | [398766007](https://codeforces.com/contest/1555/submission/398766007) | AC |
| B · Two Tables | 11-16 19:03 | [398767822](https://codeforces.com/contest/1555/submission/398767822) | AC |
| C · Coin Rows | 未见提交 | — | 考虑两个人的位置组成状态，存储过大；本地保留 dfs(x1,y1,x2) 的未完成草稿 |
| D · Say No to Palindromes | 未见提交 | — | 考虑区间 DP，使每个长度的子串都非回文，状态及复杂度过大 |

用户反馈 VP 已结束，截图确认 A/B 通过。截图时间是绝对提交时间，没有比赛开始时间，不能据此推算解题用时。C/D 以下为赛后 AI 辅助推导，尚未独立补题 AC；本次不改动未完成的源码。

## C · 路径由下移位置唯一决定

[官方题面](https://codeforces.com/contest/1555/problem/C)

只有两行，只能向右、向下走，因此每个人必定且只能下移一次。先不保存两个人的完整位置状态，而是固定 Alice 在第 k 列下移。

Alice 会拿走上排 1..k 和下排 k..m 的金币。剩余金币分成两段：上排 k+1..m 与下排 1..k-1。

Bob 也只能下移一次：

- 若在第 k 列及之前下移，只能拿下排剩余段的一部分；第 1 列下移可拿完整下排剩余段。
- 若在第 k 列及之后下移，只能拿上排剩余段的一部分；第 m 列下移可拿完整上排剩余段。
- 不可能两段都拿：想拿上排右侧就必须晚下移，想拿下排左侧则必须早下移。

金币为正数，所以 Bob 的最优回应是完整拿走两段中较大的一段：

$$
score(k)=\max\left(\sum_{j=k+1}^m a_{1,j},\sum_{j=1}^{k-1}a_{2,j}\right).
$$

Alice 再枚举 k，取最小 score。原本的两个人位置状态，缩减为一个下移列；固定先手后，后手的最优回应可以直接算出。

```cpp
void solve() {
    int m;
    cin >> m;
    vector<long long> top(m), bottom(m);
    long long upper = 0, lower = 0;
    for (auto &v : top) { cin >> v; upper += v; }
    for (auto &v : bottom) cin >> v;
    long long ans = LLONG_MAX;
    for (int k = 0; k < m; ++k) {
        upper -= top[k]; // 上排 k 右侧，不包含 k
        ans = min(ans, max(upper, lower));
        lower += bottom[k]; // 下一轮才计入下排 k
    }
    cout << ans << '\n';
}
```

时间 O(m)，空间 O(m)。边界 k=1 时下排剩余和为 0，k=m 时上排剩余和为 0；m=1 时答案 0。更新 lower 必须放在计算当前候选之后。

## D · 排除长回文，可以先排除中心的短回文

[官方题面](https://codeforces.com/contest/1555/problem/D)

每个询问要求把指定子串改成不包含任何长度至少为 2 的回文子串的字符串，字母只有 a、b、c。

不要逐个区间长度处理。任何长度至少为 4 的偶数回文，中心都有长度 2 的回文；任何长度至少为 5 的奇数回文，中心都有长度 3 的回文。因此只需要确保：

$$
t_i\ne t_{i+1},\qquad t_i\ne t_{i+2}.
$$

只有三个字母，每个新字符必须与前两个字符都不同，因此前两个字母确定后，之后的字符都被唯一确定。合法字符串只能是这六种周期串的片段：

```text
abcabc...
acbacb...
bacbac...
bcabca...
cabcab...
cbacba...
```

对每种模式 p，预处理原字符串与模式不匹配的前缀计数 pre[p][i]。询问 [l,r] 改成该模式的代价就是 pre[p][r]-pre[p][l-1]，六种取最小值。

不用在每个询问中重新按 l 对齐模式：六个全局模式已经包含所有排列及相位。长度 1、2 的子串也覆盖在这六种模式中。

```cpp
void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<vector<int>> pre(6, vector<int>(n + 1));
    string p = "abc";
    int id = 0;
    do {
        for (int i = 1; i <= n; ++i)
            pre[id][i] = pre[id][i - 1]
                       + (s[i - 1] != p[(i - 1) % 3]);//全部改为这个排列需要代价
        ++id;
    } while (next_permutation(p.begin(), p.end()));
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = r - l + 1;
        for (int k = 0; k < 6; ++k)
            ans = min(ans, pre[k][r] - pre[k][l - 1]);
        cout << ans << '\n';
    }
}
```

预处理 O(6n)，查询共 O(6q)，空间 O(6n)。n=200000 时前缀表大约 4.8 MB，不必保存 O(n²) 的区间状态。

## 本场复做重点

两题的共同卡点：先进入通用 DP 状态设计，没有先利用题目限制缩小方案空间。C 的“两行”让路径只剩一个决策点；D 的“三种字母 + 无短回文”让目标只剩六种模式。

- 先补 C：独立画出固定 k 后的剩余金币，证明 Bob 不能同时拿两段，再实现 O(m)。
- 再补 D：独立证明长回文必含中心短回文，再推出三周期，最后写六种前缀计数。
- 本次讲解后写出的代码记作辅助补题；以后闭卷复做通过，才补充独立复做记录。
