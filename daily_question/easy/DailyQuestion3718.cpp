class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % k == 0)
                maxm = max(maxm, nums[i] / k);
        }
        if (maxm == INT_MIN)
            return k;
        vector<int> mul(maxm + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % k == 0)
            {
                mul[nums[i] / k] = 1;
            }
        }
        for (int i = 1; i <= maxm; i++)
        {
            if (mul[i] != 1)
                return i * k;
        }
        return (maxm + 1) * k;
    }
};