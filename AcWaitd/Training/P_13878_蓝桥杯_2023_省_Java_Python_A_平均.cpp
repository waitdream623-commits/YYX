#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
PII a[N];
void solve()
{
    int n;cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        sum+=a[i].second;
    }
    sort(a+1,a+1+n,[](PII a,PII b){
        if(a.first==b.first)return a.second>b.second;
        return a.first<b.first;
    });
    int k=n/10;
    int j=0;
    for(int i=1;i<=n;i=j)
    {
        for( j=i;j<=n&&a[j].first==a[i].first;j++);
        //此时j与i不相同
        int cnt=j-i;
        int keep = min(cnt, k);//不够也全部保留
        for (int t = i; t < i + keep; t++)
            sum -= a[t].second;
            }
    cout<<sum;//结果为消耗
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
