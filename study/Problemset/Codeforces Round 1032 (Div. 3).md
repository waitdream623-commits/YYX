# Codeforces Round 1032 (Div. 3)

2026-11-07 · VP · 截图中 **A–D 共 4 题 AC，6 次提交，2 次 WA**。提交记录以截图为准，思路从当前本地源码整理。

![ChatGPT Image 2026年11月7日 13_51_19](./assets/ChatGPT%20Image%202026%E5%B9%B411%E6%9C%887%E6%97%A5%2013_51_19.jpg)

| 题目与本地源码 | 通过时间（页面显示） | 记录 |
| --- | --- | --- |
| [A. Letter Home](<../../AcWaitd/Contest/Codeforces Round 1032 (Div. 3)/A_Letter_Home.cpp>) | [00:04:42](https://codeforces.com/contest/2121/submission/397676901) | 一次 AC |
| [B. Above the Clouds](<../../AcWaitd/Contest/Codeforces Round 1032 (Div. 3)/B_Above_the_Clouds.cpp>) | [00:19:33](https://codeforces.com/contest/2121/submission/397677591) | [00:13:52，WA on test 1](https://codeforces.com/contest/2121/submission/397677342) |
| [C. Those Who Are With Us](<../../AcWaitd/Contest/Codeforces Round 1032 (Div. 3)/C_Those_Who_Are_With_Us.cpp>) | [01:33:59](https://codeforces.com/contest/2121/submission/397681346) | [01:14:13，WA on test 2](https://codeforces.com/contest/2121/submission/397680253) |
| [D. 1709](<../../AcWaitd/Contest/Codeforces Round 1032 (Div. 3)/D_1709.cpp>) | [02:00:43](https://codeforces.com/contest/2121/submission/397682996) | 一次 AC |
| [E. Sponsor of Your Problems](<../../AcWaitd/Contest/Codeforces Round 1032 (Div. 3)/E_Sponsor_of_Your_Problems.cpp>) | — | 本地有草稿，截图无提交记录## 复盘 |

- **A**：必须到达两个端点。先到较近的端点，再走完整段距离。
- **B**：只枚举内部位置作为中间串，检查该字符是否还在别处出现。自测 `aab`、`abb`、`aba`，分别检查重复发生在左端、右端、仅在两个端点的情况。首次 WA 的实际原因待核对。
- **C**：B 到 C 的通过时间相隔 **74 分 26 秒**，C 从 WA 到 AC 间隔 **19 分 46 秒**。闭卷回做时，把原最大值的位置当成点，先写清一行一列覆盖的点数 `row[i] + col[j] - (a[i][j] == mx)`。再用反对角线最大值的 `2×2` 矩阵检查交点和并列选择，减少分情况。首次 WA 的实际原因待核对。
- **D**：两行先分别用相邻交换排好序，每列再把较小值放在上方。逐列取 `min` 和 `max` 后，两行仍严格递增，因为交换前两行都严格递增。

## 下次回做

- [ ] C 闭卷重写，先写覆盖条件，再实现。
- [ ] E 独立补题。卡住时记录第一次遇到不同数位后，当前前缀是否仍贴着某个边界。
