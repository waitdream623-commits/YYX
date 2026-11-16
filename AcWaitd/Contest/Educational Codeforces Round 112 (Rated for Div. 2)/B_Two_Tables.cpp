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
    int W,H;cin >> W >> H;
    int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
    int w,h;cin >> w >> h;
    // if(w>W-(abs(x2-x1))||h>H-abs(y2-y1))
    // {
    //     cout << -1 <<'\n';
    // }
    int hx = 1e9;
    //放在上下
    int h1 = y1,h2 = H-y2;
    if(W>=w&&abs(y1-y2)+h<=H)
    {
    if(h<=max(h1,h2))//已经可以满足
    {
        hx = 0;
    }
    else{
        hx = abs(h-max(h1,h2));
    }

    }
    int w1 = x1,w2 = W-x2;
    int wx = 1e9;
    if(H>=h&&abs(x1-x2)+w<=W)
    {
        if(w<=max(w1,w2))
        {
            wx=0;
        }
        else
        {
            wx = abs(w-max(w1,w2));
        }
    }
    if(wx==1e9&&hx==1e9)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << min(wx,hx)<<'\n';
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
