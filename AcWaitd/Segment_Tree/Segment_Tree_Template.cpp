#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;           // 按题调整

// ==================== 全局变量 ====================
int a[N];                          // 原数组（1-indexed）
ll tree[N * 4];                    // 线段树：维护区间和
ll lazy[N * 4];                    // 懒标记：区间加

// ==================== 1. pushup ====================
// 用左右儿子的值更新父节点
void pushup(int p)
{
  tree[p] = tree[p << 1] + tree[p << 1 | 1];   // 区间和
}

// ==================== 2. build ====================
// 建树：p=当前节点, [l,r]=当前区间
void build(int p, int l, int r)
{
  if(l == r)
  {
    tree[p] = a[l];                // 叶子：直接取原数组
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);           // 递归左子树
  build(p << 1 | 1, mid + 1, r);   // 递归右子树
  pushup(p);                       // 合并左右儿子信息
}

// ==================== 3. pushdown ====================
// 将懒标记下传给左右儿子（区间加专用）
void pushdown(int p, int l, int r)
{
  if(lazy[p] == 0) return;         // 无标记，跳过

  int mid = (l + r) >> 1;
  int left_len = mid - l + 1;      // 左儿子区间长度
  int right_len = r - mid;         // 右儿子区间长度

  // 下传给左儿子
  tree[p << 1] += lazy[p] * left_len;
  lazy[p << 1] += lazy[p];

  // 下传给右儿子
  tree[p << 1 | 1] += lazy[p] * right_len;
  lazy[p << 1 | 1] += lazy[p];

  lazy[p] = 0;                     // 清除当前节点标记
}

// ==================== 4. query ====================
// 查询区间 [ql, qr] 的和
ll query(int p, int l, int r, int ql, int qr)
{
  if(ql <= l && r <= qr)           // 当前区间被完全包含
    return tree[p];

  pushdown(p, l, r);               // ★ 查询前先下传懒标记
  int mid = (l + r) >> 1;
  ll sum = 0;
  if(ql <= mid) sum += query(p << 1, l, mid, ql, qr);
  if(qr > mid)  sum += query(p << 1 | 1, mid + 1, r, ql, qr);
  return sum;
}

// ==================== 5. modify（单点修改） ====================
// 单点修改：将 a[pos] 改为 val
void modify(int p, int l, int r, int pos, int val)
{
  if(l == r)
  {
    tree[p] = val;                 // 到达叶子
    return;
  }
  int mid = (l + r) >> 1;
  if(pos <= mid)
    modify(p << 1, l, mid, pos, val);
  else
    modify(p << 1 | 1, mid + 1, r, pos, val);
  pushup(p);                       // 回溯更新父节点
}

// ==================== 6. update（区间修改） ====================
// 区间修改：将 [ml, mr] 每个元素加上 val
void update(int p, int l, int r, int ml, int mr, int val)
{
  if(ml <= l && r <= mr)           // 完全覆盖 → 打懒标记
  {
    tree[p] += (ll)val * (r - l + 1);
    lazy[p] += val;
    return;
  }
  pushdown(p, l, r);               // ★ 先下传再处理子节点
  int mid = (l + r) >> 1;
  if(ml <= mid) update(p << 1, l, mid, ml, mr, val);
  if(mr > mid)  update(p << 1 | 1, mid + 1, r, ml, mr, val);
  pushup(p);                       // 回溯合并
}

// ==================== 7. 区间最大值（无懒标记版） ====================
// --- 用于 RMQ 场景，不需要懒标记 ---
int maxv[N * 4];

void pushup_max(int p)
{
  maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]);
}

void build_max(int p, int l, int r)
{
  if(l == r)
  {
    maxv[p] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build_max(p << 1, l, mid);
  build_max(p << 1 | 1, mid + 1, r);
  pushup_max(p);
}

int query_max(int p, int l, int r, int ql, int qr)
{
  if(ql <= l && r <= qr) return maxv[p];
  int mid = (l + r) >> 1;
  int res = -0x3f3f3f3f;           // 初始化为极小值
  if(ql <= mid) res = max(res, query_max(p << 1, l, mid, ql, qr));
  if(qr > mid)  res = max(res, query_max(p << 1 | 1, mid + 1, r, ql, qr));
  return res;
}

// ==================== 主函数 ====================
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;                   // n 个数，m 次操作
  for(int i = 1; i <= n; i++) cin >> a[i];

  build(1, 1, n);                  // 建树

  while(m--)
  {
    int op;
    cin >> op;
    if(op == 1)                    // 区间加：[l, r] 每个数加 val
    {
      int l, r, val;
      cin >> l >> r >> val;
      update(1, 1, n, l, r, val);
    }
    else if(op == 2)               // 区间查询：[l, r] 的和
    {
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << '\n';
    }
  }
  return 0;
}
