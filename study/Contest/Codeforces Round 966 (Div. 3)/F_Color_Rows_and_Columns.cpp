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
    int n,k;cin >> n >> k;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    rep(i,1,n)
    {
        int a,b;
        cin >> a >>b;
        q.push({min(a,b),max(a,b)});
    }
    ll ans =0 ;
    while(q.size())
    {
        auto [a,b] = q.top();
        q.pop();
        if(k>=a+b)
        {
            k-=a+b;
            ans+=a*b;
        }
        else
        {
            if(a!=b)
            {
                if(k>=b-a)//转化为正方形
                {
                    ans+=(b-a)*a;
                    k-=b-a;
                    
                        int t = k/2;
                        ans+=t*(2*a-1+2*(a-t+1)-1)/2;
                        a=a-t;
                        k%=2;//可能是奇数
                        if(k)//至少k分，可能多得一分1*1时
                        {
                            ans+=a;
                        }
                    k = 0;
                    break;

                }
                else//结束了
                {
                    ans +=k*a;
                    k=0;
                    break;
                }
            }
            else
            {
                 int t = k/2;
                        ans+=t*(2*a-1+2*(a-t+1)-1)/2;
                        a=a-t;
                        k%=2;//可能是奇数
                        if(k)//至少k分，可能多得一分1*1时
                        {
                            ans+=a;
                        }
                         k = 0;
                        break;
            }
        }
        

    }
    if(k)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans<<'\n';
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
