#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
//对每个点记录看是否有标记大于等于2；
map<PII,int>mp;
ll ret=0;
void cal(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1,dy=y2-y1;
    int d=abs(gcd(dx,dy));//可能返回负数，仅作约分
    dx/=d;dy/=d;
    for(int i=0;;i++)
    {
        int x=x1+i*dx,y=y1+i*dy;//可能为水平或者竖直线
        mp[{x,y}]++;
        if(mp[{x,y}]==2)ret++;//重复不计算
        if(x==x2&&y==y2)break;
    }

} 
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cal(a,b,c,d);
    }
    cout<<ret;
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
