// ============================================================================
//  字典树 对拍：验证 insert / erase / find / query_prefix
//  ---------------------------------------------------------------------------
//  编译 & 运行（和你平时一样的 clang++）：
//    clang++ -std=c++20 -O2 -I "C:\Users\wait" trie_stress.cpp -o trie_stress.exe
//    .\trie_stress.exe
//
//  里面嵌的是你 `字典树.md` 里的实现：
//    - 只把 get_num(ec) 那个笔误改成 get_num(c)
//    - erase 由 int 改成 void（原版掉出末尾是 UB）
//    其余逻辑与你文件里**完全一致**
//
//  检查方式：
//    ① 定点用例：把你踩过的 5 类坑各写一条
//    ② 随机对拍：随机 200 次操作，**每步之后遍历全部 30 个候选串**，
//       把 find / query_prefix 和 map<string,int> 暴力版逐一对上
//       （不是只在操作后抽查 —— 状态一旦漂移，立刻会被抓到）
// ============================================================================
#include <bits/stdc++.h>
using namespace std;

// ===================== 你的实现 =====================
const int N = 200000;
int trie[N][62], p[N], e[N];
int idx;

int get_num(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}

void insert(string &s) {
    int cur = 0;
    p[cur]++;
    for (char c : s) {
        int path = get_num(c);
        if (trie[cur][path] == 0) trie[cur][path] = ++idx;
        cur = trie[cur][path];
        p[cur]++;
    }
    e[cur]++;
}

int query_prefix(string &s) {
    int cur = 0;
    for (char c : s) {
        int path = get_num(c);
        if (trie[cur][path] == 0) return 0;
        cur = trie[cur][path];
    }
    return p[cur];
}

int find_cnt(string &s) {
    int cur = 0;
    for (char c : s) {
        int path = get_num(c);
        if (!trie[cur][path]) return 0;
        cur = trie[cur][path];
    }
    return e[cur];
}

void erase(string &s) {
    if (find_cnt(s) > 0) {
        int cur = 0;
        p[cur]--;
        for (char c : s) {
            int path = get_num(c);
            if (--p[trie[cur][path]] == 0) {
                trie[cur][path] = 0;   // 砍掉整棵子树
                return;
            }
            cur = trie[cur][path];
        }
        e[cur]--;
    }
}

void trie_clear() {
    for (int i = 0; i <= idx; i++) {
        p[i] = e[i] = 0;
        for (int j = 0; j < 62; j++) trie[i][j] = 0;
    }
    idx = 0;
}

// ===================== 暴力版（map） =====================
map<string, int> cnt;

void bf_insert(string &s) { cnt[s]++; }
void bf_erase(string &s) {
    auto it = cnt.find(s);
    if (it != cnt.end() && --it->second == 0) cnt.erase(it);
}
int bf_find(const string &s) {
    auto it = cnt.find(s);
    return it == cnt.end() ? 0 : it->second;
}
int bf_prefix(const string &s) {          // 有多少个串（按出现次数）以 s 为前缀
    int r = 0;
    for (auto &kv : cnt)
        if (kv.first.size() >= s.size() && kv.first.compare(0, s.size(), s) == 0) r += kv.second;
    return r;
}

// ===================== 候选串全集：字母表 {a,b} 上长度 1~4 =====================
vector<string> UNI;
void build_uni() {
    const string A = "ab";
    for (int len = 1; len <= 4; len++)
        for (int m = 0; m < (1 << len); m++) {
            string s;
            for (int i = 0; i < len; i++) s += A[(m >> i) & 1];
            UNI.push_back(s);
        }
}

// ===================== 全状态比对 =====================
string opname(int t) { return t == 0 ? "insert" : t == 1 ? "erase " : t == 2 ? "find  " : "prefix"; }
struct Op { int type; string s; };

