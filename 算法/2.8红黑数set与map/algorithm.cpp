//P5250 【深基17.例5】木材仓库
//没有重复长度 
//进货时存在格外处理
//出货，没有找最近长度，优先输出短的，空仓库输出empty 
#include<iostream>
#include<set>

using namespace std;
typedef long long LL;
const int INF=1e10+10;//如果要加右边界，要确保INf-x大于1e9或者不加右边界 
set<LL>mp;
int main()
{
    //处理mp边界条件
    mp.insert(-INF);mp.insert(INF);   
	int m;cin>>m;
	while(m--)
	{
		LL op,x;
		cin>>op>>x;
		if(op==1)
		{
			if(mp.count(x))cout<<"Already Exist"<<endl;
			else
			mp.insert(x);
		}
		if(op==2)
		{
            if(mp.size()==2) cout<<"Empty"<<endl; 
			else//不为空
			{
				//lower 找的是大于等于可以归为一起 
//				if(mp.count(x))
//				{
//					cout<<x<<endl
//					mp.erase(x);
//				}
//				//不存在 ，找最近长度，优先输出小的 
				
					auto it=mp.lower_bound(x);
					auto tmp=it;
					tmp--;//找到该长度前一个小于等于
					if(*it==x){
						cout<<x<<endl;
						mp.erase(x);
					}
					else if(abs(*it-x)>=abs(*tmp-x))
					{
						cout<<*tmp<<endl; 
						mp.erase(*tmp);
					}
					else
					{
						cout<<*it<<endl; 
						mp.erase(*it);
						
					}
			}
			
		}
	}
	return 0;
 } 
//P2234 [HNOI2002] 营业额统计
//#include<iostream>
//#include<set>
//
//using namespace std;
//set<int>mp;
//int main()
//{
//	int n;cin>>n;
//	int ret=0; 
//	//防止越界
//	mp.insert(-1e7); 
//	//第一个数
//	int x;cin>>x;
//	ret=x;
//	mp.insert(x);
//	mp.insert(1e7); 
//	for(int i=1;i<n;i++)
//	{
//		cin>>x;
//		//找出距离x最近的数
//		auto p=mp.lower_bound(x);
//		//因为set存储是有序的 
//		auto tmp=p;
//		int mi=*(tmp--);
//		ret+=min(abs(mi-x),abs(*p-x));
//		mp.insert(x);
//	}
//	cout<<ret;
//	return 0;
//}


////P2786 英语1（eng1）- 英语作文
//#include<iostream>
//#include<string>
//#include<map>
//
//using namespace std;
//int N,P;
//map<string,int>mp;
//int main()
//{
//	cin>>N>>P;
//	while(N--)
//	{
//		string s;
//		cin>>s;cin>>mp[s];
//	}
//	string comp="";
//	long long sum=0; 
//	char ch;
//	while(scanf("%c",&ch)!=EOF)
//	{
//		if(isalnum(ch))comp+=ch;
//		if(!isalnum(ch))
//		{
//			if(mp.count(comp))sum+=mp[comp];
//			comp.resize(0);
//		}
//	 } 
//	//不能这样输入 
////	while(cin>>comp)
////	{
////		int i=0;
////		//处理连着的标点
////		for(auto e:comp)
////		{
////			if(isalnum(e))i++;
////		 }
////		 comp.resize(i) ;
////		//含金量大于0，存在高级词汇即进入 
////		//如果为这样判顶不成功：“hansbug.” juruo!but
////		if(mp.count(comp))sum+=mp[comp];
////	}
//	cout<<sum%P;
//	return 0;
//}
