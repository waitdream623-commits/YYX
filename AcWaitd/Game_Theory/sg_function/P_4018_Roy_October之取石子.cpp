#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int a[]={1,2,3,4,5,7,8,9,11,13,16,17,19};
// 0:0
// 1:1
// 2:2
// 3:3
// 4:4
// 5:5
// 6:0
// 7:1
// 8:2
// 9:3
// 10:4
// 11:5
// 12:0
// 13:1
// 14:2
// 15:3
// 16:4
// 17:5
// 18:0
// 19:1
// 20:2
//可以得出n%6==0，必败
int sg(int x)
{
    unordered_set<int>st;
    for(auto&e:a)
    {
        if(x-e<0)break;
        st.insert(sg(x-e));
    }
    for(int i=0;;i++)
    {

        if(!st.count(i))return i;
    }
}
void solve()
{
    for(int i=0;i<=20;i++)
    {
        cout<<i<<":"<<sg(i)<<endl;;
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
