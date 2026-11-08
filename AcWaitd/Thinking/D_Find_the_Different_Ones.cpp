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
int p[N];//分块
void wait()
{
    int n; cin >> n;
    rep(i,1,n)cin >> a[i];
    int cnt = 0;
    rep(i,1,n)
    {
        int l = i;
        while(i<n&&a[i] == a[i+1])i++;
        p[++cnt] = l;
    }
    int q;cin >> q;
    while(q--)
    {
        int l,r;cin >> l >> r;
        if(r-l+1<2)
        {
            cout << -1 << ' ' << -1 << '\n';
            continue;

        }
        int pos = upper_bound(p+1,p+1+cnt,l)-p-1;//找到左下标，如果r>=pos+1位置说明有
        auto p2 = pos+1;//p2可能无效，最后一块
        
        if(p2>cnt||r<p[p2])
        {
            cout << -1 << ' ' << -1 << '\n';
        }
        else
        {
            cout << l << ' ' << p[p2]<< '\n';//左端点可能拿不到，右边必定有p2,可能跨多个区
        }
        
    }
    cout << '\n';
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
