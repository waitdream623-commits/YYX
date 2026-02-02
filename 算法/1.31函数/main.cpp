//B3619 10 进制转 x 进制
#include<iostream>
using namespace std;
string s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void n_to_xscale(int n,int x)
{
	if(n>=x)
	n_to_xscale(n/x,x);
	cout<<s[n%x];
	
}
int main()
{
	int n,x;
	cin>>n>>x;
	n_to_xscale(n,x);
	return 0;
 } 



////B2143 进制转换
//#include<iostream>
//using namespace std;
//char arr[]="0123456789ABCDEF";
//void scale(int x,int m)
//{
//	if(x>=m)
//	 scale(x/m,m);
//	cout<<arr[x%m]; 
//	
//}
//int main()
//{
//	int x,m;
//	cin>>x>>m;
//	scale(x,m);
//	return 0;
//}


////B2148 再求 f(x,n)
//#include<iostream>
//using namespace std;
//double f(double x,int n)
//{
//	if(n==1)
//	return x/(1+x);
//	else
//	return x/(n+f(x,n-1));
//	
//}
//int main()
//{
//	int n;
//	double x;
//	cin>>x>>n;
//	printf("%.2lf",f(x,n));
//	return 0;
//}

////B2147 求 f(x,n)
//#include<iostream>
//#include<cmath>
//using namespace std;
//double f(double x,double n)
//{
//	if(n==1)
//	return sqrt(1+x);
//	else 
//	return sqrt(n+f(x,n-1)) ;
//	
// } 
//int main()
//{
//	double x,n;
//	cin>>x>>n;
//	double m=f(x,n);
//	printf("%.2lf",m); 
//	return 0;
//}


////B2145 digit 函数
//#include<iostream>
//using namespace std;
//int digit(int n,int k)
//{
//	if(k==1)
//	return n%10;
//	else
//	return digit(n/10,k-1);
//	
// } 
//int main()
//{
//	int n,k;
//	cin>>n>>k;
//	cout<<digit(n,k);
//	return 0;
//}

////B2144 阿克曼（Ackermann）函数
//#include<iostream>
//using namespace std;
//int A(int m,int n)
//{
//	if(m==0)
//	return n+1;
//	if(n==0&&m>0)
//	return A(m-1,1);
//	else 
//	return A(m-1,A(m,n-1));
//	
//	
//}
//
//int main()
//{
//	int m,n;
//	cin>>m>>n;
//	cout<< A(m,n);
//	return 0;
//}



////B2142 求 1+2+3+...+N 的值
//#include<iostream>
//using namespace std;
//int Sum(int n)
//{
//	
//	if(n==1)
//	return 1;
//	else 
//	return n+Sum(n-1);
//}
//int main()
//{
//	int n;
//	cin>>n;
//	 cout<<Sum(n);
//	
//}

////B2139 区间内的真素数
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//bool is_prime(int m)
//{
//	if(m<2)
//	return false;
//	for(int i=2;i<=sqrt(m);i++)
//	{
//		if(m%i==0)
//		return false;
//		
//	 } 
//	 return true;
//	
// } 
// int rever_num(int m)
// {
// 	string s;
// 	s=to_string(m);
// 	reverse(s.begin(),s.end());
// 	return stoi(s);
// }
//int main()
//{
//	int M,N;
//	cin>>M>>N;
//	int x=1;//假设没有 
//	int flag=1;
//	for(int i=M;i<=N;i++)
//	{
//		//最后一个没有逗号 
//	
//		if(is_prime(i)&&is_prime(rever_num(i)))
//		{
//			//只有第一次进入才进入 
//			if(flag)
//			{
//				cout<<i;
//				flag=0;
//			}
//			else
//			cout<<','<<i; 
//			x=0;
//		}
//		
//	}
//	if(x)
//	{
//		cout<<"No";
//	}
//	
//	return 0;
// } 
//////B2136 素数回文数的个数
//#include<iostream>
//#include<string>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//bool is_prime(int m)
//{
//	if(m<2)
//	return false;
//	for(int i=2;i<=sqrt(m);i++)
//	{
//		if(m%i==0)
//		return false;
//	}
//	return true;
//}
//int main()
//{
//	int cnt=0;
//	int n;
//	cin>>n;
//	string s,t;
//	for(int i=11;i<=n;i++)
//	{
//		if(is_prime(i))
//		{
//			t=s=to_string(i);
//			reverse(s.begin(),s.end());//仅操作s 
//			if(s==t)
//			cnt++;
//		}
//	}
//	cout<<cnt;
//	return 0;
//}
//


////B2132素数对
//#include<iostream>
//#include<cmath>
//using namespace std;
//bool is_prime(int m)
//{
//	if(m<2)
//	return false;
//	for(int i=2;i<=sqrt(m);i++)
//	{
//		if(m%i==0)
//		return false;
//		
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	int flag=1;
//	cin>>n;
//	for(int i=1;i+2<=n;i++)
//	{
//		if(is_prime(i)&&is_prime(i+2))
//		{
//			cout<<i<<" "<<i+2<<endl;
//			flag=0;
//		}
//		
//	}
//	if(flag)
//	cout<<"empty";
//	return 0;
//}


////B2128 素数个数
//#include<iostream>
//#include<cmath>
//using namespace std;
//bool judge(int i)
//{
//	for(int j=2;j<=sqrt(i);j++)//减少判断次数 
//	{
//		if(i%j==0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	cin>>n;
//	int sum=0;
//	for(int i=2;i<=n;i++)
//	{
//		//判断素数
//		if(judge(i))
//		sum++;
//		
//	}
//	cout<<sum;
//	return 0;
// } 

////B2131甲流病人初筛
//#include<iostream>
//#include<string>
//using namespace std;//体温超过 37.5 度（含等于 37.5 度）
//					//并且咳嗽的病人初步判定为甲流病人（初筛）
//int main()
//{
//	int n;
//	cin>>n;
//	string s;
//	int cnt=0;
//	while(n--)
//	{
//		cin>>s;
//		int a;
//		float b;
//		cin>>b>>a;
//		if(b>=37.5&&a==1)
//		{
//			cout<<s<<endl;
//			cnt++;
//		}
//		
//	 } 
//	 cout<<cnt;
//	return 0;
//}
////B2127 求正整数 2 和 n 之间的完全数
//#include<iostream>
//using namespace std;//28=4+7+2+14+1因数之和 
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=2;i<=n;i++)
//	{
//		//找因数并累加
//		int sum=1; //一定有1； 
//		for(int j=2;j<i;j++)
//		 {
//		 	if(i%j==0)
//		 	{
//		 		sum+=j; 
//			 }
//		 	
//		 }
//		if(sum==i)
//		cout<<i<<endl;
//	 } 
//	
//	return 0;
// } 
