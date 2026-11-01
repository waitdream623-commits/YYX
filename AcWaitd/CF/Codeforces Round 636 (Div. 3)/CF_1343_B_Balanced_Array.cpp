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
//对于奇数，连续的每个位置比对应位置，小1，如果要补全，必须比偶数大于n/2-1个，因此要求其为奇数，如果选择两个大的(不可能选两个大的，只能选一个)
void wait()
{
    int n;cin >> n;
    if((n/2-1)%2==0)
    {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";

    for(int i = 1;i<=n/2;i++)
    {
        cout << i*2<<" ";
    }
    int x = 1;
    for(int i = 1 ; i<n/2;i++)
    {
        cout << x<<" ";
        x+=2;
    }
    cout << n+n/2-1<<endl;
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
