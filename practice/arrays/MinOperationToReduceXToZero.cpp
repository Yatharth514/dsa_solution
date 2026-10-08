class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = 0;
        for (int x : nums)
            sum += x;

        int target = sum - x;
        if (target == 0)
            return n;

        int maxm = INT_MIN;
        int l = 0;
        int r = 0;
        sum = 0;
        while (r < n)
        {
            sum += nums[r];
            if (sum == target)
            {
                maxm = max(maxm, r - l + 1);
            }
            else if (sum > target)
            {
                while (l < r && sum > target)
                {
                    sum -= nums[l];
                    l++;
                }
                if (sum == target)
                    maxm = max(maxm, r - l + 1);
            }
            r++;
        }
        if (maxm == INT_MIN)
            return -1;

        return n - maxm;
    }
};