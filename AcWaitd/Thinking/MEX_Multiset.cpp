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
//对于该题，最好就是尽量平均分配，如果出现第一个不是3的倍数后面全部给那个没有的，防止前面有的继续增长
//破裂时计算下每个的mex;
//如何计算mex，三人分别计算是否从零开始累加1

int a[N];
void wait()
{
    multimap<int,int>mp;//记录下标，排序
    map<int,int>cnt;
    int mex[3]={-1,-1,-1};//后续判断是否有-1+1==0
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        mp.insert({x,i});//自动排序
        cnt[x]++;
    }
    string ans;
    ans.resize(n+1);
    //三个一循环
    int i=0;
    int br=0;int flag=1;//第一次分配不均
    char x;//后续全部未填占用
    for(auto e:mp)
    {
        i%=3;
        auto [k,idx]=e;
        if(cnt[k]>=3)
        {
            if(mex[i]+1==k)mex[i]=k;

            ans[idx]='A'+i++;
        }
        else  //要分配不均了
        {
            if(flag)
            {
                br=cnt[k];
              flag=0;
            }
           
                //没有分配均匀，有人断了，其余有了的不能继续增加，将其余全部改为此时字母，即ans为空的
            if(mex[i]+1==k)mex[i]=k;
            
            ans[idx]='A'+i++;

            br--;
             if(!br)//此时完了直接跳出
            {
                i%=3;//上一位加加越界
                x='A'+i;
                break;
            }
            
        }
    }
    //计算比较
    if(mex[0]+1+mex[1]+1+mex[2]+1<2*max({mex[0]+1,mex[1]+1,mex[2]+1}))
    {
        cout << "NO"<<"\n";
        return;
    }
    else
    {
        cout<< "YES"<<'\n';
        for(int i=1;i<=n;i++)
            {
                if(ans[i]=='\0')
                cout<<x;
                else
                cout<<ans[i];
            }
            cout<<'\n';
    }


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  // 多测时取消注释
    while (T--) {
        wait();
    }
    return 0;
}
