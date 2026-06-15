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
    int n,d;
    cin>>n>>d;
    int end;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        end=max(end,a[i].second);
    }
    sort(a+1,a+1+n);
    ll cnt=0;//开ll
    
    int s=a[1].first;
    for(int i=s;i<=end-d;i++)//i为起始时间
    {
        ll su=0;
        int j=1;
        while(a[j].first<=i&&j<=n)//找在区间内满足
        {
            if(i+d<=a[j].second)//i为起始时间
            su++;

            j++;
        }
        if(su>=2)
        cnt+=su*(su-1)/2;
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
