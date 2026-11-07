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
int a[N],b[N];
void wait()
{
    //只能临近换
    int n;cin >> n;
    rep(i,1,n)
    {
        int x; cin >> x;
        a[i] = x;
    }
    rep(i,1,n)
    {
        int x;cin >> x;
        b[i] = x;
    }
    int len =0;
    vector<PII>ans;
    rep(i,1,n)
    {
        rep(j,1,n-i)
        {
            if(a[j]>a[j+1])
            {swap(a[j],a[j+1]);
            ans.push_back({1,j});}
        }
    }
     rep(i,1,n)
    {
        rep(j,1,n-i)
        {
            if(b[j]>b[j+1])
           { swap(b[j],b[j+1]);
            ans.push_back({2,j});}
        }
    }
       rep(i,1,n)
    {
       
            if(a[i]>b[i])
           { swap(a[i],b[i]);
            ans.push_back({3,i});}
        
    }
    cout << ans.size()<<'\n';
    for(auto [op,i]:ans)
    {
        cout << op << ' ' << i << '\n';
    }
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
