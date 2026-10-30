#include<bits/stdc++.h>

using namespace std;
pair<double,double>nodex[100],nodey[100];
int n;
double getdis(pair<double,double> i,pair<double,double> j)
{
    double ans = sqrt(pow(i.first-j.first,2)+pow(i.second-j.second,2));
    return ans;
}
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
        return 1e9;//无效值
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
                return  a.second<b.second;
            });
    //找每个点以自身y为中心，上下为d范围的点比较距离
    for(int i = 0;i<tmp.size();i++)
        {
            for(int j = max(0,i-4);j<=i+4&&j<tmp.size();j++)
                {
                    if(j==i)continue;//不与自身
                    double t =getdis(tmp[i],tmp[j]);
            if(d>t)
            {
                if(tmp[j].first+tmp[j].second>tmp[i].first+tmp[i].second)
                    x = tmp[i],y = tmp[j];
                else
                x = tmp[j],y = tmp[i];
                d = t;
            }
                }
        }
    return d;
    
}
int main()
{
    cin >> n;
    for(int i =1;i<=n;i++)
        {
            cin >> nodex[i].first>>nodex[i].second;
            nodey[i] = nodex[i];
        }
    sort(nodex+1,nodex+1+n);//以x;
    sort(nodey+1,nodey+1+n,[&](auto&a,auto&b){
        return a.second<b.second;
    });
    //分治
    //以x分治
    pair<double,double>x,y;
    double dis = getmindis(1,n,x,y);
    printf("(%.2f,%.2f),(%.2f,%.2f),miniDist=%.3f",x.first,x.second,y.first,y.second,dis);
    return  0;
}