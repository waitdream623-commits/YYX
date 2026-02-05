//P1241 括号序列
#include<iostream>
#include<stack>
#include<string>
 
using namespace std;
const int N=110;
bool f[N];//标记是否配对；
stack<int>st;//存储左括号位置i，左括号入栈，右括号找配对 
int main()
{
	string s; cin>>s;
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
		if(ch=='('||ch=='[')
		{
			
			st.push(i);//放入未配对左括号的位置 
			f[i]=0;//先标记未未配对 默认为零 
		}
		//括号匹配 
		else 
		{
			if(st.empty()) continue;//没有左括号 
			char tmp=s[st.top()];//st栈中存储的是s中的左括号下标 
			if((ch==')'&&tmp=='(')||(ch==']'&&tmp=='['))
			{
				
				f[i]=f[st.top()] =1;//标记已经配对 
				st.pop();
			}
			
		}
		//不匹配或者多出来右括号 均标记为false 默认初始化即为零 
	 } 
	 string ret="";
	 for(int i=0;i<s.size();i++)
	 {
	 	char ch=s[i];
	 	if(f[i])ret+=ch;
	 	else//未配对的 
	 	{
	 		if(ch=='(')
	 		{
	 			ret+=ch;ret+=')';
			 }
			 if(ch==')')
	 		{
	 			ret+='(';ret+=ch;
			 }
			 if(ch=='[')
	 		{
	 			ret+=ch;ret+=']';
			 }
			 if(ch==']')
	 		{
	 			ret+='[';ret+=ch;
			 }
			 
		 }
	 }
	 cout<<ret<<endl;
	return 0;
 } 


////P1449 后缀表达式
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//string s;
//int main()
//{
//	cin>>s;
//	//压栈，如果是运算符出栈两个数字，计算结果压栈，结束为@
//	stack<int>st;//不能是char，存放不了 两位以上数字
//	int i=0;
//	int num=0; 
//	while(s[i]!='@')
//	{
//		
//		if(isdigit(s[i]))
//		{
//			
////			//stoi只能传字符串 
////			//int x=stoi(s[i]);
////			int num=s[i]-'0';
////			//处理连着的数字 
////			i++;
////			while(s[i]!='.')//数字后面必然有'.'
////			{
////					
////				num=num*10+(s[i]-'0');
////				
////				i++; 
////			}
////			st.push(num);
//			num=num*10+s[i]-'0';
//			i++;
//		}
//		else if(s[i]=='.')
//		{
//			i++;
//			st.push(num);
//			num=0;
//		 } 
//		 else
//		 {
//		 	//遇到运算符，出栈两个数 
//		 	int b=st.top();//第2个操作数 
//			 st.pop();
//			int a=st.top(); //第1个操作数
//             st.pop();//切勿忘记 
//			 switch(s[i])
//			 {
//			 	case '+':
//				 st.push(a+b);
//				 break; 
//				 case '-':
//				 st.push(a-b);
//				 break; 
//				 case '*':
//				 st.push(a*b);
//				 break; 
//				 case '/':
//				 st.push(a/b);
//				 break; 
//			 }
//			 i++;
//		 }
//	 } 
//	 //最后结果依然放在栈中 
//	 cout<<st.top();
//	return 0;
// } 

////P4387 【深基15.习9】验证栈序列
//#include <iostream>
//#include <stack>
//using namespace std ;
//const int N=1e5+10;
//int a[N],b[N]; 
//
//int main()
//{
//	int q;
//	cin>>q;
//	while(q--)
//	{
//		int n;
//		cin>>n;
//		for(int i=0;i<n;i++)
//		{
//			cin>>a[i];
//		}
//		for(int i=0;i<n;i++)
//		{
//			cin>>b[i];
//		}
//		//模拟进出栈
//		stack<int>st;
//		int j=0;
//			for(int i=0;i<n;i++)
//			{
//				st.push(a[i]);
//				//不只出栈一次，可能连续出栈
//				while(j<n&&st.size()&&st.top()==b[j])
//				{
//					//出栈
//					st.pop();
//					j++; 
//				}
//				
//				
//			}
//		 if(st.size()) cout<<"No"<<endl;
//		 else cout<<"Yes"<<endl;
//		 
//	}
//	
//}


////20. 有效的括号
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char>st;
//        for(auto e:s)
//        {
//            if(e=='('||e=='{'||e=='[')
//            st.push(e);
//            //将栈顶与其匹配
//            else{
//                //如果栈已经空了没有左括号，此时返回false,即无top
//                if(st.empty())return 0;
//                 char left=st.top();
//            if(e==')'&&left!='(') return 0;
//            if(e==']'&&left!='[') return 0;
//            if(e=='}'&&left!='{') return 0;
//                       
//            //不满足上述情况说明匹配，将其消去
//            st.pop();
//            }
//                
//        }
//        //最后为空说明匹配完全
//        return st.empty();
//        
//    }
//};
////B3614 【模板】栈
//#include<iostream>
//#include<string>
//using namespace std;
//const int N=1e6+10;
//unsigned long long stk[N],top;//ll最多存2的64次方减一 
//void push(unsigned long long x)
//{
//    stk[++top]=x;
//}
////判空
//int size()
//{
//    return top;
//}
//void pop()
//{
//    if(size())
//    {
//        top--;
//    }
//    else 
//        cout<<"Empty"<<endl;
//}
//////输出栈顶元素
//unsigned long long query()
//{
//    return stk[top];
//
//}
//int main()
//{
//    int T,q;
//    cin>>T;
//    while(T--)//每次操作后需要清空数据 
//    {
//    cin>>q;
//        while(q--)
//        {
//            string s;
//            unsigned long long a;//注意类型一致
//            cin>>s;
//            if(s=="push")
//            {
//                cin>>a;
//                push(a);
//            }
//            else if(s=="query")
//            {
//               if(size())
//               {
//                   cout<<query()<<endl;
//               }
//                else
//                    cout<<"Anguei!"<<endl;
//            }
//            else if(s=="size")
//                cout<<size()<<endl;
//            else
//                pop();
//        }
//        //清空数据
//		top=0; 
//
//        
//    }
//}
