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
void wait()
{
    int a , b;
    int cnt = 0;
    cin >> a >> b;
    if(b > a)swap(a,b);
//     if(a == b)cnt = 1;
//     else
//    { while(a!=1&&b!=1)
//     {
//         cnt += a/b;
//         int t = b;
//         b = a%b;
//         a = t;
//     }
//     cnt += a/b;}
    while(a&&b)
    {
        cnt += a/b;
        int t = b;
        b = a%b;
        a = t;
    }
    cout << cnt <<endl;

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
