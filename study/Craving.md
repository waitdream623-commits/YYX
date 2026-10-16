# 元信息

## 错误

- 开 long long
- 区间越界，特别对于 `while`，`while` 内先判断是否越界
- 自定义比较时，记得&，减少因为开辟空间而影响速度

## 语法知识

- `priority_queue<PII, vector<PII>, greater<PII>> q;`
  - 小根堆绑 `pair<int,int>`，优先按照 `first` 排序
- 对于解绑操作
  - 可以对 `struct` 类型里多个变量进行解绑
  - 结构化解绑不能在 lambda 参数列表里解绑
    - `auto cmp = [](auto [w1,x1,y1], auto [w2,x2,y2]) { return w1 < w2; };` // ✗
  - 不修改最好加个引用来减少拷贝占用

- 对于unique，去重是去掉相邻相同元素，返回最后位的下一个位置

- map自动排序

    - `map` 的键唯一，同一个键再次赋值会覆盖原值。

        插入、查找、删除都是 `O(log n)`。

        `unordered_map` 不保证顺序，查找和插入平均为 `O(1)`。

- printf("%%");  // 输出一个 %


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
    
    - ```cpp
            int find(int x)
            {
                int root = x;
                while(fa[root] != root)
                {
                    root = fa[root];
                }
                while(fa[x] != x)
                {
                    int t = fa[x];
                    fa[x] = root;
                    x = t;
                }
                return root;
            }
        ```
    
    - 
  - **小挂大**：需要维护 `size` 和转移 `size`，初始化为 1；`union` 时 a -> b，`size[b] += size[a]`；小（认为高度小）的挂在大（认为高度大）的上，减小递归深度，可不做
  
      - 因为**小树挂到大树下面时，只有小树里的节点深度增加 1**，大树里的节点深度不变。
  
      - ```cpp
           auto un = [&](int x,int y)->void
                  {
                      int fx = find(x),fy = find(y);
                      if(fx != fy)
                      {
                          if(sz[fy] > sz[fx])
                          {
                              swap(fy,fx);
                          }
                          fa[fy] = fx;
                          sz[fx] += sz[fy];
                      }
                  };
          ```
  
      - 
- 带权并查集、可持久化并查集、可撤销并查集



### 题目

-   [ ] [947. 移除最多的同行或同列石头](https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/)


-   要移除最多，将能连的连起来，最后一定只会剩一个(从边缘往中心交点删，如果删掉交点，会多保留几个，不符合题意)

[2092. 找出知晓秘密的所有专家](https://leetcode.cn/problems/find-all-people-with-secret/)

-   时间排序，从前往后处理，对于同一时间，可能后面连接上了，前面没有得到信息
-   解决上述，我们应该将其全部连接起来，最后能连的都在一起，对于不能的，最后需要取消并查集，防止影响后面不同时间的
-   对于多次访问同一个集合，可将改find提前准备好，避免多次调用函数

-   [ ] [2421. 好路径的数目 - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-good-paths/description/)

-   优先处理两头节点最大值，最小的边，合并计数，如果最大值相等才计数，并更新最大值与其个数(方便后续计数)
-   按照从大到小顺序，避免大的阻挠

-   [ ] [928. 尽量减少恶意软件的传播 II - 力扣（LeetCode）](https://leetcode.cn/problems/minimize-malware-spread-ii/)
    -   **把健康节点的连通块作为整体，判断它是否只依赖一个感染源。**(只有一个感染源才可以取出后减少感染次数)
    
        1.  **先标记感染点，只合并健康节点。**
            感染点不参与并查集合并；统计邻居时也要用 `!vis[i]` 排除所有感染点。
        2.  **感染来源记录在并查集根上。**
            使用 `cnt[find(i)]`，不能记录在普通节点 `i` 上。
        3.  **区分“没有、唯一、多个”三种来源。**
            你的约定是：`-1` 无来源，`-2` 多个来源，`>=0` 为唯一感染点编号。编号 `0` 也是合法节点。
        4.  **统计不同感染点，不是边数。**
            同一个感染点连接同一块多次，状态不变；出现另一个感染点，才标为多个来源。
        5.  **每块只结算一次，每个感染点累加所有独占块。**
            无来源的块原本安全；多来源的块删一个点也救不了；唯一来源的块，将整个块大小贡献给该感染点。
        6.  **同分取编号最小。**
            `initial` 不保证有序，要么先排序，要么更新答案时显式比较编号。
    
        实现时再检查初始化：`fa[i]=i`、`sz[i]=1`、`vis` 清零、`cnt[i]=-1`。

## 树状数组

> 模板：[P3374 树状数组 1](<../AcWaitd/Binary Indexed Tree/P_3374_模板_树状数组_1.cpp>) ｜ [P3368 树状数组 2](<../AcWaitd/Binary Indexed Tree/P_3368_模板_树状数组_2.cpp>) ｜ 笔记：[树状数组.md](<../AcWaitd/Binary Indexed Tree/树状数组.md>)

- 可差分数据类型
- 求解逆序对
  - 从右往左遍历，加入词频，将数值对应为树状数组下标；遍历到 `a[i]`，对应树状数组下标 `a[i]++`，求解 `sum(1, a[i]位置-1(一个位置可能有多个重复值，因此不能包含自身)) ，这即为该点造成的逆序对
  - 从右往左找“小于自己”，从左往右找“大于自己”
  
      - ```cpp
          ll ans = 0;
          for(int i = 1;i<=n;i++)
          {
              int pos = lower_bound(b+1,b+1+n,a[i])-b;
              ans += i-1-query(pos);
              add(pos,1);
          }
          ```
      - 
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



### 题目

-   **全排列**

    -    无重复值情况，每次都从头开始选，避免选到已经选过的，如果长度满足就完成一次排列，返回递归需要回溯，删除加入元素和去除标记，不影响同一层的其他遍历

    -   对于有重复的元素，排序后递归选择

        -   ```
            if(i>0 && s[i]==s[i-1] && !vis[i-1])continue;
            ```

            含义是：

            -   `s[i]==s[i-1]`：当前字符与前一个字符相同。
            -   `!vis[i-1]`：前一个还没被使用，此时选择当前这个，会产生重复分支，跳过。
            -   如果前一个已经被使用，则允许选择当前这个，用来组成连续多个相同字符。

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

本章已拆分至 [动态规划.md](动态规划.md)，笔记与题目在该文件中维护。

# 图论

本章已拆分至 [图论.md](图论.md)，笔记与题目在该文件中维护。

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
