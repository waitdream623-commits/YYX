#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
void slove()
{
    int n;cin>>n;
    ll ret=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        ret^=x;
    }
    if(ret==0)
    {
        cout<<"lose";
    }
    else
    cout<<"win";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        slove();
    }
    return 0;
}
