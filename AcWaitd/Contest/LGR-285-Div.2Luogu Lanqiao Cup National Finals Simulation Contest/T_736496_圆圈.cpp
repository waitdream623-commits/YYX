#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int f[1010][1010];
void cal(int a,int b,int r)
{
    double t=r*r;
    for(int i=max(1,a-r);i<=a+r;i++)
    {
    for(int j=max(1,b-r);j<=b+r;j++)
        {
            
            if(pow(a-i,2)+pow(b-j,2)<=t)
            f[i][j]++;
        }
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,r;cin>>a>>b>>r;
        cal(a,b,r);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(f[x][y]%2==1)cout<<"Yes\n";
        else
        cout<<"No\n";
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
