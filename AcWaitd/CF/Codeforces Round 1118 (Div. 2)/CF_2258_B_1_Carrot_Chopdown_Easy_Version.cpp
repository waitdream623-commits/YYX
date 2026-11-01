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
void wait()
{
    int n, m;
    cin >> n >> m;

    map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+1+n);
    int ret=0;
    int j=1;
    for(int i=1;i<=m;i++)//枚举长度
    {
        while(i>a[j])j++;//移到能提供长度的地方
        ret=max(ret,n-j+1+mp[i*2]);//加上两倍位置
        
    }
    cout << ret << '\n';
 
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
