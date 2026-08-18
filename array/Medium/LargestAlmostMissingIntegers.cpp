class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxm = INT_MIN;
        unordered_map<int, int> mpp;
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
            {
                mpp[nums[i]]++;
            }
            for (auto &it : mpp)
            {
                if (it.second == 1)
                {
                    maxm = max(it.first, maxm);
                }
            }
            if (maxm == INT_MIN)
                return -1;
            return maxm;
        }
        else if (k == n)
        {
            for (int i = 0; i < n; i++)
                maxm = max(maxm, nums[i]);
            if (maxm == INT_MIN)
                return -1;
            return maxm;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                mpp[nums[i]]++;
            }
            if (mpp[nums[0]] == mpp[nums[n - 1]] && mpp[nums[0]] == 1)
                return max(nums[0], nums[n - 1]);
            else if (mpp[nums[0]] > 1 && mpp[nums[n - 1]] == 1)
                return nums[n - 1];
            else if (mpp[nums[n - 1]] > 1 && mpp[nums[0]] == 1)
                return nums[0];
            else
                return -1;
        }
    }
};