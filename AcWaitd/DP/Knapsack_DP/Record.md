## 题目
- P1776 宝物筛选
  - 多重背包，二进制优化成0/1背包
- P1049 [NOIP 2001 普及组] 装箱问题
  - 0/1背包，找最小剩余空间，将重量与价值看成相同，找最大f
- P1757 通天之分组背包
  - 标准分组，三层循环，主要是将组内包含存储起来
  - ~~~cpp
    int maxGroup = 0;
    for (int i = 1; i <= n; i++) {
        int g; cin >> w[i] >> v[i] >>   g;
        maxGroup = max(maxGroup, g);
        a[g].push_back(i);
    }
    // 然后 for (int i = 1; i <= maxGroup; i++)
    ~~~
- P1164 小 A 点菜
  - 刚好花完，种类,定义f[i][j]为选择前1~i个，满足j的方案数目
  - f[1][0]=1，f[i][j]=f[i-1][j]+f[i-1][j-v[i]];//不选i的方案数，选i的方案数
- P2722 [USACO3.1] 总分 Score Inflation
  - 完全背包f[i][j]=max(f[i-1][j],f[i][j-w[i]]+v[i])
- P1077 [NOIP 2012 普及组] 摆花
  - 初始化f[0][0]为1，多重背包计算方案数