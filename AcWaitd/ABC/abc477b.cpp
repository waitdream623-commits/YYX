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
pair<long long,int> a[N];
void wait()
{
    int n , d;
    cin >> n>>d;
    rep(i,1,n)
    {
        cin >>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    vector<int>b;
    //对于第一个
    a[0].first=-1e9;
    a[n+1].first=1e18;
    for(int i=1;i<=n;i++)//加入原先下标
    {
        if((a[i].first-a[i-1].first>=d)&&(a[i+1].first-a[i].first>=d))b.push_back(a[i].second);

    }
    sort(b.begin(),b.end());
    cout<<b.size()<<'\n';
    for(auto e:b)
    cout << e<<' ';
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
