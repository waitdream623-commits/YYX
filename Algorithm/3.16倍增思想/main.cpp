//P10446 64位整数乘法
#include <iostream>

using namespace std;
typedef long long LL;
LL a,b,p;
LL qmut(LL a,LL b,LL p)
{
	LL ret=0;
	while(b)
	{
		if(b&1)ret=(ret+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ret;
 } 
int main()
{
	cin>>a>>b>>p; 
	cout<<qmut(a,b,p);
	return 0;
 } 

////P1226 【模板】快速幂
//#include <iostream>
//
//using namespace std;
//typedef long long LL;
//LL a,b,p;
//LL qpow(LL a,LL b,LL p)
//{
//	LL ret=1;//充当中间数 
//	while(b)//次方不为零，二进制位确定是否*ret
//	{
//		if(b&1)ret=ret*a%p;//该二进制为1 
//		a=a*a%p;//倍增，跟每一位权重挂勾 防止溢出 
//		b>>=1;//去掉这一位 
//	 } 
//	 return ret; 
//}
//int main()
//{
//	cin>>a>>b>>p;
//	printf("%lld^%lld mod %lld=%lld",a,b,p,qpow(a,b,p));
//	return 0;
// } 
