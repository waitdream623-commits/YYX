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
typedef pair<int,int> PII;
int INF = 0x3f3f3f3f;

#define lc p<<1
#define rc p<<1|1

const int N = 1e6 + 10;
vector<int> primes;
bool is_prime[N];

// 预处理质数：线性筛（欧拉筛）
void sieve() {
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p >= N) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

void solve()
{
    ll d;
    cin >> d;
    
    // a = 1
    // 找到第一个 >= 1 + d 的质数 b
    ll b = *lower_bound(primes.begin(), primes.end(), 1 + d);
    
    // 找到第一个 >= b + d 的质数 c
    ll c = *lower_bound(primes.begin(), primes.end(), b + d);
    
    // 最终答案 y = a * b * c
    ll y = b * c; 
    cout << y << "\n"; // 使用 '\n' 替代 endl 提高 IO 效率
}

int main() {
    // 优化输入输出流
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(); // 记得先初始化质数表！

    int T = 1;
    cin >> T;  
    while (T--) {
        solve();
    }
    return 0;
}