#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
int INF = 0x3f3f3f3f;
const int N = 1e6 + 10; // 洛谷P3372数据范围N=1e5，这里开1e5+10即可

#define lc p<<1
#define rc p<<1|1

int n, m;
ll a[N];

struct node
{
    ll l, r, sum, lazy; // 将 lazy 标记完美封装进结构体，共享 4 倍空间
} tr[N << 2];

void pushup(int p)
{
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void build(int p, int l, int r)
{
    // 统一初始化区间边界和标记
    tr[p] = {l, r, 0, 0}; 
    if (l == r) 
    {
        tr[p].sum = a[l]; // 只有在叶子节点时，才精准对应原数组的值
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p); // 靠回溯时的 pushup 完美撑起非叶子节点的 sum 值
}

void pushdown(int p)
{
    if (tr[p].lazy == 0) return;
    
    // 下放给左子树
    tr[lc].sum += tr[p].lazy * (tr[lc].r - tr[lc].l + 1);
    tr[lc].lazy += tr[p].lazy;
    
    // 下放给右子树
    tr[rc].sum += tr[p].lazy * (tr[rc].r - tr[rc].l + 1);
    tr[rc].lazy += tr[p].lazy;
    
    tr[p].lazy = 0; // 清空父节点标记
}

void modify(int p, int ml, int mr, ll val)
{
    if (tr[p].l >= ml && tr[p].r <= mr)
    {
        tr[p].sum += (ll)val * (tr[p].r - tr[p].l + 1);
        tr[p].lazy += val;
        return;
    }
    pushdown(p); // 只要不能完全覆盖，立刻下放标记
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (ml <= mid) modify(lc, ml, mr, val);
    if (mr > mid) modify(rc, ml, mr, val);
    pushup(p); // 子树更新完毕，重新计算当前节点的 sum
}

ll query(int p, int x)
{
    if (tr[p].l == tr[p].r)
    {
        return tr[p].sum;
    }
    pushdown(p); // 查询前先下放标记，确保子节点数据正确
    ll sum = 0;
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) sum += query(lc, x);
    else sum += query(rc, x);
    return sum;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int x, y; ll k; cin >> x >> y >> k;
            modify(1, x, y, k);
        }
        else
        {
            int x; cin >> x ;
            cout << query(1, x) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}