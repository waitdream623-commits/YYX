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
//见平板，维护前m的最小次数
int cnt[N];
void wait()
{
    int n, m ,k;
    cin  >> n >> m >> k;
    rep(i,1,k)
    {
        int x; cin >> x;
        cnt[x]++;
    }
    //单调队列
    deque<int>q;
    int l =1;
    while (l<=n) {
        if(q.empty())
        {
            q.push_back(l);
            
        }
       else
       {
         while (q.size()&&cnt[l]<=cnt[q.back()]) {//
            q.pop_back();
        }
        q.push_back(l);
        if(q.front()<=l-m)q.pop_front();//注意下标

       }
        if(l<m)
        {
            cout << 0 <<' ';
        }
        else {
        cout << cnt[q.front()]<<' ';
        }
        l++;
    }
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
