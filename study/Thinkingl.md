# 一些小想法记录
1. 区间加减，差分数组
2. 空间优化，滚动数组
3. 存边权重 vector<PII> edges[N];



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

## 贪心
- 最长重叠段
- 哈夫曼