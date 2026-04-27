//P1784 数独

#include<iostream>

using namespace std;
const int N=11;
int n=9;
int a[N][N];
bool col[N][N],row[N][N],st[N][N][N];//st表示方格 
bool dfs(int i,int j)
{
	if(j==n)//一排已经排完
	{
		i++;
		j=0; 
	 } 
	 if(i==n)return 1;
	 if(a[i][j])return dfs(i,j+1);
	 for(int x=1;x<=9;x++)
	 {
	 	if(	row[i][x]||col[j][x]||st[i/3][j/3][x])continue;
	 	
	 		row[i][x]=col[j][x]=st[i/3][j/3][x]=1;
	 		a[i][j]=x;
	 		if(dfs(i,j+1))return true;
	 		//回溯
			 row[i][x]=col[j][x]=st[i/3][j/3][x]=0;
	 		a[i][j]=0; 
	 }
	 return false;
}
int main()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			int x=a[i][j];
			row[i][x]=col[j][x]=st[i/3][j/3][x]=1;
		}
	 } 
	 dfs(0,0);
	 	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	 } 
	return 0;
 } 
