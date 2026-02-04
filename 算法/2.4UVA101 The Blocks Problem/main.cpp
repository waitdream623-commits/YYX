#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int N=30;
vector<int>arr[N];//存储n个存放木板的槽 
typedef pair<int,int>PII;
int n;
PII find(int x)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i].size();j++)
		{
		if(arr[i][j]==x)
			return {i,j};
		}
	}
}
void move(int x1,int y1,int x2)
{
	for(int i=y1;i<arr[x1].size();i++)
	{
		arr[x2].push_back(arr[x1][i]);
	}
	//x2不用改大小，x1需要改
	arr[x1].resize(y1); 
 } 
int main()
{
	
	cin>>n;//接收有多少个槽 
	//初始化槽初始为空不能用下标访问 
	for(int i=0;i<n;i++)
	{
		arr[i].push_back(i); 
	}
	 //实现操作
	string op1,op2;
	int a,b;
	while(cin>>op1>>a>>op2>>b)//每次读取4个，quit为最后一次读取不完整会结束
	{
		//需要找到a，b的位置
		PII p1=find(a);
		PII p2=find(b); 
		int x1=p1.first;int y1=p1.second;
		int x2=p2.first;int y2=p2.second;
		//非法操作
		if(x1==x2)
			continue; 
		if(op1=="move")//把a上木块归位放在顶部用push_back不能直接赋值 
		{
			for(int i=y1+1;i<arr[x1].size();i++)
			{
				arr[arr[x1][i]].push_back(arr[x1][i]);
			 } 
			 arr[x1].resize(y1+1); 
		 } 
		 if(op1=="onto")//把b上木块归位
		{
			for(int i=y2+1;i<arr[x2].size();i++)//最大下标是size-1 
			{
				arr[arr[x2][i]].push_back(arr[x2][i]);
			 } 
			  arr[x2].resize(y2+1); 
		 } 
		 //移动
		 move(x1,y1,x2);//把a（及以上）移动到b上方 
	 } 
	 //打印
	 for(int i=0;i<n;i++)
	 {
	 	cout<<i<<":";
	 	for(int j=0;j<arr[i].size();j++)
	 	cout<<' '<<arr[i][j];
	 	cout<<endl;
	  } 
	return 0;
 } 
