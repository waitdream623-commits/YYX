#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cout << i << " " << n + i * 2 - 1 << ' ' << n + i * 2<<' ';

		}
		cout << endl;
	}

	return 0;
}