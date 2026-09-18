class Solution
{
public:
    void solve(vector<int> &nums, int n, int i, vector<vector<int>> &b, vector<int> &c, int k)
    {
        if (i == n)
        {
            b.push_back(c);
            return;
        }
        if (k == nums[i])
        {
            solve(nums, n, i + 1, b, c, k);
            return;
        }
        c.push_back(nums[i]);
        solve(nums, n, i + 1, b, c, k);
        if (c.size() > 0)
            k = c.back();
        c.pop_back();
        solve(nums, n, i + 1, b, c, k);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> c;
        vector<vector<int>> b;
        sort(nums.begin(), nums.end());
        int k = INT_MAX;
        solve(nums, n, 0, b, c, k);
        return b;
    }
};