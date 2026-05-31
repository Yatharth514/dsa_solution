class cmp
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
};
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp());
        int removals = 0;
        int curEnd = intervals[0][1];
        int i = 1;
        int nextStart = 0;
        while (i < n)
        {
            nextStart = intervals[i][0];
            if (curEnd > nextStart)
            {
                removals++;
                curEnd = min(curEnd, intervals[i][1]);
            }
            else
            {
                curEnd = intervals[i][1];
            }
            i++;
        }
        return removals;
    }
};