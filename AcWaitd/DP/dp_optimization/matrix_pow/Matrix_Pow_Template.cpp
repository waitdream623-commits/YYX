/**
 * 矩阵快速幂 模板
 * ============================================================================
 * 用途：加速【线性递推】
 *   1 维 k 阶 : f[n] = c1*f[n-1] + c2*f[n-2] + ... + ck*f[n-k]
 *   k 维 1 阶 : V[n] = A * V[n-1]          （V 是 k 维状态列向量）
 * 两者是同一件事：都能写成「状态向量 × 固定矩阵」，于是 n 次转移被压成一次幂。
 *
 * 复杂度：O(log n · k³)    —— 只有 k 很小时才划算（k ≤ 10 随意，k ≥ 100 危险）
 *
 * 成立前提（缺一不可，先自查再动手）：
 *   1. 转移是【线性】的：只有加法和常数倍，不能有 min/max/乘法项
 *   2. 系数与 n【无关】：固定关系，不能出现 c(n)
 *   3. 阶数 k 【固定】
 *   → 三条全过才叫"固定关系的线性递推"，才有资格上矩阵
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;   // 题面有则改

// ============================================================================
// 0. 标量快速幂（对照组）
//    矩阵快速幂 = 把这里的"数乘"换成"矩阵乘"，其他一字不改
// ============================================================================
ll qpow(ll a, ll b, ll m = MOD) {
    ll r = 1 % m;
    a %= m;
    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

// ============================================================================
// 1. 定长矩阵（K 编译期已知，竞赛首选：零堆分配、循环可展开）
// ============================================================================
template <int K>
struct Mat {
    ll a[K][K];

    // identity = true → 单位矩阵（快速幂的起点，必须用它！）
    explicit Mat(bool identity = false) {
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++) a[i][j] = 0;
        if (identity)
            for (int i = 0; i < K; i++) a[i][i] = 1;//单位矩阵*b等于b
    }

    // res = (*this) * o  —— 矩阵乘法不满足交换律，顺序不能反
    Mat operator*(const Mat& o) const {
        Mat res;
        for (int i = 0; i < K; i++)
            for (int t = 0; t < K; t++) {
                if (a[i][t] == 0) continue;          // 稀疏剪枝，别删
                ll v = a[i][t];
                for (int j = 0; j < K; j++)
                    res.a[i][j] = (res.a[i][j] + v * o.a[t][j]) % MOD;
            }
        return res;
    }
};

// 矩阵快速幂：返回 base^exp
template <int K>
Mat<K> mat_qpow(Mat<K> base, ll exp) {
    Mat<K> res(true);                     // ★ 单位矩阵，不是全 1 也不是全 0
    while (exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

// 矩阵 × 列向量：返回 A * v
template <int K>
array<ll, K> mat_vec_mul(const Mat<K>& A, const array<ll, K>& v) {
    array<ll, K> r{};
    for (int i = 0; i < K; i++) {
        ll s = 0;
        for (int j = 0; j < K; j++) s = (s + A.a[i][j] * v[j]) % MOD;
        r[i] = s;
    }
    return r;
}

// ============================================================================
// 2. 通用武器：1 维 k 阶线性递推（要背就背这个）
//
//    f[n] = c[0]*f[n-1] + c[1]*f[n-2] + ... + c[k-1]*f[n-k]
//    状态向量（列）S[n] = [ f[n], f[n-1], ..., f[n-k+1] ]ᵀ
//    则 S[n+1] = A · S[n]，A 的构造口诀：
//        第 0 行 = [ c[0], c[1], ..., c[k-1] ]   ← 递推系数照抄
//        第 i 行 = 上一行整体右移一格             ← 即 A[i][i-1] = 1
//    于是 S[n] = A^(n-k) · S[k]，答案取第 0 个分量
// ============================================================================
template <int K>
Mat<K> companion_matrix(const array<ll, K>& c) {
    Mat<K> A;                                     // 伴随矩阵 / 转移矩阵
    for (int j = 0; j < K; j++) A.a[0][j] = (c[j] % MOD + MOD) % MOD;
    for (int i = 1; i < K; i++) A.a[i][i - 1] = 1;
    return A;
}

/**
 * @param c    递推系数：c[0..k-1] 依次对应 f[n-1] ... f[n-k]
 * @param init 初值：init[0..k-1] = f[1], f[2], ..., f[k]
 * @param n    求 f[n]（1-indexed）
 */
template <int K>
ll linear_recurrence(const array<ll, K>& c, const array<ll, K>& init, ll n) {
    if (n <= K) return init[n - 1] % MOD;         // 边界：n 落在初值里，直接返回
    // ★ 必须显式写 <K>：std::array 的长度是 size_t，自动推导会和 Mat 的 int K 打架
    Mat<K> A = mat_qpow(companion_matrix<K>(c), n - K);
    array<ll, K> v{};                             // S[k] = [f[k], f[k-1], ..., f[1]]
    for (int i = 0; i < K; i++) v[i] = init[K - 1 - i] % MOD;
    return mat_vec_mul<K>(A, v)[0];
}

// ============================================================================
// 3. 应用一：斐波那契 / 爬楼梯（1 维 2 阶）
//    f[n] = f[n-1] + f[n-2]
//    [f[n], f[n-1]]ᵀ = [[1,1],[1,0]] · [f[n-1], f[n-2]]ᵀ
// ============================================================================
ll fib(ll n) {                                    // f[1] = 1, f[2] = 1
    if (n <= 2) return 1 % MOD;
    return linear_recurrence<2>({1, 1}, {1, 1}, n);
}

