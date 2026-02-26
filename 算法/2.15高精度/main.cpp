#include<iostream>

using namespace std;
const int N=1e6+10;

int a[N],b[N],c[N];
int la,lb,lc;
 
 void mul(int c[],int a[],int b[])
 {
 	//无进位乘法
	  for(int i=0;i<la;i++)
	  {
	  	for(int j=0;j<lb;j++)
	  	{
	  		c[i+j]+=a[i]*b[j];
		  }
	   } 
	   //进位
	   for(int i=0;i<lc;i++)
	   {
	   	if(c[i]>=10)
	   	{
	   		c[i+1]+=c[i]/10;
	   		c[i]%=10;
		   }
		} 
		//处理前导零
		while(lc>1&&c[lc-1]==0)lc--; 
 }
int main()
{
	string x,y;cin>>x>>y;
	la=x.size();lb=y.size();lc=la+lb;
	
		//逆序存储在整数数组中
	for(int i=0;i<la;i++)a[la-1-i]=x[i]-'0'; 
	for(int i=0;i<lb;i++)b[lb-1-i]=y[i]-'0';
	//
	mul(c,a,b);//c=a*b;
	//输出
	
	for(int i=lc-1;i>=0;i--)cout<<c[i]; 
	return 0;
 } 
