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
    int x=0;
    rep(i,0,n-1)
    {
        int t;cin >> t;
        a[i] = t;
        x^=t;
    }
    if(x)
    {
        int pr = 0, pr_ind = -1;
		for (int i = 0; i < n; i++) {
				pr ^= a[i];
				if (pr == x) {
						pr_ind = i;
						break;
				}
		}


		int suf = 0, suf_ind = -1;
		for (int i = n - 1; i >= 0; i--) {
				suf ^= a[i];
				if (suf == x) {
						suf_ind = i; 
						break;
				}
		}

		if (suf_ind > pr_ind)
				cout << "YES\n";
		else
				cout << "NO\n";
}

    else
    {
        cout << "YES\n";
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
