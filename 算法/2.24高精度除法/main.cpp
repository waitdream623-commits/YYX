#include <iostream>

using namespace std;

const int N=1e6+10;

int a[N],b,c[N];

int la,lc;
void divide(int c[],int a[],int b)
{
	long long  t=0; //可能超过int 
	for(int i=la-1;i>=0;i--)
	{
		t=t*10+a[i];
		c[i]=t/b;
		t%=b; 
	}
	
	//处理前导零
	while(lc>1&&c[lc-1]==0)lc--; 
	
}
int main()
{
	string x;cin>>x>>b;//b是除数
	la=lc=x.size(); 
	//逆序存储被除数，并从最后一位开始模拟
	for(int i=0;i<la;i++) a[la-1-i]=x[i]-'0';
	//处理
	divide(c,a,b);
	//输出
	for(int i=lc-1;i>=0;i--)cout<<c[i]; 
	 
	return 0;
}
