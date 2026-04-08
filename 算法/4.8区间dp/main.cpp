//P1435 [IOI 2000] ╩ьндвж╢╝
#include<iostream>
#include<string> 
using namespace std;
int f[1100][1100];
int main()
{
	string s;
		cin>>s;
	int n=s.size();

	s=' '+s;
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j])f[i][j]=f[i+1][j-1];
			else
			f[i][j]=min(f[i+1][j],f[i][j-1])+1;
		}
	}
	cout<<f[1][n];
	return 0;
}
