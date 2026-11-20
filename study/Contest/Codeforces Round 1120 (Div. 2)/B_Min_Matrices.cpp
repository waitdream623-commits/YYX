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
void wait()
{
    int n,k;
    cin>>n>>k;
    if(k<n||k>2*n-1)
    {
        cout<<-1<<'\n';
        return;
    }
    int b=1,e=n*n;
    int cnt=n-(k-n);//斜着放1~n个数
    int s=k-n;//斜边填大于n的个数
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                 {
                    if(cnt)
                {
                    cout<<b++<<' ';
                    cnt--;
                }
                else if(!cnt&&b>n)
                {
                    if(s)
                    cout<<b++<<" ";
                }
                 }
                else 
                {
                    if(!cnt&&b<=n)
                    {
                        cout<<b++<<' ';
                    }
                    else
                    cout<<e--<<" ";
                }

            
            }

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
