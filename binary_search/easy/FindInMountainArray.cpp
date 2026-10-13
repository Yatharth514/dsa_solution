/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        if (n == 1)
            return 0;

        int l = 0;
        int h = n - 1;
        int mid = 0;

        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                h = mid;
        }
        int piv = l;

        cout << piv << endl;
        if (piv == 0)
        {
            l = piv + 1;
            h = n - 1;
        }
        else if (piv == n - 1)
        {
            l = 0;
            h = n - 1;
        }
        else if ((mountainArr.get(0) <= target && mountainArr.get(piv) >= target))
        {
            l = 0;
            h = piv;
            while (l <= h)
            {
                mid = l + (h - l) / 2;
                if (mountainArr.get(mid) == target)
                    return mid;
                else if (mountainArr.get(mid) < target)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        l = n - 1;
        h = piv + 1;

        while (l >= h)
        {
            mid = l + (h - l) / 2;
            if (mountainArr.get(mid) == target)
                return mid;
            else if (mountainArr.get(mid) < target)
                l = mid - 1;
            else
                h = mid + 1;
        }
        return -1;
    }
};