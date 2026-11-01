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
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
const int N = 1e6 + 10;
int a[N];

// void wait()
// {
//     int n , m;
//     cin >> n>> m;
//     rep(i,1,n)cin>>a[i];
//     int j=1;
//     priority_queue<int>heap;
//     int x=m;
//     int sum=0;
//     x--;
//     while(x--)
//     {
//         heap.push(a[j]);
//         sum+=a[j];
//         j++;
//     }
//     int r=m*a[j]-sum;
//     for(int i=j;i<n;i++)
//     {
//         if(a[i]<heap.top())
//         {
//             sum+=a[i]-heap.top();
//             heap.pop();
//             heap.push(a[i]);
            

//         }
//         r=max(m*a[i+1]-sum,r);

//     }
//     cout<<r<<"\n";

// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin >> T;  // 多测时取消注释
//     while (T--) {
//         wait();
//     }
//     return 0;
// }
void wait()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    priority_queue<int> heap;

    long long sum = 0;

    // 先放前 m-1 个
    for(int i = 1; i < m; i++)
    {
        heap.push(a[i]);
        sum += a[i];
    }

    long long ans = LLONG_MIN;

    // a[i] 作为第 m 个数
    for(int i = m; i <= n; i++)
    {
        ans = max(ans, 1LL * m * a[i] - sum);

        // 为下一轮准备：
        // 把 a[i] 加入前面的候选集合
        // 只保留最小的 m-1 个
        if(heap.size()>0)
        if(a[i] < heap.top())
        {
            sum -= heap.top();
            heap.pop();

            heap.push(a[i]);
            sum += a[i];
        }
    }

    cout << ans << '\n';
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