class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return 0;
        int l = 0;
        int h = n - 1;
        int mid;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            cout << mid << endl;
            if (mid != 0 && mid != n - 1 && nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (mid != n - 1 && nums[mid + 1] > nums[mid])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return mid;
    }
};