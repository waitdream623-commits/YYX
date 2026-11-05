// #include <bits/stdc++.h>
// using namespace std;
// #ifndef DEBUG
// struct __X {
//   __X& operator<<(const auto& str) {return *this;}
//   void sp(const string& str = "") {}
// } dout;
// #define debug(x)
// #endif
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e6 + 10;
// void solve()
// {
//     int a,b,c,d;
//     cin>>a>>b>>c>>d;
//     //对于a
//     int fa=0;
//     if(a>c)fa++;
//     if(a>d)fa++;
//     //考虑平局
//     //对于b
//     int fb=0;
//     if(b>c)fb++;
//     if(b>d)fb++;
//     if(fa==2&&fb==2)cout<<4<<endl;
//     else if(fa==0||fb==0)cout<<0<<endl;
//     else{
//         //都为1可能为同时对于同一个大
//         if((fa==1&&fb==1)&&((a>c&&b>c)||(a>d&&b>d)))cout<<0<<endl;
//         else
//          cout<<2<<endl;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin >> T;  // 多测时取消注释
//     while (T--) {
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// 判定在特定出牌顺序下，Suneet 是否获胜
int check(int x, int y, int z, int w) {
    int suneet_score = 0;
    int slavic_score = 0;
    
    // 第一轮
    if (x > z) suneet_score++;
    else if (x < z) slavic_score++;
    
    // 第二轮
    if (y > w) suneet_score++;
    else if (y < w) slavic_score++;
    
    // Suneet 赢的轮数严格大于 Slavic 赢的轮数才算赢
    return (suneet_score > slavic_score) ? 1 : 0;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int ans = 0;
    
    // 暴力枚举 4 种可能的对局顺序：
    ans += check(a, b, c, d); // Suneet: (a, b), Slavic: (c, d)
    ans += check(a, b, d, c); // Suneet: (a, b), Slavic: (d, c)
    ans += check(b, a, c, d); // Suneet: (b, a), Slavic: (c, d)
    ans += check(b, a, d, c); // Suneet: (b, a), Slavic: (d, c)
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}