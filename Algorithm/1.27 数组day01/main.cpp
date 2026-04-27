//冒泡排序
#include<iostream>
using namespace std;
int arr[30] ;
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cin>>arr[i];
   }
   //排序
   int x=n-1;
   while(x)
   {
   	int count=0;
   for(int i=0;i<x;i++)
   {
	   if(arr[i]<arr[i+1])//从大到小 
   	{
	   int t=arr[i+1];
   	arr[i+1]=arr[i];
	   arr[i] =t;
	   count++;
	} 
	}
	if(count==0)
	break;
	x--;
}
//输出
for (int i=0;i<n;i++)
{
	cout<<arr[i]<<endl;
 } 
    return 0;
} 
////P1428 小鱼比可爱
//#include<iostream>
//using namespace std;
//int arr[110]; 
//int main()
//{
//   int n;
//   cin>>n;
//   for(int i=0;i<n;i++)
//   {
//   	cin>>arr[i]; 
//   }
//   for(int i=0;i<n;i++)
//   {
//   	int count=0;
//   	for(int j=0;j<i;j++)
//   	{
//   		if(arr[j]<arr[i])
//   		count++;
//	   }
//	   cout<<count<<" ";
//   }
//    return 0;
//}
////B2092 开关灯
//#include<iostream>
//using namespace std;
//int light[5010];
//int main()//此方式需特殊考虑1，否则无法跳出循环。 
//{
//   int n;
//   cin>>n;
//   for(int i=1;i<=n;i++)
//   {
//	 light[i]=5000; //关灯为偶数，开灯为奇数 
//   }
//   int x=2;
//   while(1)
//   {
//   	for(int i=1;i<=n;i++)
//   {
//   	if(i%x==0)
//   	light[i]-=1;
//   }
//   if(x==n)
//   break;
//   x++;
//   
//   }
//   for(int i=1;i<=n;i++)
//   {
//   	if(light[i]%2==0)
//   	cout<<i<<" "; 
//	} 
//    return 0;
//}
////B2090 年龄与疾病
////B2090 年龄与疾病
//#include<iostream>
//using namespace std;
//int main()
//{
//   int a=0;
//   int b=0;
//   int c=0;
//   int d=0;
//   int n;
//   cin>>n;
//   for(int i=0;i<n;i++)
//   {
//   	int t;
//   	cin>>t;
//   	if(t>=0&&t<=18)
//   	{
//   		a++;
//	   }
//	   if(t>=19&&t<=35)
//   	{
//   		b++;
//	   }
//	   if(t>=36&&t<=60)
//   	{
//   		c++;
//	   }
//	   if(t>=61)
//   	{
//   		d++;
//	   }
//	   
//   }
//    printf("%.2f%%\n",a*1.0/n*100) ;
//   printf("%.2f%%\n",b*1.0/n*100) ;
//   printf("%.2f%%\n",c*1.0/n*100) ;
//   printf("%.2f%%\n",d*1.0/n*100) ;
//  
//  return 0;
//}

//B2091 向量点积计算
//#include<iostream>
//using namespace std;
//int main()
//{
//
//   int N;
//   cin>>N;
//   int arr1[N],arr2[N];
//   for(int i=0;i<N;i++)
//   {
//   	cin>>arr1[i];
//	} 
//	 for(int i=0;i<N;i++)
//   {
//   	cin>>arr2[i];
//	} 
//	int x=0;
//	int sum=0;
//	while(x!=N)
//	{
//		sum+=arr1[x]*arr2[x];
//		x++;
//	}
//	cout<<sum;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int arr1[1100];
//int arr2[1100];
//int main()
//{
//   int N;
//   cin>>N;
//   
//   for(int i=0;i<N;i++)
//   {
//   	cin>>arr1[i];
//	} 
//	 for(int i=0;i<N;i++)
//   {
//   	cin>>arr2[i];
//	} 
//	int x=0;
//	int sum=0;
//	while(x!=N)
//	{
//		sum+=arr1[x]*arr2[x];
//		x++;
//	}
//	cout<<sum;
//    return 0;
//}
//B2089 数组逆序重存放
////交换
//#include<iostream>
//using namespace std;
//int main()
//{
//   
//    return 0;
//} 
//逆序输入或输出； 
//#include<iostream>
//using namespace std;
// const int n = 110;
// int arr[n];
// 
//int main()
//{
//   int n ;
//   cin>>n;
//   for(int i =n-1;i>=0;i--)
//   {
//   	cin>>arr[i];
//   }
//   for(int i=0;i<n;i++)
//   {
//   	cout<<arr[i]<<" "; 
//   }
//    return 0;
//} 
