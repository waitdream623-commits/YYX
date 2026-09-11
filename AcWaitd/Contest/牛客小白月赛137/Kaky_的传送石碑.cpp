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

int a[N];
void wait()
{
    int mx=0;
    int n,k;cin>>n>>k;
    
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=k;i++)
    {
        mx=max(mx,(a[i]-a[i-1])/2);
    }
    mx=max(mx,a[1]-1);
    mx=max(mx,n-a[k]);
    cout<<mx<<endl;
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
