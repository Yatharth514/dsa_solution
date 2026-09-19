class Solution
{
public:
    void solve(vector<int> &nums, int k, int n, vector<vector<int>> &b, vector<int> &c, int sum, int i)
    {
        if (sum == k)
        {
            b.push_back(c);
            return;
        }
        for (int j = i; j < n; j++)
        {
            if (nums[j] > k - sum)
                return;
            else
            {
                sum += nums[j];
                c.push_back(nums[j]);
                solve(nums, k, n, b, c, sum, j);
                sum -= nums[j];
                c.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> c;
        vector<vector<int>> b;
        sort(nums.begin(), nums.end());
        solve(nums, target, n, b, c, 0, 0);
        return b;
    }
};