# Codeforces Round 1133 (Div. 2)

整理日期：2026-11-08。按本地 A–D 源码和 CPH 用例整理。样例通过记为本地验证，线上提交结果待补。[比赛页面](https://codeforces.com/contest/2280)

| 题目 | 本地源码 | 当前进度 |
| --- | --- | --- |
| [A. Are They the Same?](https://codeforces.com/contest/2280/problem/A) | [A.cpp](<../../AcWaitd/Contest/Codeforces Round 1133 (Div. 2)/A_Are_They_the_Same.cpp>) | 按 `k` 的奇偶比较两组的偶数个数，本地 CPH 样例通过 |
| [B. Secret String Patterns](https://codeforces.com/contest/2280/problem/B) | [B.cpp](<../../AcWaitd/Contest/Codeforces Round 1133 (Div. 2)/B_Secret_String_Patterns.cpp>) | 交互草稿，查询和答案分支待补 |
| [C. Reverse and Double](https://codeforces.com/contest/2280/problem/C) | [C.cpp](<../../AcWaitd/Contest/Codeforces Round 1133 (Div. 2)/C_Reverse_and_Double.cpp>) | 枚举相邻差的草稿，尚未输出答案 |
| [D. Balanced Subsets](https://codeforces.com/contest/2280/problem/D) | [D.cpp](<../../AcWaitd/Contest/Codeforces Round 1133 (Div. 2)/D_Balanced_Subsets.cpp>) | 讨论后写出状压记忆化，本地 CPH 样例通过，滚动递推待回做 |

## D · 从稳定性随选择变化想到状压

先前的组合数做法按原集合把元素分成稳定与不稳定两类。用 `A={1,2,3,4}` 就能看出问题。全选时 `1` 看见三个邻居，在 `{1,3,4}` 中它只看见两个，稳定性会随选择变化。

对任意至少选两个数的子集，最大的两个数一定不稳定。因此从大到小扫时，前两次可以直接选，后面每次再选都要求当前数稳定。`mask` 记录 `x+1、x+2、x+3` 是否被选，`cnt` 记录右侧已选数量，达到 `2` 后保持为 `2`。两个状态都需要。例如处理 `x=5` 时，`{6}` 和 `{6,10}` 的 `mask` 相同，但只有前者允许再选 `5`。

不选时下一个掩码为 `(mask << 1) & 7`，选时再把最低位置 `1`。原集合缺失的值只能走不选。按数组下标扫描也可行，掩码需要按相邻元素的**数值差**移动。汇总后减掉空集。

本地记忆化版本在样例得到 `14 66 23 1`。数值上限可达 `600000`，递归逐值向下会有深栈风险。提交版可用 `dp[8][3]` 和 `ndp[8][3]` 滚动，时间复杂度为 `O(n)`，DP 额外空间为 `O(1)`。

## 回做

- [ ] D 闭卷写滚动递推。自测 `{1,2,3,4}`、只有一个数以及中间有缺口的集合。
- [ ] B 先补齐交互读写。当前读入的是 `a[1]`，随后判断的 `x` 没有初始化。查询要在读取回答前换行并刷新。
- [ ] C 先补推导，再检查相邻差的范围。当前循环会读取 `a[n+1]`，后续还有 `a[k+2]`，需要结合端点情况处理。
