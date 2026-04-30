#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int h[N],v[N];
int r[N];
int main()
{
    int n;
    cin>>n;
    int ret=0;
    stack<int>st1;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i]>>v[i];
    }
    //分别左右递减栈
    //左边
    for(int i=1;i<=n;i++)
    {
       
        while(st1.size()&&h[st1.top()]<=h[i])st1.pop();
        if(st1.size())
        {
            r[st1.top()]+=v[i];
            ret=max(ret,r[st1.top()]);
        }
        st1.push(i);

    }
    //右边
    stack<int>st2;
    for(int i=n;i>0;i--)
    {
       
        while(st2.size()&&h[st2.top()]<=h[i])st2.pop();
            
        if(st2.size())
        {
            //找到距离最近高的，高的加上v【i】
            r[st2.top()]+=v[i];
            ret=max(ret,r[st2.top()]);
        }
        st2.push(i);

    }
    cout<<ret;
    return 0;
}