#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
void solve()
{
    int n,m;cin>>n>>m;
    string s;cin>>s;
    string b;cin>>b;
    sort(b.begin(),b.end());
    int t=0;
    string tmp;
    // for(int i=0;i<m;i++)
    // {
    //     if(b[i]<=s[t])
    //     {
    //         tmp+=b[i];
    //     }
    //     else
    //     {
    //         while(b[i]>s[t]&&t<=n-1)
    //         {
    //             tmp+=s[t];
    //             t++;
    //         }
    //         tmp+=b[i];
    //     }
    //     if(t==n-1)
    //     {
    //         tmp+=b.substr(i+1);
    //         break;
    //     }

    // }
    int x=0;
    while(x<m&&t<n)
    {
        if(b[x]<s[t])//不能取等，如果原串是“ba",修改串是”b",取等bba，先取修改串bab；，所以优先放原串
        {
            tmp+=b[x];
            x++;
        }
        else
        {
            tmp+=s[t++];
        }
    }
    if(t<n)
    tmp+=s.substr(t);
    if(x<m)
    tmp+=b.substr(x);
    cout<<tmp;
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
