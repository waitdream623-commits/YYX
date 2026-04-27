//P2550 [AHOI2001] 彩票摇奖
#include<iostream>
using namespace std;
int a[7];
int medal[7]={0};
int main()
{
	int n;
	cin>>n;
	//存入中奖号码
	for(int i=0;i<7;i++)
	{
		cin>>a[i];
	 } 
   //读取匹配
   while(n--) 
   {
   	int count=0;
   	for(int i=0;i<7;i++)
   	{
   		int t;
   		cin>>t;
   		for(int j=0;j<7;j++)
   		{
   			if(t==a[j])
   			count++;
		   }
	   }
	   medal[7-count]++;
   	
   }
   //输出
   for(int i=0;i<7;i++)
   {
   	cout<<medal[i]<<' ';
	} 
    return 0;
}



//B2108 图像模糊处理
//
//#include<iostream>
//using namespace std;
//const int N=110;
//int arr1[N][N]; //存入 
//int arr2[N][N]; //修改存入 
//int main()
//{
//   int n,m;
//   cin>>n>>m;
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cin>>arr1[i][j];
//   	arr2[i][j]=arr1[i][j];	
//	   }
//   } 
//   //求平均
//    for(int i=1;i<n-1;i++)
//   {
//   	for(int j=1;j<m-1;j++)
//   	{
//   		arr2[i][j]=(int)((arr1[i][j]+arr1[i-1][j]+arr1[i][j-1]+arr1[i][j+1]+arr1[i+1][j])/5.0 +0.5);//四舍五入 
//	   }
//   } 
//    
//   //输出
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cout<<arr2[i][j]<<" "; 
//	   }
//	   cout<<endl;
//   }  
//    return 0;
//}

////B2101 计算矩阵边缘元素之和
//
//#include<iostream>
//using namespace std;
//const int N=110;
//int arr[N][N]; 
//int main()
//{
//   int n,m;
//   cin>>n>>m;
//   int sum=0;
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cin>>arr[i][j];
//   		if(i==0||i==n-1||j==0||j==m-1)
//		   sum+=arr[i][j] ;
//	   }
//   }
//   cout<<sum;
//    return 0;
//}





////B2106 矩阵转置
//#include<iostream>
//using namespace std;
//const int N=110;
//int arr[N][N]; 
//int main()
//{
//   int n,m;
//   cin>>n>>m;
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cin>>arr[i][j]; 
//	   }
//   }
//   
//	 //输出  
//
//
//   for(int i=0;i<m;i++)
//   {
//   	for(int j=0;j<n;j++)
//   	{
//   		cout<<arr[j][i
//		   ]<<" "; 
//	   }
//	   cout<<endl;
//   } 
//    return 0;
//}
//


////B2104 矩阵加法
//#include<iostream>
//using namespace std;
//const int N=110;
//int arr[N][N]; 
//int main()
//{
//   int n,m;
//   cin>>n>>m;
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cin>>arr[i][j]; 
//	   }
//   }
//   int a;
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cin>>a; 
//   		arr[i][j] +=a;
//   		
//	   }
//	  
//   }
//   //输出
//   for(int i=0;i<n;i++)
//   {
//   	for(int j=0;j<m;j++)
//   	{
//   		cout<<arr[i][j]<<" "; 
//	   }
//	   cout<<endl;
//   } 
//    return 0;
//}
////B2103 图像相似度
//#include<iostream>
//using namespace std;
//const int N=110;
//int arr[N][N]; 
//int main()
//{
//   int m ,n;
//   cin>>m>>n;
//   for(int i=0;i<m;i++)
//   {
//   	for(int j=0;j<n;j++)
//   	{
//   		cin>>arr[i][j];
//	   }
//	} 
//	int c=0;
//	for(int i=0;i<m;i++)
//   {
//   	for(int j=0;j<n;j++)
//   	{
//   		int t;
//   		cin>>t;
//   		if(t==arr[i][j])
//   		c++;
//	   }
//	} 
//	printf("%.2f",c*1.0/(m*n)*100);
//    return 0;
//}
//


////B2099 矩阵交换行
//#include<iostream>
//using namespace std;
//int arr[6][6]; 
//int main()
//{
//   for(int i=0;i<5;i++)
//   {
//   	for(int j=0;j<5;j++)
//   	{
//   		cin>>arr[i][j];
//	   }
//   }
//   int m,b;
//   cin>>m>>b;
//   swap(arr[m-1],arr[b-1]);
//    for(int i=0;i<5;i++)
//   {
//   	for(int j=0;j<5;j++)
//   	{
//   		cout<<arr[i][j]<<" ";
//	   }
//	   cout<<endl; 
//   }
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int arr[25][25]; 
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=i;j++)
//		{
//			if(j==0||j==i)
//			{
//			arr[i][j]=1; 
//			cout<<1<<" ";
//			}
//			else
//			{
//				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
//			cout<<arr[i][j]<<" ";
//			}
//		}
//		cout<<endl; 
//	}
//	return 0;
//}
