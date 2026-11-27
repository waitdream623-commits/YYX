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
void wait()
{
    int n,m;cin >> n >> m;
    vector<vector<int>>a(n+1);
    int k = (n+m-1)/m;
    rep(i,1,n)
    {   
        int x;cin >>x;
        a[x].push_back(i);
        k=max(k,(int)a[x].size());
    }
    vector<int>ans(n+1,0);
    int x = 1;
    for(auto& e:a)
    {
        for(auto i:e)
        {
            ans[i]=x;
            x++;
            if(x>k)x=1;//必然够
        }
    }
    cout << k << '\n';
    rep(i,1,n)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
