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
int pos[N][2];
void wait()
{
    memset(pos,0,sizeof pos);
      int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
   
    for (int i = 0;i < k;i++){
        cin >> pos[i][0] >> pos[i][1];
    }
    int dist = 0,x = 0,y = 0;
    for (int i = 0;i < n;i++){
        if (s[i] == 'U') x--;
        else if (s[i] == 'D') x++;
        else if (s[i] == 'L') y--;
        else if (s[i] == 'R') y++;
        else dist++;
        for (int j = 0;j < k;j++){
            if (abs(x - pos[j][0]) + abs(y - pos[j][1]) <= dist){
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";

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
