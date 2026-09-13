#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, k;
ll x;
ll a[45];
int n1, n2;

// leftvals[c] 存储左半边选出 c 个筹码所能形成的所有异或和
vector<ll> leftvals[25];

// 递归搜索左半边 [l, r]
void dfsleft(int l, int r, int cnt, ll curxor) {
    if (l > r) {
        leftvals[cnt].push_back(curxor);
        return;
    }
    // 不选当前筹码
    dfsleft(l + 1, r, cnt, curxor);
    // 选当前筹码（剪枝：选的数量不能超过 k）
    if (cnt + 1 <= k) {
        dfsleft(l + 1, r, cnt + 1, curxor ^ a[l]);
    }
}

ll ans = 0;

// 递归搜索右半边 [l, r]
void dfsright(int l, int r, int cnt, ll curxor) {
    if (l > r) {
        int needcnt = k - cnt;
        // 检验左半边需要选的个数是否合法
        if (needcnt >= 0 && needcnt <= n1) {
            ll targetxor = x ^ curxor;
            // 在左半边已选 needcnt 个数的异或和列表中二分查找 targetxor 的个数
            auto range = equal_range(leftvals[needcnt].begin(), leftvals[needcnt].end(), targetxor);
            ans = (ans + (range.second - range.first)) % MOD;
        }
        return;
    }
    // 不选当前筹码
    dfsright(l + 1, r, cnt, curxor);
    // 选当前筹码
    if (cnt + 1 <= k) {
        dfsright(l + 1, r, cnt + 1, curxor ^ a[l]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> k >> x)) return 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    n1 = n / 2;
    n2 = n - n1;

    // 1. 预处理左半边
    dfsleft(1, n1, 0, 0);

    // 2. 对左半边每一组异或和进行排序，以便进行二分查找
    for (int i = 0; i <= n1; i++) {
        sort(leftvals[i].begin(), leftvals[i].end());
    }

    // 3. 搜索右半边并实时统计答案
    dfsright(n1 + 1, n, 0, 0);

    cout << ans << "\n";

    return 0;
}