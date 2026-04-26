#define _CRT_SECURE_NO_WARNINGS
//P5788 【模板】单调栈
//此题可列为从右往左单调递减栈
#include<iostream>
#include<stack>

using namespace std;
const int N = 3e6 + 10;//不能写成3*e6
int a[N];
int f[N];
int main()
{
	//超时优化
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	stack<int>st;
	for (int i = n; i > 0; i--)
	{
		//为空，即第一次，直接加入
		while (st.size() && a[st.top()] <= a[i])st.pop();
		//此时栈里满足条件
		if (st.size())f[i] = st.top();//为空，表示没有满足条件的
										//默认为空
		st.push(i);

	}
	//输出
	for (int i = 1; i <= n; i++)
	{
		cout << f[i] << ' ';
	}
	return 0;
}