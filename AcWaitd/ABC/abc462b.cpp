#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
vector<vector<int>>a(110);
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        while(k--)
        {
            int x;cin>>x;
            a[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].size()<<" ";
        for(auto e:a[i])
        {
            cout<<e<<" ";
        }
        cout<<endl;

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
