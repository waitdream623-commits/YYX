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
int b[N];
int gcd(int x ,int y)
{
    return y==0?x:gcd(y,x%y);
}
void wait()
{
    int l ;
    cin >> l;
    ll sum = 0;
    for(int i = 1; i <=l; i++ )
    {
        cin >> a[i];
        //看能否分成两半
        sum += a[i];
    }
    int c ; cin >> c;
    //对于圆，裴蜀定理，能否凑出最大那个,有误，最大的那个也可以由多个拼接
    rep(i,1,c)
    {
        cin >> b[i];
    }
    //没有圆
    if(c == 0 )cout << "NO" << '\n';
    else
    {
        // 处理圆
        sort(b+1,b+1+c);
        int x  = 0;
        for(int i =2 ;i <c;i++)
        {
            x = gcd(a[i-1], a[i]);
        }    
        if(c>2&&a[c]%x!=0)
        {
            cout << "NO\n";
            return ;
        }
        else if(c == 2)
        {
            if(b[1]!=b[2])
            {
                cout << "NO\n";
                return ;
            }
        }
        else if((c-1)%2==0)
        {
            cout << "NO\n";
                return ;
        }
        //对于圆，对于小的部分中间需要有过度半圆，使其拼接,例如1，3，4，1与3直接没有过度圆如果是1，1，2，4即可
        //处理直线能否分为两部分
        //背包问题；
        if(sum%2!=0)
        {
              cout << "NO\n";
            return ;
        }
        vector<vector<bool>>dp(l+1,vector<bool>(sum/2+1,0));
        for(int i = 0;i <= l ;i++)dp[i][0] = 1;
        for(int i = 1; i<= l;i++)
        {
            for(int j = 1;j<=sum/2;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=a[i])dp[i][j]=dp[i][j]|dp[i-1][j-a[i]];
            }
        }
        if(dp[l][sum/2])
        {
            cout << "YES\n";

        }
        else
        {
            cout << "NO\n";
        }
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
