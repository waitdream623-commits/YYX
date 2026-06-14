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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n);//对x从小到大排序
    int cnt=1;//count
    int mn=a[1].second;
    for(int i=2;i<=n;i++)
    {
        //判断这个y是否是否包含前一个最小值，
        if(a[i].second<=mn)cnt++;
        mn=min(mn,a[i].second);//注意更新最小y
    }
    cout<<cnt;
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
