#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
void solve()
{
    int x,y,z;
    cin>>x>>y>>z;
    ll ret=0;
    if(z==0)
    {
        ret+=y;
        ret++;
        cout<<ret<<endl;
        return;
    }
    if(z>=x)
    {
        ret+=x*3+(z-x+y)*2;
        cout<<ret<<endl;
        return;
    }
    ret+=z*3+y*2+1;
    cout<<ret<<endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
