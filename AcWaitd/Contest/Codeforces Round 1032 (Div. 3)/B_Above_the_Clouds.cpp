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
    int n;cin >> n;
    string s ;
    cin >> s;
    vector<bool>vis(1000,0);//太小了
    vis[s[n-1]] =1;//先加入,为c末尾,
    vis[s[0]] = 1;
    for(int i = 1;i<n-1;i++)//a,b拆分，分为[0,a],b ,[b+1,n];
    {
        char e =s[i];
        if(vis[e])//有相同，但是不是最后一个，要给c,可能相同在最后一个
        //改为不能是第一个，先加入最后一个
        {
            cout << "Yes\n";
            return;
        }
        vis[e] = 1;
    }
    cout << "No\n";
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
