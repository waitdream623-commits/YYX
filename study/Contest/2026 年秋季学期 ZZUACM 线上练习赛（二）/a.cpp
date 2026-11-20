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
    int n ,d , L ,R;
    cin >> n >> d >> L >>R;
    rep(i,1,n)cin >> a[i];
    ll ans = 0;
    // deque<int>q;
    // rep(l,1,n)
    // {
    //     while(!q.empty()&&a[l]>a[q.back()])q.pop_back();
    //     q.push_back(l);
    //     if(a[l]<L)//区间内必然大于L
    //     {
    //         while (q.size())
    //         {
    //             q.pop_back();
    //         }
            
    //     }
    //     if(q.size()&&l-q.front()+1>d)q.pop_front();
    //     if(q.size()&&l>=d&&a[q.front()]<=R)ans ++ ;

    // }
    int len = 0;

    rep(i,1,n)
    {
        if(L <= a[i] && a[i] <= R)
            len++;
        else
            len = 0;

        if(len >= d)ans++;
    }

    cout << ans << '\n';
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
