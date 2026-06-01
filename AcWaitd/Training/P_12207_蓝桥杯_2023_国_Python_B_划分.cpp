#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10; // 总和 S 大约是 226924，N 开 30万 绝对安全
int a[50]={0, 5160, 9191, 6410, 4657, 7492, 1531, 8854, 1253, 4520, 9231,
           1266, 4801, 3484, 4323, 5070, 1789, 2744, 5959, 9426, 4433,
           4404, 5291, 2470, 8533, 7608, 2935, 8922, 5273, 8364, 8819,
           7374, 8077, 5336, 8495, 5602, 6553, 3548, 5267, 9150, 3309};
bool f[N];

void solve()
{
    ll s = 0;
    for(int i = 1; i <= 40; i++)
    {
        s += a[i]; 
    }
    
    // 【关键修复 1】标准初始化，容量为 0 永远是可达的
    f[0] = 1; 
    
    for(int i = 1; i <= 40; i++)
    {
        // 【关键修复 2】0-1 背包必须 倒序遍历！防止同一物品被重复使用
        for(int j = s; j >= a[i]; j--)
        {
            if(f[j - a[i]])
            {
                f[j] = 1;
            }
            // 更极客的写法是直接按位或：f[j] |= f[j - a[i]];
        }
    }
    
    ll ans = 0;
    for(ll i = 1; i <= s; i++) // 注意 i 乘 (s-i) 会很大，i 也用 ll 会更保险
    {
        if(f[i])
        {
            ans = max(ans, i * (s - i));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}