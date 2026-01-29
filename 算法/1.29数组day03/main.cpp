//B2110 找第一个只出现一次的字符
#include<iostream>
#include<cstring>
using namespace std;
char str[1100];
int arr[26];
int main()
{
	char c;
	int i=0;
	while((str[i]=getchar())!='\n')
	{
		arr[str[i]-'a']++;
		i++;
	}
	str[i]='\0';
	 i=0;
	while(str[i])
	{
		if(arr[str[i]-'a']==1)
		{
			cout<<str[i];
			return 0;
		}
		i++;
	 } 
   cout<<"no";
    return 0;
}




//暴力检索 
//#include<iostream>
//#include<cstring>
//using namespace std;
//char arr[1111];
//int main()
//{
//   cin>>arr;
//   int len=strlen(arr);
//   int j=0;
//   while(j!=len)
//   {
//   	for(int i=0;i<len;i++)
//   	{
//	   if(arr[i]==arr[j]&&i!=j)
//   	break;
//   	if(i==len-1)
//   	{
//   		cout<<arr[j];
//		   return 0; 
//	   }
//   }
//   j++;
//   }
//   cout<<"no";
//    return 0;
//}
//


////B2118 验证子串
//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char s1[40],s2[40];
//	cin>>s1>>s2;
//	if (strstr(s1,s2))
//	cout<<s2<<" is substring of "<<s1;
//	else if(strstr(s2,s1))
//	cout << s1<<" is substring of "<<s2;
//	else
//	cout<<"No substring"; 
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<utility>
//using namespace std;
//int main()
//{
//	char s1[40],s2[40];
//	cin>>s1>>s2;
//	int sz1,sz2;
//	sz1=strlen(s1);
//	sz2=strlen(s2);
//	//保证s1是短的 
//	if(sz2<sz1)
//	{
//	swap(s1,s2);
//	swap(sz1,sz2);
//	}
//	for(int i=0;i<=sz2-sz1;i++)//应该小于等于，比如sz1等于sz2时，123与45123 
//	{
//		int j=0;
//		for(j=0;j<sz1;j++)
//		{
//			if(s2[i+j]!=s1[j])//从s2每个开头进行一一与s1比较 
//			break;
//		}
//		if(j==sz1)//内层完成最后一次循环未进行break说明相同 
//		{
//			cout<<s1<<" is substring of "<<s2;
//			return 0;
//		}
//	}
//	cout<<"No substring";
//	return 0;
//}

////B2113 输出亲朋字符串
//#include<iostream>
//#include<cstring>
//using namespace std;//需要保留原始值 
//char arr[110];
//char t[110]; 
//int main()
//{
//	
//	cin>>arr;
//	int sz=strlen(arr);
//	//边判断边输出 
//	for(int i=0;i<sz;i++)
//	{
//	char c=arr[i]+arr[(i+1)%sz];
//	cout<<c; 
//	}
//	return 0; 
//}

//#include<iostream>
//#include<cstring>
//using namespace std;//需要保留原始值 
//char arr[110];
//char t[110]; 
//int main()
//{
//	
//	cin>>arr;
//	int sz=strlen(arr);
//	//保留原始字符串 
//	for(int i = 0; i < sz; i++)
//    {
//        t[i] = arr[i];
//    }
//	for(int i=0;i<sz;i++)
//	{
//		if(i==sz-1)
//		arr[i]=(char)(t[i]+t[0]);
//	//选择
//		else
//		arr[i]=(char)(t[i]+t[i+1]); 
//	}
//	cout<<arr;
//	return 0; 
//}



////B2111 基因相关性
//#include<iostream>
//#include<cstring>
//using namespace std;
//char arr[510];
//int main()
//{
//	float n;
//	cin>>n>>arr;
//	int count=0;
//	int sz=strlen(arr);
//	for(int i=0;arr[i]!='\0';i++)
//	{
//		char c;
//		cin>>c;
//		if(c==arr[i])
//		count++ ;
//	}
//	cout<<(n>count*1.0/sz?"no":"yes");
//	return 0;
//}



//////1139：整理药名
//#include <iostream>
//#include <cctype>
//using namespace std;
//const int N = 25;
//char arr[N];
//int main()
//{
// int n = 0;
// cin >> n;
// for (int i = 0; i < n; i++)
// {
// scanf("%s", arr);
// if (islower(arr[0]))
// arr[0] -= 32;
// int j = 1;
// while (arr[j])
// {
// if (isupper(arr[j]))
// {
// arr[j] += 32;
// }
// j++;
// }
// cout << arr << endl;
// }
// return 0;
//}
//#include<iostream>
//#include<cctype>
//using namespace std;
//char arr[110][30];
//int main()
//{
//   int n;
//   cin>>n;
//   for(int i=0;i<n;i++)
//   {
//   	cin>>arr[i]; 
//   	int j; 
//   	for(j=0;arr[i][j]!='\0';j++)
//	   {
//	   	if(j==0)
//	   	{
//	   		if(islower(arr[i][j]))
//	   		arr[i][j]=toupper(arr[i][j]);
//		   }
//	   	else
//	   	{
//	   		if(isupper(arr[i][j]))
//	   		arr[i][j]=tolower(arr[i][j]);
//		   }
//		} 
//	}
//   for(int i=0;i<n;i++)
//   {
//   	cout<<arr[i]<<endl;
//   }
//    return 0;
//}




////B2109 统计数字字符个数
//#include<iostream>
//using namespace std;
//char c[266];
//
//int main()
//{
//	//cin>>c;//无法输入带空格 
//	scanf("%[^\n]s",c) ;
//	int count=0;
//	for(int i=0;c[i]!='\0';i++)
//	{
//		if(c[i]>=48&&c[i]<=57)
//		count++;
//	}
//	cout<<count; 
//    return 0;
//}
//


////P5733 【深基6.例1】自动修正小写转换大写 
//#include<iostream>
//#include<cstring>
//#include<cctype>
//using namespace std;
//char c[110];
//int main()
//{
//   cin>>c;
//   int sz=strlen(c);
//   for(int i=0;i<sz;i++)
//   {
//   	if(islower(c[i]))
//   c[i]	=toupper(c[i]);
//	} 
//	cout<<c;
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//using namespace std;
//char c[110];
//int main()
//{
//   cin>>c;
//   int sz=strlen(c);
//   for(int i=0;i<sz;i++)
//   {
//   	if(c[i]>=97&&c[i]<=122)
//   	c[i]-=32;
//	} 
//	cout<<c;
//    return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	char c[5]={'a','b','c','f','g'};
//	return 0;
// } 
