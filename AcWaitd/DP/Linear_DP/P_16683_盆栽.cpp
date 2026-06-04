#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int b[N];//a[i]^k-a[i];
void solve()
{
    int n,m;
    cin>>n>>m;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=x;
        sum+=x;
    }
    while(m--)
    {
        ll r1=0,a1=0,r2=0,a2=0;
        //1表示最大字段和，表示最多能提供，2最小字段和
        ll k;cin>>k;
        for(int i=1;i<=n;i++)
        {
            b[i]=(a[i]^k)-a[i];
        }
        for(int i=1;i<=n;i++)
        {
            r1+=b[i];
            if(r1<0)r1=0;
            r2+=b[i];
            if(r2>0)r2=0;
            a1=max(r1,a1);
            a2=min(a2,r2);
        }
        cout<<sum+a2<<" "<<sum+a1<<endl;
    }

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
