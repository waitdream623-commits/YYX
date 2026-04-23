#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 4000;
int a[N];
////int main()
//{
//	int T; cin >> T;
//	while (T--)
//	{
//		int ret=-0x3f3f3f3f;
//		int n; cin >> n;
//		int x = 0;
//		int flag = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			int x = a[i];
//			for (int j = i+1; j <= n; j++)
//			{
//				ret = max(ret, a[i] ^ a[j]);
//			}
//			
//		}
//		cout <<ret << endl;
//		
//	}
//
//	return 0;
//}