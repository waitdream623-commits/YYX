# Attention
## 格式化输出
```cpp
#include <iomanip> // io manipulation (输入输出操纵器)

```

总结了算法竞赛中最常用的 **3 大格式化场景**，以及它们和 C 语言 `printf` 的对照：

### 1. 保留小数位数

你需要同时使用 `fixed` 和 `setprecision(n)`。

* **`fixed`**：告诉编译器“请用普通的定点小数显示，绝对不要给我搞成科学计数法（如 1e-5）”。
* **`setprecision(n)`**：告诉编译器“小数点后保留 n 位”。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265;
    
    // 相当于 printf("%.2f\n", pi);
    cout << fixed << setprecision(2) << pi << "\n"; // 输出: 3.14
    
    // 注意：设置一次后，后面所有的浮点数都会默认保留两位小数！
    double x = 2.0;
    cout << x << "\n"; // 输出: 2.00
    return 0;
}

```

### 2. 设置输出宽度（常用于打印矩阵、杨辉三角）

使用 `setw(n)`（set width），强制让输出的内容占据 `n` 个字符的宽度。默认是**右对齐**。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a = 5, b = 123;
    
    // 相当于 printf("%5d%5d\n", a, b);
    cout << setw(5) << a << setw(5) << b << "\n";
    // 输出:     5  123 (前面会有空格)
    
    // 如果想左对齐，可以加一个 left
    // 相当于 printf("%-5d\n", a);
    cout << left << setw(5) << a << "X\n"; 
    // 输出: 5    X
    
    return 0;
}

```

🚨 **超级避坑警告**：`setw(n)` 是所有控制符里最特殊的一个！它**只对紧跟在它后面的那一个元素有效**。印完之后立刻失效。所以每次你想控制宽度，都必须重新写一遍 `setw`。

### 3. 前导零填充（常用于输出时间，比如 09:05）

配合 `setw(n)` 使用 `setfill('0')`。当宽度不够时，用字符 `'0'` 来填补空白。

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int hour = 9, minute = 5;
    
    // 相当于 printf("%02d:%02d\n", hour, minute);
    cout << setw(2) << setfill('0') << hour << ":" 
         << setw(2) << setfill('0') << minute << "\n";
    // 输出: 09:05
    return 0;
}

```

---

### 💡 核心总结与速查表

| 需求 | C 语言 (`printf`) | C++ (`cout` + `<iomanip>`) | 特性说明 |
| --- | --- | --- | --- |
| **保留3位小数** | `printf("%.3f", x);` | `cout << fixed << setprecision(3) << x;` | **永久生效**，直到你再次修改它 |
| **占5格右对齐** | `printf("%5d", x);` | `cout << setw(5) << x;` | **一次性生效**，只对下个元素有效 |
| **左对齐** | `printf("%-5d", x);` | `cout << left << setw(5) << x;` | `left` 永久生效 |
| **补前导零** | `printf("%03d", x);` | `cout << setw(3) << setfill('0') << x;` | `setfill` 永久生效，但 `setw` 需每次写 |

刚开始用 `<iomanip>` 可能会觉得比 `printf` 长很多，但在 VS Code 的代码补全（clangd）加持下，敲出 `setp` 就会自动补全 `setprecision`，实际上手速非常快。而且它**绝对类型安全**，再也不用担心 `%d` 匹配到了 `long long` 导致 RE（段错误）了！
## 图
### 存图
- 注意处理重边

## unique
- 只能去重相邻，需要去重所有，需要先排序