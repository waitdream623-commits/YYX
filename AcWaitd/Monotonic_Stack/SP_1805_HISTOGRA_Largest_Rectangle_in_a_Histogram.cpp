#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll ;
const int N=1e5+10;
int a[N];
ll  sum[N];
//找临近
int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while(cin>>n&&n)
  {
    ll ret=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    stack<int>st;
    //从左往右遍历，找到左边离的最近小的数,单调递增的栈
    //存下标
    for(int i=1;i<=n;i++)
    {
      while(st.size()&&a[st.top()]>=a[i])st.pop();
      // 【关键修复 2】宽度不需要 +1，(i - st.top()) 恰好包含了柱子 i 本身
        if(st.size())sum[i]+=a[i]*(i-st.top());//(i-st.top()+1)st.top()是第一个不满足，不计算
        else sum[i]+=a[i]*i;
      ret=max(ret,sum[i]);
      st.push(i);
    }
    while(st.size()) st.pop();//清空
    //从右往左遍历，找到右边离的最近小的数,单调递增的栈
    for(int i=n;i>0;i--)
    {
      while(st.size()&&a[st.top()]>=a[i])st.pop();
      
        if(st.size())sum[i]+=a[i]*(st.top()-i-1);//st.top()是第一个不满足，不计算，左计了柱子本身
        else sum[i]+=a[i]*(n-i);
      
      ret=max(ret,sum[i]);
      st.push(i);
    }
  cout<<ret<<endl;
  memset(sum, 0, sizeof(sum));
  }
  return 0;
}
