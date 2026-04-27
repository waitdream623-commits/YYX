#define _CRT_SECURE_NO_WARNINGS
//试题D:卡牌合并
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;
		queue<pair<int, int>>a;
		a.push({ 1,n });
		int size = 1;
		while (1)
		{
			if (a.front().second <= 1)break;
			int x = a.front().first, y = a.front().second;
			if (y >= 2)
				a.push({ 2 * x,y / 2 });
			if (y % 2)
			{
				a.front().second %= 2;
				size++;
				a.pop();
			}
			else
				a.pop();

		}
		if (size== 1)cout << "Fang" << endl;
		else cout << "Ben" << endl;

	}

	return 0;
}




////试题C:数字滚轮
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cmath>
//#include<vector>
//using namespace std;
//const int N = 2e5 + 10;
//int a[N];
//int main()
//{
//	int T; cin >> T;
//	while (T--)
//	{
//		int n, q; cin >> n >> q;
//		for (int i = 1; i <= n; i++)
//		{
//			char x; cin >> x;
//			a[i] = x - '0';
//		}
//		string s; cin >> s;
//		int j = 1;
//		for (int i = 0; i < q; i++)
//		{
//			switch (s[i])
//			{
//			case 'L':
//				if (j > 1)
//					j--;
//				break;
//
//			case 'R':
//				if (j < n)
//					j++;
//				break;
//			case 'U':
//				a[j] = (++a[j]) % 10;
//				break;
//			default:
//				a[j] = ((--a[j]) % 10 + 10) % 10;
//				break;
//			}
//
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			cout << a[i];
//		}
//		puts("");
//	}
//
//	return 0;
//}
