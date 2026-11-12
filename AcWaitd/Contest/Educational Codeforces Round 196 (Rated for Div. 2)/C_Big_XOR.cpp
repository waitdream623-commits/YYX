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
const int N = 200000+10;
array<int,20> cnt[N];
int msb[N];
void build()
{
    for(int i =1;i<=200000;i++)
    {
        int x= i;
        cnt[i] = cnt[i-1];//复用
        rep(j,0,19)
        {
            if((x>>j)&1){cnt[i][j]++;
            msb[i] = max(msb[i],j);}
        }
    }
}
void wait()
{
    int n;cin >> n;
    vector<array<int,20>> now(cnt, cnt + n + 1);
    vector<int>ans(n+1,0);
    int r = n;
    int x = r;
    ans[n]=1;
        rep(j,0,msb[n])
        {
            if((x>>j)&1)
            {
                now[n][j+1]++;//扩大
                now[n][j]--;
            }
        }
        r--;
        for(int i = n-1;i>0;i--)
        {
          
            // if((msb[i]+1)!=msb[n]+1&&now[n][msb[i]+1]%2==1&&cnt[n][msb[i]+1]%2==0)
            // {
            //     break;
            // }
            if(now[n][msb[i]+1]%2==1)//该位是奇数
            continue;
            //上一位是偶数，这一位提一位往上面，直到，上一位是奇数，原先是偶数，后面必然比原数大，满足要求
            ans[i]=1;
            int x= i;
            rep(j,0,msb[x])
            {
                if((x>>j)&1)
                {
                    now[n][j+1]++;//扩大
                    now[n][j]--;
                }
            }
        }
        rep(i,1,n)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    build();   // 只建一次表，别放进 wait()
    while (T--) {
        wait();
    }
    return 0;
}
