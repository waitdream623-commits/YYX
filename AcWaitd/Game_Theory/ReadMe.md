# Game Theory（博弈论）

## 目录结构

```
Game_Theory/
├── bash_game/      ← 巴什博弈（最基础）
├── nim_game/       ← Nim 博弈（核心模型）
└── sg_function/    ← SG 函数（通用解法）
```

## 学习路线

```
Bash（最简模型） → Nim（异或核心） → SG（通用框架）
      ↓                  ↓                  ↓
   P4018            P2197 模板         SG 打表
   P4860            P1247 输出方案     Cutting Game
```

## 核心理念

1. **Bash**：$n \bmod (m+1) = 0$ 先手必败
2. **Nim**：异或和为 $0$ 先手必败
3. **SG**：$\operatorname{mex}$ 递推 + 子博弈异或
