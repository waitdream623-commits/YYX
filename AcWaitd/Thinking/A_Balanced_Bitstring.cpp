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
    string s;cin >> s;
    rep(i,0,k-1)//因为要保证每一组个数相同需要，左边界与右边界下一个相同，因此可以先每个位置跳k比较是否相同，对于？，也是比较如果都是？是对的，如果有确定值即必须将？更改
    {
        int j = i+k;
        while(j<n)
        {
            if(s[i]==s[j])
            j+=k;
            else//不相同
            {
                if(s[i]=='?'&&s[j]!='?')
                {
                    s[i]=s[j];
                    j+=k;
                }
                else if(s[i]!='?'&&s[j]=='?')
                {
                    j+=k;
                }
                else//不是问号
                {
                      cout << "NO\n";
                     return;
                }
            }
        }
    }
    //统计区间内是否满足
    int one=0,z=0;
    rep(i,0,k-1)
    {
        if(s[i]!='?')
        {
            if(s[i]=='1')
            {
                one++;
            }
            else
            {
                z++;
            }
        }
    }
    if(one>k/2||z>k/2)//均小于说明可以用？补
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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
