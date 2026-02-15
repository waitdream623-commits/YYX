//高精度减法
#include <iostream>
#include <string>
using namespace std;
string x,y;
int la,lb,lc;
const int N=1e6+10;
int a[N],b[N],c[N];
bool cmp(string&x,string&y)
{
	//比较长度 
	if(x.size()!=y.size()) return  x.size()<y.size();
	//比较字典序 
	return x<y;
}
void sub(int c[],int a[],int b[])
{
	for(int i=0;i<=lc-1;i++)
	{
		c[i]+=a[i]-b[i];//以防该位被上一位借位； 
		if(c[i]<0)//处理借位 
		{
			c[i+1]--;
			c[i]+=10;
		}
	}
	//处理999-998或者1-1；
	while(lc>1&&c[lc-1]==0)
	{
		lc--;
	 } 
 } 
int main()
{
	cin>>x>>y;

	//大减小
	if(cmp(x,y))
	{
		swap(x,y);
		cout<<'-';
	 } 
	 la=x.size();lb=y.size();lc=max(la,lb);
	//逆序存储在数组中
	for(int i=0;i<=la-1;i++)a[i]=x[la-i-1]-'0';
	for(int i=0;i<=lb-1;i++)b[i]=y[lb-i-1]-'0'; 
	//相减结果存入c
	sub(c,a,b);
	//输出
	for(int i=lc-1;i>=0;i--)
	{
		cout<<c[i];
	 } 
	
	return 0;
 } 
