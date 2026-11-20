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
void dfs(int l ,int r)
{
    if(r-l+1<3)return;
    else
    {
        a[(r+l)/2] = 1;
        dfs(l,(r+l)/2-1);
        dfs((r+l)/2+1,r);
    }
}
void wait()
{
    int n ;cin >> n;
   if(n==2)
   {
    cout << "10";
    return ;
   }
   else if(n==1)
   {
    cout << 1;
    return ;
   }
   else
   {
    a[1] = 1;
    a[n] = 1;
    dfs(2,n-1);
    for(int i = 1;i<=n;i++)
    {
        cout << a[i];
    }
   }
  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
