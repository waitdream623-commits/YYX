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
int a[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    if(n%2==1)//奇数不可行
    {
        cout << -1 <<'\n';
        return;
    }
    ll ans = 0;
    int l =2,r = n-1;
    while(l<=n)
    {
            ans+=abs(a[l]-a[l-1]);
            l+=2;
            //如果交错相同，a b a b,前a后b，b,a a,b,也不用，
            // if(l>2&&a[l]==a[l-2]&&a[l-1]!=a[l-3])//跟前一个区块相同,如果都相同说明可以交替
            // {
            //     ans+=2;//前一个区块一起改
            // }
            if(l>2&&a[l]==a[l-2]&&a[l-1]==a[l-2])//都相同
            ans+=2;
    }
    cout << ans<<'\n';

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
