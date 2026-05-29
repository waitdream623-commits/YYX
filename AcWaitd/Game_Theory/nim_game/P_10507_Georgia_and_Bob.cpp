#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//最后一堆放在n个棋子后面
//排序
//可能不从1开始，注意第一个空格
int a[N];
int blank[N];
int pos;
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //排序
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        blank[i]=a[i]-a[i-1]-1;
    }
    //blank[1]=0，是否有影响
    //第一个距离地面最近为n；
    int ret=0;
    for(int i=n;i>=1;i-=2)ret^=blank[i];
    if(ret)
    {
        cout<<"Georgia will win\n";
    }
    else
    {
        cout<<"Bob will win\n";
    }
    
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
