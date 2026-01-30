//BC45 小乐乐改数字
#include<iostream>
#include<cmath>
using namespace std;
int main()					//1.将每一位数字拿出来判断奇偶
							//2.累加，循环乘上权重 
{
	int n;
	cin>>n;
	int ans=0;
	int i=0;
	while(n)
	{
		if(n%10%2==1)
		ans+=1*pow(10,i);
		i++;
		n/=10;
		
	 } 
	cout<<ans<<endl;
	return 0;
}



////B2109 统计数字字符个数
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int cnt=0;
//	string s;
//	getline(cin,s);
//	for(auto e:s)
//	{
//		if(isdigit(e))
//		cnt++;
//	}
//	cout<<cnt;
//	return 0;
// } 


////多组数据a+b III
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a,b;
//	
//	while(cin>>a>>b)
//	{
//		if(a==0&&b==0) 
//		return 0;
//		cout<<a+b<<endl;
//	}
//	
//	
//	return 0;
// } 

////字符统计
//#include<iostream>
//#include<cctype>
//using namespace std;
//int main()
//{
//	int l=0,n=0,o=0;
//	char ch;
//	while((ch=getchar())!='?')
//	{
//		
//	 	if(isdigit(ch))
//		n++;
//		else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
//		l++;
//		else
//		o++;
//		
//		
//	}
//	cout<<"Letters="<<l<<endl; 
//	cout<<"Digits="<<n<<endl;
//	cout<<"Others="<<o<<endl;
//	return 0;
// } 
//

////定位查找
//#include<iostream>
//using namespace std;
//int arr[30];
//int main()
//{
//	int n;
//	while(cin>>n)
//	{
//		for(int i=0;i<n;i++)
//		{
//			cin>>arr[i];
//		 } 
//		int f;
//		cin>>f;
//		int flag=1;
//		for(int i=0;i<n;i++)
//		{
//			if(arr[i]==f)
//			{
//					cout<<i<<endl;
//					flag=0;
//					break;
//			}
//			
//		}
//		if(flag)
//		cout<<"No"<<endl;
//		
//		
//	 } 
//	
//	return 0;
// } 
//

////数字三角形
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while(cin>>n)
//	{
//		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=i;j++)
//			{
//				cout<<j<<' ';
//			}
//			cout<<endl;
//			
//		}
//		
//	}
//	return 0;
//}




////多组输入a+b
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a,b;
//	//while(cin>>a&&cin>>b)
//	while(cin>>a>>b)
//{
//	
//	
//	cout<<a+b<<endl; 
//}
//	
//	return 0;
//}


////B3769 [语言月赛202305] 制糊串
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s,t;
//	cin>>s>>t;
//	int q;
//	cin>>q;
//	while(q--)
//	{
//		int f1,l1,f2,l2;
//		cin>>f1>>l1>>f2>>l2;
//		string s1,t1;
//		s1=s.substr(f1-1,l1-f1+1);
//		t1=t.substr(f2-1,l2-f2+1);
//		if(s1==t1)
//		{
//			cout<<"ovo"<<endl;
//		 } 
//		 else if(s1<t1)
//		 {
//		 	cout<<"yifusuyi"<<endl;
//		 }
//		 else
//		 {
//		 	cout<<"erfusuer"<<endl; 
//		  } 
//		
//		
//	}
//	
//	return 0;
//}


////B2064 斐波那契数列
//#include<iostream>
//using namespace std;
//int arr[40];
//int main()
//{
//	for(int i=1;i<=30;i++)
//	{
//		if(i==1||i==2)
//		arr[i]=1;
//		else
//		arr[i]=arr[i-1]+arr[i-2];
//		
//		
//	}
//	int n;
//	cin>>n;
//	while(n--)
//	{
//		int t;
//		cin>>t;
//		cout<<arr[t]<<endl; 
//	}
//	
//	return 0;
// } 



////多组输入a+b II
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin>>n;
//	while(n--)
//	{
//		
//		int a,b;
//		cin>>a>>b;
//		cout<<a+b<<endl; 
//	}
//	return 0;
// } 
//


////B2081 与 7 无关的数
//#include<iostream>
//#include<cmath>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	cin>>n;//n<100,最多两位77； 
//	int sum=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(i%7==0)
//		;
//		else if(to_string(i).find('7')!=string::npos)
//		;
//		else
//		sum+=pow(i,2);
//		
//		}	
//		cout<<sum<<endl;
//	return 0;
//}

////B2009 计算 (a+b)/c 的值
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a,b,c;
//	cin>>a>>b>>c;
//	cout<<(a+b)/c;
//	return 0;
//}
