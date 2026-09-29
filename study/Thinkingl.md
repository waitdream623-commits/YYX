# 一些小想法记录
1. 区间加减，差分数组
2. 空间优化，滚动数组
3. 存边权重 vector<PII> edges[N];
4. gcd(0,5)=0;,0能被所有数整除
5. C++17 的结构化绑定（structured binding）
6. bitset，进制转换，转换成string，string 转换成int，stoi();
~~~
for (auto [a, b] : v)
{
    cout << a << " " << b;
}
pair<int, int> e = {3, 5};

auto [a, b] = e;
~~~

## 动态规划
### 思想
1. 任何动态规划问题都一定对应着一个有重复调用行为的递归（从递归入手）
2. 最长回文子序列，原串与逆序串的最长公共子序列

### 记录
1. 划分子问题，当前问题依赖前面还是后面，决定是正推或者逆推(编码)
2. 递归加记忆化搜索
3. 求斐波拉契数，最快矩阵快速幂O($log(n)$)
4. 带路径的递归无法改成动态规划(单词搜索)https://leetcode.cn/problems/word-search/
~~~ 
防止走重复路径改了原组，状态并非相同
带路径的递归（可变参数类型复杂）
~~~

### 树形dp
- dfn序，依照递归顺序，给每个节点重新标记
- 两次 dfs。
对于某⼀个点的权值之和，不仅需要孩⼦的信息，也需要⽗亲的信息。对⾯这种问题，常常⽤两次 dfs
来解决：
~~~
P3047 [USACO12FEB] Nearby Cows G
1. 第⼀次 dfs 解决只往下时，权值之和；
2. 第⼆次 dfs 解决上下都考虑时，权值之和。
~~~



### 题目
- 爬楼梯
- P_1095_NOIP_2007_普及组_守望者的逃离
~~~
一直跑与休息跑比较，最后结合；
~~~
- 力扣最低票价https://leetcode.cn/problems/minimum-cost-for-tickets/description/
~~~
会写递归，但是忘记加记忆化超时
不会写递推也就是动态规划
从后往前推，左边依赖右边已经填好
如果顺推，每个点都有多种转移方式（感觉行）
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
auto dfs = [&](auto&& dfs, int i) -> int
Lanbda写法，引用是Lambda 可以使用外面的变量，并且按引用捕获。
auto&& dfs，表示可以调用自己
->int 这个 Lambda 返回 int.
~~~
- 解码方法
~~~
递归转递推，边界条件处理
// if(s[i-2]!='0'&&i-1>0)//会报错，非法访问i-2位置。先写边界有效
if(i>1&&s[i-2]!='0')
~~~
## 贪心
- 最长重叠段
- 哈夫曼

## 递归
5）master公式
- a. 所有子问题规模相同的递归才能用master公式，T(n) = a * T(n/b) + O(n^c)，a、b、c都是常数
- b. 如果log(b,a) < c，复杂度为：O(n^c)
- c. 如果log(b,a) > c，复杂度为：O(n^log(b,a))
- d. 如果log(b,a) == c，复杂度为：O(n^c * logn)
- 6）一个补充
- T(n) = 2\*T(n/2) + O(n\*logn)，时间复杂度是O(n \* ((logn)的平方))，证明过程比较复杂，记住即可



## 二分
###
- 一般在有序数组上操作；
- ⬜二分搜索不一定发生在有序数组上(比如[寻找峰值问题](https://leetcode.cn/problems/find-peak-element/description/))
罗尔中值定理
- 二分答案，确定上界，想清楚限制条件，不要太过鲁莽
~~~
- 二分答案法
- 1）估计 最终答案可能的范围 是什么，可以定的粗略，反正二分不了几次
- 2）分析 问题的答案 和 给定条件 之间的 单调性，大部分时候只需要用到 自然智慧
- 3）建立一个f函数，当答案固定的情况下，判断 给定的条件是否达标
- 4）在 最终答案可能的范围上不断二分搜索，每次用f函数判断，直到二分结束，找到最合适的答案
- 核心点：分析单调性、建立f函数
~~~

### 题目
- https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71
  - 剪枝，不然会溢出
- [第k小](https://leetcode.cn/problems/find-k-th-smallest-pair-distance/description/)
  - 对于该题，枚举区间优化，判断使用双指针，不后退
~~~
第 k 小/大问题的通用转化方法：
第 k 小等价于：求最小的 x，满足绝对差 ≤x 的数对至少有 k 个。（注意是至少不是恰好）
第 k 大等价于：求最大的 x，满足绝对差 ≥x 的数对至少有 k 个。
~~~
- 刀砍毒杀怪兽问题
  - 效果跟回合有关，二分回合数，确定效果大小