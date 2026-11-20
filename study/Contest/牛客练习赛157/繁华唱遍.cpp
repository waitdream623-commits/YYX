#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> v(3);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            sum += x;
            v[x % 3].push_back(x);
        }

        // 前缀和不能出现的余数
        int target = (2 * (sum % 3)) % 3;

        vector<int> ans;
        ans.reserve(n);

        int cur = 0;

        for (int i = 0; i < n; i++) {

            // 最后一个直接放
            if (i == n - 1) {
                for (int r = 0; r < 3; r++) {
                    if (!v[r].empty()) {
                        ans.push_back(v[r].back());
                        v[r].pop_back();
                        break;
                    }
                }
                break;
            }

            int choose = -1;

            // 在不会进入 target 的余数中，
            // 优先选择剩余数量最多的
            for (int r = 0; r < 3; r++) {
                if (v[r].empty())
                    continue;

                if ((cur + r) % 3 == target)
                    continue;

                if (choose == -1 ||
                    v[r].size() > v[choose].size()) {
                    choose = r;
                }
            }

            // 没有合法选择
            if (choose == -1)
                break;

            ans.push_back(v[choose].back());
            v[choose].pop_back();

            cur = (cur + choose) % 3;
        }

        // 检查是否真的构造成功
        if ((int)ans.size() != n) {
            cout << "NO\n";
            continue;
        }

        // 最后再验证一次
        cur = 0;
        bool ok = true;

        for (int i = 0; i < n - 1; i++) {
            cur = (cur + ans[i] % 3) % 3;

            if (cur == target) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";

            for (int i = 0; i < n; i++) {
                cout << ans[i] << " \n"[i == n - 1];
            }
        }
    }

    return 0;
}