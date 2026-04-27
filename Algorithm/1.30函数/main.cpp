//P5738 【深基7.例4】歌唱比赛
#include<iostream>
#include<algorithm>
using namespace std;
int arr[110][110];
int n,m;
	
void bubblesort(int arr[]) //冒泡排序 （顺序） 
{
	int i=1;
	while(m-1)
	{
		int flag=1;
		for(int j=0;j<m-i;j++)
		{
			int tmp;
			if(arr[j]>arr[j+1])
			{
				tmp =arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=0;//进行了交换 
			 } 
			
		 } 
		i++;
		if(flag)
		return;	
	}
	
}
int main()
{
	cin>>n>>m;
	int mx=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			cin>>arr[i][j];
		}
		bubblesort(arr[i]);//排序 
	}
	//计算分数
	 
	 for(int i=0;i<n;i++)
	{
		int score=0;
		for(int j=1;j<m-1;j++)
		{
			score +=arr[i][j];
			
		}
		//找最大
		
		mx=max(mx,score); 
	
	}
	printf("%.2lf",mx*1.0/(m-2)) ;//下标却决顺序或者逆序 
	return 0;
}



////最高分与最低分之差
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin>>n;
//	int mx=-1,mn=110;
//	while(n--)
//	{
//		int tmp;
//		cin>>tmp;
//		mx=max(mx,tmp);
//		mn=min(mn,tmp);
//	}
//	cout<<mx-mn;
//	return 0;
// } 
//


//////B2129 最大数 max(x,y,z)
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int Max(int a,int b,int c)
//{
//	a=max(a,b);
//	a=max(a,c);
//	return a;
//	
//}
//int main()
//{
//	int a,b,c;
//	cin>>a>>b>>c;
//	float m=Max(a,b,c)*1.0/(Max(a+b,b,c)*Max(a,b,b+c));
//	printf("%.3f",m); 
//	
//	return 0;
// } 

//#include<iostream>
//using namespace std;
//int max(int a,int b,int c)
//{
//	a=a>b?a:b;
//	a=a>c?a:c;
//	return a;
//	
//}
//int main()
//{
//	int a,b,c;
//	cin>>a>>b>>c;
//	float m=max(a,b,c)*1.0/(max(a+b,b,c)*max(a,b,b+c));
//	printf("%.3f",m); 
//	
//	return 0;
// } 


////B2130 简单算术表达式求值
//#include<iostream>
//#include<string>
//using namespace std;
//int calcu(int a,int b,char c)
//{
//	switch(c)
//	{
//		case '+':
//			return a+b;
//			break;
//		case '-':
//			return a-b;
//			break;
//		case '*':
//			return a*b;
//			break;
//		case '/':
//			return a/b;
//			break;
//		case '%':
//			return a%b;
//			break;
//	}
//	
//	
//	
//}
//int main()
//{
//	int a,b;
//	char c;
//	cin>>a>>c>>b;
//	int ret=calcu(a,b,c) ;
//	cout<<ret<<endl; 
//	return 0;
// } 
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int a,b;
//	char c;
//	cin>>a>>c>>b;
//	if(c=='+')
//	cout<<a+b;
//	if(c=='-')
//	cout<<a-b;
//	if(c=='*')
//	cout<<a*b;
//	if(c=='/')
//	cout<<a/b;
//
//
//	
//	
//	return 0;
// } 
