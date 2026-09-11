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
void wait()
{
    string s;cin>>s;
    int sum=0;
    int mn=999;
    bool flag=1;
    for(auto e:s)
    {
        if(e-'0'==0)flag=0;
        mn=min(mn,e-'0');
        sum+=e-'0';
    }
    sum+=9-(int)flag;//可以在操作前或者中间，意味着，如果最开始存在0，+9，不存在0，猫猫会优先从左边开始拿，
    //让猫猫先拿走到1，改变为最大
    cout<<sum<<endl;
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
