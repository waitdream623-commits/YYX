#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
string s[30];
int n;
int st[30];//标记该单词已经用过，记得回溯
ll ret=0;
string tmp;
int pos;
string x;//龙头
int cal(string&t1,string&t2)
{
    // //对t2逆序找找到就返回
    // for(int i=t2.size()-2;i>=0;i--)
    // {
    //     if(t1.find(t2,0,i))
    // }
        for(int k=1;k<min(t1.size(),t2.size());k++)//最大重叠部分？？，终点不能为0,少一位防止子集，应该为最小重叠为1，尽量长
        {
            if(t1.substr(t1.size()-k,k)==t2.substr(0,k))
            {
                return k;
            }
        }    
        return -1;

}
ll cnt=0;
void dfs()
{
    //递归出口
    //自然出去，全部被标记完，或者遍历完，
    //扩展
    cnt++;
    for(int i=1;i<=pos;i++)
    {
          string t=tmp;//保存副本
        if(st[i]!=2)
        {
            if(tmp.size()==0&&s[i][0]==x[0])//龙头
            {
                tmp=s[i];
                st[i]++;
            }
            else if(tmp.size())//防止等于零进入匹配，导致出问题，size返回无符号整型，0-1变为一个很大的数
            {
                   int p=cal(tmp,s[i]);//返回s[i]中匹配的位置
                    if(p==tmp.size()||p==s[i].size()||p==-1)continue;
                    tmp+=s[i].substr(p);//返回为长度，需要改为下标，思考一下
                    st[i]++;
                   
            }
            dfs();
            st[i]--;
            tmp=t;//回溯
        }
    }
   
    ret=max<ll>((ll)tmp.size(),ret);
    return;
}
void slove()
{
    cin>>n;
 
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x.size()==1)//防止一个字母进入？？，能直接去掉，不能做开头，后面不能接
        continue;
        s[++pos]=x;
    }
    cin>>x;
    if(pos==0)//全部去掉长度为1
    {
        cout<<1;
        return;
    }
    dfs();
    cout<<ret<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        slove();
    }
    return 0;
}
