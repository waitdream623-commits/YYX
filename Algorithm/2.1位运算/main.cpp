//P1142进制转换
#include<iostream>
#include<string>
using namespace std;
string str="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
void n_to_m(int n,int x)//需要考虑大于10进制 
{
	if(n>=x)
	n_to_m(n/x,x);
	cout<<arr[n%x];
	
	
}
int main()
{
	int n,m;
	string s;
	cin>>n>>s>>m;
	//先转换成10进制
	int tmp=stoi(s,NULL,n); 
	//10进制转换成m进制；
	n_to_m(tmp,m); 
	return 0;
 } 
////B3620 x 进制转 10 进制
//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
// int main()
// {
// 	int x;
// 	string s;
// 	cin>>x>>s;
// 
// 	int sum=0;
// 	sum=stoi(s,NULL,x); 
//	 
//	  cout<<sum;
// 	return 0;
//  } 
//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
// int main()
// {
// 	//将ABC对应数字存入数组
//	 int arr[128];
//	 int j=0;
//	for(int i='0';i<='9';i++)
//	{
//		arr[i]=j;
//		j++;
//		
//	}
//	for(int i='A';i<='Z';i++)
//	{
//		
//		arr[i]=j;
//		j++;
//	}
// 	int x;
// 	string s;
// 	cin>>x>>s;
// 	//转换
// 	int sum=0;
// 	int n=0;//次方 
//	 for(int i=s.size()-1;i>=0;i--)
//	 {
//	 	sum+=pow(x,n)*arr[s[i]];
//	 	n++;
//	 	
//	  } 
//	  cout<<sum;
// 	return 0;
//  } 
