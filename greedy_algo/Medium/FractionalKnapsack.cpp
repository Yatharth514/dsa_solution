#include<bits/stdc++.h>
using namespace std;
class cmp
{
    public:
    bool operator()(const pair<double,int>&a,const pair<double,int>&b)
    {
        return a.first<b.first;
    }
};
double fractionalknapsack(vector<int>&wt,vector<int>&val,int capicity)
{
    int n =wt.size();
    vector<double>ratio;
    vector<pair<double,int>>ans;
    double maxm_val=0.0;
    for(int i=0;i<n;i++)
    {
        ratio.push_back((double)val[i]/(double)wt[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans.push_back({ratio[i],i});
    }
    sort(ans.begin(),ans.end(),cmp());
    for(int i=0;i<n;i++)
    {
        int index=ans[i].second;
       
        if(wt[index]<=capicity)
        {
            maxm_val+=(double)val[index];
            capicity-=wt[index];
        }
        else if(wt[index]>capicity&&capicity>0)
        {
            maxm_val+=((double)capicity/(double)wt[index])*(double)val[index];
            capicity=0;
        }
        else if(capicity==0)
        break;

    }
    return maxm_val;
}
int main()
{

}