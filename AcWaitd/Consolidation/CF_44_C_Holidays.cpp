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
int diff[N];
void wait()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)diff[i]=0;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        diff[a]++;
        diff[b+1]--;
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        diff[i]=diff[i-1]+diff[i];
        if(diff[i]==0||diff[i]>=2)
        {cout<<i<<" "<<diff[i];
            flag=0;
        break;}
    }
    if(flag)cout<<"OK";
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
