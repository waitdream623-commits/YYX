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
bool vis[N];
void wait()
{
    int n, k;cin  >> n >> k;
    rep(i,1,n)cin >> a[i];
    //最后一个为最大 ，第k大为倒数
    //双指针
    //在最大到第k-1大都要满足
    //只能交换一次，
    //找到n-1或者
    memset(vis,0,sizeof vis);
    rep(i,1,n-k+1)
    {
        vis[a[i]] = 1;
    }
    int x = 0;//没有的
    for(int i = 0;i<=n;i++)
    {
        if(!vis[i])
        {
            x = i;
            break;
        }
    }
    if(x>n-k)cout << -1 <<'\n';
    else
    {
        int r = 0;

        for(int i = n;i>=0;i--)
        {
            if(a[i] == x)
            {
                r= i;
                break;
            }
        }
        int l = 0;
        for(int i = 0;i<=n;i++)
        {
            if(a[i] >n-k)//找一个可以交换的位置
            {
                l= i;
                break;
            }
        }
        cout << l << ' '<< r <<'\n';
    }
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
