#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//阶梯
void solve()
{
    int n;cin>>n;
    int ret=0;
    int flag=0;
    if(n%2==0)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    for(int i=1;i<=n;i++)//最后一层为n,倒着数
    {
        int x;cin>>x;
        //所以奇数个异或和为0，先手必败
        if(i%2==flag)
        {
            ret^=x;
        }
    }
    if(ret==0)
    {
        cout<<"zgc\n";
    }
    else
    cout<<"lyw\n";
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
