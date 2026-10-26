class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int mid = 0;
        int l = 0;
        int ans = 0;
        int h = n - 1;
        if (arr[0] > k)
        {
            return k;
        }
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (abs(arr[mid] - (mid + 1)) < k)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }

        return arr[ans] + k - (arr[ans] - (ans + 1));
    }
};