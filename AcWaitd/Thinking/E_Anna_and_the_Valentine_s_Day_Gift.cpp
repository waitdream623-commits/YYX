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
PII cnt[N];

void wait()
{
    int n,m;cin >> n >> m;
    rep(i,1,n)
    {
        int x;cin >> x;
        int t = x;
        int c = 0;
        int num = 0;
        bool f =0;
        while(t)
        {
            if(!f&&t%10==0)//记录后导零
            {
                c++;
            }
            else f=1;
            t/=10;
            num++;
        }
        cnt[i] = {c,num};
    }
    sort(cnt+1,cnt+1+n,greater<PII>());
    int ans = 0;
    rep(i,1,n)
    {
        auto [x,y] = cnt[i];
        if(i%2==1)
        {
           ans+= y-x;
        }
        else
        {
            ans +=y;
        }
    }
    if(ans>=m+1)
    {
        cout << "Sasha\n";
    }
    else
    {
        cout << "Anna\n";
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
