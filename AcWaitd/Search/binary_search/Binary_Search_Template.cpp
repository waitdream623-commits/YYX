#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;

/* ================= 二分查找四件套（闭区间写法，答案一定落在 [lo, hi] 里） =================
   前提：a[1..n] 单调不降
   记忆：只写"第一个 >= x"，其余三个都由它推出来
*/
int firstGE(int n, int *a, int x)      // 第一个 >= x 的下标；不存在返回 n+1
{
    int lo = 1, hi = n + 1;            // 把"不存在"也当成一个合法落点 n+1
    while (lo < hi)
    {
        int mid = lo + ((hi - lo) >> 1);
        if (a[mid] >= x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
int firstGT(int n, int *a, int x)      // 第一个 > x 的下标；不存在返回 n+1
{
    int lo = 1, hi = n + 1;
    while (lo < hi)
    {
        int mid = lo + ((hi - lo) >> 1);
        if (a[mid] > x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
int lastLE(int n, int *a, int x) { return firstGT(n, a, x) - 1; }  // 最后一个 <= x；不存在返回 0
int lastLT(int n, int *a, int x) { return firstGE(n, a, x) - 1; }  // 最后一个 < x；不存在返回 0
int countEq(int n, int *a, int x) { return firstGT(n, a, x) - firstGE(n, a, x); }  // 等于 x 的个数

/* STL 等价写法（要会手写，但比赛优先用 STL）：
   int p = lower_bound(a + 1, a + n + 1, x) - a;   // 第一个 >= x
   int q = upper_bound(a + 1, a + n + 1, x) - a;   // 第一个 > x
   p == n+1 表示不存在
*/

/* 易错点：
   1. mid 用 lo + ((hi - lo) >> 1)，别写 (lo + hi) / 2（lo+hi 可能溢出）
   2. 找"最后一个满足"时 mid 必须上取整 (lo+hi+1)>>1，否则死循环
   3. 想清楚答案是"第一个可行"还是"最后一个可行"，两种模板不能混
   4. 用 n+1 / 0 当哨兵，比每次特判"找没找到"省事
*/

int a[N];
void wait()
{
    // 例题：P2249 【深基13.例1】查找
    // 输出每个 x 第一次出现的位置，不存在输出 -1
    int n, q;
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        int p = firstGE(n, a, x);
        cout << (p <= n && a[p] == x ? p : -1) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
