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
    int n;
    cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    ll ans =0 ;
    if(n==1)
    {
        cout << a[1]<<"\n";
        return;
    }
    rep(i,1,n-1)
    {
        if(a[i]==a[i+1])ans|=a[i];
        else //二进制1001与1000最多相等，//1010与1000可以增加，//1000与0100，可以变为全是1，
        //此时从大的找到小的没有的1；
        {
            
            if(a[i]<a[i+1])
            {
                int t= 30,j = 30;
                while(t==j)
                {
                                               
                while (t >= 0 && !(a[i+1] >> t & 1)) t--;     // 找最高位；没找到会停在 -1
          
                while (j >= 0 && !(a[i] >> j & 1)) j--;     // 找最高位；没找到会停在 -1
                if(t==j)t--,j--;

                }
            
         ll m = (t >= 0) ? ((1LL << (t+1)) - 1) : 0;    
         ans |= m|a[i+1];
            }
            else
            {
                int t= 30,j = 30;
                while(t==j)
                {
                                               
                while (t >= 0 && !(a[i] >> t & 1)) t--;     // 找最高位；没找到会停在 -1
          
                while (j >= 0 && !(a[i+1] >> j & 1)) j--;     // 找最高位；没找到会停在 -1
                if(t==j)t--,j--;

                }
            
         ll m = (t >= 0) ? ((1LL << (t+1)) - 1) : 0;    
         ans |= m|a[i];
            }
        }
    }
    cout << ans<<"\n";
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
