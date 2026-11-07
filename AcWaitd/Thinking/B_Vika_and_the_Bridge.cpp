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
    int k ; cin >> k;
    vector<vector<int>>dif(k+1);
    rep(i,1,n)
    {
        cin >> a[i];
        if(dif[a[i]].empty())dif[a[i]].push_back(0);
        dif[a[i]].push_back(i);//每种颜色下标差值
    }
    //找每种颜色差值最大的最小，且考虑第二大；
    int mn = 1e9;
    int x = 0;
    int last = 1;
    rep(i,1,k)
    {
        last = 0;
        for(int j = 1;j<dif[i].size();j++)
        {
            int t =dif[i][j];
            dif[i][j] -= last+1;
            last = t;
        }
        //最后一步到n+1
        dif[i].push_back(n-last);
        sort(dif[i].begin(),dif[i].end(),greater<int>());
            mn = min(max(dif[i][0]/2,dif[i][1]),mn);
        
    }

    cout << mn<<'\n';
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
