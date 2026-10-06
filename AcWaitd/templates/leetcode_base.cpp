// =====================================================================
//  力扣本地调试模板  (LeetCode local debug template)
// ---------------------------------------------------------------------
//  为什么需要它 —— 力扣在线判题做不到的三件事:
//   ① 边界测试弱(隐藏数据少)   → 自己随机对拍(小数据 + 暴力)
//   ② 不显示运行时间           → 本地计时
//   ③ 死循环 / RE 看不到现场   → 本地打印现场并停在第一组反例
//
//  五步用法:
//   ① 把力扣的 class Solution 整段粘到【SOLUTION】区(不要改函数名)
//   ② 【GEN】  写小数据生成器(必须小到暴力跑得动,同时覆盖边界)
//   ③ 【BRUTE】写暴力(慢一点没关系)
//   ④ 【JUDGE】默认直接 ==;若题目"任意合法答案都算对",在这里写校验
//   ⑤ 编译 + 运行:
//        clang++ -std=c++20 -O2 -I "C:\Users\wait" leetcode_base.cpp -o debug.exe
//        想打开 debug() 输出, 再加 -DDEBUG
//
//        ./debug.exe            随机对拍 2000 组
//        ./debug.exe sample     只跑官方样例
//        ./debug.exe bench      大 case 计时(看会不会 TLE)
//        ./debug.exe 12345      指定种子对拍(复现失败现场)
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
struct __X {
    __X& operator<<(const auto& s) { return *this; }
    void sp(const string& s = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
#define rep(i,m,n) for (int i = m; i <= n; ++i)

// ==================== 力扣自带类型: 本地要自己写 ====================
// struct ListNode { int val; ListNode* next;
//                   ListNode(int x=0): val(x), next(nullptr) {} };
// struct TreeNode { int val; TreeNode *left, *right;
//                   TreeNode(int x=0): val(x), left(nullptr), right(nullptr) {} };

// ==================== ① SOLUTION: 力扣原样粘贴 ====================
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> cnt;
        cnt[0] = 1;                       // 空前缀, 不能省
        long long s = 0; int ans = 0;
        for (int x : nums) {
            s += x;
            ans += cnt[s - k];            // 先查
            cnt[s]++;                     // 后加
        }
        return ans;
    }
};

// ==================== ② GEN: 小数据生成器 ====================
// 三个要求: 规模小(暴力跑得动) / 值域小(能撞上重复) / 覆盖边界
struct Case {
    vector<int> nums;
    int k;
};

Case gen(mt19937_64& rng) {
    Case c;
    int n = 1 + (int)(rng() % 6);                     // 1..6, 别超过 8
    int hi = (int)(rng() % 4);                         // 上界 0..3
    int lo = (rng() % 4 == 0) ? 0 : -(int)(rng() % 4); // 1/4 概率全非负(边界)
    for (int i = 0; i < n; i++) c.nums.push_back(lo + (int)(rng() % (hi - lo + 1)));
    c.k = (int)(rng() % 7) - 3;                        // -3..3
    return c;
}

// ==================== ③ BRUTE: 暴力 ====================
int brute(const Case& c) {
    int n = (int)c.nums.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) { s += c.nums[j]; if (s == c.k) ans++; }
    }
    return ans;
}

// ==================== ④ JUDGE: 怎么算"答案相同" ====================
// 默认直接比较。若题目是"返回任意一个合法下标数组"(如两数之和/三数之和),
// 就不能比相等, 要改成"校验答案本身合法":
//     bool same(const vector<int>& got, const Case& c) {
//         if (got.size() != 2) return false;
//         int i = got[0], j = got[1];
//         return i != j && c.nums[i] + c.nums[j] == c.k;
//     }
bool same(int got, int exp) { return got == exp; }

// ==================== 打印 / 计时工具 ====================
template <class T>
string ts(const vector<T>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); i++) { if (i) s += ","; s += to_string(v[i]); }
    return s + "]";
}
string show(const Case& c) {
    return "nums=" + ts(c.nums) + ", k=" + to_string(c.k);
}
template <class F>
double timeit(F f) {
    auto t0 = chrono::steady_clock::now();
    f();
    return chrono::duration<double, milli>(chrono::steady_clock::now() - t0).count();
}

// ==================== 跑一次(注意两个坑) ====================
int runOnce(const Case& c) {
    vector<int> a = c.nums;      // 坑1: 力扣参数是引用, 会被改; 必须传副本
    return Solution().subarraySum(a, c.k);
    //      ^^^^^^^^^^^ 坑2: 每题都新建实例, 防止成员变量跨用例残留掩盖 bug
}

// ==================== 官方样例 ====================
void runSample() {
    vector<Case> ss = {
        {{1,1,1}, 2},            // 期望 2   (力扣 560 官方样例)
        {{1,2,3}, 3},            // 期望 2
        {{1}, 0},                // 期望 0   ← 边界
    };
    vector<int> exp = {2, 2, 0};
    for (size_t i = 0; i < ss.size(); i++) {
        int got = runOnce(ss[i]);
        printf("sample%d: %s  get=%d  expect=%d  %s\n",
               (int)i + 1, show(ss[i]).c_str(), got, exp[i],
               got == exp[i] ? "OK" : "WRONG");
    }
}

// ==================== 大 case 计时 ====================
void runBench() {
    Case c;
    int n = 200000;
    for (int i = 0; i < n; i++) c.nums.push_back((i % 7) - 3);
    c.k = 0;
    double ms = timeit([&]{ runOnce(c); });
    printf("bench: n=%d -> %.1f ms  (力扣限时通常 1000ms, 自己留 5 倍余量)\n", n, ms);
}

// ==================== 主流程 ====================
int main(int argc, char** argv) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string mode = (argc > 1) ? argv[1] : "stress";

    if (mode == "sample") { runSample(); return 0; }
    if (mode == "bench")  { runBench();  return 0; }

    ull seed = 20261006ULL;
    if (argc > 1 && string(argv[1]) != "stress") {
        char* end = nullptr;
        ull v = strtoull(argv[1], &end, 10);
        if (end && *end == '\0') seed = v;
        else { printf("usage: debug [sample|bench|stress|<seed>]\n"); return 2; }
    }
    mt19937_64 rng(seed);

    const int ROUNDS = 2000;
    for (int t = 1; t <= ROUNDS; t++) {
        Case c = gen(rng);
        int got = runOnce(c), exp = brute(c);
        if (!same(got, exp)) {
            printf(">>> MISMATCH at round %d  (seed=%llu)\n", t, seed);
            printf("    case   : %s\n", show(c).c_str());
            printf("    get    : %d\n", got);
            printf("    expect : %d\n", exp);
            printf("    复现:   ./debug.exe %llu\n", seed);
            return 1;                     // 停在第一组反例, 不刷屏
        }
    }
    printf("ALL PASS: %d rounds (seed=%llu)\n", ROUNDS, seed);
    return 0;
}
