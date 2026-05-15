class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n =points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(int i =0;i<n;i++)
        {   
            int x=points[i][0];
            int y=points[i][1];
            minh.push({x*x+y*y,i});
        }
        vector<vector<int>>ans;
        for(int i =1;i<=k;i++)
        {
            int t=minh.top().second;
            minh.pop();
            ans.push_back({points[t][0],points[t][1]});
        }
        return ans;
    }
};