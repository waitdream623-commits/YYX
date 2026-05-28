#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
ll f[N];
void slove()
{
    ll n;cin>>n;
    ll mn=1e18,index=1;
    for(int i=1;i<=n;i++)//减少最多
    {
        ll x;cin>>x;
        f[i]=x+f[i-1];
        if(x*(n-i+1)+f[i-1]<mn)
        {
            mn=x*(n-i+1)+f[i-1];//最小化减少
            index=i;
        }
    }
    cout<<index<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        slove();
    }
    return 0;
}
