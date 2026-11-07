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
    int n;cin >> n;
    map<int,int>mp;
    rep(i,1,n)
    {
        cin >> a[i];
       
    }
    vector<PII>dif;
    for(int i = n;i>0;i--)
    {
        dif.push_back({abs(a[i]-a[i+1]),i});
    }
    sort(dif.begin(),dif.end(),greater<PII>());
    //找第一大与第二大之间的差值max*2是否会变大，
    int ans = dif[0].first;
    int k = dif[0].second;
    ans = min(ans,max(abs(a[k]-2*a[k+1]),abs(2*a[k+1]-a[k+2])));
    

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
