#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    // 提升 cin/cout 速度，国赛必备
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;

    // 【终极防护】：用 map 替代定长数组，彻底免疫超大坐标导致的越界！
    map<int, vector<int>> v; 
    map<int, int> in;        
    set<int> st; // 存储真正的摄像头 ID

    for (int i = 1; i <= n; i++) {
        int a, m; 
        cin >> a >> m;
        st.insert(a); // 完美去重并记录身份
        
        // 【关键防御】如果这个摄像头谁也没指着，也要初始化入度，否则它可能进不了初始队列
        if (in.find(a) == in.end()) in[a] = 0; 

        // 内部循环变量一定要换成 j，避免覆盖外层的 i！
        for (int j = 1; j <= m; j++) {
            int x; 
            cin >> x; 
            v[a].push_back(x);
            in[x]++; // 记录入度
        }
    }

    // 过一遍拓扑排序
    queue<int> q;
    int cnt = 0;

    for (int e : st) {
        if (in[e] == 0) {
            q.push(e);
            cnt++;
        }
    }

    while (q.size()) {
        int a = q.front(); 
        q.pop();

        // 删边
        for (auto& e : v[a]) {
            in[e]--;
            // 【完美逻辑】：只有当 e 是摄像头，且入度归零时，才入队！
            if (st.count(e) && in[e] == 0) {
                q.push(e);
                cnt++;
            }
        }
    }

    if (cnt == n) 
        cout << "YES\n";
    else 
        cout << n - cnt << "\n";

    return 0;
}
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <vector>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int>PII;
// int INF=0x3f3f3f3f;
// const int N = 1e6 + 10;
// vector<int>v[510];
// int in[510];
// int main() {

//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n;cin>>n;
//   //位置可以超过n；
//  // map<int, int>mp;
//  set<int>st;
//   int pos=0;
//   for(int i=1;i<=n;i++)
//   {
//     int a,m;cin>>a>>m;
//    // if(mp.count(a)==0)//必须有这个
//    // mp[++pos]=a;
//    st.insert(a);
//     for(int i=1;i<=m;i++)
//     {
//       int x;cin>>x;//可能该位置不是摄像头
//       v[a].push_back(x);
//       in[x]++;//记录入度
//     }
//   }
//   //过一遍拓扑排序
//   queue<int>q;
//   int cnt=0;
//   for(int e:st)
//   {
//     if(in[e]==0)
//     {
//       q.push(e);
//       cnt++;
//     }
//   }
//   while(q.size())
//   {
//     int a=q.front();q.pop();
//     //cout<<a<<" ";
//     //删边
//     for(auto&e:v[a])
//     {
//       in[e]--;
//      // if(mp.count(e))//该点为摄像头
//      if(st.count(e))
//       if(in[e]==0)
//       {
//         q.push(e);
//         cnt++;
//       }
//     }
//   }
//   if(cnt==n)cout<<"YES";
//   else
//   cout<<n-cnt;
//   return 0;
// }
