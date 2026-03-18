//P10457 占卜DIY
#include <iostream>

using namespace std;
int a[14][5];
int cnt[14];//记录没翻开每种牌数量，初始为4，可以顺便访问最后一张牌 
void dfs(int x)
{
	if(x==13)return;
	int r=a[x][cnt[x]];
	cnt[x]--;
	dfs(r);
}
int main()
{
	for(int i=1;i<=13;i++)
	{
		cnt[i]=4;
		for(int j=1;j<=4;j++)
		{
			char ch;cin>>ch;
			if(ch>='2'&&ch<='9')a[i][j]=ch-'0';
			else if(ch=='A')a[i][j]=1;
			else if(ch=='0')a[i][j]=10;
			else if(ch=='J')a[i][j]=11;
			else if(ch=='Q')a[i][j]=12;
			else a[i][j]=13;
		}
	}
//		for(int i=1;i<=4;i++)
//		{
//			int x=a[13][i];
//			while(x!=13)
//			{
//				int t=a[x][cnt[x]];//找到x行的最下面牌 
//				cnt[x]--;
//				x=t;
//			}
//		}
//递归处理
	for(int i=1;i<=4;i++)
	{
		dfs(a[13][i]);
		
	 } 
		int ret=0;
		for(int i=1;i<=13;i++)
		{
			if(cnt[i]==0)ret++;
		 } 
		 cout<<ret;
	return 0;
 } 

////1205：汉诺塔问题
//#include <iostream>
//using namespace std;
////将x上盘子借助y移到z上 
//void dfs(int n,char x,char y,char z)
//{
//	if(n==0) 
//	{
//		return;
//	}
//	dfs(n-1,x,z,y);//x上n-1个盘子借助在z移到y；
//	printf("%c->%d->%c\n",x,n,z);//x上第n个盘子移到z；
//	dfs(n-1,y,x,z);//y上n-1个盘子借助x移到z； 
//}
//int main()
//{
//	//将a上盘子移到b上 
//	int n;char a,b,c;
//	cin>>n>>a>>b>>c;
//	dfs(n,a,c,b);
//	return 0;
// }
