class cmp
{
    public:
    bool operator()(const vector<int>&a,const vector<int>&b)
    {
        return a[1]<b[1];
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n =points.size();
        sort(points.begin(),points.end(),cmp());
        int arrows=1;
        int curEnd=points[0][1];
        int nextStart=0;
        int i =1;
        while(i<n)
        {
            nextStart=points[i][0];
            
            if(nextStart>curEnd)
            {
                curEnd=points[i][1];
                arrows++;
            }
            i++;
        }
        return arrows;
        
    }
};