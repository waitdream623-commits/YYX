#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N];
int d[N];
int n,m;
bool cheack(int l)
{
    int cnt=0;
    for(int i=1;i<=n;i++)//可能第一个不为1；
    {
        int x=ceil(((double)d[i])/l)-1;
        cnt+=x;
    }
    return cnt<=m;

}
void solve()
{
    cin>>n>>m;
    m++;//技能
    int ma=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        d[i]+=x;
        d[i+1]-=x;
        ma=max(ma,d[i]);
    }
    int l=1,r=ma;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(cheack(mid))r=mid;
        else l=mid+1;
    }
    cout<<l;
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


//错解，每个区间间不一定是奇数个点，，应该用二分判断
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e6 + 10;
// //维护一个大根堆，每个点之间距离
// int a[N];
// priority_queue<int>q;
// void solve()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         q.push(a[i]-a[i-1]);
//     }
//     while(m--)
//     {
//         int a=q.top();q.pop();
//         int t=a/2;
//         q.push(t),q.push(a-t);

//     }
//     int a=q.top();
//     cout<<(a+1)/2;
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
