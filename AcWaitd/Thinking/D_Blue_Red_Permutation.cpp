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
PII a[N];
char b[N];
int cnt[N];
void wait()
{
    int n;cin >> n;
    rep(i,1,n)
    {
        int x;cin >>x;
        a[i] = {x,i};
    }
    sort(a+1,a+1+n);
    rep(i,1,n)cin >> b[i];
  
    //处理负数和大于n的
    rep(i,1,n)
    {
        auto& [x,y] = a[i];
        
        if(x<0&&b[y]=='R')x= 1;
        else if((x<0&&b[y]=='B')||(x>n&&b[y]=='R'))
        {
            cout << "NO\n";
            return;
        }
        else if(x>n&&b[y]=='B')
        {
            x = n;
        }

    }
      //处理r后缀个数
    int s =0;
   
    for(int i =n;i>0;i--)
    {
        if(b[a[i].second]=='R')s++;
        cnt[i] =s;
    }
    int l = 0;
    rep(i,1,n)
    {
        if(b[a[i].second] == 'B')
        {
            l++;
        }
        if(a[i].first<l||n-a[i].first+1<cnt[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
