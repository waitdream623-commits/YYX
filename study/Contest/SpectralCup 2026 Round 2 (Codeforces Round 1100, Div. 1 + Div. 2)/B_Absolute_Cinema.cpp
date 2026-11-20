#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        ll sum_b = 0;
        int max_a = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);  // 保证 a[i] ≤ b[i]
            sum_b += b[i];
            max_a = max(max_a, a[i]);
        }
        cout << sum_b + max_a << '\n';
    }
    return 0;
}
