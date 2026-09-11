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
int a[N];
void wait()
{
    int n;
    cin>>n;
    if(n<6)cout<<"No"<<endl;
    else
    {
        int l=3,r=n;
        a[1]=3,a[2]=6;
        for(int i=1;i<=n;i++)
        {
            if(i==3||i==6)continue;
            if(i%2==0)a[l++]=i;
            else
            a[r--]=i;
        }
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
        for(int i=n;i>0;i--)cout<<a[i]<<' ';
        cout<<endl;
    }
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
