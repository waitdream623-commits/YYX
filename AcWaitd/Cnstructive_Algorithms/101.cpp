#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N],b[N];
void wait()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];
    }
    bool left=0;
    bool right=0;
    //从左往右处理
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0);
        else if(a[i]==-1)
        {
            if(!left)
            {
                a[i]=1;
                left=1;
            }
            else
            a[i]=0;
            
        }
        else
        {
            left=1;
         
        }
    }
    //从右往左
     for(int i=n;i>=1;i--)
    {
        if(b[i]==0);
        else if(b[i]==-1)
        {
            if(!right)
            {
                b[i]=1;
                right=1;
            }
            else
            b[i]=0;
        }
        else
        {
            right=1;
        }
    }
    for(int i=1;i<=n;i++)
        {
            if(a[i])b[i]=a[i];//保留1
            cout<<b[i]<<' ';
        }
    cout<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
