#include <bits/stdc++.h>
#include <algorithm>
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
void wait()
{
    vector<int>s;
    int n;cin>>n;
    
    int mx;cin>>mx;
    s.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>mx)
        {
            mx=x;
            s.push_back(i);
        }
    }
    int r=0;
    if(s.size()<2)cout<<1<<" "<<0;
    else
   { for(int i=1;i<s.size();i++){
        r=max(s[i]-s[i-1],r);
    }
    cout<<s.size()<<" " <<r;}
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
