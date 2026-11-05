# 贪心与构造思维题单（CF为主）

整理日期：2026-11-04。目标：练习观察、找反例、证明贪心与设计构造；以 1200～1600 分为主，少量 1700 分选做。

源码目录：[AcWaitd/Thinking](../../AcWaitd/Thinking/)。已在比赛或专题目录做过的题直接链接原源码，不重复复制。

## 现成题单：推荐 CP-31

[CP-31 Sheet（TLE Eliminators）](https://www.tle-eliminators.com/cp-sheet)｜[作者在 Codeforces 的介绍](https://codeforces.com/blog/entry/139079?locale=en)

作者介绍：覆盖 800～1900 分，每个难度选 31 题，按难度而非知识点分组，强调可复用的思路。它是综合题单，适合作为长期题库；想集中练贪心、构造，可以先做下面的自选序列。

**下面 20+5 题是另行筛选的练习顺序，不代表 CP-31 的原始顺序或收录范围。**顺序是训练建议；题名、评分与标签已对照 [CF 官方题库 API](https://codeforces.com/api/problemset.problems) 的 2026-11-03 快照核对，评分以后可能变化。

## 第一轮：20 道主练题

按难度递进，同一难度内混合贪心与构造。先不看标签和题解，各题不写解法提示。第 20 题会用到堆，属于少量基础数据结构辅助的贪心。

### 起步：1200

#### 1. [1537C · Challenging Cliffs](https://codeforces.com/problemset/problem/1537/C)

难度：1200｜完成记录：—

**笔记：**

<br>

先排序，找一对最近点，放在两端，且不改变其余顺序。

但是对于 1 2 3 4 5，应该选择最右边，此时5还能提供一次上升，4， 1 ，2 ， 3， 5；

**反例：**

**找到差值最小的一对放在首尾，这一步对了；中间直接从小到大输出，会损失上升次数。**

反例：

```
1
4
1 4 5 9
```

你的代码输出：

```
4 1 9 5
```

首尾差为 `1`，但相邻满足“前一个 ≤ 后一个”的只有 `1 → 9`，共 **1 次**。

换成：

```
4 9 1 5
```

首尾差仍为 `1`，满足条件的有 `4 → 9`、`1 → 5`，共 **2 次**。

原因是你的输出可能在两处下降：

```
首元素 → 最小值
最大值 → 尾元素
```

**最终**

- 排序，找最近对 (k-1,k);
- $[k-1,k+2….n][1…k-2,k]$;尽可能保证上升

[代码](D:\c\code\yy\AcWaitd\Thinking\C_Challenging_Cliffs.cpp)

#### 2. [1355B · Young Explorers](https://codeforces.com/problemset/problem/1355/B)

难度：1200｜完成记录：—

**笔记：**

<br>

#### 3. [1497C1 · k-LCM (easy version)](https://codeforces.com/problemset/problem/1497/C1)

难度：1200｜完成记录：—

**笔记：**

<br>

#### 4. [1512D · Corrupted Array](https://codeforces.com/problemset/problem/1512/D)

难度：1200｜完成记录：—

**笔记：**

<br>

#### 5. [1559C · Mocha and Hiking](https://codeforces.com/problemset/problem/1559/C)

难度：1200｜完成记录：—

**笔记：**

<br>


### 建立证明意识：1300

#### 6. [1367C · Social Distance](https://codeforces.com/problemset/problem/1367/C)

难度：1300｜完成记录：—

**笔记：**

<br>

#### 7. [1607D · Blue-Red Permutation](https://codeforces.com/problemset/problem/1607/D)

难度：1300｜完成记录：—

**笔记：**

<br>

#### 8. [1753A1 · Make Nonzero Sum (easy version)](https://codeforces.com/problemset/problem/1753/A1)

难度：1300｜完成记录：—

**笔记：**

<br>

#### 9. [1768C · Elemental Decompress](https://codeforces.com/problemset/problem/1768/C)

难度：1300｜完成记录：—

**笔记：**

<br>


### 主练区：1400

#### 10. [1506D · Epic Transformation](https://codeforces.com/problemset/problem/1506/D)

难度：1400｜完成记录：—

**笔记：**

<br>

#### 11. [1380C · Create The Teams](https://codeforces.com/problemset/problem/1380/C)

难度：1400｜完成记录：—

**笔记：**

<br>

#### 12. [1691C · Sum of Substrings](https://codeforces.com/problemset/problem/1691/C)

难度：1400｜完成记录：—

**笔记：**

<br>

#### 13. [1515C · Phoenix and Towers](https://codeforces.com/problemset/problem/1515/C)

难度：1400｜完成记录：—

**笔记：**

<br>

#### 14. [1628A · Meximum Array](https://codeforces.com/problemset/problem/1628/A)

难度：1400｜完成记录：—

**笔记：**

<br>


### 加强：1500～1600

#### 15. [1368B · Codeforces Subsequences](https://codeforces.com/problemset/problem/1368/B)

难度：1500｜完成记录：—

**笔记：**

<br>

#### 16. [1630A · And Matching](https://codeforces.com/problemset/problem/1630/A)

难度：1500｜完成记录：—

**笔记：**

<br>

#### 17. [1622C · Set or Decrease](https://codeforces.com/problemset/problem/1622/C)

难度：1600｜完成记录：—

**笔记：**

<br>

#### 18. [1481C · Fence Painting](https://codeforces.com/problemset/problem/1481/C)

难度：1600｜完成记录：—

**笔记：**

<br>

#### 19. [1798D · Shocking Arrangement](https://codeforces.com/problemset/problem/1798/D)

难度：1600｜完成记录：—

**笔记：**

<br>

#### 20. [1526C2 · Potions (Hard Version)](https://codeforces.com/problemset/problem/1526/C2)

难度：1600｜完成记录：—

**笔记：**

<br>


## 第二轮：5 道选做题

主练题能较稳定独立完成后再做。树题需要会遍历，字符串题需要能处理字典序与字符计数。

### [1627C · Not Assigning](https://codeforces.com/problemset/problem/1627/C)

难度：1400｜备注：树上构造｜完成记录：—

**笔记：**

<br>

### [1530D · Secret Santa](https://codeforces.com/problemset/problem/1530/D)

难度：1600｜备注：排列构造｜完成记录：—

**笔记：**

<br>

### [1707A · Doremy's IQ](https://codeforces.com/problemset/problem/1707/A)

难度：1600｜备注：贪心与构造综合｜完成记录：—

**笔记：**

<br>

### [1474C · Array Destruction](https://codeforces.com/problemset/problem/1474/C)

难度：1700｜备注：进阶｜完成记录：—

**笔记：**

<br>

### [1799C · Double Lexicographically Minimum](https://codeforces.com/problemset/problem/1799/C)

难度：1700｜备注：字符串贪心｜完成记录：—

**笔记：**

<br>


## 怎么使用

- 先从前 6 题开始，不必一次给整份题单排日期。如果其中多数能独立完成，再继续向 1400 推进；若连续依赖提示，先回做卡住的题。
- 每题先独立思考约 30～45 分钟；有进展可以继续。卡住时只看一个提示，自己补证明和实现，暂不直接读完整代码。
- 写代码前说清楚：为什么这个选择不会吃亏？或者为什么构造必然合法、不会超过操作上限？找不出证明时先试小反例。
- 比赛或 VP 当天可以用补题、复盘替代本题单，不额外堆任务。

完成记录只记一行：`独立 AC / 提示后 AC / 题解后 AC`；隔几天重写通过再补 `闭卷回做通过`。看懂题解不等于独立掌握。当前所有条目均未填完成状态，也未查询线上账号；若以前做过，可以直接跳过或作为回做题。

## 后续补充入口

- [CF 贪心题，1200～1600](https://codeforces.com/problemset?tags=greedy%2C1200-1600)
- [CF 构造题，1200～1600](https://codeforces.com/problemset?tags=constructive%20algorithms%2C1200-1600)

两个分类入口分开筛选，避免只看到同时带有两个标签的题。做完这一轮后，根据独立完成情况与主要错因再补下一批。
