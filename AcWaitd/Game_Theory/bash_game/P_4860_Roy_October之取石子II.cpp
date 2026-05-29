#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
//尽可能留下不是素数
void slove()
{
    int n;
    cin>>n;
    if(n%4!=0)
    cout<<"October wins!\n";
    else
    cout<<"Roy wins!\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        slove();
    }
    return 0;
}
