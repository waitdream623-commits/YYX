// Strings/KMP —— KMP 模板（起点文件）
//
// 用法：把 nxt 数组的求法 + 匹配部分闭卷写进 wait()，不看课件。
//       写完按 Strings/ReadMe.md 第五节做对拍（主串 ≤ 20、模式串 ≤ 5、字母表 ab）。
//
// 课件：cCourseware\md\算法讲解100【扩展】 KMP算法原理和代码详解.md
//       cCourseware\md\算法讲解101【扩展】 KMP算法相关题目.md
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
const int N = 1e6 + 10;
//对所找字符串进行求next
int ne[N];
void get_Next(string s)
{
    int n = s.size();
    ne[0]=-1;
    ne[1]=0;
    int last=0;
    //不能这样写，否则往前跳i会++
    // for(int i=2;i<=s.size();i++)//需要越界填一个
    // {
    //     if(s[i-1]==s[last])
    //     {
    //         ne[i]=++last;
    //     }
    //     else if(last==0)//再往下会导致越界
    //     {
    //         ne[i]=0;
    //     }

    //     else //不相等向前转移
    //     {
    //         last=ne[last];
    //     }
    // }
    int i = 2;
    while(i<n)//不需要填n
    {
        if(s[i-1]==s[last])
        {
            ne[i++]=++last;   
        }
        else if(last>0)
        {
            last = ne[last];
        }
        else
        {
            ne[i++]=0;
        }
    }
}
int KMP(string s1,string s2)//返回找到首位置
{
    get_Next(s2);
    int x = 0, y = 0;
    int n = s1.size();
    int m = s2.size();

    while(x< n && y< m)
    {
        if(s1[x]==s2[y])
        {
            x++;
            y++;
        }
       
        else if(y==0)//到0但是还没匹配成功
        {
            x++;
        }
         else
        {
            y=ne[y];
        }
    }
    return y==m?x-y:-1;//当y走完说明找到了
}
void wait()
{
    string s1,s2;
    cin >> s1 >> s2;
   
    cout<<KMP(s1,s2) << '\n';
     for(int i=0;i<=s2.size();i++)
    {
        cout<< ne[i]<<'\n';
    }
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
