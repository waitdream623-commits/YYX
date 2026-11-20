#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int mn = 1001, mx = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        // Each operation reduces the gap between min and max by 2,
        // so answer = ceil((mx - mn) / 2)
        cout << (mx - mn + 1) / 2 << '\n';
    }
    return 0;
}
//这个问题只关心全局最小值和最大值，去重不影响结果，但让代码变复杂了。
// #include <algorithm>
// #include <iostream>
// #include <set>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// ll a[N];
// set<int>mp;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin >> T;
//     while (T--) {
//             mp.clear();//清空
//             int n;
//             cin>>n;
//             ll ret=0;
//             ll pos=0;
//             for(int i=1;i<=n;i++)
//             {
//                 int tmp;cin>>tmp;
//                 if(!mp.count(tmp))
//                 {
//                     a[++pos]=tmp;
//                     ret+=tmp;
//                 }
//                 mp.insert(tmp);


//             }
//             sort(a+1,a+1+pos);
//             ll x=ret/pos;//
//             int cnt=0;
//             int r=INF;
//             cnt=max(x-a[1],a[pos]-x);
//             r=min(r,cnt);
//             x++;
//             cnt=max(x-a[1],a[pos]-x);
//             r=min(r,cnt);

//             cout<<r<<endl;
//     }
//     return 0;
// }
