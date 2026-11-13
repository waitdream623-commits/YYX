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
array<int,4>a[N];

void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        int x,y,c;
        cin >> x >> y >>c;
        a[i] = {x,y,c,i};
    }
    sort(a+1,a+1+n);
    ll t = a[1][0];
    int q[10];
    vector<ll>ans(n+1,0);
    rep(i,0,9)q[i]=0;
    rep(i,1,n)
    {
        auto [x,y,c,index] = a[i];
        if(t<x)t=x;

        if(y>t+c)
        {
            //维持最大
            if(q[i%10]>y)
            ans[index]=  q[i%10]-y;
            else
            {
                q[i%10] = y;
                ans[index]= 0 ;
            }
            
        }
        else
        {
            if(q[i%10]!=0)
            {
                int tmp = q[i%10];
                if(t+c<tmp)//此时y<t+c,,t+c小于tmp说明之前还没失效
                {
                    ans[index]= tmp-y;
                }
                else
                {
                    q[i%10]=0;
                    ans[index]= t+c-y;
                }
            }
            else
            ans[index]= t+c-y;
        }
        t+=c;
    }
    rep(i,1,n)
    {
        cout << ans[i] <<' ';
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
