//P10483 小猫爬山
#include <iostream>
#include <algorithm>
using namespace std;

int n,w;
int a[20];
int s[20];//每一辆车的重量 
int cnt;
int ret=20;//最优解 
bool comp(int x,int y)
{
	return x>y; 
}
void dfs(int pos)
{
	//最优性剪枝 
	if(cnt>ret)return;
	if(pos>n)
	{
		ret=cnt;
		return;
	 } 
	//枚举小车，优先放入已有车
	for(int i=1;i<=cnt;i++)
	{
		//可行性剪枝 
		if(a[pos]+s[i]>w)continue;
		s[i]+=a[pos];
		dfs(pos+1);
		s[i]-=a[pos];
	 } 
	 //重开
	 cnt++;
	 s[cnt]=a[pos];
	 dfs(pos+1);
	 s[cnt]=0;
	 cnt--; 
	 
 } 
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	//优化搜素顺序 
	sort(a+1,a+1+n,comp);
	dfs(1);//从第一个小猫开始 
	cout<<ret;
	return 0;
}


// //P1025 [NOIP 2001 提高组] 数的划分
//
//#include<iostream>
//
//using namespace std;
//int n,k;
//int path,ret;
//void dfs(int pos,int begin)
//{
//	if(pos==k)
//	{
//		if(path==n)
//		ret++;
//		return;
//	 } 
//	 //进入后可行性判断，会先压栈 
//	for(int i=begin;i<=(n-path)/(k-pos);i++)
//	{
//		
//		//进入前 
//		if(path+begin*(k-pos)>n)return;//剪掉不可行
//		path+=i;
//		dfs(pos+1,i);
//		//复原 
//		path-=i; 
//	}
//}
//int main()
//{
//	cin>>n>>k;
//	dfs(0,1);
//	cout<<ret;
//	return 0;
// } 
