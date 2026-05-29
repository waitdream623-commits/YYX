#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//集合型nim游戏，有限制
int a[N],c[N];
//如何输出第一次操作，让异或和为0，枚举堆与操作数
int f[N];
int m;
int sg(int u)
{
    if(f[u]!=-1)return f[u];
    unordered_set<int>st;
    for(int i=1;i<=m&&u>=c[i];i++)//注意别超过堆个数
    {
        st.insert(sg(u-c[i]));
    }
    //mex
    for(int i=0;;i++)
    {
        if(st.count(i)==0)
        return f[u]=i;
    }
    return -1;
}
void solve()
{
    int n;cin>>n;
    //堆
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(f,-1,sizeof f);
    cin>>m;
    for(int i=1;i<=m;i++)cin>>c[i];
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        ret^=sg(a[i]);
    }
    if(ret==0)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n";
        //枚举操作
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m&&a[i]>=c[j];j++)//取石字个数不能超过a[i];
            {
                if((ret^f[a[i]]^sg(a[i]-c[j]))==0)//优先级问题
                {
                    cout<<i<<" "<<c[j]<<endl;
                    return;
                }
            }
        }
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
