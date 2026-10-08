class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> close;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                {
                    return target;
                }
                else
                {
                    close.push_back(sum);
                    if (sum < target)
                        l++;
                    else if (sum > target)
                        r--;
                }
            }
        }
        int k = close.size();
        int minm = INT_MAX;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (minm > abs(target - close[i]))
            {
                minm = abs(target - close[i]);
                ans = close[i];
            }
        }
        return ans;
    }
};