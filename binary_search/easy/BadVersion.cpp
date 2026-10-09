// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1;
        int h = n;
        int mid = 0;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (isBadVersion(mid) && l == h)
                return mid;
            if (!(isBadVersion(mid)))
                l = mid + 1;
            else
                h = mid;
        }
        return mid;
    }
};