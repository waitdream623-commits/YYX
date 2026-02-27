//UVA11464 Even Parity
#include<iostream>
#include <cstring> 
using namespace std;
const int N=20;
int a[N],t[N]; 
int jude(int n,int x,int y)
{
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(((x>>i)&1)==0&&((y>>i)&1)==1)r++;
		if(((x>>i)&1)==1&&((y>>i)&1)==0)return -1;
	}
	return r;
 } 
int deal(int n)
{
	//暴力枚举第一行结果，只能将0->1
	int ret=0x3f3f3f3f;
	for(int i=0;i<(1<<n-1);i++)
	{
		memcpy(t,a,sizeof(a)); 
		int tmp=0; //暂时存放更改次数 
		int change=i;//第一行枚举结果 
		int flag=1;//判断合法标志 
		for(int j=1;j<=n;j++)
		{
			
			//判断枚举是否合法
		 if(jude(n,a[j],change)==-1)
		 {
		 	flag=0;
		 	break;
		 }
		 tmp+=jude(n,a[j],change);
		//执行结果即为change
		t[j]=change;
		
		//下一行 
		change=t[j-1]^(t[j]<<1)^(t[j]>>1);
		change&=(1<<n)-1;//消除高位影响  
		}
		if(flag) ret=min(ret,tmp);
		
	}	
	if(ret==0x3f3f3f3f)return -1;
	else 
	return ret;
 } 
int main()
{
	int q;cin>>q;
	for(int m=1;m<=q;m++)
	{
		int n;cin>>n;
		memset(a,0,sizeof(a));
		//二进制存储 
		for(int i=1;i<=n;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				int c;cin>>c;
				if(c) a[i]|=1<<j;
			}
			
		}
		printf("Case %d: %d\n",m,deal(n)); 
		
	 } 
	return 0;
}

////P10449 费解的开关
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N=10;
//int a[N],r[N];
//int calc(int push)
//{
//	int ret=0;
////	for(int i=0;i<5;i++)
////	{
////		if((a>>i)&1==0&&(b>>i)&1==1)ret++;
////		if((a>>i)&1==1&&(b>>i)&1==0)ret++;
////	}
//while(push)
//{
//	ret++;
//	push&=(push-1);//去掉最后一位1； 
//}
//	return ret;
//	
//}
//void deal()
//{
//	
//	//暴力枚举第一行开关最终情况
//	int ret=0x3f3f3f3f; 
//	for(int i=0;i<(1<<5);i++)
//	{
//		memcpy(r,a,sizeof(a));
//		int tmp=0;
//		int change=i;
//		for(int j=1;j<=5;j++)
//		{
//			tmp+=calc(change);
//			r[j]=r[j]^change^(change<<1)^(change>>1);
//			//消除边界影响
//			r[j] &=((1<<5)-1);
//			r[j+1]=r[j+1]^change;
//			change=r[j];
//		 }
//		 if(r[5]==0)
//		 ret=min(tmp,ret);
//	}
//	if(ret>6)cout<<-1<<endl;
//	else cout<<ret<<endl;
//}
//int main()
//{
//	int n;
//	cin>>n;
//	while(n--)
//	{
//		memset(a,0,sizeof(a));
//		for(int i=1;i<=5;i++)
//		{
//			//反转存储，改为全关，o存为1；
//			for(int j=0;j<5;j++) 
//			{
//				char c;cin>>c;
//				if(c=='0') a[i]|=1<<j;
//			}
//		}
//		deal();
//	}
//	return 0;
//}
