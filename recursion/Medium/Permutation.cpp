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
        for (int j = 0; j < n; j++)
        {
            if (!used[j])
            {
                used[j] = 1;
                c.push_back(nums[j]);
                solve(nums, i + 1, n, c, b, used);
                used[j] = 0;
                c.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> b;
        vector<int> c;
        int n = nums.size();
        vector<int> used(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                c.push_back(nums[i]);
                solve(nums, 1, n, c, b, used);
                used[i] = 0;
                c.pop_back();
            }
        }
        return b;
    }
};