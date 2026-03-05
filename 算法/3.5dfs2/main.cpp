//P1219 [USACO1.5] 八皇后 Checker Challenge
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n;
const int N=20;
bool st[N][N];
vector<int>choice;
int count=3;
int ret;
void dfs(int pos)
{
	if(pos>n)
	{
		if(count)
		{
			for(auto e:choice)
			cout<<e<<" ";
			cout<<endl;
		}
		count--
		ret++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[pos][i])continue;
		choice.push_back(i);
		for(int j=1;j<=n;j++)
		{
		
		}
		
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
 } 

////P9241 [蓝桥杯 2023 省 B] 飞机降落
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//int a[30],b[30],c[30];//a为初始时间，b为最终时间，c为降落花费 
//int n;
//bool use[30]; 
//bool dfs(int s,int end)//大小 
//{
//	if(s>n)
//	{
//		return true;
//	}
//	//全排列 
//	for(int i=1;i<=n;i++)
//	{
//		if(use[i])continue;//全排列标记 
//		if(end>b[i])continue;//不满足剪枝 
//		int newend=max(a[i],end);//不能修改end，否则回归判断不是上一个end 
//		newend+=c[i];
//		use[i]=1;
//		if(dfs(s+1,newend))return true;
//		use[i]=0;	 
//	}
//	//上面遍历完并且没有返回 
//	return false;
//}
//int main()
//{
//	int q;cin>>q;
//	while(q--)
//	{
//		//重置数组 
//		memset(use,0,sizeof use);
//		cin>>n;
//		for(int i=1;i<=n;i++)
//		{
//			cin>>a[i];
//			cin>>b[i];b[i]+=a[i];
//			cin>>c[i];
//		 } 
//		if(dfs(1,0))cout<<"YES"<<endl;
//		else cout<<"NO"<<endl; 
//	}
//	return 0;
//}
