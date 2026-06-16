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
    int k;
    cin>>k;
    vector<int>mn;//记录每组倒数第二小
    int mnn=INF;//记录最小
    while(k--)
    {
        priority_queue<int,vector<int>,greater<int>>q;//小根堆
        int n;cin>>n;
        while(n--)
        {
            int x;cin>>x;
            q.push(x);

        }   
        int a=q.top();q.pop();
        mnn=min(mnn,a);
        mn.push_back(q.top());
    }
    ll sum=0;
    sum+=mnn;
    sort(mn.begin(),mn.end());
    for(auto e:mn)
    {
        sum+=e;
    }
    sum-=mn[0];//减去第一个倒数第二小；
    cout<<sum<<endl;;
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
