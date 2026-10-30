#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
int INF=0x3f3f3f3f;
const int N = 1e6 + 10;
int newv[N],neww[N];
int cnt;
ll f[N];
int wait1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // 多测时取消注释
    while (T--) {
        int n,W;cin>>n>>W;
        for(int i=1;i<=n;i++)
        {
            int a,b,y;
            cin>>a>>b>>y;
            //二进制拆分
            for(int j=1;j<=y;j<<=1)
            {
                neww[++cnt]=j*b;
                newv[cnt]=j*a;
                y-=j;
            }
            //剩余不是2的次方
            if(y>0)
            {
                neww[++cnt]=y*b;
                newv[cnt]=y*a;
            }
        }
        //0/1背包，优化版本
        for(int i=1;i<=cnt;i++)
        {
            for(int j=W;j>=neww[i];j--) 
            {
                f[j]=max(f[j],f[j-neww[i]]+newv[i]);
            }
        }
        cout<<f[W];
    }
    return 0;
}
//单调队列优化
int v[N],w[N],m[N];
ll dp[100000];
void wait2()
{

    int n,W;cin>>n>>W;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i]>>w[i]>>m[i];
        }
    for(int i = 1;i<=n;i++)
    {
        // for(int mod = 0;mod<min(W+1,w[i]);mod++)//分成组处理,以重量分组，与W比较，此处要为W+1，避免漏掉mod=w;
        // {
        //     deque<int>q;//
        //     for(int j = mod ;j<=W;j+=w[i])//一组
        //     {
        //         //维护单调队列,首为最大
        //         while(q.size()&&dp[i-1][q.back()]-1LL*q.back()/w[i]*v[i]<=dp[i-1][j]-1LL*j/w[i]*v[i])
        //         q.pop_back();

        //         q.push_back(j);//不要的情况
        //         if(q.front()==j-(w[i]*(m[i]+1)))//区间长度过大
        //         q.pop_front();

        //         dp[i][j] = dp[i-1][q.front()]-1LL*(q.front()/w[i])*v[i]+1LL*j/w[i]*v[i];

        //     }
        // }
        //空间压缩
        for(int mod = 0;mod<min(W+1,w[i]);mod++)
        {
            deque<int>q;//先处理后面的，需要先加入上一层的值
            for(int k = W-mod,t = 1;k>=0&&t<=m[i];k-=w[i],t++)//加入m个包含最后
            {
                while(q.size()&&dp[q.back()]-(q.back()/w[i])*v[i]<dp[k]-k/w[i]*v[i])
                q.pop_back();

                q.push_back(k);
            }
            for(int j = W-mod;j>=0;j-=w[i])//依赖上一层，逆序
            {
                int nw = j-w[i]*m[i];//必须要大于等于零
               if(nw>=0)
               {
                 while(q.size()&&dp[q.back()]-(q.back()/w[i])*v[i]<dp[nw]-nw/w[i]*v[i])
                q.pop_back();

                q.push_back(nw);
               }
                dp[j] = dp[q.front()]+(j/w[i]-q.front()/w[i])*v[i];
                //清楚j位置的数据，因为最后的最先加入，逆着的单调队列，看最后是不是该出区间了
                while(!q.empty() && q.front() == j)
                 q.pop_front();
            }
        }
    }
    cout << dp[W];
    return ;
}
int main()
{

    wait2();
}