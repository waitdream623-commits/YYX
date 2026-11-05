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
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
void solve()
{
    int n,k;cin>>n>>k;
    if(n<=k)
    {
        cout<<k/n+(k%n!=0)<<"\n";
    }
    else
    {
        int t=n/k+(n%k!=0);//记录n是k的倍数
        
        //t*k>n;
        cout<<t*k/n+(t*k%n!=0)<<endl;//转化为k>n;
    }
    int a[]={1,2,3};
    //debug(a);
    int b[][3]={1,2,3,4,5,6};
    //debug(b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
