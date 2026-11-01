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
const int N = 1e6 + 10;
//因为k>=1;所以每次都可以删掉第二个数k=1时，k等于2删掉第三个数，因此，只有头和尾部不能删除，最大公因数只会小于等于他们俩
//所以只需要返回首和尾
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void wait()
{   
    int n; cin >> n;
    int head;
    cin >> head;
    int x=0;//记得初始化，0能被所有数整除
    rep(i,2,n)
    {
        
        cin >> x;
    }
    int d=gcd(head,x);
    cout << d << '\n';
    
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
