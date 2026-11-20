// #include <bits/stdc++.h>
// using namespace std;
// #ifndef DEBUG
// struct __X {
//   __X& operator<<(const auto& str) {return *this;}
//   void sp(const string& str = "") {}
// } dout;
// #define debug(x)
// #endif
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// #define rep(i,m,n) for(int i=m;i<=n;++i)
// #define lc p<<1
// #define rc p<<1|1
// const int N = 1e6 + 10;
// void wait()
// {
//     int n,m;cin>> n>>m;
//     string s;
//     cin>>s;
//     int cnts=1;//记录旋转次数
//     int ans=0;
//         int i=0;
//         while(s[i]=='0')i++;
//         int cnt=0;
//         for(int j=i;j<n;j++)
//         {
//             cnt=(cnt*10+s[j]-'0')%m;
//         }
//         if(cnt==0)ans++;
//     if(i!=0)//有前导零
//     {
//         int x=i;
//         while(x--)
//        {   int i=0;
//         while(s[i]=='0')i++;
//         int cnt=0;
//         for(int j=i;j<n;j++)
//         {
//             cnt=(cnt*10+s[j]-'0')%m;
//         }
//         if((cnt*10)%m==0)ans++;
//         cnts++;
//         if(cnts==10)
//         {
//             cout<<ans<<'\n';
//             return;
//         }
//     }
//     }
//     //需要改变位置
//     //继承上面，
//     string tmp(n,'0');
//     for(int j=i,x=0;j<n;j++,x++)
//     {
//         tmp[x]=s[j];
//     }
//     do{
//         char a=tmp[0];
//         tmp.erase(0,1);
//         tmp.push_back(a);
//          int i=0;
//         while(s[i]=='0')i++;
//         int cnt=0;
//         for(int j=i;j<n;j++)
//         {
//             cnt=(cnt*10+tmp[j]-'0')%m;
//         }
//         if((cnt)%m==0)ans++;
//         cnts++;
//         if(cnts==10)
//         {
//             cout<<ans<<'\n';
//             return;
//         }
//     }while(1);
    
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin >> T;  // 多测时取消注释
//     while (T--) {
//         wait();
//     }
//     return 0;
// }
//上面读错题意，不是旋转
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
void wait()
{
    ll n,m;
    cin>>n>>m;

    string s;
    cin>>s;
    int ans=0;
     ll cnt=0;
        rep(i,0,n-1)
        {
            cnt=(cnt*10+s[i]-'0')%m;
        }
        if(cnt==0)
            ans++;
    rep(x,1,9)
    {
        rep(k,0,n-1)
        {
            s[k]=(char)((s[k]-'0'+1)%10+'0');//基于原始修改
        }
        cnt=0;
        rep(i,0,n-1)
        {
            cnt=(cnt*10+s[i]-'0')%m;
        }
        if(cnt==0)
            ans++;
    }
    cout<<ans<<'\n';
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