#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
void solve()
{
    int n;cin>>n;
    ll ret=0;
    cin>>a[1];
    cout<<a[1]<<" ";
    ll t=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=t)//与t判断
        {
            ret+=a[i]-t;

            cout<<t<<" ";

        }
        else
        {
            if(ret>=t-a[i])
            {
                ret-=t-a[i];
                cout<<t<<" ";

            }
            else 
            {
                ll x=t;
                t=(ret+t*(i-1)+a[i])/i;
                ret=(ret+x*(i-1)+a[i])-t*i;
                cout<<t<<" ";

            }
        }
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        solve();
    }
    return 0;
}
// void solve()
// {
//     int n;cin>>n;
//     ll sum=0,ans=1e18;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         sum+=x;
//         ans=min(ans,sum/i);
//         cout<<ans<<" \n"[i==n];
//     }
// }