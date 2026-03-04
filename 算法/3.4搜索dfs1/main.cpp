//P1036 [NOIP 2002 普及组] 选数
//一个超时 
#include<iostream>
#include<cmath>
using namespace std;
int a[30];
 
int ret,n,k,sum;
//判断是否为素数
 
bool cheack(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)return 0;
	 } 
	 return 1;
}
int s;
void dfs(int pos)
{
	if(s==k)
	{
		if(cheack(sum))
		ret++;
		return;
	}
	for(int i=pos;i<=n;i++)
	{
		sum+=a[i];
		s++;
		dfs(i+1);
		sum-=a[i];
		s--;
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<ret;
	return 0;
}

////P1706 全排列问题
//#include <iostream>
//#include<vector>
//using namespace std;
//int n;
//bool us[11];
//vector<int>a;
//void dfs()
//{
//	if(a.size()==n)
//	{
//		cout<<"    ";
//		for(auto e:a)
//		cout<<e<<"    ";
//		cout<<endl;
//		return;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(us[i])continue;
//		a.push_back(i);
//		us[i]=1;
//		dfs();
//		a.pop_back();
//		us[i]=0;
//	}
//}
//int main()
//{
//	cin>>n;
//	
//	dfs();
//	return 0;
//}


////B3623 枚举排列（递归实现排列型枚举）
//#include<iostream>
//#include <vector>
//using namespace std;
//int n,k;
//vector<int>a;
//bool use[11];
//void dfs()
//{
//	if(a.size()==k)
//	{
//		for(auto e:a)
//		cout<<e<<' ';
//		cout<<endl;
//		return;
//	}
//	for(int i=1;i<n+1;i++)
//	{
//		if(use[i])continue;
//		 a.push_back(i);
//		 use[i]=1;
//		 dfs();
//		 a.pop_back();
//		 use[i]=0;
//	}
//}
//int main()
//{
//	cin>>n>>k;
//	dfs();
//	return 0;
//}


////P10448 组合型枚举
//#include <iostream>
//#include<vector>
//using namespace std;
//int n,m;
//vector<int>a;
//void dfs(int pos)
//{
//	//递归出口
//	if(a.size()==m)
//	{
//		for(auto e:a)
//		cout<<e<<' ';
//		cout<<endl;
//		return; 
//	 } 
//	 //选择
//	 for(int i=pos;i<=n;i++)
//	 {
//	 	a.push_back(i);
//	 	dfs(i+1);
//	 	a.pop_back();
//	  } 
//}
//int main()
//{
//	cin>>n>>m;
//	dfs(1);
//	return 0;
//}


////B3622 枚举子集（递归实现指数型枚举）
//
//#include <iostream>
//
//using namespace std;
//int n;
//string s;
//void dfs(int pos)
//{
//	//递归出口
//	if(pos>n)
//	{
//		cout<<s<<endl;
//		return;
//	}
//	//不参加
//	s+='N';
//	dfs(pos+1);
//	s.pop_back();//消除影响选择另一种
//	//参加
//	s+='Y';
//	dfs(pos+1);
//	s.pop_back(); 
//}
//int main()
//{
//	cin>>n;
//	dfs(1);
//	return 0;
// } 
