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

//赛时，题意理解出问题，不是两个加中间一个
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// ll f[N];
// ll a[N];
// void solve()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         ll x;cin>>x;
//         a[i]=x;
//         f[i]=f[i-1]+x;
//     }
//     while(m--)
//     {
//         ll k;cin>>k;
//         // for(int i=1;i<=n;i++)
//         // {
//         //     cout<<(a[i]^k)<<' ';
//         // }
//         ll mn=INF,mx=-INF;
//         for(int i=2;i<n;i++)
//         {
//             ll t=f[i+1]-f[i-2];
//             ll tmp=(a[i-1]^k)+(a[i]^k)+(a[i+1]^k);//三盆
//             mn=min(mn,t-tmp);
//             mx=max(mx,t-tmp);
//             ll t2=f[i]-f[i-2];//两盆，缺最后两盆
//             ll tmp2=(a[i]^k)+(a[i-1]^k);
//             mn=min(mn,t2-tmp2);
//             mx=max(mx,t2-tmp2);
//         }
//           ll tmp3=+(a[n-1]^k)+(a[n]^k);
//             mn=min(mn,f[n]-f[n-2]-tmp3);
//             mx=max(mx,f[n]-f[n-2]-tmp3);
//         cout<<min(f[n]-mx,f[n])<<' '<<max(f[n]-mn,f[n])<<endl;//可以选择不操作
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;  // 多测时取消注释
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
