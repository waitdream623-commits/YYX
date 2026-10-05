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
//对于该题，分析可知，a_k后每个数都可以选，总共选n-k+1个，
//对于a_m-k+1可取范围左边界为m=k时候(1,m-k+1),a_k(k,n);
//分为边界交叉与不交叉
//对于不交叉，两边从m-k+1->1,和k->n只能二选1，优先选大的，对于交叉情况，交叉部分必选，后转为不交叉
int a[N];
void wait()
{
    priority_queue<int>q;
    int n, k; cin >> n>> k;
    //取边界
    rep(i, 1, n)
    {
        cin >> a[i];
     
    }
    long long ans=0;
    //不交叉封装函数
    auto cacu = [&](int r1,int l1)->long long{
        int cnt = n-k+1;
        long long ans = 0;
        while(cnt--&&r1>=0&&l1<=n)
        {
            if(a[r1]>a[l1])ans+=a[r1];
            else
            ans += a[l1];
            r1--;l1++;//移位
        }
        while(cnt--&&r1>=0)ans+=a[r1--];
        while(cnt--&&l1<=n)ans+=a[l1++];
        return ans;
    };
    if(n-k+1>=k){
        int j = k;
        while(j<=n-k+1)
        ans+=a[j],j++;
    //此时取不交叉状态
        ans += cacu(k-1,n-k+1+1);
    }
    else
    ans = cacu(n-k+1,k);
    cout<<ans<<'\n';
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
