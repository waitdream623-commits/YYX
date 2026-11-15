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

//     set<int> getLIS(vector<int>& a) {
//         int n = a.size();
//         vector<int> f(n + 1);//存储长度为i的最小末尾
//         vector<int> pos(n + 1, -1);// pos[k]：长度为 k 的递增子序列中，最小末尾元素的原数组下标
//         vector<int> pre(n, -1);//i号节点的前驱
//         int len = 0;

//         for (int i = 0; i < n; i++) {
//             int k = upper_bound(
//                 f.begin() + 1, f.begin() + len + 1, a[i]
//             ) - f.begin();

//             // 先记录：当前元素接在哪个元素后面
//             if (k > 1) {//k位置时替换点，i的前驱就是k-1长度的位置
//                 pre[i] = pos[k - 1];
//             }

//             f[k] = a[i];
//             pos[k] = i;//更新长度为k的位置
//             if (k > len) len = k;
//         }

//         set<int> ans;
//         if (len == 0) return ans;

//         // 从最后一个元素沿前驱倒着找
//         for (int i = pos[len]; i != -1; i = pre[i]) {
//             ans.insert(i);
//         }
      
//         return ans;
//     }
// void wait()
// {
//     int n;cin >> n;
//     vector<int>a(n);
//     for(auto& e:a)
//     {
//         cin >> e;
//     }
//     reverse(a.begin(),a.end());
//     auto ans = getLIS(a);
//     int last = 0;
//     int cnt = 0;
//     rep(i,0,n-1)
//     {
//         if(ans.count(i))continue;
//         else
//         {
//             if(a[i]<last)cnt++;

//             last = a[i];
//         }
//     }
//     cout << cnt<<'\n';
// }
void wait()
{
    int n;
    cin >> n;

    int x = INT_MAX, y = INT_MAX;
    int ans = 0;

    while (n--) {
        int v;
        cin >> v;

        if (x > y) swap(x, y);

        if (v <= x) {
            x = v;
        } else if (v <= y) {
            y = v;
        } else {
            ++ans;
            x = v;
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
