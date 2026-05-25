#include<bits/stdc++.h>
using namespace std;
class cmp
{   
    public:
    bool operator()(const vector<int>&a,const vector<int>&b)
    {
        return a[1]<b[1];
    }

};
int activitySelection(vector<int>&start,vector<int>&finish)
{
    int n=start.size();
    vector<vector<int>>activity;
    for(int i =0;i<n;i++)
    {
        activity.push_back({start[i],finish[i]});
    }
    sort(activity.begin(),activity.end(),cmp());
    int ans=1;
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(activity[i][0]>activity[j][1])
        {
        ans++;
        j=i;
        }
    }
    return ans;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    return 0;
}



//this can be done by priority queue also

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;

for(int i =0;i<n;i++)
{
    minh.push({finish[i],start[i]});
}
int finish=-1;
int cnt=0;
while(!minh.empty())
{
    auto p=minh.top();
    minh.pop();

    if(p.second>finish)
    {
        cnt++;
        finish=p.first;
    }
}
return cnt;