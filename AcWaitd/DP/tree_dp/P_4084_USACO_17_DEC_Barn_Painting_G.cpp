#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

vector<int> edges[N];
int f[N][4];

void dfs(int x, int fa)
{
    // 如果 x 没有被限制颜色
    if (f[x][1] == 0 &&
        f[x][2] == 0 &&
        f[x][3] == 0)
    {
        f[x][1] = f[x][2] = f[x][3] = 1;
    }

    for (auto y : edges[x])
    {
        if (y == fa)
            continue;

        dfs(y, x);

        f[x][1] =
            (ll)f[x][1] * (f[y][2] + f[y][3]) % mod;

        f[x][2] =
            (ll)f[x][2] * (f[y][1] + f[y][3]) % mod;

        f[x][3] =
            (ll)f[x][3] * (f[y][1] + f[y][2]) % mod;
    }
}

void wait()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        // a 必须染成 b
        f[a][b] = 1;
    }

    dfs(1, -1);

    ll ans = (f[1][1] + f[1][2] + f[1][3]) % mod;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    wait();

    return 0;
}