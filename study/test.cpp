#include<bits/stdc++.h>

using namespace std;
pair<double,double>nodex[10005],nodey[10005];
// pair<double,double> z; 
// int zid=INT_MAX;
// int n;
// struct point{
//     double x,y; int id;
// }node[100005];
int n;
double getdis(pair<double,double> i,pair<double,double> j)
{
    double ans = sqrt(pow(i.first-j.first,2)+pow(i.second-j.second,2));
    return ans;
}
//判断是否相等，
map<pair<double,double>,int>mp;
double getmindis(int l,int r,pair<double,double>&x,pair<double,double>&y)
{
    if(r-l+1==2)
    {
        x = nodex[l],y= nodex[r];
        return getdis(nodex[l],nodex[r]);
    }
    //只有1个怎么办
    else if(r==l)
    {
        return numeric_limits<double>::infinity();
    }
    //处理中间
    int mid = (l+r)>>1;
    pair<double,double>x1,y1,x2,y2;
    double d;
    double d1 = getmindis(l,mid,x,y),d2=getmindis(mid+1,r,x2,y2);
    if(d2<d1)
       {
        x=x2,y=y2;
           d= d2;
       }
    else
        d=d1;
    // vector<pair<int,int>>tmp;
    // //加入区间位于[a[mid]-d,a[mid]+d];
    // for(int i =1;i<=n;i++)
    //     {
    //         if(nodey[i].first<=nodex[mid].first+d&&nodey[i].first>=nodex[mid].first-d)
    //           tmp.push_back(nodey[i]);//在范围内，且以y轴从小到大
            
    //     
    //可能收集到不属于该区间的点
    vector<pair<double,double>>tmp;
    for(int i = l;i<=r;i++)
        {
            if(nodex[i].first<=nodex[mid].first+d&&nodex[i].first>=nodex[mid].first-d)
                tmp.push_back(nodex[i]);

        }
            sort(tmp.begin(),tmp.end(),[](auto&a,auto&b){
                return  a.second<b.second;});
    if(x.first>y.first)swap(x,y);
    //找每个点以自身y为中心，上下为d范围的点比较距离
    for(int i = 0;i<tmp.size();i++)
        {
            for(int j = i+1;j<tmp.size();j++)
                {
                    if(tmp[j].second-tmp[i].second>d)break;//超过
                    double t =getdis(tmp[i],tmp[j]);
            if(d>t)//相等选x轴小的，输入以x递增输入
            {
                x = tmp[i],y = tmp[j];
                if(x.first+x.second>y.second+y.first)swap(x,y);
                
                d = t;
            }
            else if(fabs(d-t)<1e-12)//xi相等选出正确点
            {
                if(1)
                { int a = i,b = j;
                if(mp[tmp[i]]>mp[tmp[j]])
                {
                     a = j; b = i;
                }
                if(mp[x]>mp[y])swap(x,y);
                if(mp[x]>mp[tmp[a]]||(mp[x]==mp[tmp[a]]&&mp[y]>mp[tmp[b]]))//可能是同一个点，第二个选小的
                {
                    x = tmp[a],y= tmp[b];
                }}
                if(1)
                { auto a = min(x,y),b = max(x,y);
                auto c = min(tmp[i],tmp[j]),d = max(tmp[i],tmp[j]);
                if(a>c||(a==c&&b>d))x = c,y = d;}
            }
                }
        }
    return d;
    
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr); cin >> n;
    for(int i =1;i<=n;i++)
        {
            cin >> nodex[i].first>>nodex[i].second;
            if(!mp.count(nodex[i]))//相同数据
            mp[nodex[i]] = i;
        }
    //sort(nodex+1,nodex+1+n);//以x;已经以x排序
    // sort(nodey+1,nodey+1+n,[&](auto&a,auto&b){
    //     return a.second<b.second;
    // });
    //分治
    //以x分治
    pair<double,double>x,y;
    double dis=getmindis(1,n,x,y);
    if(x.first+x.second>y.first+y.second+1e-12||((fabs(x.first+x.second-y.first-y.second)<=1e-12)&&mp[x]>mp[y])||y<x)swap(x,y);
    printf("(%.2f,%.2f),(%.2f,%.2f),miniDist=%.3f",x.first,x.second,y.first,y.second,dis);
    return  0;
}