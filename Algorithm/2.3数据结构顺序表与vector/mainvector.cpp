//P3613 【深基15.例2】寄包柜
#include<iostream>
#include<vector>
using namespace std;
int a[5][100000];
int n,q;
int main()
{
	cin>>n>>q;
	int cse;

	int i,j,x;
	while(q--)
{		cin>>cse;
		if(cse==1)
	{
		cin>>i>>j>>x;//x==0即代表清空 
		a[i][j]=x;
	}
	if(cse==2)
	{
		cin>>i>>j;
		cout<<a[i][j]<<endl;
	}
}
	
	return 0;
}


////P3156 【深基15.例1】询问学号
//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int>a;
//int main()
//{
//	int n,m;
//	cin>>n>>m;
//	while(n--)
//	{
//		int x;
//		cin>>x;
//		a.push_back(x);
//	}
//	while(m--)
//	{
//		int t;
//		cin>>t;
//		cout<<a[t-1]<<endl;
//	}
//	return 0;
//}
//#include <iostream>
//#include<vector>
//using namespace std;
//vector<int>a1;
//vector<int>a2(10);//初始空间为10，默认为0
//vector<int>a3(10,1);//初始化为1
//vector<int>a4[10]; //vector<int>数组
//vector<int>a5={1,2,3,4,5};//初始化 
////打印
//void print(vector<int>& a) 
// {
// for(auto e:a)
//	 {
//	 	cout<<e<<" ";
//	 }
//	 cout<<endl;
//}
//int main()
//{	
//	for(int i=1;i<=5;i++)
//	{
//		a1.push_back(i);
//	 } 
//	print(a1);
//	return 0;
// } 
