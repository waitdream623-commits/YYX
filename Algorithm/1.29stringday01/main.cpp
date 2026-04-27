//P1957 口算练习题

#include<iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;
   string ch;
   string last;
   while(n--)
   {
  
   	cin>>ch;
   	
   	int a,b;
   		
   		
   	string s;//用于计算长度 
   		if(ch[0]=='a'||ch[0]=='b'||ch[0]=='c')
   		{
   			cin>>a>>b;
		   if(ch[0]=='a')
   		{
   			cout<<a<<'+'<<b<<'='<<a+b<<endl;
   			s=to_string(a)+to_string(b)+to_string(a+b);
   			cout<<s.size()+2<<endl;//加上运算符和等号符 
		   }
		   	if(ch[0]=='b')
   		{
   			cout<<a<<'-'<<b<<'='<<a-b<<endl;
   				s=to_string(a)+to_string(b)+to_string(a-b);
   			cout<<s.size()+2<<endl;
		   }
		   	if(ch[0]=='c')
   		{
   			cout<<a<<'*'<<b<<'='<<a*b<<endl;
   				s=to_string(a)+to_string(b)+to_string(a*b);
   			cout<<s.size()+2<<endl;
		   }
		   last=ch;//保存上一次操作 
		}
		
	   else//只输入两个
	   {
	   	a=stoi(ch);
	   	cin>>b;
	   	   if(last[0]=='a')
   		{
   			cout<<a<<'+'<<b<<'='<<a+b<<endl;
   			s=to_string(a)+to_string(b)+to_string(a+b);
   			cout<<s.size()+2<<endl;//加上运算符和等号符 
		   }
		   	if(last[0]=='b')
   		{
   			cout<<a<<'-'<<b<<'='<<a-b<<endl;
   				s=to_string(a)+to_string(b)+to_string(a-b);
   			cout<<s.size()+2<<endl;
		   }
		   	if(last[0]=='c')
   		{
   			cout<<a<<'*'<<b<<'='<<a*b<<endl;
   				s=to_string(a)+to_string(b)+to_string(a*b);
   			cout<<s.size()+2<<endl;
		   }
	   	
	   	
		} 
	   
   	
   }
    return 0;
}

////P1765 手机
//#include<iostream>
//#include<string>
//#include<cctype>
//using namespace std;
//int arr[128];
//int main()
//{
//	char t='a'; 
//	int x=6;
//	while(x--)
//	{
//		for(int i=1;i<4;i++)
//		{
//		arr[t-1+i]=i;
//		}
//		t+=3;
//	}
//	arr['s']=arr['z']=4;
//	int z=2;
//	char a='t';
//	while(z--)
//	{
//		for(int i=1;i<4;i++)
//		{
//		arr[a-1+i]=i;
//		}
//		a+=3;
//	}
//   
//   string s;
//   //有空格不能用cin    cin>>s;
//   getline(cin,s);
//   int  cnt=0;
//   for(int i=0;i<s.size();i++)
//   {
//   	if(isspace(s[i]))
//   	cnt++;
//   	else
//   	cnt+=arr[s[i]];
//   }
//   cout<<cnt;
//    return 0;
//}




////B2124 判断字符串是否为回文
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//   string s,s1;
//   cin>>s;
//   s1=s;
//   reverse(s.begin(),s.end());
//   if(s==s1)
//   cout<<"yes";
//   else
//   cout<<"no";
//    return 0;
//}
////
////B2122 单词翻转
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//   string s;
//   while(cin>>s)
//   {
//   	//手动翻转 
//   int left=0;
//   int right=s.size()-1;
//   while(left<right)
//   {
//   	char t=s[left];
//   	s[left]=s[right];
//   	s[right]=t;
//   	left++;
//   	right--;
//	} 
//	cout<<s<<endl;
//}
//    return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//   string s;
//   while(cin>>s)
//   {
//   for(string::iterator sp=s.end()-1;sp>=s.begin();sp--)
//   {
//   	cout<<*sp;
//   }
//   cout<<endl;
//}
//    return 0;
//}




//
////B2120 单词的长度
//#include<iostream>
//#include<string> 
//using namespace std;
//int main()
//{
//   string s;
//   cin>>s;
//   cout<<s.size(); 
//   while(cin>>s)
//   {
//   	cout<<","<<s.size();
//   }
//    return 0;
//}



////P5734 【深基6.例6】文字处理软件
//#include<iostream>
//#include<string> 
//using namespace std;
//int main()
//{
//   int n;
//   string s;
//   cin>>n>>s;
//   while(n--)
//   {
//   	int c;
//   	cin>>c;
//   	if(c==1)
//   	{
//   		string s2;
//   		cin>>s2; 
//   		s+=s2;
//   		cout<<s<<endl;
//	   }
//	   if(c==2)
//	   {
//	   	int a,b;
//	   	cin>>a>>b;
//	   	s= s.substr(a,b);
//	   	cout<<s;
//	   	
//	   }
//	   if(c==3)
//	   {
//	   	int a;
//	   	string s2;
//	   	cin>>a>>s2;
//	   	s.insert(a,s2);
//	   	cout<<s;
//	   }
//	   if(c==4)
//	   {
//	   	string s2;
//	   	cin>>s2;
//	   	if(s.find(s2)!=string::npos)
//	   	cout<<s.find(s2);
//	   	else
//	   	cout<<-1;
//	   	
//	   }
//   	
//   	
//   	
//   }
//    return 0;
//}
////B2115 密码翻译
//#include<iostream>
//#include<string> 
//using namespace std;
//int main()
//{ 
//	string s;//自动扩容 
//	getline(cin,s);
//	for(int i=0;i<s.size();i++)
//	{
//		if((s[i]>='b'&&s[i]<='z')||(s[i]>='B'&&s[i]<='Z'))
//		s[i]-=1;
//		else if(s[i]=='a'||s[i]=='A')
//		s[i]+=25;
//	}
//	cout<<s;
//	return 0;
//}

////B2112 石头剪子布
//#include<iostream>
//using namespace std;
//int main(){
//	
//	int n;
//	cin>>n;
//	while(n--)
//	{
//		string s1,s2;
//		cin>>s1>>s2;
//		if(s1==s2)
//		cout<<"Tie";
//		else if(s1=="Rock"&&s2=="Scissors") 
//		cout<<"Player1";
//		else if(s1=="Scissors"&&s2=="Paper")
//		cout<<"Player1";
//		else if (s1=="Paper"&&s2=="Rock")
//		cout<<"Player1";
//		else
//		cout<<"Player2";
//		cout<<endl; 
//	}
//	return 0;
//} 


////P5015 [NOIP 2018 普及组] 标题统计
//#include<iostream>
//#include<cctype>
//using namespace std;
//#include<string>
//int main()
//{
//   string s;
//   getline(cin,s);//不读取\n 
//   int sz=s.size();
//   int count=0;
//   for(auto e:s)
//   {
//   	if(isspace(e))
//   	continue;
//   	else
//   	count++;
//   	
//	} 
//	cout<<count;
//    return 0;
//}
