class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0;
        int h = n - 1;
        int mid = 0;
        if (nums[l] < nums[l + 1])
            return nums[l];
        else if (nums[h - 1] < nums[h])
            return nums[h];
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (mid != 0 && mid != n - 1 && (nums[mid + 1] > nums[mid] && nums[mid] > nums[mid - 1]))
                return nums[mid];
            else if (mid != 0 && nums[mid - 1] != nums[mid])
            {
                if ((mid - l) % 2 == 0)
                    l = mid;
                else
                    h = mid - 1;
            }
            else
            {
                if ((mid - l) % 2 == 0)
                    h = mid;
                else
                    l = mid + 1;
            }
        }
        return mid;
    }
};