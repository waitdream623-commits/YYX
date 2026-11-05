# 刷题目录导航

## 题目放在哪里

| 目录 | 用途 |
| --- | --- |
| [Thinking](Thinking/) | 贪心、构造、观察规律等思维训练；已整合原构造目录 |
| [Contest](Contest/) | 正式比赛、VP，按完整比赛名称归档 |
| [CF](CF/) | CF 日常练习，沿用按比赛名称分组的结构 |
| [ABC](ABC/)、[AGC](AGC/) | AtCoder 练习 |
| DP、Graph_Theory、Tree、Search 等专题目录 | 以学习某个算法或数据结构为目的的练习 |
| [Training](Training/) | 原有综合训练、蓝桥杯练习 |
| [Consolidation](Consolidation/) | 原有基础巩固练习 |
| [templates](templates/) | 代码模板 |
| [Daily_Log](Daily_Log/) | 训练日志 |

一道题保留一份主要源码：已经放在比赛或专题目录的题，题单中链接到它即可。新做的贪心与构造题单优先放入 `Thinking`。

## 笔记与命名

- 题单和比赛复盘放在 [study/Problemset](../study/Problemset/)。
- 通用知识点放在 `study` 对应学科或算法笔记中。
- 新建 CF 源码建议用 `CF_1537_C_Challenging_Cliffs.cpp`，保留题号便于搜索；历史文件名暂时保留。
- 同一题的简短笔记、配图可以与源码放在一起，图片使用相对路径。

## CPH

每个目录下的 `.cph` 保存测试数据。移动源码时，需要同时更新配置中的 `srcPath`，并按新源码绝对路径重新计算配置文件名中的 MD5；仅搬走 `.cpp` 或仅修改 `srcPath` 都不够。

在最终目录中新建源码，再导入 CPH 测试，能减少后续迁移。
