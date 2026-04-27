//P1098 [NOIP 2007 提高组] 字符串的展开
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int p1,p2,p3;
string ret; 
void deal(int x)
{
	
	int p=s.find('-',x);
	if(p==string::npos) 
	{
		ret+=s.substr(x);//加上剩余的
		return; 
	}
    //处理第一个或者最后一个为‘-‘
	if(p==0||p==s.size()-1)
	{
        ret+='-';
		deal(p+1);
		return;
	 } 
	string s1=s.substr(x,p-x);//截取前面一段；加上左字符
	ret+=s1;
	string s2=s.substr(p-1,3);//处理第一段 
	
	
	if((isdigit(s2[0])&&isdigit(s2[2])&&s2[0]<s2[2])||(isalpha(s2[0])&&isalpha(s2[2])&&s2[0]<s2[2])) 
	{
		 if(s2[2]-s2[0]==1)
		{
			ret+=s2[2];
		}
		else
		{
				string s3; //中间字符串 
		if(p1==3)
		 {
		 	
			for(int i=1;i<=s2[2]-s2[0]-1;i++)
			{
				for(int j=0;j<p2;j++)//重复
				{
					s3+='*';
				 } 
			}
		 }
		
		else
		{
			for(int i=1;i<=s2[2]-s2[0]-1;i++)
			{
				for(int j=0;j<p2;j++)//重复
				{
					s3+=s2[0]+i;
				 } 
			}
		}
		//小写
		if(p1==1)
		{
			for(int i=0;i<s3.size();i++)
			{
				s3[i]=tolower(s3[i]);
			}
		}
		if(p1==2)
		{
			for(int i=0;i<s3.size();i++)
			{
				s3[i]=toupper(s3[i]);
			}
		}
		if(p3==2)
		reverse(s3.begin(),s3.end());
		//拼接
		ret+=s3;
		ret+=s2[2]; 
		
		}
	 } 
	 else //不满足 
	 {
	 	ret+='-';
         ret+=s2[2];
	 }
	 //处理剩下的
	 deal(p+2);//找下一个‘-’ 
}
int main()
{
	cin>>p1>>p2>>p3>>s; 
	//处理 
	deal(0);
	cout<<ret;

	return 0;
}




////P5731 【深基5.习6】蛇形方阵
//#include <iostream>
//
//using namespace std;
//const int N=20;
//int a[N][N];
////右 下 左 上 
//int dx[]={0,1,0,-1};
//int dy[]={1,0,-1,0};
//
//int main()
//{
//	int n;cin>>n;
//	int num=1;//计数 
//	int x=1,y=1;
//	int p=0;//标识方向 
//	while(num<=n*n)
//	{
//		a[x][y]=num;
//		//更新
//		//x+=dx[p];y+=dy[p];不能直接修改，越界无法保存上个值
//		int c=x+dx[p],b=y+dy[p];
//		if(c>n||b>n||c<1||b<1||a[c][b])
//		{
//			p=(p+1)%4;//0,1,2,3循环走
//			c=x+dx[p];b=y+dy[p];
//		 } 
//		 x=c;y=b;
//		 num++;
//		 
//	 } 
//	 for(int i=1;i<=n;i++)
//	 {
//	 	for(int j=1;j<=n;j++)
//	 	{
//	 		printf("%3d",a[i][j]);
//		 }
//		 puts("");
//	 }
//	return 0;
// } 
//


//P1067 [NOIP 2009 普及组] 多项式输出
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=n;i>=0;i--)
//	{
//		int a;cin>>a;
//		if(a==0)continue;
//		//符号 
//		if(a>0)
//		{
//			if(i!=n)cout<<'+';
//		}
//		else cout<<'-';
//		//数字
//		if(abs(a)!=1||(abs(a)==1&&i==0))
//		{
//			cout<<abs(a);
//		 } 
//		 //x
//		 if(i>1)cout<<"x^"<<i;
//		 else if(i==1)cout<<"x";
//		 //等于0不输出 
//	}
//	return 0;
// } 

