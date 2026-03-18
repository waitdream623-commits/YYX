//P1087 [NOIP 2004 普及组] FBI 树
#include <iostream>
#include <string>
using namespace std;
int cheack(string s)
{
	int flag1=0,flag2=0;
	for(auto e:s)
	{
		if(e=='1')
		{
			flag1=1;
		}
		if(e=='0')
		{
			flag2=1;
		}
	}
	if(flag1&&flag2)return 2;
	if(flag1&&!flag2)return 1;
	return 0;
}
void dfs(string s)
{
	int n=s.size();
	if(n==1)
	{
		switch(cheack(s))
	{
		case 0 :cout<<'B';
		break;
		case 1 :cout<<'I';
		break;
		default :
		cout<<'F';
	}
	return;
	 } 
	string a,b;
	a=s.substr(0,n/2);//从下标0开始，长度为一半，最后下标为N/2-1； 
	b=s.substr(n/2,n/2);
	dfs(a);
	dfs(b);
	switch(cheack(s))
	{
		case 0 :cout<<'B';
		break;
		case 1 :cout<<'I';
		break;
		default :
		cout<<'F';
	}
 } 
 int main()
 {
 	int n;cin>>n;
 	string s;cin>>s;
 	dfs(s);
 	return 0;
 }
