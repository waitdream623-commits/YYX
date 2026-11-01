#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)
   { int n;
    cin >> n;

    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    // suf[i] = a[i] + a[i+1] + ... + a[n]
    vector<ll> suf(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        suf[i] = (suf[i + 1] + a[i]) % MOD;
    }

    // (n-1)!
    ll fact = 1;
    for (int i = 1; i <= n - 1; i++) {
        fact = fact * i % MOD;
    }

    ll ans = 0;

    for (int i = 1; i <= n - 1; i++) {

        // sum_{j=i+1}^{n} (a[j] - a[i])
        ll cnt = n - i;

        ll sum = (suf[i + 1] - cnt * (a[i] % MOD)) % MOD;
        if (sum < 0) sum += MOD;

        // 固定 i -> j 后的树数量
        // (n-1)! / (n-i)
        //
        // 需要求逆元
        ll inv = 1;
        ll x = cnt;
        ll p = MOD - 2;

        while (p) {
            if (p & 1) inv = inv * x % MOD;
            x = x * x % MOD;
            p >>= 1;
        }

        ll ways = fact * inv % MOD;

        ans = (ans + sum * ways) % MOD;
    }

    cout << ans << '\n';
   }
    return 0;
}