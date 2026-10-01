#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
#define rep(i,m,n) for(int i=m;i<=n;++i)
#define lc p<<1
#define rc p<<1|1
#define lowbit(x) (x&-x)
const int N = 1e6 + 10;
int ne[100];
void getnext(string& s)
{
    ne[0]=-1;
    ne[1]=0;
    int last=0;
      int i = 2;
    while(i<s.size())//不需要填n
    {
        if(s[i-1]==s[last])
        {
            ne[i++]=++last;  //匹配成功 
        }
        else if(last>0)
        {
            last = ne[last];//往前
        }
        else//此时last==0且没有相等
        {
            ne[i++]=0;
        }
    }
}
vector<int>f;
void  kmp(string& s,string& t)//找与t相同的首位置
{
    
    int i=0,j=0;
    while(i<s.size()&&j<t.size())
    {
        if(s[i]==t[j])
        {
            i++;j++;
        }
        else if(j>0)
        {
            j=ne[j];
        }
        else
        i++;

        if(i<=s.size()&&j==t.size())//匹配完一个//i也要等于，如果在字符串末尾匹配完
        {
            
            f.push_back(i-t.size());//此时i为下一个
            i=i-t.size()+1;
            j=0;
        }
    }
}
void wait()
{
    int q; cin >> q;
    string s ,t ;
    cin >> s>> t;
    getnext(t);
    kmp(s,t);
    //debug(f);
    while(q--)
    {
        int l ,r; cin >>l >>r;//此处为第几个字符，注意减一
        //找起点在里面的
        int pos=lower_bound(f.begin(),f.end(),l-1)-f.begin();
        //越界处理
        
        if(pos==f.size()||f[pos]>r-1||f[pos]+t.size()-1>r-1)cout<<"No\n";
        else
        cout<<"Yes\n";
    }
    //debug(ne);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
