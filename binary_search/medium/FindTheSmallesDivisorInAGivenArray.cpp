class Solution
{
public:
    bool isValid(vector<int> &nums, long long &mid, int &threshold)
    {
        long long count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            count += (nums[i] / mid);
            if (nums[i] % mid != 0)
                count++;
        }
        return count <= threshold;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        long long start = 1, end = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            if (isValid(nums, mid, threshold))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};