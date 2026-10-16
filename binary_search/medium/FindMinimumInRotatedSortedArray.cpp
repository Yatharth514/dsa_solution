class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if (n == 2)
            return min(nums[0], nums[1]);

        int l = 0;
        int h = n - 1;
        if (nums[l] < nums[h])
            return nums[l];
        int mid = 0;
        while (l < h)
        {
            mid = l + (h - l) / 2;

            if (nums[mid] > nums[n - 1])
                l = mid + 1;
            else
                h = mid;
        }
        return nums[h];
    }
};