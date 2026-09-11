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
void wait()
{
    ll n,k;cin>>n>>k;
    vector<ll>a(n);//堆上开辟
    for(int i=1;i<n;i++)cin>>a[i];
    partial_sum(a.begin(),a.end(),a.begin());
    //找到范围2*k的最大值
    ll mx=0;
    for(int i=n-1;i>0;i--)
    {
        int j=i-k;
        if(j<0)j=0;//去除了第一个，不对
        mx=max(mx,a[i]-a[j]);
    }
    cout<<a[n-1]-mx;
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