int check_all(const vector<Op> &log, int round, int opi) {
    int bad = 0;
    for (auto &u : UNI) {
        string t = u;                       // find/prefix 要非 const 引用
        int g1 = find_cnt(t), w1 = bf_find(u);
        int g2 = query_prefix(t), w2 = bf_prefix(u);
        if (g1 != w1 || g2 != w2) {
            if (bad == 0) {
                printf("  >>> MISMATCH  round=%d  after op#%d  探测串 \"%s\"\n", round, opi, u.c_str());
                printf("        find  : got %d , want %d\n", g1, w1);
                printf("        prefix: got %d , want %d\n", g2, w2);
                printf("        最近的操作:\n");
                for (int k = max(0, (int)log.size() - 12); k < (int)log.size(); k++)
                    printf("          [%d] %s \"%s\"\n", k, opname(log[k].type).c_str(), log[k].s.c_str());
            }
            bad++;
        }
    }
    return bad;
}

// ===================== 定点用例 =====================
int named_case(const char *name, const vector<Op> &ops, bool verbose) {
    trie_clear();
    cnt.clear();
    for (auto &o : ops) {
        string s = o.s;
        if (o.type == 0) { insert(s); bf_insert(s); }
        else if (o.type == 1) { erase(s); bf_erase(s); }
    }
    int bad = check_all(ops, -1, -1);
    printf("%-58s %s\n", name, bad == 0 ? "PASS" : "FAIL");
    if (verbose && bad) { /* 详情已由 check_all 打印 */ }
    return bad;
}

int main() {
    build_uni();
    int total = 0;

    printf("===================== 定点用例（你踩过的坑）=====================\n");
    // 1. 删一个边都不存在的串
    total += named_case("删【不存在】的串（连边都没有）", {{0, "ab"}, {1, "xy"}}, true);
    // 2. 删一个"只是别人的前缀"的串
    total += named_case("删【只是别人前缀】的串：只插 abc，删 ab", {{0, "abc"}, {1, "ab"}}, true);
    // 3. 删完再查前缀
    total += named_case("删完再查前缀：插 ab/ac，删 ab", {{0, "ab"}, {0, "ac"}, {1, "ab"}}, true);
    // 4. 重复串
    total += named_case("重复串：插两次 ab，删一次", {{0, "ab"}, {0, "ab"}, {1, "ab"}}, true);
    total += named_case("重复串：再删一次（应当彻底消失）", {{0, "ab"}, {0, "ab"}, {1, "ab"}, {1, "ab"}}, true);
    // 5. 前缀链
    total += named_case("前缀链：插 a/ab/abc，删中间的 ab", {{0, "a"}, {0, "ab"}, {0, "abc"}, {1, "ab"}}, true);

    printf("\n===================== 随机对拍 =====================\n");
    mt19937 rng(20260922);
    const int ROUNDS = 40, OPS = 200;
    for (int r = 0; r < ROUNDS; r++) {
        if (r % 8 == 1) rng.seed(20260922 + r * 7919);   // 换一批随机序列
        trie_clear();
        cnt.clear();
        vector<Op> log;
        for (int i = 0; i < OPS; i++) {
            int type = rng() % 4;
            // 故意把串弄得很短 + 字母表只有 a/b → 前缀、重复、前缀串大量出现
            int len = 1 + rng() % 4;
            string s;
            for (int k = 0; k < len; k++) s += char('a' + rng() % 2);
            log.push_back({type, s});
            string t = s;
            if (type == 0) { insert(t); bf_insert(s); }
            else if (type == 1) { erase(t); bf_erase(s); }
            int bad = check_all(log, r, i);
            if (bad) {
                total += bad;
                printf("  （本轮中止，已把出错前的操作历史打印在上方）\n\n");
                goto next_round;
            }
        }
        next_round:;
    }

    printf("\n===================== 结果 =====================\n");
    if (total == 0) printf("全部通过：定点用例 + 40 轮 x 200 次随机操作，状态始终与暴力版一致\n");
    else printf("共 %d 处不一致\n", total);
    return total != 0;
}
