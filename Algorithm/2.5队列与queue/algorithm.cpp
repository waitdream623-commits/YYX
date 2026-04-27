//P2058 [NOIP 2016 普及组] 海港
#include <iostream>
#include<queue>
using namespace std;
const int N=1e5+10;
typedef pair<int,int>PII;//将时间与国籍绑定
queue<PII>q;
int cnt[N];//cnt[i]存放i国家人数 
int kinds;//存放国家种类，cnt[i]从0到1kinds++，从1到0 kinds--； 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int t,p;
		cin>>t>>p;
		while(p--)
		{
			int x;cin>>x;
			q.push({t,x});//将信息存入队列
			//种类
			if(cnt[x]++==0) kinds++;
			//else cnt[x]++; 
		}
		//判断时间，进出队与种类
		while(q.size()&&q.back().first-q.front().first>=86400) 
		{
		
			//种类变化
			int t=q.front().second;
			if(cnt[t]--==1) kinds--;//不论是否成立都加减 
			//else cnt[t]--;
			q.pop();//先改变种类再pop！！！！防止第一项丢失 
		}
		cout<<kinds<<endl;
	}
	return 0;
 } 

//// //P1540 [NOIP 2010 提高组] 机器翻译
//#include<iostream>
//#include<queue>
//using namespace std;
//const int N=1010;
//queue<int>q;//充当内存，满了前面弹出 
//bool arr[N];//arr[i]判断内存中是否有i 
//int cnt; 
//int main()
//{
//	int m,n;
//	cin>>m>>n;
//	while(n--){
//		int a;
//		cin>>a;
//		if(arr[a]) continue;
//		q.push(a);
//		arr[a]=1;//放入内存
//		cnt++;//查询字典次数； 
//		if(q.size()>m)//内存放满了
//		{
//			//丢掉第一个，并把arr改为false
//			arr[q.front()]=0; 
//			q.pop();
//			 
//		 } 
//	}
//	cout<<cnt<<endl; 
//}

// //ac9个，wa一个

// #include <iostream>
// using namespace std;
// int arr[1100];//存放已经放入内存单词 
// int main()
// {
// 	int m,n;
// 	cin>>m>>n;
// 	int cnt=0;
// 	int j=0;//标记内存中数据下标 
// 	for(int i=0;i<n;i++)
// 	{
// 		int a;
// 		cin>>a;
// 		int x=0;
// 		for(x=0;x<m;x++)
// 		{
// 			if(arr[x]==a)//存在直接翻译 
// 			break;
// 		}
// 		if(x==m) //没找到
// 		{
// 			arr[j++]=a;
// 			cnt++;
// 		 } 
// 		 if(j==m)
// 		 j=0; 
// 	 } 
// 	 cout<<cnt;
	
// }
////B3616 【模板】队列
//#include <iostream>
//using namespace std;
//const int N=1e5+10;
//int arr[N],h,t;
//int main()
//{
//	int q;
//	cin>>q;
//	while(q--)
//	{
//		int c;
//		cin>>c;
//		switch(c)
//		{
//			case 1:
//				int x;
//				cin>>x;
//				arr[++t]=x;
//				break;
//			case 2://弹出队首
//				if(h!=t) h++;
//				else cout<<"ERR_CANNOT_POP"<<endl;
//				break;
//			case 3:
//				if(h!=t) cout<<arr[h+1]<<endl;
//				else cout<<"ERR_CANNOT_QUERY"<<endl;
//				break;
//			case 4:
//				cout<<t-h<<endl;
//				break;
//		}
//	}
//	return 0;
//}
