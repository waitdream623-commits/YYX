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
int a[6];
void wait()
{
    int n;cin >> n;
        cout << "? " << 1 <<' '<<n<<'\n';
         cin >>a[1];
        if(a[1]==0||a[1]==n)
        {
            cout << "! NO\n";
            return;
        }
        //此时有0/1
        int one = a[1],zero = n-one;
        cout << "? " << n-zero+1 <<' '<<n<<'\n';
        cin >> a[2];
        
        if(a[2]==0)//0都在末尾
        {
              cout << "! NO\n";
            return;
        }
        else
        {
              cout << "! YES\n";
            return;
        }

}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
