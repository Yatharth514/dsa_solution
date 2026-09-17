class Solution
{
public:
    void solve(vector<int> &nums, int i, int n, vector<int> &c, vector<vector<int>> &b, vector<int> &used)
    {
        if (i == n)
        {
            b.push_back(c);
            return;
        }
        int k;
        for (int j = 0; j < n; j++)
        {
            if (j > 0 && nums[j] == k)
                continue;
            if (!used[j])
            {
                used[j] = 1;
                c.push_back(nums[j]);
                solve(nums, i + 1, n, c, b, used);
                k = c.back();
                c.pop_back();
                used[j] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> b;
        vector<int> c;
        sort(nums.begin(), nums.end());
        vector<int> used(n, 0);
        int k;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == k)
                continue;
            if (!used[i])
            {
                used[i] = 1;
                c.push_back(nums[i]);
                solve(nums, 1, n, c, b, used);
                k = c.back();
                c.pop_back();
                used[i] = 0;
            }
        }
        return b;
    }
};