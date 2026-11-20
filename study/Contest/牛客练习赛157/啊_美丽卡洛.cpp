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
const int N = 1e6 + 10;
int a[N];

 int numDecodings(string s) {
        int n=s.size();
        int a=0,b=1,c=0;//a=dp[i-2],b=dp[i-1];
        for(int i=1;i<=n;i++)//下标整体加一
        {
            c=0;//每次都是新的
            if(s[i-1]!='0')
            c+=b;
           //两个
           if(s[i-2]!='0'&&i-1>0)
           {
            int x = (s[i-2]-'0')*10 +s[i-1]-'0';
            if(x>0&&x<=26)
            {
                c+=a;
                
            }
           }
          
        a=b;
        b=c;
        }
        cout<<c;
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;  // 多测时取消注释
    while (T--) {
       numDecodings("226");
    }
    return 0;
}
