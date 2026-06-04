class cmp{
    public:
    bool operator()(const vector<int>&a,const vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),cmp());
        vector<vector<int>>ans;
        for(int i =0;i<n;i++)
        {
            int k=people[i][1];
            ans.insert(ans.begin()+k,people[i]);
        }
        return ans;
        
    }
};