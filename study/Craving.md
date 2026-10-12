# 元信息

## 错误

- 开 long long
- 区间越界，特别对于 `while`，`while` 内先判断是否越界

## 语法知识

- `priority_queue<PII, vector<PII>, greater<PII>> q;`
  - 小根堆绑 `pair<int,int>`，优先按照 `first` 排序
- 对于解绑操作
  - 可以对 `struct` 类型里多个变量进行解绑
  - 结构化解绑不能在 lambda 参数列表里解绑
    - `auto cmp = [](auto [w1,x1,y1], auto [w2,x2,y2]) { return w1 < w2; };` // ✗
  - 不修改最好加个引用来减少拷贝占用

## 一些小想法记录

1. 区间加减，差分数组
2. 空间优化，滚动数组
3. 存边权重：`vector<PII> edges[N];`
4. `gcd(0,5)=5`（0 能被所有数整除，所以 `gcd(0,x)=x`）
5. C++17 的结构化绑定（structured binding）
6. `bitset`，进制转换，转换成 `string`，`string` 转换成 `int`，`stoi();`

```cpp
for (auto [a, b] : v)
{
    cout << a << " " << b;
}
pair<int, int> e = {3, 5};

auto [a, b] = e;
```

- C++ 默认大根堆（顶部最大），小根堆要加 `greater`
- 看一题：避免第一直觉就想方法，多列几个思路再评估每个思路的正确性（基本样例）与复杂度，避免栽坑
- 二维压成一维（压缩数组技巧 → [最大矩形](https://leetcode.cn/problems/maximal-rectangle/description/) 单调栈）
  - [最大子矩阵](https://leetcode.cn/problems/max-submatrix-lcci/description/) dp
- 要排序、且要保留原先位置时，可以用

```cpp
vector<PII> v(n);                    // (值, 原下标)
for (int i = 1; i <= n; i++) { cin >> v[i-1].first; v[i-1].second = i; }
sort(v.begin(), v.end());            // 值与下标一次搞定

// 原先数据复杂（一组不只一个值）时
vector<pair<vector<int>, int>> q;
for (int i = 0; i < queries.size(); i++) q.push_back({queries[i], i});

// 也可以直接把下标 push 进去
for (int i = 0; i < queries.size(); i++) queries[i].push_back(i);

// map 映射：值 → 该值出现的所有下标
unordered_map<int, vector<int>> positions;
for (int i = 0; i < n; ++i) positions[value[i]].push_back(i);

// 复制一份 + 排序去重 + 二分找排名（离散化）
vector<int> xs = values;
sort(xs.begin(), xs.end());
xs.erase(unique(xs.begin(), xs.end()), xs.end());   // unique 返回去重后的新尾，erase 删掉多余部分
int id = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
```

> 注意：`vector` 不能用结构化绑定（元素个数不定）
-   四方遍历写法

    - `int a[] = {-1,0,1,0,-1};`dx = a[i], dy = a[i+1]

-   封装数据类型维护更多信息

    ```cpp
    queue<array<int, 3>> q;//也可以改为struct
    q.push({1, 2, 3});
    
    auto [x, y, steps] = q.front();
    q.pop();
    ```

    

# 基础算法

## 二分

### 适用

- 一般在有序数组上操作
- 二分搜索不一定发生在有序数组上（比如 [寻找峰值问题](https://leetcode.cn/problems/find-peak-element/description/)）—— 罗尔中值定理
- 二分答案：确定上界，想清楚限制条件，不要太过鲁莽

```text
- 二分答案法
- 1）估计"最终答案可能的范围"是什么，可以定得粗略，反正二分不了几次
- 2）分析"问题的答案"和"给定条件"之间的单调性，大部分时候只需要用到自然智慧
- 3）建立一个 f 函数：当答案固定的情况下，判断给定的条件是否达标
- 4）在最终答案可能的范围上不断二分搜索，每次用 f 函数判断，直到二分结束，找到最合适的答案
- 核心点：分析单调性、建立 f 函数
```

### 题目

- [机器人跳跃问题](https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71)
  
  - 题意：$N$ 个建筑高度 `H[i]`，从 0 位置开始跳；能量 $E$ 不够 `H[k]` 就减少 `H[k]-E`，否则增加 `E-H[k]`，全程能量不能为负，求最小初始能量
  - 剪枝，不然会溢出
- [第 k 小](https://leetcode.cn/problems/find-k-th-smallest-pair-distance/description/)
  
  - 题意：求所有数对绝对差中第 $k$ 小的值（数据量大到不能枚举所有数对）
  - 对于该题，枚举区间优化，判断使用双指针，不后退
    ```text
    第 k 小/大问题的通用转化方法：
    第 k 小等价于：求最小的 x，满足绝对差 ≤ x 的数对至少有 k 个。（注意是至少不是恰好）
    第 k 大等价于：求最大的 x，满足绝对差 ≥ x 的数对至少有 k 个。
    ```
- 刀砍毒杀怪兽问题 —— [讲解 051 · 题目7](<C:\Users\wait\Desktop\cCourseware\md\算法讲解051【必备】二分答案法与相关题目.md>)（真实大厂笔试，对数器验证）
  - 题意：共 n 回合，每回合选「刀砍」（立即扣 `cuts[i]`）或「毒杀」（之后每回合扣 `poisons[i]`，多个毒叠加）；n 回合内没打死就靠余毒继续扣，问至少多少回合怪兽死
  - 效果跟回合有关：二分回合数，确定效果大小
- [同时运行 N 台电脑的最长时间](https://leetcode.cn/problems/maximum-running-time-of-n-computers/description/)
  - 题意：每台电脑同一时刻只能用一块电池，求 $n$ 台电脑同时工作的最长时间
  - 贪心优化，碎片处理是否能满足
- 计算等位时间 —— [讲解 051 · 题目6](<C:\Users\wait\Desktop\cCourseware\md\算法讲解051【必备】二分答案法与相关题目.md>)（谷歌面试题）
  - 题意：`arr[i]` 是第 i 个服务员服务一位客人的时长，你前面有 m 个人排队，求你需要等多久（`n ≤ 1e3`，`m ≤ 1e9`）
  - 枚举时间，看目前每个服务员服务了多少顾客
- [ ] [爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/) —— [讲解 051 · 题目1](<C:\Users\wait\Desktop\cCourseware\md\算法讲解051【必备】二分答案法与相关题目.md>)
  - 题意：n 堆香蕉，每小时选一堆吃掉 k 根（这堆不够 k 也占满这一小时），要在 h 小时内吃完，求最小的 k
- [ ] [分割数组的最大值（画匠问题）](https://leetcode.cn/problems/split-array-largest-sum/) —— [讲解 051 · 题目2](<C:\Users\wait\Desktop\cCourseware\md\算法讲解051【必备】二分答案法与相关题目.md>)
  - 题意：把数组切成 m 个非空连续子数组，使「各子数组和的最大值」最小

## 贪心

- 最长重叠段
- 哈夫曼

### 反悔贪心

- 利用堆保存之前信息，如果发现更优就反悔

## 构造

### 题目

- 贪心 → [CF 2268A K Is Important](https://codeforces.com/problemset/problem/2268/A)（Div.1 A，\*1200，constructive + greedy）
  - 题意：给长度为 $n$ 的正整数数组和参数 $k$，只要当前长度 $m \ge k$，就可以删掉 $a_k$ 或 $a_{m-k+1}$ 并把它的值计入得分（删完其余元素保持相对顺序），求最大得分
  - 数据范围：$t \le 10^4$，$\sum n \le 10^5$，$a_i \le 10^9$ → 得分开 `long long`
  - 确定每个长度的左右可选范围；因为选了一个范围会变化，分为"范围交叉"与"不交叉"讨论

-   [ ] - 

## 滑动窗口

> 模板（单调队列）：[P1886 滑动窗口](../AcWaitd/Monotonic_Queue/P_1886_模板_单调队列_滑动窗口.cpp)

### 适用

- 滑动窗口：维持左、右边界都**不回退**的一段范围，来求解很多子数组（串）的相关问题
- 滑动窗口的关键：找到"范围"和"答案指标"之间的**单调性关系**（类似贪心）
  - 如果不达标只能往右扩
- 滑动过程：可以用简单变量或者结构来维护信息
- 求解大流程：求子数组在**每个位置**开头或结尾情况下的答案（开头还是结尾在于个人习惯）
- 注意：滑动窗口维持最大值或最小值的更新结构 —— **单调队列**

### 想法

- 对于窗口，要求连续一段满足某个条件，需要维护区间信息
- 单调性方面：窗口越大越容易满足，增加 l 就会找到极限值 —— 这需要判断题目是否有此性质

### 题目

- [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)
  - 如果存在负数，可能会一直往后加，导致单调性与答案指标不一致；[862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k) 该题存在负数
- [无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)
  - 题意：求不含重复字符的最长连续子串长度
  - 可以记录上个字符出现位置，实现快速去重
- [最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/description/)
  - 利用负债表：需要的为负，如果加完后小于等于零，说明是需要的 `cnt(债务)--`
  - 此时债务清零，看 l 能否缩减，缩完会不会变为负数；如果不会就缩掉（要么本身是不需要字符，要么是多的需要字符）
- [加油站](https://leetcode.cn/problems/gas-station/description/)
  - 多种思考方式，找最低点
- [替换子串得到平衡子串](https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/)
  - 利用了最小覆盖子串，债务法
  - 对于 `vector<char>` 表示存储大小不超过 `char`

# 数据结构

## 单调栈

> 模板：[P5788 单调栈](../AcWaitd/Monotonic_Stack/P_5788_模板_单调栈.cpp) ｜ [SP1805 Histogram](../AcWaitd/Monotonic_Stack/SP_1805_HISTOGRA_Largest_Rectangle_in_a_Histogram.cpp)

### 适用

- 单调栈最经典的用法是解决如下问题，每个位置都求：
  - 0）当前位置的**左侧**比当前位置的数字**小**，且距离最近的位置在哪
  - 1）当前位置的**右侧**比当前位置的数字**小**，且距离最近的位置在哪
  - 或者
  - 0）当前位置的**左侧**比当前位置的数字**大**，且距离最近的位置在哪
  - 1）当前位置的**右侧**比当前位置的数字**大**，且距离最近的位置在哪
- 用单调栈的方式可以做到：求解过程中，单调栈所有调整的总代价为 $O(n)$，单次操作的均摊代价为 $O(1)$
- 注意：这是单调栈最经典的用法，可以解决很多题目
- 注意：单调栈可以和很多技巧交叉使用！比如：动态规划 + 单调栈优化
- 单调栈过程详细图解：
  1. 数组无重复值的情况
  2. 数组有重复值的情况

### 想法

1. **思路**
   - 存下标
   - 实现是栈按照大小排好序，当该点被遗弃时，更新该点左右的值
   - 对于有重复值：来的值与该点相同，该点弹出，记录左右，最后逆序遍历，如果右边点与本身相同，更新为相同点的右边（必定更新完）—— 想不通图解
   - 处理有重复值情况，条件怎么更新
   - 左神一次遍历找到该点左右距离最近的大于值或者小于值，在于第一次遇到不符合规定，更新被弹出值的左右边界（[柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/)）
     - 例如，求该点的小于他的值：此时栈维持单调递增，该点栈下就是距离他最近的小于他的值；右边呢，在遇到一个点不满足单调递增时，要求他弹出，该点就是他的右边界
     - 对于有重复值：先弹掉，正常更新，后续逆序遍历一遍，如果边界值与本身相同，索引找相同值（该点一定更新到正确值了）
   - 对于两次遍历版本，每次遍历找到一侧大于/小于该点距离最近的值
     - 依照去除不满足点，取栈头
     - 依照移除无用数据原则，移除不满足，剩余头部就是满足的
     - 例如求大于该点
       - 求左边，正序遍历建立：单调递增还是递减？想着如果 x 加入，不会影响后续，x 一定大于前面值，所以建立单调递减；这时下一个点小于 x，直接取 x 位置（前面被踢掉的点一定比该点小，表示：后续的点如果小于被踢掉的点，一定小于 x，但 x 点距离他更近）
     - 对于右边，逆序遍历一遍同样操作
     - 对于重复值，直接移除：对于栈中重复点，依赖他更新的点此时已经弹出，不再需要保留；后续如果需要他，也有新进重复值顶替，因此弹出
   - 对于遍历完数组，栈内剩余值怎么处理
     - 取决于题目：若求某侧最近更小/更大，栈里剩余元素在该侧没有答案，填哨兵值即可

2. 维持求解答案的可能性
   - 1）单调栈里的所有对象按照规定好的单调性来组织
   - 2）当某个对象进入单调栈时，会从栈顶开始依次淘汰单调栈里"对后续求解答案没有帮助"的对象
   - 3）每个对象从栈顶弹出时，结算当前对象参与的答案，随后这个对象不再参与后续求解答案的过程
   - 4）其实是先有对题目的分析！进而发现单调性，然后利用单调栈的特征去实现
   - 注意：单调栈可以和很多技巧交叉使用！比如：动态规划 + 单调栈优化

### 题目

- 如何转化为单调栈：找最近小于/大于，想延申
- [最大矩形](https://leetcode.cn/problems/maximal-rectangle/description/)
  - 题意：在 0/1 矩阵中找出只包含 1 的最大矩形，返回面积
  - 利用数组压缩，求最大矩形，中间有断开直接为 0。求以每个为底跑单调栈，与 [柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram) 一致
- [最大宽度坡](https://leetcode.cn/problems/maximum-width-ramp/description/)
  - 题意：求满足 `i < j` 且 `nums[i] <= nums[j]` 的最大 `j - i`
  - 找到距离自己最远的比自己大的值
    - 从暴力来看，枚举左边界，如果比上一个大，寻求长度肯定小于之前
    - 因此先顺序维护一个（包含首位）严格单调递减的栈
    - 后续逆序遍历 j，如果 `nums[j] >= st.top()`，保存结果，出栈，寻求是否有更长；空栈表示已经为最长（包含了第一位），否则 `j--`
- [最小字典序](https://leetcode.cn/problems/remove-duplicate-letters/description/)
  - 题意：给一个字符串，找出"最小字典序且不包含重复字符"的最小子串（去除重复字母）
  - 要最小，前面越小越好：利用单调栈维护严格递增，后面有小的就让前面出去（后面还有替代品）
  - 注意栈内不能加入重复字母
- [大鱼吃小鱼（牛客）](https://www.nowcoder.com/practice/77199defc4b74b24b8ebf6244e1793de) —— [讲解 053 · 题目3](<C:\Users\wait\Desktop\cCourseware\md\算法讲解053【必备】单调栈-下.md>)
  - 题意：每轮每条鱼吃右边最近的、比自己轻的鱼（同时发生，可以多条鱼吃同一条），问几轮后数量稳定
- [ ] [单调栈最经典用法的模板（牛客）](https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb) —— [讲解 052 · 题目1](<C:\Users\wait\Desktop\cCourseware\md\算法讲解052【必备】单调栈-上.md>)
  - 关键：**不同题目中相等值出现时的处理**（后续题会用到）
- [ ] [每日温度](https://leetcode.cn/problems/daily-temperatures/) —— [讲解 052 · 题目2](<C:\Users\wait\Desktop\cCourseware\md\算法讲解052【必备】单调栈-上.md>)
  - 题意：每天求「下一个更高温度出现在几天后」，没有则填 0
- [ ] [子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums/) —— [讲解 052 · 题目3](<C:\Users\wait\Desktop\cCourseware\md\算法讲解052【必备】单调栈-上.md>)
  - 题意：所有连续子数组的最小值求和，答案取模 $10^9+7$（取模原理见讲解 041）
- [ ] [统计全 1 子矩形的数量](https://leetcode.cn/problems/count-submatrices-with-all-ones/) —— [讲解 053 · 题目4](<C:\Users\wait\Desktop\cCourseware\md\算法讲解053【必备】单调栈-下.md>)
  - 题意：0/1 矩阵里统计元素全为 1 的子矩形个数（前置：柱状图中最大的矩形 + 全 1 的最大矩形）

## 并查集

> 模板：[P3367 并查集](../AcWaitd/union-find_sets/P_3367_模板_并查集.cpp) ｜ 坑点记录：[Attention.md](../AcWaitd/union-find_sets/Attention.md)

- 并查集的使用是如下的场景
  - 一开始每个元素都拥有自己的集合，在自己的集合里只有这个元素自己（初始化）
  - `int find(i)`：查找 i 所在集合的代表元素，代表元素来代表 i 所在的集合
  - `bool isSameSet(a, b)`：判断 a 和 b 在不在一个集合里
  - `void union(a, b)`：a 所在集合所有元素与 b 所在集合所有元素合并成一个集合
  - 各种操作单次调用的均摊时间复杂度为 $O(1)$
- 并查集优化（在 `find` 中）
  - **扁平化**：每次查询，如果所挂的不是本身（是本身说明自己是头），说明有上级，直接递归修改为最上级
    - 可以递归写法，也可以用栈模拟递归防止爆栈
  - **小挂大**：需要维护 `size` 和转移 `size`，初始化为 1；`union` 时 a -> b，`size[b] += size[a]`；小（认为高度小）的挂在大（认为高度大）的上，减小递归深度，可不做
- 带权并查集、可持久化并查集、可撤销并查集



### 题目

[947. 移除最多的同行或同列石头](https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/)

-   要移除最多，将能连的连起来，最后一定只会剩一个(从边缘往中心交点删，如果删掉交点，会多保留几个，不符合题意)



## 树状数组

> 模板：[P3374 树状数组 1](<../AcWaitd/Binary Indexed Tree/P_3374_模板_树状数组_1.cpp>) ｜ [P3368 树状数组 2](<../AcWaitd/Binary Indexed Tree/P_3368_模板_树状数组_2.cpp>) ｜ 笔记：[树状数组.md](<../AcWaitd/Binary Indexed Tree/树状数组.md>)

- 可差分数据类型
- 求解逆序对
  - 从右往左遍历，加入词频，将数值对应为树状数组下标；遍历到 `a[i]`，对应树状数组下标 `a[i]++`，求解 `sum(1, a[i]) - 1`，这即为该点造成的逆序对
  - 可能需要离散化，这里就可以处理负数
    - 将每个数据加入 `map`（自排序）
    - 遍历 `map`，为每个数据赋予下标
    - 此时逆序遍历数组，访问数值对应新下标
    - 或者：原数组拷贝排序，去重，对原数组每个值在排完序中二分找下标

### 题目

- [最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/description/)
  - 题意：求最长的严格递增子序列长度
  - 利用其来保存最大长度

## 线段树

> 模板：[Segment_Tree_Template.cpp](../AcWaitd/Segment_Tree/Segment_Tree_Template.cpp) ｜ 题目清单：[ReadMe.md](../AcWaitd/Segment_Tree/ReadMe.md)
> LIS 系列：[Range_LIS.cpp](../AcWaitd/Segment_Tree/Range_LIS.cpp)、[Segment_Tree_LIS_Range.cpp](../AcWaitd/Segment_Tree/Segment_Tree_LIS_Range.cpp)、[Segment_Tree_LCIS.cpp](../AcWaitd/Segment_Tree/Segment_Tree_LCIS.cpp)

- 维护数据范围过大可能需要离散化处理
  - [掉落的方块](https://leetcode.cn/problems/falling-squares)
    - 题意：方块依次落下（给出落点与边长），求每次落下后所有方块堆叠的最大高度
    - 离散所有区间，维护区间内的最大值

## ST 表（RMQ）

> 讲解 **117**：[P3865【模板】ST 表](<../AcWaitd/Sparse Table/P_3865_模板_ST_表_RMQ_问题.cpp>)｜笔记 [st.md](<../AcWaitd/Sparse Table/st.md>)
> 应用：[P1890 gcd 区间](<../AcWaitd/Sparse Table/P_1890_gcd_区间.cpp>)｜[P2880 Balanced Lineup G](<../AcWaitd/Sparse Table/P_2880_USACO_07_JAN_Balanced_Lineup_G.cpp>)｜[P1198 最大数](<../AcWaitd/Sparse Table/P_1198_JSOI_2008_最大数.cpp>)｜[P2251 质量检测](<../AcWaitd/Sparse Table/P_2251_质量检测.cpp>)

# 搜索

## 递归DFS

- **master 公式**
    - a. 所有子问题规模相同的递归才能用 master 公式：$T(n) = a \cdot T(n/b) + O(n^c)$，$a$、$b$、$c$ 都是常数
    - b. 如果 $\log_b a < c$，复杂度为：$O(n^c)$
    - c. 如果 $\log_b a > c$，复杂度为：$O(n^{\log_b a})$
    - d. 如果 $\log_b a = c$，复杂度为：$O(n^c \log n)$
- **一个补充**：$T(n) = 2T(n/2) + O(n\log n)$，时间复杂度是 $O(n \log^2 n)$，证明过程比较复杂，记住即可

- [ ] - 

## BFS

#### 特点

- 宽度优先遍历与优先级队列结合，更进一步的内容会在 Dijkstra 算法体现
- 宽度优先遍历与深度优先遍历结合，去生成路径
    - 1. bfs 建图
    - 2. dfs 利用图生成路径

#### 普通BFS(无权图/等权图)

- bfs 的特点是逐层扩散，从源头点到目标点扩散了几层，最短路就是多少（使用队列）

- bfs 可以使用的特征是：任意两个节点之间的相互距离相同（无向图）

- bfs 开始时，可以是单个源头，也可以是多个源头（多个源头开始一起加入）

- bfs 频繁使用队列，形式可以是单点弹出，或者整层弹出（对于整层弹出，需要事先记录每层大小，`while(size--)` 的弹出与更新）

- bfs 进行时，进入队列的节点需要标记状态，防止同一个节点重复进出队列

- bfs 进行时，可能会包含剪枝策略的设计

- bfs 是一个理解难度很低的算法，**难点在于**：**节点如何找到路、路的展开、剪枝设计**([691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word/description/))

- #### [多源层序遍历模板](https://leetcode.cn/problems/as-far-from-land-as-possible/description/)

    ##### 题目

    -   [ ] [691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word/description/)

        - 题意：给出若干贴纸和目标单词，每种贴纸可以无限次使用（每次用掉一张贴纸上的字母），求拼出目标单词所需的最少贴纸数

        - 贪心（找到每次重叠最多的）反例：`target = abcdef`，`{ade, bcf, bcde}`，局部选择第三个最终答案还是 3，实际只需要 1 + 2 两种贴纸

        - BFS 拓展

            - 对每个都操作一遍，层序遍历出去，去掉重复字母后形成新的 string 加入 hash 标记

            - 当变成零即可退出

            - 对每个字符串**排序**，方便后续处理重复字母

            - 如何去掉重复字母：类似归并的 merge，双指针；对于上一层，如果与下一层相同直接跳转到下一个比较字母，如果小于下面，加入；其余自行思考

            - ==对于上述，时间和空间(队列)占用很大，需要进行剪枝操作==

                - 对于每个target字符我们最后肯定要删除所有字母，对于存在首字符，优先处理，先以首字母为第一要务进行`bfs`

                - 维持这个首字母集，使用

                    ```cpp
                    map<char,string>mp
                    string a[26];//表示
                    ```

        -   动态规划(待做) 

#### 0/1BFS(Dijkstra特例)

- 0/1 bfs，适用于图中所有边的权重只有 0 和 1 两种值，求源点到目标点的最短距离
- 时间复杂度为 $O(节点数量 + 边的数量)$，为什么不能用传统 bfs？
- 步骤：[模板](https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/description/)
    1. `distance[i]` 表示从源点到 i 点的最短距离，初始时所有点的 `distance` 设置为无穷大
    2. 源点进入双端队列，`distance[源点] = 0`
    3. 双端队列头部弹出 `x`
        - A. 如果 `x` 是目标点，返回 `distance[x]` 表示源点到目标点的最短距离
        - B. 考察从 `x` 出发的每一条边，假设某边去 `y` 点，边权为 `w`
            - 1）如果 `distance[y] > distance[x] + w`，处理该边；否则忽略该边
            - 2）处理时，更新 `distance[y] = distance[x] + w`
                - 如果 `w == 0`，`y` 从头部进入双端队列；
                - 如果 `w == 1`，`y` 从尾部进入双端队列
            - 3）考察完 `x` 出发的所有边之后，重复步骤 3
    4. 双端队列为空停止
- 01bfs省visited主要是因为每个节点最多进入两次，但是dj中，权值很大，一个节点可能进入不止两次，这个时候再仅仅根据distance判断效率就比较低了

BFS+DFS[单词接龙](https://leetcode.cn/problems/word-ladder-ii/)

- [题解](D:\c\code\yy\study\Problemset\126. 单词接龙Ⅱ.md)
- 关键点在于建图与剪枝

#### 双向广搜

-   双向广搜常见用途1：小优化
-   bfs的剪枝策略，分两侧展开分支，哪侧数量少就从哪侧展开
-   双向广搜常见用途2：重要！本体！用于解决特征很明显的一类问题
-   特征：全量样本不允许递归完全展开，但是半量样本可以完全展开(折半搜索)
-   过程：把==数据分成两部分==，每部分 各自展开 计算结果，然后设计两部分结果的 整合逻辑

##### 题目

[单词接龙](https://leetcode.cn/problems/word-ladder/description/)

-   已知开头与结尾，向中间搜索
-   优先看对面扩展出来是否有答案，而不是先去判断重复，因为如果有的话已经被标记过了

[P4799 [CEOI 2015] 世界冰球锦标赛 (Day2)](https://www.luogu.com.cn/problem/P4799)

-   不能用动态规划来解？尽管只有选与不选，但是无法存储背包信息
-   从中间分割成两部分，将展开到最后的结果存放，后面整合
-   [代码](D:\c\code\yy\AcWaitd\Search\search_advanced\P_4799_CEOI_2015_世界冰球锦标赛_Day_2.cpp)
-   出现问题
    -   递归结束是下一个的开始
    -   读入数据要开long long

[ [1755. 最接近目标值的子序列和]](https://leetcode.cn/problems/closest-subsequence-sum/description/)

-   与上题一样
-   多了些剪枝﻿﻿
    -   求正数最大，负数最小，极端值对目标判段
    -   展开前排序，对于相同数子求组合数，采用分组展开，二叉树展开变成多叉树展开

-   错误点，最后总结时，两个指针都只能增大，外层i增大，goal - a减小，此时j应该逆序转移

### 总结 

-   对于普通bfs第一次访问就可以标记vis，而0/1bfs因为可以被松弛所以必须出队时才可以标记vis，由于只有0/1，0插头，1插尾，可以模仿堆作用，此时能松弛的一定先出来，因此可以用dist来代替vis作用，此时每个点最多入队两次
-   但是对于dijkstra算法，出队是标记已经处理完，避免堆中元素重复操作
-   模板：[Search_Template.cpp](../AcWaitd/Search/Search_Template.cpp) ｜ 搜索知识图谱与题目清单：[Search/ReadMe.md](../AcWaitd/Search/ReadMe.md)

-   [ ] - [二维接雨水](https://leetcode.cn/problems/trapping-rain-water-ii/description/)

-   [ ] - 

# 动态规划

> 📋 配套题单：[动态规划 66-88 题单](动态规划66-88题单.md)
> 📝 题解统一放 `study/Problemset/`，命名 `题号. 题目名.md`
> 🗂️ 讲次导航：070、071 的题已全在「子数组最大累加和」小节；066~069、072 见文末「讲次题目索引」

### 思想

1. 任何动态规划问题都一定对应着一个有重复调用行为的递归（从递归入手）
2. 最长回文子序列 = 原串与逆序串的最长公共子序列
3. 从递归到递推，三步：
   - 第一步要会**描述局面**（看待问题的方式）
   - 转移方式：递归是自顶向下，递推可以自底向上；递推要看向哪边求值 —— **前面填好了才能填后面**
   - 因此，**递推方向一般与对应递归方向相反**，只保留"归"

### 记录

1. 划分子问题：当前问题依赖前面还是后面，决定是正推还是逆推（编码顺序）
2. 递归加记忆化搜索
3. 求[斐波那契数](https://leetcode.cn/problems/fibonacci-number/)（LC509）：最快是矩阵快速幂 $O(\log n)$
4. 带路径的递归无法改成动态规划 —— [单词搜索](https://leetcode.cn/problems/word-search/)
   - 题意：在字符网格里四方向相邻地走，判断能否拼出目标单词，同一格不能重复走
   - 原因：
     ```text
     防止走重复路径改了原组，状态并非相同
     带路径的递归（可变参数类型复杂）
     ```
5. 记忆化搜索记录的值为负数时，是否可以改成可统计的值
   - ⬜ [盈利计划](https://leetcode.cn/problems/profitable-schemes/)（多维费用背包）

### 子数组最大累加和问题

**[最大子数组和](https://leetcode.cn/problems/maximum-subarray/)（LC53）**

- 要求连续
- 做法一：**前缀和 + 贪心**
  - 维护"前缀和"与"最小前缀和"，答案为 `前缀和 − 最小前缀和` 取 max
  - 最小前缀和怎么维护：沿途比较记录即可
- 做法二：以 `i` 为结尾往左延伸，或以 `i` 为开头往右延伸（逆序遍历）
- 附加问题：返回最大子数组的 `left / right / sum`（不止一个时返回哪一个都可以）
  - dp 时若继承前面的值：`l` 记录上一步，`r` 记为本步
  - 若取自身：`l = r = 自身下标`
  - 只有当 `sum` 比之前大时才更新

- [ ] **[乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/)（LC152）** —— [讲解 071 · 题目1](<C:\Users\wait\Desktop\cCourseware\md\算法讲解071【必备】子数组最大累加和问题与扩展-下.md>)
  - 题意：求乘积最大的非空连续子数组（维护“最大 / 最小”两个值，课上讲的是 int、double 都通用的做法）

**[不能连续选数的最大累加和](https://leetcode.cn/problems/house-robber/)（LC198 打家劫舍）**

- 转移需要隔一个阶段转移
- 或者每个点存储"选 / 不选"两种情况

**[环形最大连续子数组](https://leetcode.cn/problems/maximum-sum-circular-subarray/)（LC918）**

- 正难则反
- 分为两种情况：最大连续 / 不连续；不连续就等于总和减去最小连续和
- 特殊处理全部为负数：此时最大为数组最大值；如果"最小连续和等于总和"就返回最大值（保存在最大连续和中）

**[环形不能取相邻](https://leetcode.cn/problems/house-robber-ii/)（LC213）**（环形子序列，不能相邻）

- 对首位特殊处理：如果取了首位，那么末尾不能取，对 `(2, n-2)` 操作；如果不取，对 `(1, n-1)` 操作

**给定数组 nums，从中选择一个长度至少为 k 的子序列 A，要求 A 中没有任何元素在 nums 中是相邻的，最小化 max(A)**（[LC2560 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv/)）

- 二分 `max`：判定"不取相邻的最长序列"是否满足长度 ≥ k，满足返回 true，不满足返回 false
- 二分后贪心：能偷就偷

**给定数组，从中取长度至少为L，求其最大平均值**（左神课程里没找到；描述与洛谷 P1404 平均数一致，待你确认）

-   二分平均值，(l为min,r为max)

-   构造新数组 $b_i = a_i-mid$

-   要求 $j-i\ge L，即 i\le j-L$​。所以只需要判断：
    $$
    \boxed{s_j-\min_{0\le i\le j-L}s_i\ge 0}
    $$
    

    -   求长度至少为L是否有字段和大于等于0；
    -   维护前缀最小和，i=L开始枚举，这样保证长度大于等于L；

-   对于存在小数处理，浮点二分

-   `while(r-l>1e-(n+2))`保留n位小数

**[最大子矩阵](https://leetcode.cn/problems/max-submatrix-lcci/)（面试题 17.24）**

- 如果只有 0/1 且找全为 1 的子矩阵：用单调栈求最大矩形，枚举以每行为底，中间断开直接为零
- 任意数：注意数据量，方法是 $O(n^3)$
  - 枚举起始行，再枚举末尾行，压缩为一行，求最大子数组和

**选定子序列的和要是 k 的倍数，且最大** —— [讲解 071 · 题目2](<C:\Users\wait\Desktop\cCourseware\md\算法讲解071【必备】子数组最大累加和问题与扩展-下.md>)（原题是“必须被 7 整除”，对数器验证）

- `dp[i][j]`：前 `i` 个里模数为 `j` 的最大值
- 注意初始化；分为第 i 个"选 / 不选"；**有些模数没有就不能选**（别拿 0 当有效值）

**给你两次机会可以让连续一段化为零，求最大数组和（魔法卷轴）** —— [讲解 071 · 题目3](<C:\Users\wait\Desktop\cCourseware\md\算法讲解071【必备】子数组最大累加和问题与扩展-下.md>)（对数器验证）

- 分为：不用 / 用一次 / 用两次
- 用一次：求前后缀最大子数组和
  - 前缀：`dp[i]` 表示"使用一次卷轴"的最大子数组和
  - 转移分为"要 i"与"不要 i"
    - 不要 i：就等于以 `i` 为头向前延伸刷成零 → 转移为前缀最大 `maxpresum`
    - 要 i：`dp[i-1] + nums[i]`
- 用两次卷轴：枚举两次卷轴区间 `(0, i)`、`(i+1, n-1)`

**[三个无重叠子数组（长度为 k）的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/)（LC689）**（返回每个开头下标）

- 优先维护每个长度为 k 的区间和，再跑前后缀，找到"以 i 为末尾"的最大值

**[最多删除一次求最大子数组和](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/)（LC1186）**

- 前后缀做法
  - 不删：跑一次最大子数组和
  - 删：枚举删除点，此时需要"以 i 点为结尾的最大前缀" + "以 i+2 为开头的最大后缀"
- dp 维护方式**未理解** → <https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/description/>
  - 题意：最多删掉一个元素，求剩余数组的最大子数组和
- 拓展：至多 k 次 / 恰好 k 次 / 至少 k 次
  - 【至少 k 次】其实是脑筋急转弯：转换成"选择数组中至多 n−k 个数字"，排序后从大往小选择即可，选 n−k 个数，或者遇到 ≤ 0 的数为止

**选择一个范围翻转的最大子数组和** —— [讲解 071 · 题目5](<C:\Users\wait\Desktop\cCourseware\md\算法讲解071【必备】子数组最大累加和问题与扩展-下.md>)（对数器验证）

-   必须翻转 / 不翻转 / 翻转 三种情况；注意区间长度为 1 时等价于不翻转

-   左边前缀最大子数组，一定能翻转到与右边后缀子数组最大和相接
-   最后考虑

- [ ] **删掉 1 个数字后长度为 k 的子数组最大累加和** —— [讲解 071 · 题目6](<C:\Users\wait\Desktop\cCourseware\md\算法讲解071【必备】子数组最大累加和问题与扩展-下.md>)（对数器验证）
  - 题意：必须删掉一个数字，求新数组中长度为 k 的子数组最大累加和
  - **前置**：单调队列
  - 考察每一个长度为k+1长度的子数组，减去区间中最小值(单调队列求解（单调递增，队头取得)

### 最长递增子序列问题

### 网格dp

- 如果从 `(0,0)` -> `(n-1, m-1)`，意味着向右走 `m-1` 步、向下走 `n-1` 步，顺序随意
  - 换句话说：在 $(m+n-2)$ 步里选出 $m-1$ 步往右，方案数就是这个组合数

#### 题目

- 从左上往右下，矩阵中走的路径和能被 k 整除的路径数（[LC2435](https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)）
  - k 比较小：可以改成递推（记忆化即递推）
  - k 比较大（开不出大小为 k 的数组）：只能写递归
  - 折半搜索：搜索到对角线上，记录信息，用 `map(key, cnt)`

### 树形dp

- dfn 序：依照递归顺序，给每个节点重新标记
- **两次 `dfs`**：对于某一个点的权值之和，不仅需要孩子的信息，也需要父亲的信息 —— 这种问题常常用两次 `dfs` 来解决
  ```text
  P3047 [USACO12FEB] Nearby Cows G
  1. 第一次 dfs 解决只往下时，权值之和；
  2. 第二次 dfs 解决上下都考虑时，权值之和。
  ```

- 题目：[P3047 Nearby Cows G（USACO12FEB）](https://www.luogu.com.cn/problem/P3047) ｜ 笔记：[P_3047_USACO_12_FEB_Nearby_Cows_G.md](../AcWaitd/DP/tree_dp/P_3047_USACO_12_FEB_Nearby_Cows_G.md)




#### 题目

- [爬楼梯](https://leetcode.cn/problems/climbing-stairs/)（LC70）
- [P1095 守望者的逃离（NOIP 2007 普及组）](https://www.luogu.com.cn/problem/P1095)
  ```text
  一直跑与休息跑比较，最后结合；
  ```
- [力扣 最低票价](https://leetcode.cn/problems/minimum-cost-for-tickets/description/)
  - 题意：给出要出行的日期数组 `days`，以及 1 天 / 7 天 / 30 天三种票的价格，求覆盖全部出行日的最小花费
  - 复盘：
    ```text
    会写递归，但是忘记加记忆化超时
    不会写递推也就是动态规划
    从后往前推，左边依赖右边已经填好
    如果顺推，每个点都有多种转移方式（感觉行）
    ```
  - 写法（按日期顺推，非出行日继承前一天）：
    ```cpp
    class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            int n = days.back();
    
            unordered_set<int> st(days.begin(), days.end());
    
            vector<int> dp(n + 1, 0);
    
            for (int i = 1; i <= n; i++) {
    
                // 今天不旅行
                if (!st.count(i)) {
                    dp[i] = dp[i - 1];
                }
    
                // 今天旅行
                else {
                    dp[i] = min({
                        dp[i - 1] + costs[0],
                        dp[max(0, i - 7)] + costs[1],
                        dp[max(0, i - 30)] + costs[2]
                    });
                }
            }
    
            return dp[n];
        }
    };
    ```
  - 递归 / Lambda 写法备忘：
    ```cpp
    auto dfs = [&](auto&& dfs, int i) -> int
    ```
    - `[&]`：Lambda 可以使用外面的变量，并且按引用捕获
    - `auto&& dfs`：表示可以调用自己
    - `-> int`：这个 Lambda 返回 `int`
- [解码方法](https://leetcode.cn/problems/decode-ways/)（LC91）
  ```cpp
  递归转递推，边界条件处理
  // if(s[i-2]!='0'&&i-1>0)//会报错，非法访问i-2位置。先写边界有效
  if(i>1&&s[i-2]!='0')
  ```
### 背包dp

> 模板：[Knapsack_Template.cpp](../AcWaitd/DP/knapsack_dp/Knapsack_Template.cpp)

#### 0/1背包

- ⬜ 待补充

#### 多重背包

- 二进制优化
- 单调队列优化
- 求方案数
  >  **求方案数**的题目不能用二进制优化。
  > 比如从 6 个相同物品中选 3 个，只有一种选法；但按照二进制优化，会把 6 分解为 1+2+3，于是出现 1+2 和 3 两种选法。
  > 如果要优化，可以考虑用 **同余前缀和** 优化。





### 讲次题目索引（066~069、072）

> 下面这些是**新补进笔记的题**（原先只挂在题单里），用 `- [ ]` 记录「还能不能闭卷做出来」；🔁 / ✅ / ⭐ 的进度仍然只在 [动态规划66-88题单.md](动态规划66-88题单.md) 维护。
> 070、071 的题已经全部写进上面的「子数组最大累加和」小节，不在这里重复。

**066 一维dp**

- [ ] [斐波那契数](https://leetcode.cn/problems/fibonacci-number/)（LC509）
- [ ] [最低票价](https://leetcode.cn/problems/minimum-cost-for-tickets/)（LC983）
- [ ] [解码方法](https://leetcode.cn/problems/decode-ways/)（LC91）
- [ ] [解码方法 II](https://leetcode.cn/problems/decode-ways-ii/)（LC639）
- [ ] [丑数 II](https://leetcode.cn/problems/ugly-number-ii/)（LC264）
- [ ] [最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/)（LC32）
- [ ] [环绕字符串中唯一的子字符串](https://leetcode.cn/problems/unique-substrings-in-wraparound-string/)（LC467）
- [ ] [不同的子序列 II](https://leetcode.cn/problems/distinct-subsequences-ii/)（LC940，去重思路已在题单里）

**067 二维dp**

- [ ] [最小路径和](https://leetcode.cn/problems/minimum-path-sum/)（LC64）
- [ ] [单词搜索](https://leetcode.cn/problems/word-search/)（LC79，改不了 dp）
- [ ] [最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)（LC1143）
- [ ] [最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/)（LC516，= 原串与逆串的 LCS）
- [ ] [节点数为 n、高度不大于 m 的二叉树个数](https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea)
- [ ] [矩阵中的最长递增路径](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/)（LC329）

**068 二维dp**

- [ ] [不同的子序列](https://leetcode.cn/problems/distinct-subsequences/)（LC115）
- [ ] [编辑距离](https://leetcode.cn/problems/edit-distance/)（LC72，要会完整版：插入a/删除b/替换c）
- [ ] [交错字符串](https://leetcode.cn/problems/interleaving-string/)（LC97）
- [ ] 有效涂色问题（对数器验证）
- [ ] 删除至少几个字符可以变成另一个字符串的子串（对数器验证）

**069 三维dp**

- [ ] [一和零](https://leetcode.cn/problems/ones-and-zeroes/)（LC474，多维费用背包）
- [ ] [盈利计划](https://leetcode.cn/problems/profitable-schemes/)（LC879，多维费用背包）
- [ ] [骑士在棋盘上的概率](https://leetcode.cn/problems/knight-probability-in-chessboard/)（LC688）
- [ ] [矩阵中和能被 K 整除的路径](https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)（LC2435）
- [ ] [扰乱字符串](https://leetcode.cn/problems/scramble-string/)（LC87）

**072 最长递增子序列**

- [ ] [最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)（LC300，还要会“最长不下降”，只改二分策略）
- [ ] [俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes/)（LC354）
- [ ] [使数组 K 递增的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/)（LC2111）
- [ ] [最长数对链](https://leetcode.cn/problems/maximum-length-of-pair-chain/)（LC646）
- [ ] [有一次修改机会的最长不下降子序列](https://www.luogu.com.cn/problem/P8776)（洛谷 P8776）
- [ ] 预习：[最长递增子序列的个数](https://leetcode.cn/problems/number-of-longest-increasing-subsequence/)（LC673，会用树状数组做）

> 072 的 LIS 最优解是 $O(n\log n)$ 的「贪心 + 二分」；线段树也能做，复杂度和它一样（见「线段树 / 树状数组」小节）。

# 图论

## 图论

> 📋 题目清单 + 复习梯子：[Graph_Theory/ReadMe.md](../AcWaitd/Graph_Theory/ReadMe.md)

### 拓扑排序

- 维护入度与出度
- 当入度为零表示没有前置要求，用于解决任务次序

#### 题目

- [火星词典](https://leetcode.cn/problems/Jf1JuT/description/)给你一个已经排好序的字符串列表，找到一个递增的字符串
  - 题意：外星文字典，根据已按新字母顺序排好序的单词列表，还原字母表的顺序
  - 将能确定顺序，建图小 -> 大，构造入度信息，此后进行拓扑，最小的在前

### 最小生成树

- 最小生成树：在无向带权图中选择一些边，在保证连通性的情况下，边的总权值最小
- 最小生成树可能不只一棵，只要保证边的总权值最小，就都是正确的最小生成树
- 如果无向带权图有 $n$ 个点，那么最小生成树一定有 $n-1$ 条边
- 扩展：最小生成树一定是最小瓶颈树（将所有点连通，最大边权值尽可能小）
  - MST（最小生成树）-> MBST（最小瓶颈树），充分不必要

#### 实现算法

- **Kruskal 算法**（最常用）：贪心 + 并查集，加边
  - 1. 把所有的边，根据权值从小到大排序，从权值小的边开始考虑
  - 2. 如果连接当前的边不会形成环，就选择当前的边（并查集判断）
  - 3. 如果连接当前的边会形成环，就不要当前的边
  - 4. 考察完所有边之后，最小生成树也就得到了
  - 边数等于 `n-1`，表示全部连通
  - 证明略！
  - 时间复杂度 $O(m \log m) + O(n) + O(m)$
- **Prim 算法**（不算常用）：加点
  
  - 1. 解锁的点的集合叫 `set`（标记是否加入）（普通集合）、解锁的边的集合叫 `heap`（小根堆）。`set` 和 `heap` 都为空。
  - 2. 可从任意点开始，开始点加入到 `set`，开始点的所有边加入到 `heap`
  - 3. 从 `heap` 中弹出权值最小的边 `e`，查看边 `e` 所去往的点 `x`
    - A. 如果 `x` 已经在 `set` 中，边 `e` 舍弃，重复步骤 3
    - B. 如果 `x` 不在 `set` 中，边 `e` 属于最小生成树，把 `x` 加入 `set`，重复步骤 3
  - 4. 当 `heap` 为空，最小生成树也就得到了
  - 证明略！
  - 时间复杂度 $O(n + m) + O(m \log m)$
  - 可以反向索引堆优化，当边多时算法更优
    - 时间复杂度 $O(n+m) + O((m+n) \log n)$

#### 细节

- 判断是否全部连通：kk 算法看加边数量，prim 看加点数量
- 如何处理重边
  - 对于 kk：排序 + 并查集自动选择最优且去重
  - 对于 prim：小根堆，选择最优，`set` 去重
- 稠密用 prim，稀疏用 kk
- 如果不连通，prim 要遍历整个森林，需要看哪些节点未访问
  - 此时 kk 一定会遍历所有的，只是可能无法连通

### 单源最短路

|                | 常规版 `dijkstra`                                            | 堆优化` dijkstra`                                            | Bellman-Ford                                                 | SPFA                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **算法思想**   | **贪心**<br>• 每次拿出还未确定最短路的点中，距离起点最近的点<br>• 打上标记之后，更新出边所连点的最短路 | **使用堆优化找点操作：**<br>• 把还未确定最短路的点扔到堆中，用堆快速找出距离起点最近的点 | **暴力松弛：**<br>• 执行 $n-1$ 轮松弛操作<br>• 每次都扫描所有的边，看看能否松弛 | **使用队列优化 BF 算法：**<br>• 只有上一轮被松弛的点，下一轮才有可能松弛 |
| **负边权**     | 失效                                                         | 失效                                                         | 可行                                                         | 可行                                                         |
| **负环**       | 失效                                                         | 失效                                                         | 可以判断负环：<br>• 执行 $n$ 轮操作，判断是否松弛            | 可以判断负环：<br>• 创建 `cnt` 数组，标记从起点到该点的边数  |
| **时间复杂度** | $O(n^2)$                                                     | $O(m\log m)$                                                 | $O(nm)$                                                      | $O(km)\sim O(nm)$                                            |

#### Dijkstra算法

-   Dijkstra算法：给定一个源点，求解从源点到每个点的最短路径长度。单源最短路径算法。
-   适用范围：有向图、边的权值没有负数
-   彻底暴力的Dijkstra算法，遍历每个距离看找到最近的点，O($n^2$)
-   普通堆实现的Dijkstra算法，最普遍、最常用
-   算法核心过程：
-   节点弹出过就忽略
-   节点没弹出过，让其它没弹出节点距离变小的记录加入堆
-   反向索引堆实现的Dijkstra算法，最快速、最极致

##### 实现

[模板](D:\c\code\yy\AcWaitd\Graph_Theory\single_source_shortest\P_4779_模板_单源最短路径_标准版.cpp)

-   普通堆实现的Dijkstra算法，时间复杂度O(m * log m)，m为边数
-   1，distance[i]表示从源点到i点的最短距离，visited[i]表示i节点是否从小根堆弹出过
-   2，准备好小根堆，小根堆存放记录：(源点到x的距离, x点)，小根堆根据距离组织
-   3，令distance[源点]=0，(0， 源点)进入小根堆
-   4，从小根堆弹出(u点，源点到u的距离)
-   a. 如果visited[u] == true，不做任何处理，重复步骤4
-   b. 如果visited[u] == false，令visited[u] = true，u就算弹出过了
-   然后考察u的每一条边，假设某边去往v，边权为w
-   1）如果visited[v] == false 并且 distance[u] + w < distance[v]
-   令distance[v] = distance[u] + w，把(v, distance[u] + w)加入小根堆
-   2）处理完u的每一条边之后，重复步骤4
-   5，小根堆为空过程结束，distance表记录了源点到每个节点的最短距离。

##### 细节

-   入队时，不能标记vis，出队时标记

##### 题目

[维护路径上最大差值最小](https://leetcode.cn/problems/path-with-minimum-effort/description/)

```text
1.网格图，从左上到右下，四方遍历，找差值绝对值，距离为差值绝对值，依旧松弛操作
2.可以使用最小生成树解决，看两点是否连通，kruskal算法可以解决
```

[维护路径上最大值最小](https://leetcode.cn/problems/swim-in-rising-water/description/)

#### 分层图最短路

-   分层图最短路，又叫扩点最短路
-   不把实际位置看做图上的点，而是把 实际位置及其状态的组合 看做是图上的点，然后搜索
-   `bfs` 或者 `Dijkstra`的过程不变，只是扩了点（分层）而已
-   原理简单，核心在于如何扩点、如何到达、如何算距离，每个题可能都不一样
-   增加一维度，维护更多信息



##### 题目

[一些格子需要获取前置条件](https://leetcode.cn/problems/shortest-path-to-get-all-keys/description/)

-   多维护一层信息，是否有钥匙
-   只有当位置和钥匙信息重复时才跳过，因为可能后面去别的路拿到了钥匙返回
-   错点
    -   判断钥匙是否存在存在错误

[边走边充电问题](https://leetcode.cn/problems/DFPeFJ/)

-   维护电量信息，枚举每个地点要充的电量；
-   或者每次选择只充一格电量或者不充电看能扩的点，因为后续充两格电会由充一个电扩展，优化大幅度的时间

[维护免费路线信息](D:\c\code\yy\AcWaitd\Graph_Theory\single_source_shortest\P_4568_JLOI_2011_飞行路线.cpp)

-   错误点，不适用免费路线时，push还是使用免费的时候代价，copy注意改条件



#### A*

-   A*算法，指定源点，指定目标点，求源点到达目标点的最短距离
-   增加了当前点到终点的预估函数
-   在堆中根据 从源点出发到达当前点的距离+当前点到终点的预估距离 来进行排序(聚焦最有可能的近点)
-   剩下的所有细节和Dijskra算法完全一致
-   预估函数要求：当前点到终点的预估距离 <= 当前点到终点的真实最短距离
-   预估函数是一种吸引力
    -   1）合适的吸引力可以提升算法的速度，吸引力过强会出现错误
    -   2）保证 预估距离 <= 真实最短距离 的情况下，尽量接近真实最短距离，可以做到功能正确 且 最快
-   预估终点距离经常选择：
    -   曼哈顿距离
    -   欧式距离
    -   对角线距离

#### Bellman-Ford与SPFA

-   适用

    - 1）适用于小图

    - 2）解决有负边（没有负环）的图的单源最短路径问题

    - 3）可以判断从某个点出发是否能遇到负环，如果想判断整张有向图有没有负环，需要设置虚拟源点(到每个点的距离为0)

    - 4）并行计算时会有很大优势，因为每一轮多点判断松弛操作是相互独立的，可以交给多线程处理

- 注意：
    - SPFA的另一个重要的用途是解决“费用流”问题，当然也可以被Primal-Dual原始对偶算法替代

[BF模板](D:\c\code\yy\AcWaitd\Graph_Theory\single_source_shortest\Bellman-ford_Algorithm.cpp)

- Bellman-Ford算法，解决可以有负权边但是不能有负环（保证最短路存在）的图，单源最短路算法
- 松弛操作
    - 假设源点为A，从A到任意点F的最短距离为distance[F]
    - 假设从点P出发某条边，去往点S，边权为W
    - 如果发现，distance[P] + W < distance[S]，也就是通过该边可以让distance[S]变小
    - 那么就说，P出发的这条边对点S进行了松弛操作
- Bellman-Ford过程
    - 1，每一轮考察每条边，每条边都尝试进行松弛操作，那么若干点的distance会变小
    - 2，当某一轮发现不再有松弛操作出现时，算法停止
- Bellman-Ford算法时间复杂度
    - 假设点的数量为N，边的数量为M，每一轮时间复杂度O(M)
    - 最短路存在的情况下，因为1次松弛操作会使1个点的最短路的边数+1，每轮必定会使一个点更新到正确值
    - 而从源点出发到任何点的最短路最多走过全部的n个点，所以松弛的轮数必然 <= n - 1
    - 所以Bellman-Ford算法时间复杂度O(M*N)
- 重要推广：判断从某个点出发能不能到达负环
    - 上面已经说了，如果从A出发存在最短路（没有负环），那么松弛的轮数必然 <= n - 1
    - 而如果从A点出发到达一个负环，那么松弛操作显然会无休止地进行下去
    - 所以，如果发现从A点出发，在第n轮时松弛操作依然存在，说明从A点出发能够到达一个负环

##### SPFA

[SPFA模板](D:\c\code\yy\AcWaitd\Graph_Theory\single_source_shortest\Spfa.cpp)

- Bellman-Ford + SPFA优化（Shortest Path Faster Algorithm）
- 很轻易就能发现，每一轮考察所有的边看看能否做松弛操作是不必要的
- 因为只有上一次被某条边松弛过的节点，所连接的边，才有可能引起下一次的松弛操作
    - 所以用队列来维护 “这一轮哪些节点的distance变小了”
    - 下一轮只需要对这些点的所有边，考察有没有松弛操作即可
    - 入队标为T，出队标为F，不要重复入队
- SPFA只优化了常数时间，在大多数情况下跑得很快，但时间复杂度为O(n*m)
- 看复杂度就知道只适用于小图，根据数据量谨慎使用，在没有负权边时要使用Dijkstra算法

##### 负环

-   使用BF只需要判断是否松弛次数大于等于n

-   SPFA使用cnt数组

    -   ```cpp
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            cnt[v] = cnt[u] + 1;
        } 
        ```

        到达 \(u\) 的路径包含 `cnt[u]` 条边。

        从 \(u\) 再走一条边到 \(v\)。

        因此，新路径包含 `cnt[u] + 1` 条边。

##### 题目

### 多源最短路

-   可以单源最短路对每个点都跑一次单源最短路

#### Floyd

-   [模板](D:\c\code\yy\AcWaitd\Graph_Theory\multi-Source_Shortest_Path\B_3647_模板_Floyd.cpp)
    -   里面直接用min要取，要预防两个最大相加导致溢出，溢出是mod($2^n$)的值

- Floyd算法，得到图中任意两点之间的最短距离
- 时间复杂度O(n\^3)，空间复杂度O(n\^2)，常数时间小，容易实现
- 适用于任何图，不管有向无向、不管边权正负、但是不能有负环（保证最短路存在）
- 过程简述:
- $distance[i][j]表示i和j之间的最短距离$
- $distance[i][j] = min ( distance[i][j] , distance[i][k] + distance[k][j])$
- 枚举所有的k即可，实现时一定要最先枚举跳板！

## 树上倍增与LCA

### 适用

- 求树上两点的最近公共祖先（LCA）
- 配套常见量
  - 两点距离：$\text{dist}(u,v) = dep[u] + dep[v] - 2 \cdot dep[lca]$
  - 第 $k$ 级祖先
  - 树上差分：`diff[u]++`、`diff[v]++`、`diff[lca]--`、`diff[fa[lca]]--`

### 做法

- **向上标记法** —— 代码见 [Pta最近公共祖先.cpp](../AcWaitd/Tree/Pta最近公共祖先.cpp)
  
  - 从 `c` 一路向上走并打标记，再从 `b` 一路向上走，遇到的第一个被标记的点就是 LCA
  - 单次查询 $O(深度)$；该题 $N \le 110$，够用
  - 输入细节：边以 `0 0` 结束（末尾实际上给了 3 个 0，跳出循环后仍要补读一个），之后才读查询
  
- **倍增法**（待补充）
  - `up[i][j]`：`i` 的第 $2^j$ 级祖先
    - `up[i][0] = fa[i]`、`up[i][j] = up[ up[i][j-1] ][j-1]`
    
  - 预处理 $O(n \log n)$，单次查询 $O(\log n)$
  
  - 查询两步：先把深的那个跳到同一深度，再一起往上跳（$j$ 从大到小试）
  
-   **tarjan算法**

​      

### 易错

- 根的 `fa` 设为 0，并让 `up[0][j] = 0`，避免越界
- `dep[]` 在建树的 `dfs` 里顺手求
- 多组数据：`fa` / `up` / `dep` / 标记数组都要清空

# 数学

> 讲次对照：[041 最大公约数、同余原理](<C:\Users\wait\Desktop\cCourseware\md\算法讲解041【必备】最大公约数、同余原理.md>)｜[097 质数判断、质因子分解、质数筛](<C:\Users\wait\Desktop\cCourseware\md\算法讲解097【必备】质数判断、质因子分解、质数筛.md>)｜[098 快速幂、矩阵快速幂与两类问题](<C:\Users\wait\Desktop\cCourseware\md\算法讲解098【必备】快速幂、矩阵快速幂与两类问题.md>)｜[099 逆元和除法同余、容斥原理](<C:\Users\wait\Desktop\cCourseware\md\算法讲解099【扩展】 逆元和除法同余、容斥原理.md>)｜[139 裴蜀定理和扩展欧几里得](<C:\Users\wait\Desktop\cCourseware\md\算法讲解139【扩展】裴蜀定理和扩展欧几里得算法.md>)｜[140 扩展欧几里得和二元一次不定方程](<C:\Users\wait\Desktop\cCourseware\md\算法讲解140【扩展】扩展欧几里得和二元一次不定方程.md>)｜[095 博弈-上](<C:\Users\wait\Desktop\cCourseware\md\算法讲解095【必备】博弈类问题必备内容详解-上.md>)｜[096 博弈-下](<C:\Users\wait\Desktop\cCourseware\md\算法讲解096【必备】博弈类问题必备内容详解-下.md>)

### 数论：gcd / 同余 / 不定方程

[分解质因数/欧拉函数/逆元/扩欧定理证明](D:\c\code\yy\AcWaitd\Number_Theory\fundamental_theorem\ReadMe.md)

- 最大公约数、同余原理 —— 讲解 **041**
  - [B_3736 最大公约数](../AcWaitd/Number_Theory/gcd_and_lcm/B_3736_信息与未来_2018_最大公约数.cpp)｜[小红的 gcd](../AcWaitd/Number_Theory/gcd_and_lcm/小红的_gcd.cpp)
  - 坑：`gcd(0,5)=5`（见「一些小想法记录 4」）
- **P4549【模板】裴蜀定理** —— 讲解 **139**：[代码](../AcWaitd/Number_Theory/modular_arithmetic/P_4549_模板_裴蜀定理.cpp)
- **P5656【模板】二元一次不定方程（exgcd）** —— 讲解 **140**：[代码](../AcWaitd/Number_Theory/modular_arithmetic/P_5656_模板_二元一次不定方程_exgcd.cpp)
  - 同余方程（exgcd）：[模板_同余方程.cpp](../AcWaitd/Number_Theory/modular_arithmetic/模板_同余方程.cpp)
  - 应用：[P1516 青蛙的约会](../AcWaitd/Number_Theory/modular_arithmetic/P_1516_青蛙的约会.cpp)
- **P3811【模板】模意义下的乘法逆元** —— 讲解 **099**：[代码](../AcWaitd/Number_Theory/modular_arithmetic/P_3811_模板_模意义下的乘法逆元.cpp)｜[模板_逆元.cpp](../AcWaitd/Number_Theory/modular_arithmetic/模板_逆元.cpp)
  - 逆元三件套：费马小定理（p 是质数）、exgcd、线性递推求 1~n 的逆元
- **P5091【模板】扩展欧拉定理**：[代码](../AcWaitd/Number_Theory/modular_arithmetic/P_5091_模板_扩展欧拉定理.cpp) —— 核心是「降幂」，指数很大时先把指数模 $\varphi(p)$
  - 应用：[P4139 上帝与集合的正确用法](../AcWaitd/Number_Theory/modular_arithmetic/P_4139_上帝与集合的正确用法.cpp)（无限递归的指数塔）
- ⬜ 待补：中国剩余定理（讲解 141）、线性基（136/137）、高斯消元（133~135）、01 分数规划（138）、同余最短路（143）

## 质数判定
### 试除法
试除法判断质数
- 对于⼀个数 x ，根据定义，可以从 [2, x − 1] ⼀个⼀个尝试，判断 x 能否被整除。
但是，没有必要每⼀个都去判断。因为a如果是x的约数，那么x/a也是x的约数。因此，我们
仅需判断较⼩的a是否是x的约数，没有必要再去看看x/a。那么，仅需枚举到$\sqrt{n}$即可。
~~~cpp
bool isprime(int x)
{
    if(x <= 1) return false; // ⼩于等于 1 的数不考虑
    // 试除法判断是否是质数 - 只需枚举到 sqrt(x)
    for(int i = 2; i <= x / i; i++) // 防溢出的写法
    {
    if(x % i == 0) return false;
    }
    return true;
}
~~~
O($\sqrt{n}$)
### 埃氏筛法
算法思想：
- 对于任意⼀个⼤于 1 的正整数 ，那么它的 k(k > 1) 倍就是合数。
因此，如果我们从⼩到⼤考虑每个数，然后同时把当前这个数的所有倍数记为合数，没有被标记的数
就是素数。
⼩优化：
- 找到⼀个质数 x 之后，可以从该数的 x 倍向后筛，因此⼩于 x 的倍数⼀定被之前筛过了。
~~~cpp
bool st[N]; // 当前这个数有没有被筛掉
int p[N]; // 记录质数
int cnt; // 统计质数个数
// 埃⽒筛
void get_prime()
{
    for(LL i = 2; i <= n; i++)
    {
        if(!st[i]) // 没有被标记，说明是质数
        {
            p[++cnt] = i; // 记录这个质数
            // 从 i*i 开始，因为⼩于 i 的倍数已经被划掉了
            //例如，3*2，被2筛掉，3只需要从3倍开始
            for(LL j = i * i; j <= n; j += i) // 筛掉这个质数的倍数,这个i必须为ll，也可以使用1ll*i*i转换
            {
                st[j] = true;
            }
        }
    }
}
~~~
O(n log log n) 

只计算质数个数

```cpp
    const int N = 6e6;
    bool st[N];
    int countPrimes(int n) {
        if (n <= 1) {
			return 0;
		}
        //使用优化埃式筛法
        int cnt = (n+1)/2;//预估计，质数个数，偶数必定不是，1也不是，2是质数占位1；
        for(int i = 3; i < n; i += 2)
        {
            if(!st[i])
            {
                for(int j = i*i; j <= n; j += 2*i)//这里i必定是奇数加i变成(j+1)*j前者必定为偶数
                {
                    if(!st[j])//可能被多个标记
                    {
                        st[j] = true;
                    	cnt--;//找到预估内不满足的
                    }
                }
            }
        }
        return cnt;
    }
```



### 线性筛法（欧拉筛法）
线性筛法，⼜称欧拉筛法。算法思想：
- 在埃⽒筛法中，它会将⼀个合数重复多次标记。如果能让每个合数都只被标记⼀次，那么时间复杂
度就可以降到 O(n) 了。
我们的做法是，让每⼀个合数被它的最⼩质因数筛掉。
~~~cpp
int n, q;
bool st[N];
int p[N], cnt;

// 欧拉筛
void get_prime()
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) p[++cnt] = i; // 如果没标记过，就是质数
        // 枚举所有的质数
        //记得开long long ,1ll是将1转换为ll；
        //1ll 就是数据类型为 long long 的数字 1，默认为int类型
        for(ll j = 1; 1ll * i * p[j] <= n; j++)
        {
            st[i * p[j]] = true;
            if(i % p[j] == 0) break;
            /*
            这个判定条件能让每⼀个合数被⾃⼰的最⼩质因数筛掉。
            1. 如果 i 是合数，枚举到最⼩质因数的时候跳出循环
            2. 如果 i 是质数，枚举到⾃⾝时跳出循环
            注意，在筛的过程中，我们还能知道 p[j] 是 i 的最⼩质因数
            */
        }
    }
}
~~~
o(n)

## 质因子分解

#### 1. 单个数的分解（试除法）O($\sqrt{n}$)

从 2 枚举到 $\sqrt{x}$，能整除就一边除一边数指数：

~~~cpp
// x = p1^c1 * p2^c2 * ...
for(int i = 2; i <= x / i; i++) // 写成 x / i，别写 i * i <= x（防溢出）
{
    if(x % i == 0)
    {
        int c = 0;
        while(x % i == 0) { x /= i; c++; }
        cnt[i] = c;
        // 这里拿到了一个质因子 i，指数为 c
        cnt.push_back({i,c});
    }
}
if(x > 1) // 别忘了！剩下的是 > sqrt(原数) 的那个大质因子，指数是 1
{
    // 质因子 x，指数 1
    cnt.push_back({x,1});
}
//log方法
//预处理 x 的最小质因子 LPF(x)，从而做到 O(logx) 分解 x，求出 x 的质因子及其出现次数。
constexpr int MX = 1'000'001; // **根据题目数据范围修改**
int lpf[MX];

int init = [] {
    for (int i = 2; i < MX; i++) {
        if (lpf[i] == 0) { // i 是质数
            for (int j = i; j < MX; j += i) {
                if (lpf[j] == 0) { // 首次访问 j
                    lpf[j] = i;//记录最小
                }
            }
        }
    }
    return 0;
}();

// 质因数分解
// 例如 prime_factorization(45) = {{3, 2}, {5, 1}}，表示 45 = 3^2 * 5^1
// 时间复杂度 O(log x)
vector<pair<int, int>> prime_factorization(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = lpf[x];
        int e = 1;
        for (x /= p; x % p == 0; x /= p) {
            e++;
        }
        res.emplace_back(p, e);
    }
    return res;
}

~~~

- 循环条件是 `i <= x / i`：一是防 `i * i` 溢出，二是 **x 在变小**，判断跟着缩
- 只有"从 2 往上试"才保证 i 一定是质数（小的因子都被除掉了）
- 漏了 `if(x > 1)` 就会丢掉最后一个大质因子（比如 `14 = 2 * 7`，7 是除完 2 之后剩下的）
- pollard_rho启发式方法分解质因数

- [P2043 质因子分解](../AcWaitd/Number_Theory/fundamental_theorem/P_2043_质因子分解.cpp)：1~n 每个数单独试除，用 `c[p]` 累计指数，O($n\sqrt{n}$)

#### 2. 预处理分解

```cpp
constexpr int MX = 1'000'001; // **根据题目数据范围修改**
vector<int> prime_factors[MX];

int init = [] {
    for (int i = 2; i < MX; i++) {
        if (prime_factors[i].empty()) { // i 是质数
            for (int j = i; j < MX; j += i) { // i 的倍数 j 有质因子 i，从一倍开始才不会漏掉
                prime_factors[j].push_back(i);
            }
        }
    }
    return 0;
}();
```



#### 3. 阶乘分解 n! —— 不要真的算 n!

**勒让德公式**：质数 p 在 n! 里的指数

$$e_p(n!) = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \cdots$$

含义：$\lfloor n/p \rfloor$ 数出"至少贡献 1 个 p"的倍数；$\lfloor n/p^2 \rfloor$ 补上"贡献第 2 个 p"的；依此类推。

~~~cpp
// 先筛出 <= n 的所有质数
for(int i = 1; i <= cnt; i++)
{
    int s = 0;
    for(ll j = p[i]; j <= n; j *= p[i]) // j 必须开 ll，j *= p 会溢出 int（不开 long long 见祖宗）
        s += n / j;
    // 质数 p[i] 的指数就是 s
}
~~~

- 枚举的是**每个质数**，不是每个数；O(质数个数 × $\log n$) ≈ O(n)
- [P10495 阶乘分解](../AcWaitd/Number_Theory/fundamental_theorem/P_10495_阶乘分解.cpp)

#### 4. 由分解直接得到的两条公式（约数）

若 $n = \prod p_i^{c_i}$：

- 约数个数：$d(n) = \prod (c_i + 1)$（每个质因子取 0~$c_i$ 次）
- 约数之和：$\sigma(n) = \prod \dfrac{p_i^{c_i+1}-1}{p_i-1}$（等比数列求和）

其他常见问法：

- 求单个 n 的约数和：不用分解，直接**试除配对** O($\sqrt{n}$) —— 枚举 $i \le \sqrt n$，`i` 和 `n / i` 成对加上（注意 `i != n/i` 时才加第二个）→ [约数之和](../AcWaitd/Number_Theory/fundamental_theorem/约数之和.cpp)
- 求 1~n 的**约数个数之和**：等价于 $\sum_{k=1}^{n}\lfloor n/k \rfloor$ —— 换成"数每个 k 是哪些数的约数"，$k > n/2$ 的部分每项都是 1，可以省掉那半圈 → [约数个数的和](../AcWaitd/Number_Theory/fundamental_theorem/约数个数的和.cpp)
- **P3383【模板】线性筛素数**：[代码](../AcWaitd/Number_Theory/prime/P_3383_模板_线性筛素数.cpp)｜[P5736 质数筛](../AcWaitd/Number_Theory/prime/P_5736_深基_7_例_2_质数筛.cpp)
- 筛法应用：[P1835 素数密度](../AcWaitd/Number_Theory/prime/P_1835_素数密度.cpp)（区间筛）｜[UVA543 Goldbach's Conjecture](../AcWaitd/Number_Theory/prime/UVA_543_Goldbach_s_Conjecture.cpp)
- 质因子分解：[P10495 阶乘分解](../AcWaitd/Number_Theory/fundamental_theorem/P_10495_阶乘分解.cpp)｜[P2043 质因子分解](../AcWaitd/Number_Theory/fundamental_theorem/P_2043_质因子分解.cpp)
- 约数：[约数个数的和](../AcWaitd/Number_Theory/fundamental_theorem/约数个数的和.cpp)｜[约数之和](../AcWaitd/Number_Theory/fundamental_theorem/约数之和.cpp)
- 应用：[P2158 仪仗队](../AcWaitd/Number_Theory/fundamental_theorem/P_2158_SDOI_2008_仪仗队.cpp)（$\varphi$ 前缀和）｜[P2568 GCD](../AcWaitd/Number_Theory/fundamental_theorem/P_2568_GCD.cpp)

## 逆元

**单个逆元**

- 如果你想计算：a / b，然后 % MOD结果
- 1) 必须保证a/b可以整除，每次有除法的时候，都需要保证绝对能整除
- 2) 必须保证MOD是质数，求逆元的原理是费马小定理，要求MOD是质数，比如1000000007
- 3) 必须保证b和MOD的最大公约数为1，也就是b和MOD互质
- 先求 1/b 的乘法同余数，也就是b的逆元，b的逆元 = b的(MOD-2)次方 % MOD
- 然后，(a / b) % MOD的结果，等于，((a % MOD) * (b的逆元)) % MOD的结果

**连续数字逆元的线性递推**

- 在 % p意义下，1、2、3 . . . n，求每个数的逆元
    - 用inv[i]，代表i的逆元
    - inv[1] = 1
    - inv[i] = (int) (p - (long) inv[p % i] * (p / i) % p); // 从左往右线性递推
- 连续阶乘逆元的线性递推
    - 在 % p意义下，
    - 1!、2!、3! . . . n!，求每个数的逆元，
    - 用inv[i]，代表i!的逆元
    - 先求n!乘法同余的结果，假设为a，然后求a的逆元，假设为b
    - inv[n] = b
    - inv[i] = ((long) (i + 1) * inv[i + 1]) % MOD; // 从右往左线性递推

## 容斥原理

-   作用：把「至少满足一个条件」或「所有条件都满足」的计数，拆成若干个「且（交集）」来数，正负交错。
-   并集公式：

### 基本公式

$$
|A_1\cup A_2\cup\cdots\cup A_m|
=
\sum_{i=1}^{m}|A_i|
-\sum_{1\le i<j\le m}|A_i\cap A_j|
+\sum_{1\le i<j<k\le m}|A_i\cap A_j\cap A_k|
-\cdots
+(-1)^{m+1}|A_1\cap A_2\cap\cdots\cap A_m|
$$


### 通项公式

$$
\boxed{
\left|\bigcup_{i=1}^{m}A_i\right|
=
\sum_{k=1}^{m}
(-1)^{k+1}
\sum_{1\le i_1<i_2<\cdots<i_k\le m}
\left|
A_{i_1}\cap A_{i_2}\cap\cdots\cap A_{i_k}
\right|
}
$$


### 符号规律

取 $k$ 个集合的交集：

$$
\boxed{(-1)^{k+1}}
$$


即：

$$
+,-,+,-,+,\cdots
$$


### 两个集合

$$
|A\cup B|
=
|A|+|B|-|A\cap B|
$$


### 三个集合

$$
\begin{aligned}
|A\cup B\cup C|
=&|A|+|B|+|C|\\
&-|A\cap B|-|A\cap C|-|B\cap C|\\
&+|A\cap B\cap C|
\end{aligned}
$$



-   交集个数为**奇数**的项取 ++，**偶数**取 −−。

## 快速幂 / 矩阵快速幂（讲解 098）

- [Matrix_Pow_Template.cpp](../AcWaitd/DP/dp_optimization/matrix_pow/Matrix_Pow_Template.cpp)｜笔记 [Record.md](../AcWaitd/DP/dp_optimization/matrix_pow/Record.md)
- 应用：斐波那契数的最优解 $O(\log n)$ —— 见「动态规划 · 记录 3」

## 组合数学

- 组合数计算（杨辉三角 / 取模）：[P2822 组合数问题](../AcWaitd/Combinatorics/computing_combinations/P_2822_NOIP_2016_提高组_组合数问题.cpp)｜[B_3717 组合数问题](../AcWaitd/Combinatorics/computing_combinations/B_3717_组合数问题.cpp)
- 计数题：[P1866 编号](../AcWaitd/Combinatorics/combinatorial_counting/P_1866_编号.cpp)｜[P6191 Bulls And Cows S](../AcWaitd/Combinatorics/combinatorial_counting/P_6191_USACO_09_FEB_Bulls_And_Cows_S.cpp)｜[P8469 文文的数学游戏](../AcWaitd/Combinatorics/combinatorial_counting/P_8469_Aya_Round_1_D_文文的数学游戏.cpp)｜[P8557 炼金术](../AcWaitd/Combinatorics/combinatorial_counting/P_8557_炼金术_Alchemy.cpp)
- 容斥原理 —— 讲解 **099**（还没写题）
- ⬜ **待补（这几个文件夹还是空的）**：卡特兰数 `catalan_numbers`、错排 `derangement`、容斥 `inclusion_exclusion_principle`、隔板法 `stars_and_bars`

## 博弈论（讲解 095 / 096）

- **P2197【模板】Nim 游戏**：[代码](../AcWaitd/Game_Theory/nim_game/P_2197_模板_Nim_游戏.cpp)（全部堆异或 ≠ 0 先手必胜）
- Nim 类：[P1247 取火柴游戏](../AcWaitd/Game_Theory/nim_game/P_1247_取火柴游戏.cpp)｜[P10507 Georgia and Bob](../AcWaitd/Game_Theory/nim_game/P_10507_Georgia_and_Bob.cpp)｜[lyw 的石子游戏](../AcWaitd/Game_Theory/nim_game/lyw的石子游戏.cpp)｜[取石子游戏 2](../AcWaitd/Game_Theory/nim_game/取石子游戏_2.cpp)
- 巴什博弈：[P4018 Roy October 之取石子](../AcWaitd/Game_Theory/bash_game/P_4018_Roy_October之取石子.cpp)｜[P4860 Roy October 之取石子 II](../AcWaitd/Game_Theory/bash_game/P_4860_Roy_October之取石子II.cpp)｜[取石子游戏 1](../AcWaitd/Game_Theory/bash_game/取石子游戏_1.cpp)｜[两堆石头的巴什博弈](../AcWaitd/Game_Theory/sg_function/两堆石头的巴什博弈.cpp)
- SG 函数 / Mex：[P10501 Cutting Game](../AcWaitd/Game_Theory/sg_function/P_10501_Cutting_Game.cpp)｜[移棋子游戏](../AcWaitd/Game_Theory/sg_function/移棋子游戏.cpp)｜[取石子游戏](../AcWaitd/Game_Theory/sg_function/取石子游戏.cpp)｜[1025 除数博弈](../AcWaitd/Game_Theory/sg_function/1025. 除数博弈.cpp)

# 字符串

## 字符串（Trie / 哈希 / KMP）

- 前缀树 Trie —— 讲解 **044 / 045**：[P8306【模板】字典树](../AcWaitd/Trie/P_8306_模板_字典树_Trie.cpp)
- 字符串哈希 —— 讲解 **105**（原理、代码、题目）：[P3370【模板】字符串哈希](../AcWaitd/Character_Hash_Array/P_3370_模板_字符串哈希.cpp)｜[P10468 兔子与兔子](../AcWaitd/Character_Hash_Array/P_10468_兔子与兔子.cpp)
- KMP —— 讲解 **100 / 101**：[Strings/KMP/Readme.md](../AcWaitd/Strings/KMP/Readme.md)