//P1434 [SHOI2002] 滑雪
#include <iostream>

using namespace std;
int a[110][110];
int f[110][110];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dfs(int i,int j)
{
	if(f[i][j]) return f[i][j];//记忆 
	int s=1;//最短为1 
	for(int k=0;k<4;k++)//枚举四个方向
	{
		//可行性验证 
		int x=i+dx[k],y=j+dy[k];
		if(x<1||x>n||y<1||y>m)continue;
		if(a[x][y]>=a[i][j])continue;//需要大于等于,否侧超空间,取等的时候,往下面递归,会在两个相同之间来回递归;
		 s=max(dfs(x,y)+1,s);//递归返回这层，需要加上这层 
		  
	 } 
	 //标记该位置的最远距离
	 return f[i][j]=s; 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
	}
	//枚举每个起始位置
	int ret=0; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		ret=max(dfs(i,j),ret);
	}
	cout<<ret;
	return 0;
 } 


////P5635 【CSGRound1】天下第一
//#include <iostream>
//
//using namespace std;
//const int N=1e4+10;
//char f[N][N];//int 存不下 
//int t,p;
//char dfs(int x,int y)
//{
//	if(f[x][y])return '3';//循环
//	f[x][y]='3'; 
//	if(x==0)return f[x][y]='1';//多组测试数据，记录并修改3，
//	if(y==0)return f[x][y]='2';//说明到达这条路径上都是1或者2赢 
//	return f[x][y]=dfs((x+y)%p,(x+y+y)%p); 
//}	
//int main()
//{
//	cin>>t>>p;
//	while(t--)
//	{
//		int x,y;cin>>x>>y;
//		char r=dfs(x,y);
//		if(r=='1')cout<<1<<endl;
//		else if(r=='2')cout<<2<<endl;//不加else 不满足if会执行else 
//		else cout<<"error"<<endl; 
//	}
//	
//	return 0; 
//}


////P1464 [PacNW 1999] Function
//#include <iostream>
//
//using namespace std;
//typedef long long LL;
//LL a,b,c;
//LL f[30][30][30];//记忆 
//LL dfs(LL a,LL b,LL c)
//{
//	if(a<=0||b<=0||c<=0)return 1;
//	if(a>20||b>20||c>20)return dfs(20,20,20);
//	if(f[a][b][c]) return f[a][b][c];
//	if(a<b&&b<c) return f[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
//	else return f[a][b][c]= dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1); 
//}
//int main()
//{
//	while(cin>>a>>b>>c)
//	{
//        if(a==-1&&b==-1&&c==-1)break;
//		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,dfs(a,b,c));
//	}
//	
//	return 0;
//}
