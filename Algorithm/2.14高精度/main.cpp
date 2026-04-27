//P1601 高精度加法
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;
// ?精度加法的模版 - c = a + b;
void add(int c[], int a[], int b[])
{
	for(int i = 0; i < lc; i++)
	{
		c[i] += a[i] + b[i]; // 对应位相加，再加上进位
		c[i + 1] += c[i] / 10; // 处理进位
		c[i] %= 10; // 处理余数
	}
	if(c[lc]) lc++;
}
int main()
{
	string x, y; cin >> x >> y;
	// 1. 拆分每?位，逆序放在数组中
	la = x.size(); lb = y.size(); lc = max(la, lb);
	for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
	// 2. 模拟加法的过程
	add(c, a, b); // c = a + b
	// 输出结果
	for(int i = lc - 1; i >= 0; i--) cout << c[i];
	return 0;
}

//#include <iostream>
//#include <string>
//#include <algorithm> 
//using namespace std;
//string a,b;
////进位
//void putforword(int x,int i)
//{
//	if(x<10) return;//不需要进位 
//	a[i]=(char)(x-10);
//	a[i+1]++;
//	//万一连续进位 
//	putforword((int)(a[i+1]+1),i+1); 
// } 
//int main()
//{
//	cout<<(int)'9';
////	cin>>a>>b;
////	//逆序存储，方便进位 
////	reverse(a.begin(),a.end());
////	reverse(b.begin(),b.end());
////	for(int i=0;i<=b.size()-1;i++)
////	{
////		int t=int(a[i]+b[i]);
////		if(t<10)a[i]=(char)t;
////		else
////		putforword(t,i);
////	}
////	reverse(a.begin(),a.end());//正序结果
////	cout<<a; 
//	return 0;
// } 
