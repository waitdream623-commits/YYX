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
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int start=0;
void dfs(int n,int be, int i,int j)
{
    if(n==1){cout<<be+1;return;}
    if(i==1||j==1||i==n||j==n)
    {
        if(i==1)cout<<be+j;
        else if(j==n)cout<<be+n-1+i;
        else if(i==n)cout<<be+n*2-1+n-j;
        else cout<<be+4*n-4-i+2;//已经舍弃i==1
        return;
    }
    dfs(n-2,be+4*n-4,i-1,j-1);
}
void wait()
{   
    int n,i,j;
    cin>>n>>i>>j;
    dfs(n,0,i,j);
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
