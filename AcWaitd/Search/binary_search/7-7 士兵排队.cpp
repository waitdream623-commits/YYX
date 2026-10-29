// 在一个划分成网格的操场上，n个士兵散乱地站在网格点上。网格点用整数坐标(x,y)表示。士兵们可以沿网格边往上、下、左、右移动一步，但在同一时刻任一网格点上只能有一名士兵。按照军官的命令，士兵们要整齐地列成一个水平队列，即排列成(x,y),(x+1,y),…,(x+n-1,y)。如何选择x和y的值才能使士兵们以最少的总移动步数排成一行。

// 编程计算使所有士兵排成一行需要的最少移动步数。

// 题目引自POJ

// 输入格式:
// 第1行是士兵数n，1≤n≤10000。接下来n行是士兵的初始位置，每行有2个整数x和y，-10000≤x，y≤10000。

// 输出格式:
// 一个数据，即士兵排成一行需要的最少移动步数。

// 输入样例:
// 5
// 1  2
// 2  2
// 1  3
// 3  -2
// 3  3
// 输出样例:
// 8
#include<bits/stdc++.h>

using namespace std;
int a[100000],b[100000];
int main()
{
    int n; cin >> n;
    //对于y只需要在中间即可
    int l = 100000,r=-100000;
    for(int i = 1;i<=n;i++)
        {
            cin >> a[i] >> b[i];
             l = min(l,a[i]);
            r = max(r,a[i]);
        }
    sort(b+1,b+1+n);
    sort(a+1,a+1+n);
    long long ans = 0;
    for(int i = 1;i<=n;i++)
        {
            ans += abs(b[i]-b[(n+1)/2]);
        }
    //对于x,二分；
    auto f = [&](int x)
    {
        long long t = 0;
        for(int i = 1;i<=n;i++)
            {
                t+=abs(a[i]-x);
                x++;//下一个位置
            }
        return t;
    };
    //向左扩展(起点)，例如横坐标全为0，起点-1更优；
    l -= n;
    while(l<r)
        {
            int mid = l+(r-l)/2;
            if(f(mid)<=f(mid+1))
            {
                r = mid;
            }
            else
                l = mid +1;
        }
    ans += f(l);
    cout << ans;
    return 0;
}