ll climbStairs(ll n) {                            // LeetCode 70：f[1]=1, f[2]=2
    if (n <= 2) return n % MOD;
    return linear_recurrence<2>({1, 1}, {1, 2}, n);
}

ll tribonacci(ll n) {      // LeetCode 1137：T0=0, T1=1, T2=1, T3=2, T4=4
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (n == 3) return 2 % MOD;
    // 注意：这里按 f[i] = T(i) 对齐，所以初值取 T(1)=1, T(2)=1, T(3)=2
    return linear_recurrence<3>({1, 1, 1}, {1, 1, 2}, n);
}

// ============================================================================
// 4. 应用二：k 维 1 阶递推（状态向量自己造）
//    LeetCode 1220 统计元音字母序列的数目
//    状态：V[n] = [以 a 结尾, e, i, o, u 结尾]ᵀ
//    规则（旧 → 新）：a→e ; e→a,i ; i→a,e,o,u ; o→i,u ; u→a
//    转移 dp_new[v] = Σ dp_old[u]，其中 u 能走到 v，即 A[新][旧] = 1 表示可达
//        新\旧   a  e  i  o  u
//        a       0  1  1  0  1
//        e       1  0  1  0  0
//        i       0  1  0  1  0
//        o       0  0  1  0  0
//        u       0  0  1  1  0
//    V[1] = 全 1，V[n] = A^(n-1) · V[1]，答案 = A^(n-1) 全部元素之和
// ============================================================================
ll countVowelPermutation(ll n) {
    const int K = 5;
    Mat<K> A;
    A.a[0][1] = A.a[0][2] = A.a[0][4] = 1;                     // a <- e, i, u
    A.a[1][0] = A.a[1][2] = 1;                                 // e <- a, i
    A.a[2][1] = A.a[2][3] = 1;                                 // i <- e, o
    A.a[3][2] = 1;                                             // o <- i
    A.a[4][2] = A.a[4][3] = 1;                                 // u <- i, o
    A = mat_qpow(A, n - 1);                                    // n = 1 时 A = I，答案 5 ✓
    ll ans = 0;
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++) ans = (ans + A.a[i][j]) % MOD;
    return ans;
}

/*  同类型练手（自己写，别抄）：
 *    LeetCode 552  学生出勤记录 II     —— 3 维状态机递推
 *    LeetCode 790  多米诺和托米诺平铺   —— 1 维 4 阶
 *    LeetCode 1137 第 N 个泰波那契数    —— 上面已给
 */

// ============================================================================
// 5. 动态大小矩阵（K 运行时才确定时用；常数比定长版大）
// ============================================================================
using Matrix = vector<vector<ll>>;

Matrix mul(const Matrix& A, const Matrix& B) {
    int n = A.size(), k = B.size(), m = B[0].size();
    Matrix C(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int t = 0; t < k; t++) {
            if (!A[i][t]) continue;
            for (int j = 0; j < m; j++)
                C[i][j] = (C[i][j] + A[i][t] * B[t][j]) % MOD;
        }
    return C;
}

Matrix mat_qpow(Matrix A, ll b) {
    int n = A.size();
    Matrix C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) C[i][i] = 1;
    while (b) {
        if (b & 1) C = mul(C, A);
        A = mul(A, A);
        b >>= 1;
    }
    return C;
}

// ============================================================================
// 6. 变形（需要时改 operator* 内部，结构不变）
// ============================================================================
// (1) 不取模 / 模数很大：删掉 % MOD；MOD > 1e9 时乘积要 __int128 中转
//          res.a[i][j] = (res.a[i][j] + (__int128)v * o.a[t][j]) % MOD;
// (2) 最值矩阵（min-plus 广义乘法）：+ → max(a,b)，* → +，
//         然后可用来加速"恰好走 k 步的最短路"（Floyd + 快速幂）
// (3) 带常数项的递推 f[n] = ... + d：加一维常量状态（值恒为 1）
//
// ============================================================================
// 7. 踩坑清单（每一条都踩过）
// ============================================================================
// ❌ 快速幂把 res 初始化成全 0     → 结果永远 0。必须是【单位矩阵】
// ❌ 写成 res * base 以外还要注意顺序：矩阵乘法不交换，A*B ≠ B*A
// ❌ 行列向量搞混：本模板状态是【列向量】，S[n+1] = A·S[n]；
//    若写成行向量 V[n] = V[n-1]·A，则 A 要转置，答案取的行也不同
// ❌ 伴随矩阵系数位置写反：第 0 行是 c1..ck（对应 n-1..n-k），第 1 行起是移位
// ❌ 忘记 n ≤ k 的边界特判 → 访问 init[n-1] 越界
// ❌ 指数写成 n 而不是 n-k → 整体偏移（差一个 A 的次幂）
// ❌ 乘法溢出：两个 <MOD 的数相乘，MOD 取 1e9+7 时 ≈1e18 < 9.2e18（ll 安全）；
//    MOD ≥ 1e10 必须换 __int128
// ❌ k 很大时还硬上（k=500 时 k³=1.25e8 乘 log n 直接爆）→ 回去想状态设计
