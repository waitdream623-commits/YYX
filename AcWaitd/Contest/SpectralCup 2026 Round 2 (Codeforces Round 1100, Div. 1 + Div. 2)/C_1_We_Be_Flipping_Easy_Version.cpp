#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int a[N], ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        int cnt = 0, flip = 0;
        // 从右向左: 若有效值为正则翻转前缀 [1..i]
        for (int i = n; i >= 1; i--) {
            //翻转偶数次为本身，奇数取负
            int cur = flip ? -a[i] : a[i];
            if (cur > 0) {
                ans[++cnt] = i;
                flip ^= 1;
            }
        }

        cout << cnt << '\n';
        for (int i = 1; i <= cnt; i++) {
            cout << ans[i] << " \n"[i == cnt];
        }
    }
    return 0;
}
