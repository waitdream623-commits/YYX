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
int a[N],r[N];

void wait()
{
    int n , k;
    cin >> n >> k;
    rep(i,1,n)cin >> a[i];
// r[i]：原数组中以 i 开头、向右的最长不下降子序列长度
// 从右往左遍历，转化为求以当前元素结尾的最长不上升子序列
    vector<int>f;
    for(int i = n; i>0;i--)
    {
        auto pos = upper_bound(f.begin(),f.end(),a[i],greater<int>());//小于x位置
        if(pos == f.end())
        {
            f.push_back(a[i]);
            r[i] = f.size();
        }
        else
        {
            *pos = a[i];
            r[i] = pos-f.begin()+1;
        }

    }
    vector<int>dp;//维持[0,i-k-1]的能连接a[i]的子序列，也就是跑最长不下降
    int ans = 0;
    for(int i = k+1;i<=n;i++)
    {
       // 1. 查询：左侧有多长的子序列可以接到 a[i]
    int len = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    ans = max(ans, len + k + r[i]);

    // 2. 插入：为下一轮准备，把 a[i-k] 加入左侧前缀
    auto it = upper_bound(dp.begin(), dp.end(), a[i-k]);
    if (it == dp.end())
        dp.push_back(a[i-k]);
    else
        *it = a[i-k];
     
    }
    //特殊情况i=n+1时
    ans = max(ans,(int)f.size()+k);
    cout << ans;
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
