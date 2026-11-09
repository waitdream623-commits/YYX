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
    rep(i,1,n)cin >> a[i];
    if(n==1)
    {
        cout <<"1 1 \n";
        return;
    }
    if(n==2)
    {
        if(a[1]!=a[2])
        {
            cout << "1 2 \n";
            return;
        }
        else
        {
            cout << 0 << '\n';
            return;
        }
    }

    //找最长连续一段词频为1
    vector<int>cnt(n+1,0);
    rep(i,1,n)
    {
        cnt[a[i]]++;
    }
    int x=1,y=1,len = 0;
    int ax= 0 ,ay=0;
    bool f=0;
    rep(i,1,n)
    {
        if(cnt[a[i]]==1)
        {
            y=i;
        }
        else
        {
            while(i+1<=n&&cnt[a[i+1]]!=1)i++;
        x = i+1,y=i+1;
        if(x>n&&!f)
        {
            cout << 0 << '\n';
            return;
        }
            
        }
     
        if(y-x+1>len)
        {
            f=1;
            len = y-x+1;
            ax = x,ay= y;
        }

    }
    cout << ax << ' '<< ay << ' ';
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
