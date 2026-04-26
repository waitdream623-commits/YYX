#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int main()
{
	int a = 1;
	int& b = a;
	int& c = a;
	b++;
	int d = 9;
	b = d;
	cout << &a << endl << &b << endl << &d << endl;
	cout << a << endl << d << endl;
	return 0;
}
//using namespace std;
//int main()
//{
//	int x; cin >> x;
//	cout << x << ' ' << "Hello World!";
//
//	return 0;
//}
//

//using namespace std;
//
//int ADD(int a, int b)
//{
//	return a + b;
//}
//double ADD(double a, double b)
//{
//	return a + b;
//
//}
//int main()
//{
//	cout << ADD(1, 2) << endl;
//	cout << ADD(2.1, 3.5) << endl;
//	return 0;
//}
//void yy(int a, int b = 10, int c=99)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//int main()
//{
//	yy(1);
//	yy(10);
//	yy(1, 2, 3);
//	return 0;
//}
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(false);
//	cout.tie(false);
//
//}
//namespace yy {
//	int a = 1;
//	namespace zz
//	{
//		int b = 0;
//	}
//}
//using namespace yy::zz;
//int main()
//{
//	std::cout << yy::a << ' ' << b << std::endl;
//	std::cout << b;
//	std::cout << "\n";
//	std::cout << yy::a;
//	return 0;
//}
//int main()
//{
//	int a = 99;
//	std::cout << a << " " << yy::a <<' ' << ::a << std::endl;
//	return 0;
//}