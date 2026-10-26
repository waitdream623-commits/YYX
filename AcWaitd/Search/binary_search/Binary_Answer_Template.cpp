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

/* ================= 二分答案：把"求最优"变成"判断可行" =================
   三个前提，缺一不可：
   1. 答案是一个数，且有明确值域 [L, R]
   2. 能写 check(x)：x 是否可行，O(n) 或 O(n log n)
   3. check 的可行性随 x 单调（要么"可行..可行,不可行..不可行"，要么反过来）

   两种模板只差一个上取整：
   模板 A（最大化答案，找最后一个可行的）: mid = (lo + hi + 1) >> 1, 可行 -> lo = mid
   模板 B（最小化答案，找第一个可行的）  : mid = (lo + hi) >> 1,     可行 -> hi = mid
*/

// ---------- 模板 A：最大化答案 ----------
// check(x) 单调：x 小一定可行，x 大不可行
// ll lo = L, hi = R;
// while (lo < hi)
// {
//     ll mid = (lo + hi + 1) >> 1;
//     if (check(mid)) lo = mid;
//     else hi = mid - 1;
// }
// 答案 = lo

// ---------- 模板 B：最小化答案 ----------
// check(x) 单调：x 大一定可行，x 小不可行
// ll lo = L, hi = R;
// while (lo < hi)
// {
//     ll mid = (lo + hi) >> 1;
//     if (check(mid)) hi = mid;
//     else lo = mid + 1;
// }
// 答案 = lo

// ---------- 实数二分：迭代固定次数，比 eps 判断稳 ----------
// double lo = ..., hi = ...;
// for (int iter = 0; iter < 100; iter++)
// {
//     double mid = (lo + hi) / 2;
//     if (checkReal(mid)) hi = mid;   // 视单调方向决定改 lo 还是 hi
//     else lo = mid;
// }
// 答案 = hi

/* ================= 例题：P1873 [COCI2011/2012#5] EKO / 砍树 =================
   题意：选刀片高度 h，能得到的木材总量 = sum(max(0, a[i] - h))，要 >= m，求最大的 h
   check(h) 单调：h 越小砍得越多
*/
int n, mlen;
int tree[N];

bool check(ll h)
{
    ll sum = 0;
    rep(i, 1, n)
    {
        if (tree[i] > h) sum += tree[i] - h;
        if (sum >= mlen) return true;   // 提前退出，顺便防溢出
    }
    return false;
}
void wait()
{
    cin >> n >> mlen;
    int mx = 0;
    rep(i, 1, n)
    {
        cin >> tree[i];
        mx = max(mx, tree[i]);
    }
    int lo = 0, hi = mx;                // 模板 A：最大化
    while (lo < hi)
    {
        int mid = (lo + hi + 1) >> 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
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

/* ================= 常见 check 骨架（做题时对号入座） =================
   P2678 跳石头        : 最大化最小值 -> check(最小间距 d) = 要搬走的石头是否 <= M
   P1182 数列分段 II   : 最小化最大值 -> check(每段和 <= S) = 最少需要几段，是否 <= M
   P3853 路标设置      : 最小化最大值 -> check(最大间隔 d) = 需要加的路标数是否 <= K
   P1083 借教室        : 二分订单前缀 + 差分 O(n)，check(前 x 个订单) 是否够用
   P3743 kotori 的设备 : 实数二分 + 贪心判断总供电是否够
   P2824 [HEOI2016]排序 : 二分答案 mid + 把 >= mid 记 1，(0,1) 线段树维护排序
*/
