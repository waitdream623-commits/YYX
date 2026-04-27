//P1104 生日
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct stu{
	string name;
	int y,m,d;
}s[120];
bool cmp(stu s1,stu s2)
{
	if(s1.y!=s2.y)
	return s1.y<s2.y;//数字越小年龄越大 
	else if(s1.m!=s2.m)
	return s1.m<s2.m;
	else
	return s1.d<s2.d;
}
int main()
{
	int n;
	cin>>n;
	 for(int i=0;i<n;i++)
	 {
	 	cin>>s[i].name>>s[i].y>>s[i].m>>s[i].d;
	 }
	 sort(s,s+n,cmp);
	 for(int i=0;i<n;i++)
	 {
	 	cout<<s[i].name<<endl;
	 }
	return 0;
 } 


////P1093 [NOIP 2007 普及组] 奖学金
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct stu{
//	int id;
//	int chinese,math,english,total;
//	
//}s[310];
////仿函数 
//struct Cmp{
//	bool operator()(stu s1,stu s2)
//	{
//		if(s1.total>s2.total)
//		return true;
//		else if(s1.total<s2.total)
//		return false;
//		else
//		{
//			if(s1.chinese>s2.chinese)
//			return true;
//			else if(s1.chinese<s2.chinese)
//			return false;
//			else
//			{
//				if(s1.id<s2.id)
//				return true;
//				else if(s1.id>s2.id)
//				return false;
//			}
//		}
//		
//	}
//}cmp;
//int main()
//{
//	int n;
//	cin>>n;
//	//输入数据 
//	for(int i=1;i<=n;i++)
//	{
//		cin>>s[i].chinese>>s[i].math>>s[i].english;
//		s[i].id=i;
//		s[i].total=s[i].chinese+s[i].math+s[i].english;
//		
//	}
//	//比较
//	sort(s+1,s+n+1,cmp); //从1到n+1 
//	for(int i=1;i<=5;i++)
//	{
//		cout<<s[i].id<<' '<<s[i].total<<endl;
//	}
//	
//	
// } 
////争夺前五名
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int arr[60];
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cin>>arr[i];
//		
//		
//	 } 
//	 sort(arr,arr+n);
//	 int cnt=0;//计数5个 
//	 for(int i=n-1;;i--)
//	 {
//	 	cout<<arr[i]<<" ";
//	 	cnt++;
//	 	if(cnt==5)
//		 break; 
//	 }
//	return 0;
//}

////B2131 甲流病人初筛
//#include<iostream>
//#include<string>
//using namespace std;
//struct patient{
//	string name;
//	double tem;
//	int cou;
//}s;
//
//int main()
//{
//	int n;
//	cin>>n;
//	int cnt=0;
//	while(n--)
//	{
//		cin>>s.name>>s.tem>>s.cou;
//		if(s.tem>=37.5&&s.cou)
//		{
//			cout<<s.name<<endl;
//			cnt++;
//		}
//		
//	}
//	cout<<cnt;
//	return 0;
//}


//////B2125 最高分数的学生姓名
////将最大分数存为结构体 
//#include<iostream>
//#include <string>
//#include<algorithm> 
//using namespace std;
//struct stu{
//	int score;
//	string name;
//	
//}s;
//stu Max={0,""}; 
//int main()
//{
//	int n;//n次询问输出
//	cin>>n;
//	int tmp=0;
//	for(int i=0;i<n;i++)
//	{
//		cin>>s.score>>s.name;
//		if(Max.score<s.score)
//	{
//		Max.score=s.score;
//		Max.name=s.name;
//	 }
//}
//	 cout<<Max.name;
//	return 0;
//  
//}
////使用排序 
//#include<iostream>
//#include <string>
//#include<algorithm> 
//using namespace std;
//struct stu{
//	int score;
//	string name;
//	
//}s[110];
//bool cmp(stu s1,stu s2)
//{
//	return s1.score>s2.score;
//}
//int main()
//{
//	int n;//n次询问输出
//	cin>>n;
//	int tmp=0;
//	for(int i=0;i<n;i++)
//	{
//		cin>>s[i].score>>s[i].name;
//		
//	 } 
//	sort(s,s+n,cmp);
//	 cout<<s[0].name;
//	return 0;
// } 
//#include<iostream>
//#include <string>
//using namespace std;
//struct stu{
//	int score;
//	string name;
//	
//}s[110];
//int main()
//{
//	int n;//n次询问输出
//	cin>>n;
//	int tmp=0;
//	for(int i=0;i<n;i++)
//	{
//		cin>>s[i].score>>s[i].name;
//		tmp=max(tmp,s[i].score);
//		
//	 } 
//	for(int i=0;i<n;i++)
//	{
//		if(s[i].score==tmp)
//		cout<<s[i].name;
//		
//	 } 
//	
//	return 0;
// } 


////P5742 【深基7.例11】评等级
//#include<iostream>
//using namespace std;
//
//struct stu
//{
//	long long id;
//	int x;
//	int t;
//	double total;
//	
//	
//}s;
//void is_good(stu s)
//	{
//		if((s.x+s.t)>140&&s.total*10>=800)
//		cout<<"Excellent"<<endl;
//		else
//		cout<<"Not excellent"<<endl;
//	}
//int main()
//{
//	int n;
//	cin>>n;
//	while(n--)
//{
//	cin>>s.id>>s.x>>s.t;
//	s.total=s.x*0.7+s.t*0.3;
//	is_good(s);
//	}	
//
//	return 0;
//}
////CPP64 重载小于号
//#include <iostream>
//using namespace std;
//
//class Time {
//
//    public:
//        int hours;      // 小时
//        int minutes;    // 分钟
//
//        Time() {
//            hours = 0;
//            minutes = 0;
//        }
//
//        Time(int h, int m) {
//            this->hours = h;
//            this->minutes = m;
//        }
//
//        void show() {
//            cout << hours << " " << minutes << endl;
//        }
//
//        // write your code here......
//        bool operator<(Time& t)//可优化先比较小时，相同再比较分钟 
//        {
//            int a,b;
//            a=hours*60+minutes;
//            b=t.hours*60+t.minutes;
//            return a<b;
//        }
//        
//
//};
//
//int main() {
//    int h, m;
//    cin >> h;
//    cin >> m;
//
//    Time t1(h, m);
//    Time t2(6, 6);
//	
//    if (t1<t2) cout<<"yes"; else cout<<"no";
//    return 0;
//}

////CPP43 加号运算符重载
//#include <iostream>
//using namespace std;
//
//class Time {
//
//    public:
//        int hours;      // 小时
//        int minutes;    // 分钟
//
//        Time() {
//            hours = 0;
//            minutes = 0;
//        }
//
//        Time(int h, int m) {
//            this->hours = h;
//            this->minutes = m;
//        }
//
//        void show() {
//            cout << hours << " " << minutes << endl;
//        }
//
//        // write your code here.....
//        Time operator+(Time& t)
//        {
//            Time ret;
//            ret.minutes=minutes+t.minutes;
//            int flag=0;//进位
//            if(ret.minutes>=60)
//            {
//                ret.minutes-=60;
//                flag=1;
//            }
//            ret.hours=hours+t.hours+flag;
//            return ret;
//        }
//        
//
//};
//
//int main() {
//
//    int h, m;
//    cin >> h;
//    cin >> m;
//
//    Time t1(h, m);
//    Time t2(2, 20);
//
//    Time t3 = t1 + t2;
//    t3.show();
//    
//    return 0;
//}
