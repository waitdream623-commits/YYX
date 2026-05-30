#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

// ================================================================
// 线段树：区间最长连续上升子数组（LCIS）
// 元素必须相邻，如 [3,4,8] 是上升段，跳过 [5] 不行
// 支持：建树 O(n) / 单点修改 O(log n) / 区间查询 O(log n)
// ================================================================

int a[N];

struct Node {
    int maxLen, leftLen, rightLen;
    int leftVal, rightVal, len;
} tree[N * 4];

Node merge(Node L, Node R) {
    Node P;
    P.len = L.len + R.len;
    P.leftVal = L.leftVal;
    P.rightVal = R.rightVal;

    P.maxLen = max(L.maxLen, R.maxLen);
    if (L.rightVal < R.leftVal)
        P.maxLen = max(P.maxLen, L.rightLen + R.leftLen);

    P.leftLen = L.leftLen;
    if (L.leftLen == L.len && L.rightVal < R.leftVal)
        P.leftLen = L.len + R.leftLen;

    P.rightLen = R.rightLen;
    if (R.rightLen == R.len && L.rightVal < R.leftVal)
        P.rightLen = R.len + L.rightLen;

    return P;
}

void build(int p, int l, int r) {
    if (l == r) { tree[p] = {1, 1, 1, a[l], a[l], 1}; return; }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

void modify(int p, int l, int r, int pos, int val) {
    if (l == r) { tree[p] = {1, 1, 1, val, val, 1}; return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(p << 1, l, mid, pos, val);
    else            modify(p << 1 | 1, mid + 1, r, pos, val);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

Node query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(p << 1, l, mid, ql, qr);
    if (ql > mid)  return query(p << 1 | 1, mid + 1, r, ql, qr);
    return merge(query(p << 1, l, mid, ql, qr),
                 query(p << 1 | 1, mid + 1, r, ql, qr));
}

// ============================ 样例 ============================
/*
输入：
7 5
2 1 5 3 4 8 2
2 1 7
2 3 6
1 2 6
2 1 7
2 3 6
输出：
3
3
3
3
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {          // 单点修改
            int pos, val;
            cin >> pos >> val;
            modify(1, 1, n, pos, val);
        } else {                // 区间查询
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).maxLen << '\n';
        }
    }
    return 0;
}
