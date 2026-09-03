class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int minm = INT_MAX;
        int n = nums1.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] % 2 == 0)
                c++;
        }
        if (c == n || c == 0)
            return true;
        c = 0;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            minm = min(minm, nums1[i]);
        }
        if (minm % 2 != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums1[i] % 2 == 0)
                    nums1[i] -= minm;
            }
            for (int i = 0; i < n; i++)
            {
                if (nums1[i] % 2 != 0)
                    c++;
            }
            if (c == n)
                return true;
        }
        return false;
    }
};