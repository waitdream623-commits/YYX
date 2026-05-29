#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
void slove()
{
    int n;cin>>n;
    ll ret=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ret^=a[i];
    }
    if(ret==0)
    {
        cout<<"lose";
    }
    else
    {
        //找到最小的满足
        int i=0;
        for(i=1;i<=n;i++)
        {
            if((ret^a[i])<a[i])
            {
                cout<<a[i]-(a[i]^ret)<<' '<<i;//拿走
                
                a[i]=(a[i]^ret);//剩下
                break;
            }
        }
        cout<<"\n";
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<' ';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        slove();
    }
    return 0;
}
